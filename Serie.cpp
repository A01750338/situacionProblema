/**
 * Autor: Min Che Kim
 * Implementacion de la clase Serie
 */
#include "Serie.h"

// Constructor
Serie::Serie(string id, string nombre, int duracion, string genero, double calif, string fecha, string idEp, string nombreEp, int temporada, int numEp)
: Video(id,nombre,duracion,genero,calif,fecha)
{
    this->idEp = idEp;
    this->nombreEp = nombreEp;
    this->temporada = temporada;
    this->numEp = numEp;
}

// Regresa nombre del Episodio
string Serie::getNombreEp()
{
    return nombreEp;
}

// Función para mostrar la información general de la serie y el episodio
void Serie::mostrarInfo()
{
    cout<< endl << "\nSerie: \n"<< endl;

    cout << "ID: " << id << endl;
    cout << "Nombre: "    << nombre << endl;
    cout << "Duracion: " << duracion << " minutos" << endl;
    cout << "Género: " << genero << endl;
    cout << "Fecha de estreno: " << fecha << endl;

    cout << "\nID Ep: " << idEp << endl;
    cout << "Temporada: " << temporada << endl;
    cout << "Episodio: " << numEp << endl;
    cout << "Nombre: " << nombreEp <<endl;
    cout << "Calificación: " << calif << endl;  
}

// Función para mostrar la información específica del episodio
void Serie::mostrarEp()
{
    cout << "ID Ep: " << idEp << endl;
    cout << "Temporada: " << temporada << endl;
    cout << "Episodio: " << numEp << endl;
    cout << "Nombre: " << nombreEp <<endl;
    cout << "Calificación: " << calif << endl;  
}

// Función para calificar un episodio de la serie
void Serie::calificar(double calN)
{
    calif = calN;
    cout << "La nueva calificación de " << nombre << " del episodio " << numEp << " " << nombreEp <<" es: " << calif;
}

// Sobrecarga del operador '<<' para la clase Serie
ostream &operator<<(ostream &output, Serie &serie)
{
    output << "Calificación antigüa: " << serie.getCalif() << endl;
    return output;
}
