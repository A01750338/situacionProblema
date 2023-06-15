/**
 * Autor: Min Che Kim
 * Clase Video
 */

#include "Menu.h"

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> // string stream flujo de datos apartir de una cadena
#include <vector>

vector<Video *> Menu::archivo(string nombreArch)
{
    ifstream archivo;
    archivo.open(nombreArch);

    if (archivo.is_open())
    {
        string linea, id, nombre, genero, fecha, idEp, nombreEp;
        int duracion, temporada, numEp;
        double cal;
        getline(archivo, linea);

        while (getline(archivo,linea))
        {
            vector<string> tokens;
            stringstream entrada(linea);
            //string dato;
            int numeroTokens = 0;
            while (getline(entrada, linea, ','))
            {
                if (linea != "" && linea != "\n" && linea != "\r")
                {
                    tokens.push_back(linea); // GUARDA  en el vector
                    numeroTokens++;
                }
                cout << numeroTokens << endl;
            }
            cout << "tokens: " << numeroTokens << endl
                 << endl;

            stringstream token(linea);
            getline(token, id, ',');
            getline(token, nombre, ',');
            getline(token, linea, ',');
            duracion = stoi(linea);
            getline(token, genero, ',');
            getline(token, linea, ',');
            cal = stod(linea);
            getline(token, fecha, ',');

            // vector<Pelicula> peliculas;
            // vector<Serie> series;

            if (numeroTokens == 6)
            {
                // Pelicula peli(id, nombre, d, genero, c, fecha);
                // peliculas.push_back(peli);
                videos.push_back(new Pelicula(id, nombre, duracion, genero, cal, fecha));
            }
            else
            {
                getline(token, idEp, ',');
                getline(token, linea, ',');
                temporada = stoi(linea);
                getline(token, linea, ',');
                numEp = stoi(linea);
                getline(token, nombreEp, ',');
                getline(token, fecha, ',');

                // int temp = stoi(temporada);
                // int nEp = stoi(numEp);

                // Serie serie(id, nombre, d, genero, c, fecha, idEp, nombreEp, temp, nEp);
                // series.push_back(serie);
                videos.push_back(new Serie(id, nombre, duracion, genero, cal, fecha, idEp, nombreEp, temporada, numEp));
            }
        }
    }

    archivo.close();

    return videos;
}
