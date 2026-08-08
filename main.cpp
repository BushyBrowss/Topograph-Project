#include "Topograph.h"

int main()
{
    string inFileName = "output_USGS30m.asc";
    string outFileName1 = "map.png";
    Topograph topo(inFileName);
    Picture pic(topo.getWidth(), topo.getHeight());
    topo.drawMap(pic);
    pic.save(outFileName1);

    return 0;
}
