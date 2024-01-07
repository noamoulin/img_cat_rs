use image::{Rgb, RgbImage};

fn main() {

    let path = "/home/noa/Desktop/igctest"

    let names: Vec<&str> = vec![
    "20-50-1956.jpg",  "22-54-0000-R.jpg",  "24-53-1986.jpg",  "26-47-1981.jpg",
    "20-51-1964.jpg",  "23-47-1955.jpg",    "24-54-1972.jpg",  "26-48-1990.jpg",
    "20-52-1971.jpg",  "23-48-1979.jpg",    "24-55-1978.jpg",  "26-49-1979.jpg",
    "21-49-1989.jpg",  "23-49-1975.jpg",    "25-46-1993.jpg",  "26-50-1992.jpg",
    "21-50-1988.jpg",  "23-50-1932.jpg",    "25-47-1986.jpg",  "26-51-0000-R1.jpg",
    "21-51-1989.jpg",  "23-52-1964.jpg",    "25-48-1990.jpg",  "26-52-0000-R.jpg",
    "21-52-1971.jpg",  "23-53-1970.jpg",    "25-49-1980.jpg",  "26-53-1982-R.jpg",
    "21-53-1971.jpg",  "23-54-1974.jpg",    "25-50-1985.jpg",  "26-54-1979.jpg",
    "22-48-1996.jpg",  "24-46.jpg",         "25-51-1968.jpg",  "27-47-1955.jpg",
    "22-49-1979.jpg",  "24-48-1978.jpg",    "25-52-1967.jpg",  "27-48-1984.jpg",
    "22-50-1995.jpg",  "24-49-1987.jpg",    "25-53.jpg",       "27-49-1966.jpg",
    "22-51-1995.jpg",  "24-50-1988.jpg",    "25-54-1978.jpg",  "27-50-1971.jpg",
    "22-52-1964.jpg",  "24-51-1965.jpg",    "25-55-1966.jpg",  "27-51-1966.jpg",
    "22-53-1970.jpg",  "24-52-1968.jpg",    "26-46-1897.jpg",  "27-52-1989.jpg"];
    

    let images: Vec<&str> = names.into_iter().filter(|elm| elm.ends_with(".jpg")).collect();
    let elues: Vec<(&str, Vec<i32>)> = images.into_iter().map(|name| (name, name.split('-').filter(|elm| elm.chars().all(|chr| chr.is_numeric())).map(|n| n.parse::<i32>().unwrap()).collect())).collect();
    let planches: Vec<(&str, Vec<i32>)> = elues.into_iter().filter(|elm| elm.1.len() == 2).collect();
    let positions_x: Vec<i32> = planches.iter().map(|elm| elm.1[0]).collect();
    let positions_y: Vec<i32> = planches.iter().map(|elm| elm.1[1]).collect();
    
    println!("Px : {:?} | Py : {:?}", positions_x, positions_y);

    let xlims = (positions_x.iter().min().unwrap(), positions_x.iter().max().unwrap());
    let ylims = (positions_y.iter().min().unwrap(), positions_y.iter().max().unwrap());
    let nwidth = xlims.1 - xlims.0;
    let nheight = ylims.1 - ylims.0;

    let planches_floor: Vec<(&str, i32, i32, (_, _))>= planches.into_iter().map(|elm| (path + elm.0, elm.1[0] - xlims.0, elm.1[1] - ylims.0, image::image_dimensions(elm.0).expect("Aucune image dans le repertoire selectionné"))).collect();

    println!("Xlims : {:?} | Ylims : {:?}", xlims, ylims);
    println!("{nwidth} images en largeur | {nheight} images en hauteur");
    println!("A assembler : {:?}", planches_floor);
}
