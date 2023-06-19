/**
 * Autor: Min Kim
 * Define clase Video
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
    string getID();
    string getNombre();
    string getGenero();
    double getCalif();
    virtual void mostrarInfo() = 0;
    virtual void calificar(double calN) = 0;
    friend bool operator<=(double &calif, Video &video);
};

#endif