#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include <iostream>

class Serie : public Video
{
    private:
        string idEp;
        string nombreEp;
        int temporada;
        int numEp;
    public:
        Serie(string id, string nombre, int duracion, string genero, double calif, string fecha,string idEp, string nombreEp, int temporada, int numEp);
        void mostrarVideo();
};

#endif