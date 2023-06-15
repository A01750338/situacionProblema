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
    /*
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calif = calif;
    this->fecha = fecha;
    */
}

/*void Video::leerArchivo()
{

}*/

string Video::getID()
{
    return id;
}

string Video::getNombre()
{
    return nombre;
}

int Video::getDuracion()
{
    return duracion;
}

string Video::getGenero()
{
    return genero;
}

double Video::getCalif()
{
    return calif;
}

string Video::getFecha()
{
    return fecha;
}

/*void Video::mostrarEp()
{
}*/

/*
void Video::mostrarCal()
{

}
*/
