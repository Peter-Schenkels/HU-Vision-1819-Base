#include "StudentPreProcessing.h"


#include <opencv2/core/core.hpp>
#include <stdlib.h>


#include "ImageFactory.h"



IntensityImage* StudentPreProcessing::stepToIntensityImage(const RGBImage& image) const {

	IntensityImage* new_image = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getHeight() * image.getWidth(); i++) {
		RGB pixel = image.getPixel(i);
		Intensity new_pixel = (pixel.r + pixel.g + pixel.b) / 3;
		new_image->setPixel(i, new_pixel);
	}

	return new_image;
}

IntensityImage* StudentPreProcessing::stepScaleImage(const IntensityImage& image) const {
	return nullptr;
}






IntensityImage* StudentPreProcessing::stepEdgeDetection(const IntensityImage& image) const {

	// Basic edge detection algorithm that serves as a place holder
	// for the "real deal", but it works surprisingly well nonetheless
	// especially with CHILD-1.jpg

	//int kernel[kernel_size*kernel_size];



	IntensityImage* new_image = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
		for (int x = 0; x < image.getWidth(); x++) {
			for (int y = 0; y < image.getHeight(); y++) {

				//Top  kernel
				Intensity pixel_left_up = image.getPixel(x-1, y-1);
				Intensity pixel_middle_up = image.getPixel(x, y-1);
				Intensity pixel_right_up = image.getPixel(x+1, y-1);

				//Middle kernel
				Intensity pixel_left_middle = image.getPixel(x-1, y);
				Intensity pixel_middle_middle = image.getPixel(x, y);
				Intensity pixel_right_middle = image.getPixel(x+1, y);

				// Bottom kernel
				Intensity pixel_left_down = image.getPixel(x+1, y+1);
				Intensity pixel_middle_down = image.getPixel(x, y+1);
				Intensity pixel_right_down = image.getPixel(x-1, y+1);

				//apply sobel kernel
				int sobel_x = pixel_left_up * 1 + pixel_middle_up * 2 + pixel_right_up * 1 +
					pixel_left_middle * 0 + pixel_middle_middle * 0 + pixel_right_middle * 0 +
					pixel_left_down * -1 + pixel_middle_down * -2 + pixel_right_down * -1;

				int sobel_y = pixel_left_up * 1 + pixel_middle_up * 0 + pixel_right_up * -1 +
					pixel_left_middle * 2 + pixel_middle_middle * 0 + pixel_right_middle * -2 +
					pixel_left_down * 1 + pixel_middle_down * 0 + pixel_right_down * -1;


				if (std::sqrt(sobel_x * sobel_x  + sobel_y * sobel_y) > 253) {
					new_image->setPixel(x, y, 254);
				}
				else {

					new_image->setPixel(x, y, std::sqrt(sobel_x * sobel_x + sobel_y * sobel_y));

				}


			}

	

		}

		return new_image;


}



IntensityImage* StudentPreProcessing::stepThresholding(const IntensityImage& image) const {

	Intensity min_pixel = image.getPixel(0);
	Intensity max_pixel = image.getPixel(0);

	IntensityImage* new_image = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());;
	for (int i = 0; i < image.getHeight() * image.getWidth(); i++) {
		Intensity current_pixel = image.getPixel(i);
		if (min_pixel > current_pixel) {
			min_pixel = current_pixel;
		}
		else if (max_pixel < current_pixel) {
			max_pixel = current_pixel;
		}

	}

	const unsigned int threshold_value = abs(min_pixel - max_pixel) / 3;

	for (int i = 0; i < image.getHeight() * image.getWidth(); i++) {

		if (image.getPixel(i) > threshold_value) {
			new_image->setPixel(i, 0);
		}
		else {
			new_image->setPixel(i, 255);
		}

	}

	return new_image;
}