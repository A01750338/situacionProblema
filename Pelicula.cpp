/**
 * Autor: Min Che Kim
 * Implementacion de la clase Pelicula
*/

#include "Pelicula.h"
#include <iostream>

// Constructor
Pelicula::Pelicula(string id, string nombre, int duracion, string genero, double calif, string fecha):Video(id,nombre,duracion,genero,calif,fecha)
{
}

// Función para mostrar la información de la película
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

// Función para calificar la película
void Pelicula::calificar(double calN)
{
    calif = calN;
    cout << "La nueva calificación de " + nombre + " es: " << calif << endl;
}

// Sobrecarga del operador <= para comparar la calificación de una película con un valor dado
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

// Sobrecarga del operador '<<' para la clase Pelicula
ostream &operator<<(ostream &output, Pelicula &pelicula)
{
    output << "Calificación antigüa: " << pelicula.getCalif() << endl;
    return output;
}