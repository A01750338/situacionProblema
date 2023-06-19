/**
 * Autor: Min Che Kim
 * Define clase Pelicula
*/

#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video
{
    public:
        Pelicula(string id, string nombre, int duracion, string genero, double calif, string fecha);
        void mostrarInfo();
        void calificar(double calN);
        friend bool operator<=(double &calif, Pelicula &pelicula);
        friend ostream &operator<<(ostream &output, Pelicula &pelicula);
};

#endif