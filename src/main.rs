use image::{Rgb, RgbImage};
use std::fs;

fn main() {
    let path: &str = "/home/noa/Desktop/igctest/";

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

    for elm in &planches_floor {
        println!("{:?}\n", elm);
    }

    let tile_size = (planches_floor.clone().into_iter().map(|elm| elm.3.0).max().unwrap(), planches_floor.clone().into_iter().map(|elm| elm.3.1).max().unwrap());
    let nwidth = xlims.1 - xlims.0;
    let nheight = ylims.1 - ylims.0;

    println!("tile size : {:?}", tile_size);

    let render_size: (u32, u32) = (tile_size.0 * nwidth, tile_size.1 * nheight);

    println!("render size : {:?}", render_size);

/////////////////////////////////////////////////////////////
    let mut image_buffer = RgbImage::new(100, 100);

    for (_, _, pixel) in image_buffer.enumerate_pixels_mut() {
        *pixel = Rgb([255, 255, 255]);
    }

    if let Err(e) = image_buffer.save("image.png") {
        eprintln!("Erreur lors de l'enregistrement de l'image : {}", e);
    }
//////////////////////////////////////////////////////////////
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
