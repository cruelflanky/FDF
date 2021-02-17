# FDF Project

## Project Overview
<img align="center" src="http://image.noelshack.com/fichiers/2016/52/1483109173-screen-shot-2016-12-30-at-3-40-16-pm.png" width="100%" />
FDF is a 42 Project to learn about 3d programming. The program takes a map as parameter and creates its 3d representation.
* Render a 3D map from a 2D representation. Initially I was using vectors and simple formulas as illustrated by formula.c file. Later I switched to matrixes.
* You can rotate, increase altitude coefficient and zoom in/out. All transformations are done through matrixes transformations except for the one translating the picture.
* Colors of the map altermate according to seasons and altitude. Colors slowly change to the next point's color. The program can parse colored maps and also handle transparency. Brightness of the image can also be decreased or increased. Please use menu (H button) for a full list of available options.

Note that **macOS is only supported**.

## Mathematics Sources
* Also many thanks to these very informative sites: https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/spherical-coordinates-and-trigonometric-functions
* https://web.archive.org/web/20150225192611/http://www.arcsynthesis.org/gltut/index.html
* http://inside.mines.edu/fs_home/gmurray/ArbitraryAxisRotation/

## Installation
```
make
./fdf map.fdf
```
