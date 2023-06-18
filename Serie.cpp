#include "Serie.h"

Serie::Serie(string id, string nombre, int duracion, string genero, double calif, string fecha, string idEp, string nombreEp, int temporada, int numEp)
: Video(id,nombre,duracion,genero,calif,fecha)
{
    this->idEp = idEp;
    this->nombreEp = nombreEp;
    this->temporada = temporada;
    this->numEp = numEp;
}


void Serie::mostrarInfo()
{
    cout<< endl << "\nEpisodio: \n"<< endl;

    cout << "ID: " << id << endl;
    cout << "Nombre: "    << nombre << endl;
    cout << "Duracion: " << duracion << " minutos" << endl;
    cout << "Género: " << genero << endl;
    cout << "Fecha de estreno: " << fecha << endl;

        cout << "ID Ep: " << idEp << endl;
    cout << "Temporada: " << temporada << endl;
    cout << "Episodio: " << numEp << endl;
    cout << "Nombre: " << nombreEp <<endl;
    cout << "Calificación: " << calif << endl;  
}

void Serie::calificar(double calN)
{
    this->calN = calN;
}
