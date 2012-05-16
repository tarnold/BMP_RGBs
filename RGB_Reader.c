#include <stdio.h>
#include "RGB_Reader.h"


void main(int argc, char **argv)
{

FILE *inFile;
BmpHeader header;
DibHeader info;
Rgb *pixel;
int row, column;

	
	//open file argv[1] 
	inFile = fopen(argv[1], "rb");
	if (!inFile) {
		printf("Error opening file %s.\n", argv[1]);
		return;
	}

	//read Bmp file header
	if (fread(&header, 1, sizeof(BmpHeader), inFile) != sizeof(BmpHeader)) {
		printf("Error reading BMP Header.\n");
		return;
	}

	//read Bmp Dibheader
	if (fread(&info, 1, sizeof(DibHeader), inFile) != sizeof(DibHeader)) {
		printf("Error reading DIB Header.\n");
		return;
	}

	//iterate through picture reading pixels
	pixel = (Rgb*) malloc(sizeof(Rgb));
	for (row = 0; row < info.height; row++) {
		for (column = 0; column < info.width; column++) {
			fread(pixel, 1, sizeof(Rgb), inFile) != sizeof(Rgb);
			printf("Pixel (%d, %d): %3d %3d %3d\n", column + 1, row + 1, pixel->red, pixel->green, pixel->blue);
		}
	}

	//print data 
	printf("Depth = %d\n", info.bitDepth);
	printf("Width = %3d, Height = %3d\n", info.width, info.height);
	fclose(inFile);

	return;
}
