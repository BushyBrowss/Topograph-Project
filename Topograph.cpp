#include "Topograph.h"

// Constructor
Topograph::Topograph(string fileName)
{
    ifstream in(fileName);

    if (!in)
    {
        cout << "Error: could not open file." << endl;
        exit(1);
    }

    string label;

    // Read header
    in >> label >> width;   // ncols
    in >> label >> height;  // nrows

    double temp;

    in >> label >> temp; // xllcorner
    in >> label >> temp; // yllcorner
    in >> label >> temp; // cellsize
    in >> label >> temp; // NODATA_value

    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;

    // Resize vector
    v.resize(height, vector<double>(width));

    // Read elevation data
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            in >> v[r][c];
        }
    }
}

// Find minimum elevation
void Topograph::findMin()
{
    min = v[0][0];

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            if (v[r][c] < min)
                min = v[r][c];
        }
    }
}

// Find maximum elevation
void Topograph::findMax()
{
    max = v[0][0];

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            if (v[r][c] > max)
                max = v[r][c];
        }
    }
}

// Map value from one range to another
double Topograph::mapRange(double n, double fromLow, double fromHigh, double toLow, double toHigh)
{
    return ((n - fromLow) / (fromHigh - fromLow)) * (toHigh - toLow) + toLow;
}

// Draw grayscale topographic map
void Topograph::drawMap(Picture& pic)
{
    findMin();
    findMax();

    cout << "Min elevation: " << min << endl;
    cout << "Max elevation: " << max << endl;

    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            int gray = (int)mapRange(v[r][c], min, max, 0, 255);

            pic.set(c, r, gray, gray, gray);
        }
    }
}