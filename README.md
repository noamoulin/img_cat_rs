# Rust Image Processing Program

## Description

This Rust program processes a collection of image tiles, arranges them into a grid, and creates a composite image. The input is a directory containing individual image tiles named with a specific format. The output is a composite image formed by arranging these tiles according to their positions.

## Struct: Tile

Represents an image tile.

- Fields:
  - `path`: File path of the image tile.
  - `size`: Tuple representing the dimensions (width, height) of the image.
  - `pos`: Tuple representing the position (x, y) of the image tile in the grid.

## Functions

### 1. find_images(files: Vec<String>) -> Vec<String>

Filters the input file paths, keeping only those ending with ".jpg". Returns a vector of filtered file paths.

### 2. tiles_size(tiles: &Vec<Tile>) -> (u32, u32)

Computes the maximum width and height among the input tiles. Returns a tuple (max_width, max_height).

### 3. limits(tiles: &Vec<Tile>) -> ((u32, u32), (u32, u32))

Computes the minimum and maximum x, y coordinates among the input tiles. Returns a tuple ((x_min, y_min), (x_max, y_max)).

### 4. tiled_size(limits: ((u32, u32), (u32, u32))) -> (u32, u32)

Computes the dimensions of the grid by subtracting minimum from maximum coordinates. Returns a tuple (grid_width, grid_height).

### 5. list_files(path: &str) -> Result<Vec<String>, io::Error>

Lists files in the specified directory. Returns a Result containing a vector of file paths or an IO error.

### 6. get_tiles(images: Vec<String>) -> Vec<Tile>

Processes a vector of image file paths and returns a vector of Tile structs. Prints error messages if there are issues with image file processing.

### 7. write_tiles(tiles: &Vec<Tile>, target_path: &String) -> Option<ImageError>

Writes the composite image by overlaying individual tiles onto a blank canvas. Returns an optional ImageError if there is an error during the process.

### 8. main()

The main function of the program. Parses command line arguments, processes files, and orchestrates the entire image processing workflow.

## Usage

```bash
<executable> <images directory> <target path>
