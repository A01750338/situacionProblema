/**
 * Autor: Min Che Kim
 * Clase Video 
*/

#ifndef MENU_H
#define MENU_H

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"

#include <vector>

using namespace std;

class Menu
{
    protected:
        Video* video;
        Pelicula* pelicula;
        Serie* serie;
        vector<Video*> videos;
    public:
        vector<Video*> archivo(string nombreArch);

};

#endif