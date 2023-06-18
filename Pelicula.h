/**
 * Autor: Min Che Kim
 * 
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
};

#endif