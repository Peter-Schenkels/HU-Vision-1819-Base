#include "StudentPreProcessing.h"

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

	int difference = 15;
	IntensityImage* new_image = new IntensityImageStudent{ image.getWidth(), image.getHeight() };
	
	for(int i = 1; i < new_image->getWidth() * new_image->getWidth(); i++ ){
		
		if(difference < _abs64(image.getPixel(i) - image.getPixel(i-1))) {
			new_image->setPixel(i - 1, 254);
		} else {
			new_image->setPixel(i - 1, 0);
		}
		
	}
	return new_image;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}