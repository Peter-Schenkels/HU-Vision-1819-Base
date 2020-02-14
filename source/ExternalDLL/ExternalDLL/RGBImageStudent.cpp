#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : 
	RGBImage(other.getWidth(), other.getHeight()),
	image(new RGB[other.getWidth() * other.getHeight()]) 
{
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		image[i] = other.getPixel(i);
	}
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : 
	RGBImage(width, height),
	image(new RGB[getWidth() * getHeight()]) 
{
	//int throwError = 0, e = 1 / throwError;
	//TODO: Initialize pixel storage
}

RGBImageStudent::~RGBImageStudent() {
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
	delete[] image;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[]image;
	image = new RGB[width * height];
	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete[] image;
	image = new RGB[getWidth() * getHeight()];
	for (int i = 0; i < getWidth() * getHeight(); i++)
	{
		image[i] = other.image[i];
	}

	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {

	if (x < getWidth() || y < getHeight()) {
		image[y * getWidth() + x] = pixel;
	}
	else {
		int throwError = 0, e = 1 / throwError;
	}
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	//int throwError = 0, e = 1 / throwError;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
	if (i < getHeight() * getWidth()) {
		image[i] = pixel;
	}
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	if (x < getWidth() || y < getHeight()) {
		return image[y * getWidth() + x];
	} else {
		return 0;
	}
}

RGB RGBImageStudent::getPixel(int i) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	if (i < getHeight() * getWidth()) {
		return image[i];
	} else {
		return 0;
	}
}