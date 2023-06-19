/**
 * Autor: Min Che Kim
 * 
*/

#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula(string id, string nombre, int duracion, string genero, double calif, string fecha):Video(id,nombre,duracion,genero,calif,fecha)
{
}

void Pelicula::mostrarInfo()
{
    cout << endl << "\nPelícula: \n" << endl;

    cout << "ID: " << id << endl;
    cout << "Nombre: "    << nombre << endl;
    cout << "Duracion: " << duracion << " minutos" << endl;
    cout << "Género: " << genero << endl;
    cout << "Calificación: " << calif << endl;
    cout << "Fecha de estreno: " << fecha << endl;
}

void Pelicula::calificar(double calN)
{
    calif = calN;
    cout << "La nueva calificación de " + nombre + " es: " << calif << endl;
}

bool operator<=(double &calif, Pelicula &pelicula)
{
    if (calif < pelicula.getCalif() || calif == pelicula.getCalif())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream &operator<<(ostream &output, Pelicula &pelicula)
{
    output << "Calificación antigüa: " << pelicula.getCalif() << endl;
    return output;
}