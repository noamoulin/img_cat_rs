use image::{imageops, Rgb, RgbImage};
use std::env;
use std::fs;
use std::io;

struct Tile {
    path: String,
    size: (u32, u32),
    pos: (u32, u32),
}

impl Tile {
    fn new(path: &String) -> Option<Result<Tile,(image::ImageError, String)>> {
        let name: String = path.split('/').last()?.to_string();

        let splt: Vec<&str> = name.split('-').collect();
        if splt.len() < 2 {
            return None;
        }

        let pos: (_, _) = (splt[0].parse::<u32>(), splt[1].parse::<u32>());

        let (x, y) = match pos {
            (Ok(x), Ok(y)) => (x, y),
            _ => return None,
        };

        let size = image::image_dimensions(&path);
        if size.is_err() {
            Some(Err((size.err().unwrap(), path.clone())))
        }
        else {
            let sizes = size.unwrap();

            Some(Ok(Tile {
                path: path.clone(),
                size: sizes,
                pos: (x, y),
            }))
        }
    }
}

fn find_images(files: Vec<String>) -> Option<Vec<String>> {
    let images: Vec<String> = files
        .into_iter()
        .filter(|elm| elm.ends_with(".jpg"))
        .collect();
    if images.len() > 0 {
        Some(images)
    } else {
        None
    }
}

fn tiles_size(tiles: &Vec<Tile>) -> (u32, u32) {
    let max_width = tiles.into_iter().map(|elm| elm.size.0).max().unwrap();
    let max_height = tiles.into_iter().map(|elm| elm.size.1).max().unwrap();
    (max_width, max_height)
}

fn limits(tiles: &Vec<Tile>) -> ((u32, u32), (u32, u32)) {
    let x_offset = tiles.into_iter().map(|elm| elm.pos.0).min().unwrap();
    let y_offset = tiles.into_iter().map(|elm| elm.pos.1).min().unwrap();
    let x_max = tiles.into_iter().map(|elm| elm.pos.0).max().unwrap();
    let y_max = tiles.into_iter().map(|elm| elm.pos.1).max().unwrap();
    ((x_offset, y_offset), (x_max, y_max))
}

fn tiled_size(limits: ((u32, u32), (u32, u32))) -> (u32, u32) {
    (limits.1 .0 - limits.0 .0, limits.1 .1 - limits.0 .1)
}

fn list_files(path: &str) -> Result<Vec<String>, io::Error> {
    let dir = fs::read_dir(path)?;
    Ok(dir
        .filter_map(|entry| {
            entry
                .ok()
                .map(|e| e.file_name().to_string_lossy().to_string())
        })
        .collect())
}

fn get_tiles(images: Vec<String>) -> Vec<Tile> {
    let mut tiles: Vec<Tile> = vec![];
    
    for image in images {
        let candidate = Tile::new(&image);
        if candidate.is_some() {
            let result = candidate.unwrap();
            if result.is_err() {
                let e = result.err().unwrap();
                eprintln!("Failed to read image size for {}. {}", e.1, e.0);
            }
            else {
                tiles.push(result.unwrap());
            }
        }
    }
    tiles
}
fn main() {
    let argv: Vec<String> = env::args().collect();

    if argv.len() != 3 {
        eprintln!(
            "Error, invalid arguments. Usage : <executable> <images directory> <target path>"
        );
        std::process::exit(0);
    }

    let path = &argv[1];
    let target_path = &argv[2];

    let files: Vec<String> = list_files(&path).unwrap()
        .into_iter()
        .map(|elm| path.to_string() + elm.as_str())
        .collect();
    if files.len() == 0 {
        println!("There is not any file at this location");
        std::process::exit(0);
    }
    let images = find_images(files);
    if images.is_none() {
        println!("No image found");
        std::process::exit(0);
    }

    let tiles = get_tiles(images.unwrap());
    if tiles.len() == 0 {
        println!("Wrong image name format, no tile found");
        std::process::exit(0);
    }

    let extrems_pos: ((u32, u32), (u32, u32)) = limits(&tiles);
    let tiling_size: (u32, u32) = tiled_size(extrems_pos);
    let void_size: (u32, u32) = tiles_size(&tiles);
    let render_size: (u32, u32) = (tiling_size.0 * void_size.0, tiling_size.1 * void_size.1);

    let mut target = RgbImage::new(render_size.0, render_size.1);

    image::imageops::vertical_gradient(&mut target, &Rgb([255, 255, 255]), &Rgb([255, 255, 255]));

    for tile in &tiles {
        let tile_image = image::open(tile.path.clone()).expect("failed to open an image");
        let image = tile_image.to_rgb8();

        let x_offset = (tile.pos.0 - extrems_pos.0 .0) * (void_size.0 - 1);
        let y_offset = (tile.pos.1 - extrems_pos.0 .1) * (void_size.1 - 1);

        imageops::overlay(&mut target, &image, x_offset.into(), y_offset.into());
        println!("Tile Written");
    }
    println!("\nSaving the padding to {target_path}...");
    if let Err(e) = target.save(target_path) {
        eprintln!("Error while saving target image : {}", e);
    }
}
