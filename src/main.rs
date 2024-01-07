use image::{Rgb, RgbImage};
use std::env;
use std::fs;

fn main() {

    let argv: Vec<String> = env::args().collect();

    if argv.len() != 3 {
        eprintln!("Error, invalid arguments. Usage : <executable> <images directory> <target path>");
        std::process::exit(0);
    }

    let path: &str = argv[1].as_str();
    let target_path = argv[2].as_str();

    let names = list_files(path);

    let images: Vec<String> = names
        .into_iter()
        .filter(|elm| elm.ends_with(".jpg"))
        .collect();
    let elues: Vec<(String, Vec<u32>)> = images
        .into_iter()
        .map(|name| {
            (
                name.clone(),
                name.split('-')
                    .filter(|elm| elm.chars().all(|chr| chr.is_numeric()))
                    .map(|n| n.parse::<u32>().unwrap())
                    .collect(),
            )
        })
        .collect();
    let planches: Vec<(String, Vec<u32>)> =
        elues.into_iter().filter(|elm| elm.1.len() == 2).collect();
    let positions_x: Vec<u32> = planches.iter().map(|elm| elm.1[0]).collect();
    let positions_y: Vec<u32> = planches.iter().map(|elm| elm.1[1]).collect();

    let xlims = (
        positions_x.iter().min().unwrap(),
        positions_x.iter().max().unwrap(),
    );
    let ylims = (
        positions_y.iter().min().unwrap(),
        positions_y.iter().max().unwrap(),
    );

    let planches_floor: Vec<(String, u32, u32, (_, _))> = planches
        .into_iter()
        .map(|elm| {
            (
                path.to_string() + elm.0.clone().as_str(),
                elm.1[0] - xlims.0,
                elm.1[1] - ylims.0,
                image::image_dimensions(path.to_string() + elm.0.clone().as_str())
                    .expect("Aucune image dans le repertoire selectionné"),
            )
        })
        .collect();

    let tile_size = (
        planches_floor
            .clone()
            .into_iter()
            .map(|elm| elm.3 .0)
            .max()
            .unwrap(),
        planches_floor
            .clone()
            .into_iter()
            .map(|elm| elm.3 .1)
            .max()
            .unwrap(),
    );
    let nwidth = xlims.1 - xlims.0 + 1;
    let nheight = ylims.1 - ylims.0 + 1;

    let render_size: (u32, u32) = (tile_size.0 * nwidth, tile_size.1 * nheight);

    let mut target = RgbImage::new(render_size.0, render_size.1);

    for (_, _, pixel) in target.enumerate_pixels_mut() {
        *pixel = Rgb([255, 255, 255]);
    }

    for planche in &planches_floor {
        let dimage = image::open(planche.0.clone()).unwrap();
        let image = dimage.to_rgb8();

        let x_offset = planche.1 * (tile_size.0 - 1);
        let y_offset = planche.2 * (tile_size.1 - 1);

        for x in 0..planche.3 .0 {
            for y in 0..planche.3 .1 {
                let current_pixel = image.get_pixel(x, y);
                target.put_pixel(x_offset + x, y_offset + y, *current_pixel);
            }
        }
    }

    if let Err(e) = target.save(target_path) {
        eprintln!("Erreur lors de l'enregistrement de l'image : {}", e);
    }
}

fn list_files(chemin_dossier: &str) -> Vec<String> {
    fs::read_dir(chemin_dossier)
        .expect("Erreur lors de la lecture du dossier")
        .filter_map(|entry| {
            entry
                .ok()
                .map(|e| e.file_name().to_string_lossy().to_string())
        })
        .collect()
}
