#ifndef BMPIMAGE_H
#define BMPIMAGE_H
#include <string>
#pragma pack(push, 1)

typedef struct {
    int x;
    int y;
} Coordinate;


typedef struct {
    unsigned short signature;
    unsigned int filesize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int pixelArrOffset;
} BitmapFileHeader;

typedef struct {
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xPixelsPerMeter;
    unsigned int yPixelsPerMeter;
    unsigned int colorsInColorTable;
    unsigned int importantColorCount;
} BitmapInfoHeader;

typedef struct
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
} BGR;
#pragma pack(pop)

class BMPImage
{

public:
    BitmapFileHeader bmfh;
    BitmapInfoHeader bmih;
    BMPImage();
    BGR** pixels;
    BGR colorSquare;
    BGR colorSquare_fill;
    BGR colorPrint;
    int height;
    int width;
    int BMPRead(std::string);
    void BMPWrite(std::string);
    void Razor(int, BGR, bool);
    void BMPDrawSquare(Coordinate, Coordinate, int, bool);
    void BMPTurn(Coordinate, Coordinate , int);
    void Snowflakes(int, BGR);
};

#endif // BMPIMAGE_H
