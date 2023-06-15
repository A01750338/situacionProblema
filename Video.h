/**
 * Autor: Min Che Kim
 * Clase Video 
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video
{
    protected:
        string id;
        string nombre;
        string genero;
        string fecha;
        int duracion;
        double calif;

        double calN;
    public:
        Video(string id, string nombre, int duracion, string genero, double calif, string fecha);
        // void leerArchivo();
        string getID();
        string getNombre();
        string getGenero();
        string getFecha();
        int getDuracion();
        double getCalif();
        virtual void mostrarVideo() = 0;
        void mostrarCal();
        virtual void calificar(double calN) = 0;

};

#endif