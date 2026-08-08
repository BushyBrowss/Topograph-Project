#ifndef TOPOGRAPH_H_INCLUDED
#define TOPOGRAPH_H_INCLUDED

#include "Picture.h"
#include <iostream>
#include <fstream>
using namespace std;

class Topograph
{
public:
    ///**************Part 1********************************
    ///Constructor.  Open a ArcGIS ASCII Grid file
    ///read the header to assign height and width
    ///resize v and read elevation data
    Topograph(string fileName);

    int getHeight() const{return height;}
    int getWidth() const{return width;}

    ///find min and max elevation values
    ///call mapRange to convert each elevation to grayscale
    ///set each Picture coordinate at (x,y) to its grayscale value
    void drawMap(Picture& pic);

private:
    void findMin();
    void findMax();
    ///scale n from [fromLow:fromHigh] to [toLow:toHigh]
    double mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh);

    vector<vector<double>> v;
    int height;
    int width;
    double min;
    double max;
};

#endif // TOPOGRAPH_H_INCLUDED
