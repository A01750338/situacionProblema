
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Menu.h"

int main(int argc, char const *argv[])
{
    Menu videos;
    videos.archivo("DatosPeliculas.csv");
    cout<< "prueba";
    for (int i=0; i<videos.archivo("DatosPeliculas.csv").size();i++)
    {
        cout << "tamaño: " << videos.archivo("DatosPeliculas.csv").size() << endl;
        cout << videos.archivo("DatosPeliculas.csv")[i] << endl;
    }

    return 0;
}

