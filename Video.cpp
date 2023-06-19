/**
 * Autor: Min Che Kim
 * Implementacion de la clase Video
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // string stream flujo de datos apartir de una cadena
#include <vector>

#include "Video.h"

using namespace std;

Video::Video(string id, string nombre, int duracion, string genero, double calif, string fecha)
: id(id), nombre(nombre), duracion(duracion), genero(genero),calif(calif),fecha(fecha)
{
}

// Regresa el ID del video
string Video::getID()
{
    return id;
}

// Regresa el nombre del video
string Video::getNombre()
{
    return nombre;
}

// Regresa los géneros del video
string Video::getGenero()
{
    return genero;
}

// Regresa la calificación del video
double Video::getCalif()
{
    return calif;
}


bool operator<=(double &calif, Video &video)
{
    if (calif < video.getCalif() || calif == video.getCalif())
    {
        return true;
    }
    else
    {
        return false;
    }
}

