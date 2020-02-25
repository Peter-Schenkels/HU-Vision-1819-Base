#include "StudentPreProcessing.h"


#include <opencv2/core/core.hpp>
#include <stdlib.h>

#include "IntensityImageStudent.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}


IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {

	// Basic edge detection algorithm that serves as a place holder
	// for the "real deal", but it works surprisingly well nonetheless
	// especially with CHILD-1.jpg

	const unsigned int difference = 15;
	//const unsigned int kernel_size = 3;
	//const unsigned int kernel_offset = kernel_size / 3;
	//
	//int kernel[kernel_size*kernel_size];
	
	IntensityImage* new_image = new IntensityImageStudent{ image.getWidth(), image.getHeight() };
	for (int x = 1; x < image.getWidth() - 1; x++) {
		for (int y = 1; y < image.getHeight() - 1; y++) {
			Intensity pixel = image.getPixel(x, y);
			Intensity pixel_up = image.getPixel(x, y-1);
			Intensity pixel_down = image.getPixel(x, y+1);
			Intensity pixel_left = image.getPixel(x-1, y);
			Intensity pixel_right = image.getPixel(x+1, y);
			Intensity new_pixel = 0;

			// Kernel
			if (abs((pixel + pixel_up)/ 2 - pixel_down) > difference) {
				new_pixel += 50;
			}
			
			if (abs((pixel + pixel_down) / 2 - pixel_up) > difference) {
				new_pixel += 50;
			}

			if (abs((pixel + pixel_left) / 2 - pixel_right) > difference) {
				new_pixel += 50;
			}

			if (abs((pixel + pixel_right) / 2 - pixel_left) > difference) {
				new_pixel += 50;
			}

			if(new_pixel > 99)
			{
				new_image->setPixel(x, y, 255);
			} else
			{
				new_image->setPixel(x, y, 0);
			}
		}
			
		
	}

	
	////Convolution
	//for (int x = kernel_offset; x < image.getWidth() - kernel_offset; x++) {
	//	for (int y = kernel_offset; y < image.getHeight() - kernel_offset; y++) {
	//		// Fill Kernel
	//		for (int kernel_x = 0; kernel_x < 3; kernel_x++) {
	//			for (int kernel_y = 0; kernel_y < 3; kernel_y++) {
	//				kernel[kernel_y * kernel_size + kernel_x] = image.getPixel(x + (kernel_x - kernel_offset), y + (kernel_y - kernel_offset)) * (kernel_x - kernel_offset);
	//			}
	//		}
	//		char new_pixel = 0;
	//		
	//		int* filter = new int[9]{ 1, 0, -1, 1, 0, -1, 1, 0, -1 };
	//		//for (unsigned int i = 0; i < kernel_size * kernel_size; i++) {
	//		//	new_pixel += kernel[i] * filter[i];
	//		//}
	//		//
	//		//filter = new int[9]{ -1, 0, 1, -1, 0, 1, -1, 0, 1 };
	//		//for (unsigned int i = 0; i < kernel_size * kernel_size; i++) {
	//		//	new_pixel += kernel[i] * filter[i];
	//		//}
	//
	//		filter = new int[9]{ 1,1,1,0,0,0,-1,-1,-1 };
	//		for (unsigned int i = 0; i < kernel_size * kernel_size; i++) {
	//			new_pixel += kernel[i] * filter[i];
	//		}
	//		//filter = new int[9]{ -1,-1,-1,0,0,0,1,1,1 };
	//		//for (unsigned int i = 0; i < kernel_size * kernel_size; i++) {
	//		//	new_pixel += kernel[i] * filter[i];
	//		//}
	//		
	//		//Set pixel
	//		if(new_pixel > difference){
	//			new_pixel = 250;
	//		} else {
	//			new_pixel = 0;
	//		}
	//		new_image->setPixel(x, y, new_pixel);
	//		delete[] filter;
	//	}
	//}

	// Gaussian blur
	//for (int x = kernel_offset; x < new_image->getWidth() - kernel_offset; x++) {
	//	for (int y = kernel_offset; y < new_image->getHeight() - kernel_offset; y++) {
	//		// Fill Kernel
	//		for (int kernel_x = 0; kernel_x < 3; kernel_x++) {
	//			for (int kernel_y = 0; kernel_y < 3; kernel_y++) {
	//				kernel[kernel_y * kernel_size + kernel_x] = image.getPixel(x + (kernel_x - kernel_offset), y + (kernel_y - kernel_offset)) * (kernel_x - kernel_offset);
	//			}
	//		}

	//		// Calculate mean
	//		int mean = 0;
	//		for (int i = 0; i < kernel_size * kernel_size; i++)
	//		{
	//			mean += kernel[i];
	//		}
	//		mean /= (kernel_size * kernel_size);

	//		//Set pixel
	//		new_image->setPixel(x, y, 150 - mean);
	//		
	//	}
	//}


	
//	for (int x = 1; x < new_image->getWidth() - 1; x++) {
//		for (int y = 1; y < new_image->getWidth() - 1; y++) {
//
//			// Fill Kernel
//			for (int kernel_x = 0; kernel_x < 3; kernel_x++) {
//				for (int kernel_y = 0; kernel_y < 3; kernel_y++) {
//					kernel[kernel_y * kernel_size + kernel_x] = image.getPixel(x + (kernel_x - 1), y + (kernel_y - 1)) * (kernel_x - 1);
//				}
//			}
//
//			// Calculate edge
//			int gray_value = 0;
//			for (int i = 0; i < kernel_size; i++) {
//				gray_value += kernel[i];
//			}
//
//			if (gray_value > difference)
//				new_image->setPixel(x, y, 255);
//			else
//			{
//				new_image->setPixel(x, y, 0);
//			}
//
//		}
//	}
//
	return new_image;
}



IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	
	Intensity min_pixel = image.getPixel(0);
	Intensity max_pixel = image.getPixel(0);
	
	IntensityImageStudent* new_image = new IntensityImageStudent(image.getHeight(), image.getWidth());
	for (int i = 0; i < image.getHeight() * image.getWidth(); i++){
		Intensity current_pixel = image.getPixel(i);
		if(min_pixel > current_pixel){
			min_pixel = current_pixel;
		}
		else if (max_pixel < current_pixel){
			max_pixel = current_pixel;
		}
		
	}

	const unsigned int threshold_value = abs(min_pixel - max_pixel) / 2;

	for (int i = 0; i < image.getHeight() * image.getWidth(); i++) {

		if(image.getPixel(i) > threshold_value)	{
			new_image->setPixel(i, 0);
		} else {
			new_image->setPixel(i, 255);
		}

	}
	
	return new_image;
}