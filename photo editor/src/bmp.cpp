#include "bmp.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <QVector>
using namespace std;

BMPImage::BMPImage()
{

}
void BMPImage::BMPWrite(string path) {
    ofstream image(path, ios::binary);
    image.write((char*)&bmfh, sizeof(BitmapFileHeader));
    image.write((char*)&bmih, sizeof(BitmapInfoHeader));
    int H = bmih.height;
    int W = bmih.width;
    unsigned int w = (W) * sizeof(BGR) + (W*3)%4;
    for(int i=0; i<H; i++){
        image.write((char*)pixels[i],w);
    }
    image.close();
}

int BMPImage::BMPRead(string path) {
    ifstream image(path, ios::binary);
    image.read((char*)&bmfh, sizeof(BitmapFileHeader));
    image.read((char*)&bmih, sizeof(BitmapInfoHeader));
    int H = bmih.height;
    int W = bmih.width;
    width = bmih.width;
    height = bmih.height;
    pixels = new BGR*[H*sizeof(BGR*)];
    for(int i=0; i<H; i++){
        pixels[i] = new BGR[W * sizeof(BGR) + (W*3)%4];
        image.read((char*)pixels[i], W * sizeof(BGR) + (W*3)%4);
    }
    image.close();
    return 1;
}

void BMPImage::BMPDrawSquare(Coordinate max, Coordinate min , int size, bool fill){
    for(int i=max.y; i<=min.y; i++) {
        for(int j=max.x; j<=min.x;j++) {
            if((i <= max.y+size) || (i >= min.y-size))
                pixels[i][j] = colorSquare;
            else if((j <= max.x+size) || (j >= min.x-size))
                pixels[i][j] = colorSquare;
            else if (fill)
                    pixels[i][j] = colorSquare_fill;


        }

    }
}

void BMPImage::BMPTurn(Coordinate left_corner, Coordinate right_corner, int angle){
    if(angle == 270) angle = -90;
    if((right_corner.x-left_corner.x) % 2) right_corner.x++;
    if((right_corner.y-left_corner.y) % 2) right_corner.y++;
    BGR** v;
    v = new BGR*[height*sizeof(BGR*)];
    for(int i=0; i<height; i++){
        v[i] = new BGR[width * sizeof(BGR) + (width*3)%4];
        for(int j=0; j<width; j++){
            v[i][j] = pixels[i][j];
        }
    }

    Coordinate center = {(right_corner.x+left_corner.x)/2,(left_corner.y+right_corner.y)/2};
    for(int i=left_corner.y; i<=right_corner.y; i++) {
        for(int j=left_corner.x; j<=right_corner.x; j++) {
            float new_x = center.x+((j-center.x)*cos(angle*M_PI/180)-(i-center.y)*sin(angle*M_PI/180));
            float new_y = center.y+((j-center.x)*sin(angle*M_PI/180)+(i-center.y)*cos(angle*M_PI/180));
            if(new_y >= height) continue;
            if(new_y < 0) continue;
            if(new_x < 0) continue;
            if(new_x >= width) continue;
            if(i<0) break;
            if(i>=height) continue;
            if(j<0) continue;
            if(j>=width) break;

            pixels[(int)new_y][(int)new_x] = v[i][j];

        }
    }
}

void BMPImage::Snowflakes(int size, BGR color){ //rename
    for(int size_plus = 0;size_plus <= size; size_plus++){
        int state = 0;
        int buf = 2;
    for (int n = 1; n < (4+1)*10; n*=10){
        state = 0;
        buf = 2;
        for(int i = 0+n+size_plus; i <= height-2; i++){
            for(int j = 0+n+size_plus; j < width-2; j++){
                if (state < 10){
                    pixels[i][j] = color;
                    pixels[height-2-i][width-2-j] = color;
                    state++;
                    break;
                }
                if(state < 25){
                    pixels[i][buf] = color;
                    pixels[height-2-i][width-2-buf] = color;
                    buf++;
                    state++;
                    break;
                }
                if(state < 40){
                    pixels[i][buf] = color;
                    pixels[height-2-i][width-2-buf] = color;
                    buf--;
                    state++;
                    break;
                }
                if(state == 40){
                    pixels[i][j] = color;
                    pixels[height-2-i][width-2-j] = color;
                    state = 0;
                    break;
                }
            }
        }
        state = 0;
        buf = 2;
        for(int j = 0+n+size_plus; j <= width-2; j++){
            for(int i = 0+n+size_plus; i < height-2; i++){
                if (state < 10){
                    pixels[i][width-2-j] = color;
                    pixels[height-2-i][j] = color;
                    state++;
                    break;
                }
                if(state < 25){
                    pixels[buf][width-2-j] = color;
                    pixels[height-2-buf][j] = color;
                    buf++;
                    state++;
                    break;
                }
                if(state < 40){
                    pixels[buf][width-2-j] = color;
                    pixels[height-2-buf][j] = color;
                    buf--;
                    state++;
                    break;
                }
                if(state == 40){
                    pixels[i][width-2-j] = color;
                    pixels[height-2-i][j] = color;
                    state = 0;
                    break;
                }
            }
        }
        state = 0;
        buf = 2;
    }
    }
}

void BMPImage::Razor(int size, BGR color, bool var){
    if(size >= height-15 || size >= width-15) size-=15;
    int state1;
    int state2;
    if(var){
        size += 10;
        state1 = 0;
        if(size >= height-25 || size >= width-25) size-=10;
        state2 = 15+size;
    }
    for(int j = 10; j <= 10+size; j++){
        if(!var){
            state1 = 0;
            state2 = 15+size;
        }
    for(int i = j; i < height; i++){
        if(state1 < 15+size){
            pixels[i][state1] = color;
            pixels[height-i][width-state1] = color;
            state1++;
        }else if(state1 < 30+size*2){
            pixels[i][state2] = color;
            pixels[height-i][width-state2] = color;
            state2--;
            state1++;
        }else{
            state1 = 0;
            state2 = 15+size;
        }
    }
    if(!var){
        state1 = 0;
        state2 = 15+size;
    }
    for(int i = j; i < width; i++){
        if(state1 < 15+size){
            pixels[state1][width-i] = color;
            pixels[height-state1-1][i] = color;
            state1++;
        }else if(state1 < 30+size*2){
            pixels[state2][width-i] = color;
           pixels[height-state2-1][i] = color;
            state2--;
            state1++;
        }else{
            state1 = 0;
            state2 = 15+size;
        }
    }
    }
}
