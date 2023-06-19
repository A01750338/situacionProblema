#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> separar(string linea);
vector<string> nombreSeries();
vector<string> nombrePeli();
vector<Video *> videos;

int errorOpCorrecto()
{
    int respuesta;
    bool correcto(false);

    while (!correcto)
    {
        cout << "\nIngrese la opcion: ";
        cin >> respuesta;
        try
        {
            if (respuesta != 1 && respuesta != 2)
            {
                throw invalid_argument("El numero ingresado debe de ser 1 o 2.");
                correcto = false;
            }
            else
            {
                correcto = true;
            }
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
            cout << "Intente de nuevo\n";
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
    return respuesta;
}

int errorTipoDatoCorrecto()
{
    int respuesta;
    bool correcto(false);
    while (!correcto)
    {
        cout << "\nIngrese el numero: ";
        cin >> respuesta;
        try
        {
            if (cin.fail())
                throw invalid_argument("ERROR!!! La opcion debe de ser un int.");
            correcto = true;
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
            cout << "Intente de nuevo\n";
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
    return respuesta;
}

string stringIncorrecto()
{
    string respuesta;
    bool correcto(false);
    while (!correcto)
    {
        cout << "\nIngrese el genero (sin acentos): ";
        cin >> respuesta;
        try
        {
            if (cin.fail())
                throw invalid_argument("ERROR!!! La opcion debe de ser un string.");
            correcto = true;
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
            cout << "Vuelve a intentar\n";
            cin.clear();
            cin.ignore(32767, '\n');
        }
    }
    return respuesta;
}

int main(int argc, char const *argv[])
{
    int opcion;
    int respuesta;
    bool correcto(false);
    cout << "\nBienvenido. Eliga alguna de las siguientes opciones para continuar. Se deberá de empezar por la opcion 1."
         << endl
         << "1.Cargar archivos"
         << endl
         << "2.Mostrar videos con cierta calificacion o de cierto genero"
         << endl
         << "3.Mostrar episodios de una determinada serie"
         << endl
         << "4.Mostrar las peliculas con cierta calificacion"
         << endl
         << "5.Calificar un video"
         << endl
         << "6.Calcular promedio de la calificación de una serie"
         << endl
         << "0.Salir" << endl;

    opcion = errorTipoDatoCorrecto();
    correcto = false;

    while (!correcto)
    {
        try
        {
            if (opcion != 1)
                throw invalid_argument("La primera opcion debe de ser 1.");
            correcto = true;
        }
        catch (invalid_argument error)
        {
            cout << error.what() << endl;
            cout << "Intente de nuevo\n";
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "\nIngrese la opcion:  " << endl;
            cin >> opcion;
        }
    }

    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
        {

            string respuesta;
            bool correcto = false;
            while (!correcto)
            {
                string nombreArchivo;
                cout << "Ingrese el nombre del archivo" << endl;
                cin >> nombreArchivo;
                try
                {
                    ifstream entrada;

                    entrada.open(nombreArchivo);
                    if (entrada.is_open())
                    {
                        string linea;
                        getline(entrada, linea);

                        while (getline(entrada, linea))
                        {
                            vector<string> datos = separar(linea);

                            if (datos.size() == 6)
                            {
                                Pelicula *pelicula = new Pelicula(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5]);
                                videos.push_back(pelicula);
                            }
                            else
                            {
                                Serie *serie = new Serie(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9]));
                                videos.push_back(serie);
                            }
                        }

                        entrada.close();

                        correcto = true;
                        /*for (int i = 0; i < videos.size(); i++)
                        {
                            videos[i]->mostrarInfo();
                        }*/
                    }
                    else
                    {
                        cout << "Archivo inválido" << endl;
                    }
                }
                catch (invalid_argument e)
                {
                    cout << e.what() << endl;
                    cout << "Error Vuelve a intentar\n";
                    cin.clear();
                    cin.ignore(32767, '\n');
                }
            }

            cout << "Los archivos se han cargado correctamente." << endl;
            break;
        }

        case 2:
        {
            cout << "¿Desea conocer los videos con cierta calificación(1) o de un cierto género(2)?" << endl;
            int funcionOp = errorOpCorrecto();

            if (funcionOp == 1)
            {
                cout << "Ingrese la calificacion minima de los videos: " << endl;
                int cali;
                cali = errorTipoDatoCorrecto();
                while (cali > 7)
                {
                    cout << "La calificacion debe ser menor a 7" << endl;
                    cali = errorTipoDatoCorrecto();
                }
                while (cali < 0)
                {
                    cout << "La calificacion debe ser mayor a 0" << endl;
                    cali = errorTipoDatoCorrecto();
                }
                bool bandera;
                for (Video *video : videos)
                {
                    bandera = (cali <= video->getCalif());
                    if (bandera)
                    {
                        video->mostrarInfo();
                    }
                }
            }
            else if (funcionOp == 2)
            {
                cout << "¿Cuál es el genero?:" << endl;
                cout << "• Accion    • Animacion  • Aventura  • Biografia  • Comedia"
                     << endl
                     << "• Crimen    • Drama      • Familiar  • Fantasy    • Guerra"
                     << endl
                     << "• Misterio  • Musical    • Romance   • Sci-Fi     • Suspenso"
                     << endl
                     << "• Terror    • Western" << endl;

                // int generoOpc = errorTipoDatoCorrecto();
                string generoComparar = stringIncorrecto();
                bool comparacion = false;
                /*if (generoOpc == 1)
                {
                    generoComparar = ""
                }*/
                for (Video *video : videos)
                {
                    string generos = video->getGenero();
                    stringstream ss(generos);
                    string gen;
                    while (getline(ss, gen, '&'))
                    {
                        if (gen == generoComparar)
                        {
                            video->mostrarInfo();
                            comparacion = true;
                        }
                    }
                    /*if (video->getGenero().find(generoComparar) != string::npos){
                        video->mostrarInfo();
                        comparacion = true;
                    }*/
                }
                if (!comparacion)
                {
                    cout << "No se encontraron videos con ese género." << endl;
                }
            }
            break;
        }

        case 3:
        {
            cout << "¿Cual es la serie a conocer? " << endl;

            vector<string> nombSeries = nombreSeries();

            for (int i = 0; i < nombSeries.size(); i++)
            {
                cout << i + 1 << ") " << nombSeries[i] << endl;
            }

            int serieConocer = errorTipoDatoCorrecto();

            string serieN = nombSeries[serieConocer - 1];
            if (serieConocer > 0 && serieConocer <= nombSeries.size())
            {
                cout << "\nSERIE: " << serieN << "\n"
                     << endl;
                vector<string> nombreSeries;
                for (Video *video : videos)
                {
                    Serie *series = dynamic_cast<Serie *>(video);
                    if (series)
                    {
                        if (series->getNombre() == serieN)
                        {
                            series->mostrarEp();
                            cout << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "El número ingresado no es válido" << endl;
            }

            break;
        }

        case 4:
        {
            cout << "¿Cual es la calificacion minima de las peliculas? " << endl;
            int calif = errorTipoDatoCorrecto();
            while (calif > 7)
            {
                cout << "La calificacion debe ser menor a 7" << endl;
                calif = errorTipoDatoCorrecto();
            }
            while (calif < 0)
            {
                cout << "La calificacion debe ser mayor a 0" << endl;
                calif = errorTipoDatoCorrecto();
            }

            for (Video *video : videos)
            {
                Pelicula *peliculas = dynamic_cast<Pelicula *>(video);
                if (peliculas)
                {
                    if (peliculas->getCalif() > calif)
                    {
                        peliculas->mostrarInfo();
                    }
                }
            }
            break;
        }

        case 5:
        {
            cout << "¿Desea calificar una pelicula(1) o una serie(2)?" << endl;
            int tipoCalificar = errorOpCorrecto();
            if (tipoCalificar == 1)
            {
                cout << "¿Cual es la pelicula a calificar? " << endl;

                vector<string> nombPeli = nombrePeli();

                for (int i = 0; i < nombPeli.size(); i++)
                {
                    cout << i + 1 << ") " << nombPeli[i] << endl;
                }

                int peliEscogida = errorTipoDatoCorrecto();

                if (peliEscogida > 0 && peliEscogida <= nombPeli.size())
                {
                    string peliCalifN = nombPeli[peliEscogida - 1];

                    cout << "Pelicula a calificar: " << peliCalifN << endl;

                    cout << "\n¿Cuál es la nueva calificacion? " << endl;
                    double nuevaCali = errorTipoDatoCorrecto();

                    while (nuevaCali > 7.00)
                    {
                        cout << "La calificacion debe ser menor a 7" << endl;
                        nuevaCali = errorTipoDatoCorrecto();
                    }
                    while (nuevaCali < 0.00)
                    {
                        cout << "La calificacion debe ser mayor a 0" << endl;
                        nuevaCali = errorTipoDatoCorrecto();
                    }
                    for (Video *video : videos)
                    {
                        Pelicula *peliculas = dynamic_cast<Pelicula *>(video);
                        if (peliculas)
                        {
                            if (peliculas->getNombre() == peliCalifN)
                            {
                                // Sobrecarga '<<' en la clase pelicula
                                cout << *peliculas;
                                peliculas->calificar(nuevaCali);
                                cout << endl;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    cout << "El número ingresado no es válido" << endl;
                }
            }
            else
            {
                cout << "¿Cuál es la serie a calificar? " << endl;
                vector<string> nombSeries = nombreSeries();
                vector<string> episodioNombres;
                for (int i = 0; i < nombSeries.size(); i++)
                {
                    cout << i + 1 << ") " << nombSeries[i] << endl;
                }

                int serieCalificar = errorTipoDatoCorrecto();
                int numEp = 1;
                if (serieCalificar > 0 && serieCalificar <= nombSeries.size())
                {
                    cout << "\nSERIE: " << nombSeries[serieCalificar - 1] << "\n"
                         << endl;
                    vector<string> nombreSeries;

                    cout << "¿Cual es el episodio a calificar? " << endl;
                    for (Video *video : videos)
                    {
                        Serie *series = dynamic_cast<Serie *>(video);
                        if (series)
                        {
                            if (series->getNombre() == nombSeries[serieCalificar - 1])
                            {
                                cout << numEp << ") " << series->getNombreEp();
                                cout << endl;
                                numEp++;
                                episodioNombres.push_back(series->getNombreEp());
                            }
                        }
                    }
                    int opcEp = errorTipoDatoCorrecto();

                    if (opcEp > 0 && opcEp <= episodioNombres.size())
                    {
                        string epiCalifN = episodioNombres[opcEp - 1];

                        cout << "Serie a calificar: " << epiCalifN << endl;

                        cout << "\n¿Cuál es la nueva calificacion? " << endl;
                        double nuevaCali = errorTipoDatoCorrecto();

                        while (nuevaCali > 7)
                        {
                            cout << "La calificacion debe ser menor a 7" << endl;
                            nuevaCali = errorTipoDatoCorrecto();
                        }
                        while (nuevaCali < 0)
                        {
                            cout << "La calificacion debe ser mayor a 0" << endl;
                            nuevaCali = errorTipoDatoCorrecto();
                        }
                        for (Video *video : videos)
                        {
                            Serie *series = dynamic_cast<Serie *>(video);
                            if (series)
                            {
                                if (series->getNombreEp() == epiCalifN)
                                {
                                    // Sobrecarga '<<' en la clase pelicula
                                    cout << *series;
                                    series->calificar(nuevaCali);
                                    cout << endl;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "El número ingresado no es válido" << endl;
                    }
                }
                else
                {
                    cout << "El número ingresado no es válido" << endl;
                }
            }
            break;
        }
        case 6:
        {
            cout << "¿De qué serie te gustaría conocer el promedio de calificación?" << endl;
            vector<string> nombSeries = nombreSeries();
            vector<string> episodioNombres;
            for (int i = 0; i < nombSeries.size(); i++)
            {
                cout << i + 1 << ") " << nombSeries[i] << endl;
            }

            int seriePromedio = errorTipoDatoCorrecto();
            
            if (seriePromedio > 0 && seriePromedio <= nombSeries.size())
            {
                string serieProm = nombSeries[seriePromedio - 1];
                cout << "\nSERIE: " << serieProm << "\n" << endl;
                vector<string> nombreSeries;
                double sumaCalif = 0;
                
                for (Video *video : videos)
                {
                    Serie *series = dynamic_cast<Serie *>(video);
                    if (series)
                    {
                        if (series->getNombre() == serieProm)
                        {
                            sumaCalif += series->getCalif();
                            episodioNombres.push_back(series->getNombreEp());
                        }
                    }
                }

                double promedio = sumaCalif / episodioNombres.size();
                cout << "El promedio es de: " << promedio << endl;
            }
            else
            {
                cout << "El número ingresado no es válido" << endl;
            }
            break;
        }
        default:
        {
            cout << "Ha ingresado una opción inválida" << endl;
            break;
        }
        }
        cout << "\nEliga alguna de las siguientes opciones para continuar."
             << endl
             << "1.Cargar archivos"
             << endl
             << "2.Mostrar videos con cierta calificacion o de cierto genero"
             << endl
             << "3.Mostrar episodios de una determinada serie"
             << endl
             << "4.Mostrar las peliculas con cierta calificacion"
             << endl
             << "5.Calificar un video"
             << endl
             << "6.Calcular promedio de la calificación de una serie"
             << endl
             << "0.Salir" << endl;
        opcion = errorTipoDatoCorrecto();
    }

    return 0;
}

vector<string> separar(string linea)
{
    vector<string> tokens; // componentes de la línea

    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;                 // token individual
    int numeroTokens = 0;
    while (getline(entrada, dato, ','))
    {
        // cout << dato << endl;
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            // cout << dato << numeroTokens <<endl;
            tokens.push_back(dato); // GUARDA  en el vector
            numeroTokens++;
        }
    }
    // cout << "tokens: " << numeroTokens << endl << endl; comprobar si esta contando correctamente

    return tokens;
}

vector<string> nombreSeries()
{
    vector<string> nombreSeries;
    for (Video *video : videos)
    {
        Serie *series = dynamic_cast<Serie *>(video);
        if (series)
        {
            bool serieImpresa = false;
            for (string nombre : nombreSeries)
            {
                if (nombre == series->getNombre())
                {
                    serieImpresa = true;
                }
            }
            if (!serieImpresa)
            {
                nombreSeries.push_back(series->getNombre());
            }
        }
    }
    return nombreSeries;
}

vector<string> nombrePeli()
{
    vector<string> nombrePeli;
    int numPeli = 1;

    for (Video *video : videos)
    {
        Pelicula *peliculas = dynamic_cast<Pelicula *>(video);
        if (peliculas)
        {
            nombrePeli.push_back(peliculas->getNombre());
        }
    }

    return nombrePeli;
}
