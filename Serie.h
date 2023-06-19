#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <iostream>
#include <vector>

using namespace std;

class Serie : public Video
{
    private:
        string idEp;
        string nombreEp;
        int temporada;
        int numEp;
    public:
        Serie(string id, string nombre, int duracion, string genero, double calif, string fecha, string idEp, string nombreEp, int temporada, int numEp);
        string getNombreEp();
        void mostrarInfo();
        void mostrarEp();
        void calificar(double calN);
        friend ostream &operator<<(ostream &output, Serie &serie);
};

#endif