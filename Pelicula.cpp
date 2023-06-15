/**
 * Autor: Min Che Kim
 * 
*/

#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula(string id, string nombre, int duracion, string genero, double calif, string fecha):Video(id,nombre,duracion,genero,calif,fecha)
{
}

void Pelicula::mostrarVideo()
{
    cout << "ID: " << id << endl;
    cout << "Nombre: "    << nombre << endl;
    cout << "Duracion: " << duracion << " minutos" << endl;
    cout << "Género: " << genero << endl;
    cout << "Calificación: " << calif << endl;
    cout << "Fecha de estreno: " << fecha << endl;
}

void Pelicula::calificar(double calN)
{
    this->calN = calN;
}
