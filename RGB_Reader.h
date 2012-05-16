#include <stdio.h>
#pragma pack(2)

//BMP Header struct
typedef struct
{
	char signature[2];
	int creator1;
	int creator2;
	int offset;
} BmpHeader;

//BMP DIB Header struct
typedef struct
{
	int header_sz;
	int width;
	int height;
	short numplanes;
	short bitDepth;
	short compress_type;
	int byte_sz;
	int hRes;
	int vRes;
	int numColors;
	int ImportantColors;
} DibHeader;

//RGB struct
typedef struct
{
	char blue;
	char green;
	char red;
} Rgb;

