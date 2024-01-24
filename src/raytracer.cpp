#include <iostream>
#include <vector>
#include <fstream>
#include "color.h"

void raytrace(){
    int image_width = 256;
    int image_height = 256;

    // Render

    std::ofstream output_file;
    output_file.open("output.ppm");

    //std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    output_file << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0;

            auto pixel_color = color(r, g, b);
            write_color(output_file, pixel_color);

            //std::cout << ir << ' ' << ig << ' ' << ib << '\n';
            //output_file << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    output_file.close();
}