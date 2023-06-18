#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include <iostream>
#include <fstream>  
#include <sstream>
#include <vector>
using namespace std;


vector<string> separar(string linea);
vector <Video*> videos;


int main(int argc, char const *argv[])
{
    ifstream entrada;


    entrada.open("DatosPeliculas.csv");


    string linea;
    getline(entrada, linea);


    while (getline(entrada, linea))
    {
        vector <string> datos = separar(linea);


        if(datos.size() == 6)
        {
            Pelicula* pelicula = new Pelicula(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5]);
            videos.push_back(pelicula);
        }
        else
        {
            Serie* serie = new Serie(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9]));
            videos.push_back(serie);
        }
       
    }
   
    entrada.close();


    for (int i = 0; i < videos.size(); i++)
    {
        videos[i]->mostrarInfo();
    }
    return 0;
}


vector <string> separar(string linea)
{
    vector<string> tokens;  //componentes de la línea


    stringstream entrada(linea);    //flujo de datos a partir de una cadena
    string dato;    //token individual
    int numeroTokens = 0;
  while (getline(entrada, dato, ','))
    {
        //cout << dato << endl;
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            //cout << dato << numeroTokens <<endl;
            tokens.push_back(dato); // GUARDA  en el vector
            numeroTokens++;
        }
    }
    //cout << "tokens: " << numeroTokens << endl << endl; comprobar si esta contando correctamente
   
    return tokens;
}
