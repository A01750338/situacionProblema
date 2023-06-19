/**
 * Autor: Min Che Kim
 * Prueba de todas las clases y sus métodos
 */

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Funciones utilizadas en el main
int errorOpCorrecto();
int errorTipoDatoCorrecto();
string stringIncorrecto();
vector<string> separar(string linea);
vector<string> nombreSeries();
vector<string> nombrePeli();
vector<Video *> videos;

int main(int argc, char const *argv[])
{
    int opcion;
    int respuesta;
    bool correcto(false);

    // Mostrar las opciones disponibles al usuario
    cout << "\nBienvenido. Elija alguna de las siguientes opciones para continuar. Se deberá de empezar por la opcion 1."
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

    // Se encarga de validar la entrada del usuario y asegurando de que la primera opción seleccionada sea 1
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
            // Imprime el mensaje de error de la excepción lanzada
            cout << error.what() << endl;
            cout << "Intente de nuevo\n";
            cin.clear();
            cin.ignore(32767, '\n');

            // Solicita al usuario que ingrese nuevamente la opción
            cout << "\nIngrese la opcion:  " << endl;
            cin >> opcion;
        }
    }

    while (opcion != 0)
    {
        switch (opcion)
        {

        // Cargar archivo
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
                                // Crea una nueva instancia de Pelicula y agregarla a la lista de videos
                                Pelicula *pelicula = new Pelicula(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5]);
                                videos.push_back(pelicula);
                            }
                            else
                            {
                                // Crea una nueva instancia de Serie y agregarla a la lista de videos
                                Serie *serie = new Serie(datos[0], datos[1], stoi(datos[2]), datos[3], stod(datos[4]), datos[5], datos[6], datos[7], stoi(datos[8]), stoi(datos[9]));
                                videos.push_back(serie);
                            }
                        }

                        entrada.close();

                        correcto = true;
                    }
                    // Si el nombre del archivo es incorrecto
                    else
                    {
                        cout << "Archivo inválido" << endl;
                    }
                }
                catch (invalid_argument &e)
                {
                    // Imprime el mensaje de error de la excepción
                    cout << e.what() << endl;
                    cout << "Error Vuelve a intentar\n";
                    cin.clear();
                    cin.ignore(32767, '\n');
                }
            }

            cout << "Los archivos se han cargado correctamente." << endl;
            break;
        }

        // Mostrar videos con cierta calificacion o de cierto genero
        case 2:
        {
            cout << "¿Desea conocer los videos con cierta calificación(1) o de un cierto género(2)?" << endl;
            int funcionOp = errorOpCorrecto();

            // Opción 1: Mostrar videos con cierta calificación
            if (funcionOp == 1)
            {
                cout << "Ingrese la calificacion minima de los videos: " << endl;
                int cali;
                cali = errorTipoDatoCorrecto();

                // Validar que la calificación sea válida entre 0 y 7
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
                    // Verificar si la calificación del video es mayor o igual a la calificación mínima ingresada
                    bandera = (cali <= video->getCalif());
                    if (bandera)
                    {
                        // Mostrar información del video
                        video->mostrarInfo();
                    }
                }
            }
            // Opción 2: Mostrar videos de un cierto género
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

                string generoComparar = stringIncorrecto();
                bool comparacion = false;

                for (Video *video : videos)
                {
                    string generos = video->getGenero();
                    stringstream ss(generos);
                    string gen;
                    while (getline(ss, gen, '&'))
                    {
                        // Verificar si el género del video coincide con el género ingresado
                        if (gen == generoComparar)
                        {
                            // Mostrar información del video
                            video->mostrarInfo();
                            comparacion = true;
                        }
                    }
                }
                if (!comparacion)
                {
                    cout << "No se encontraron videos con ese género." << endl;
                }
            }
            break;
        }

        // Mostrar episodios de una determinada serie con cierta calificación
        case 3:
        {
            cout << "¿Cual es la serie a conocer? " << endl;

            vector<string> nombSeries = nombreSeries();

            // Mostrar los nombres de las series al usuario
            for (int i = 0; i < nombSeries.size(); i++)
            {
                cout << i + 1 << ") " << nombSeries[i] << endl;
            }

            int serieConocer = errorTipoDatoCorrecto();

            
            if (serieConocer > 0 && serieConocer <= nombSeries.size())
            {
                // Se obtiene el nombre de la serie seleccionada
                string serieN = nombSeries[serieConocer - 1];
                cout << "\nSERIE: " << serieN << "\n"
                     << endl;
                vector<string> nombreSeries;

                // Recorrer la lista de videos y mostrar los episodios de la serie seleccionada
                for (Video *video : videos)
                {
                    // Objeto se vuelve temporalmente a tipo serie
                    Serie *series = dynamic_cast<Serie *>(video);
                    if (series)
                    {
                        // Verificar si es de la serie seleccionada
                        if (series->getNombre() == serieN)
                        {
                            // Mostrar los episodios de la serie
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

        // Mostrar las peliculas con cierta calificacion
        case 4:
        {
            cout << "¿Cual es la calificacion minima de las peliculas? " << endl;
            int calif = errorTipoDatoCorrecto();

            // Validar que la calificación sea válida entre 0 y 7
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

            // Muestra la información de las películas con una calificación mayor a la calificación mínima especificada por el usuario.
            for (Video *video : videos)
            {
                // Objeto se vuelve temporalmente a tipo pelicula
                Pelicula *peliculas = dynamic_cast<Pelicula *>(video);
                if (peliculas)
                {
                    if (peliculas->getCalif() > calif)
                    {
                        // Mostrar información de la película
                        peliculas->mostrarInfo();
                    }
                }
            }
            break;
        }

        // Calificar un video
        case 5:
        {
            cout << "¿Desea calificar una pelicula(1) o una serie(2)?" << endl;
            int tipoCalificar = errorOpCorrecto();

            // Calificar una película
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
                    // Se obtiene el nombre de la pelicula seleccionada
                    string peliCalifN = nombPeli[peliEscogida - 1];

                    cout << "Pelicula a calificar: " << peliCalifN << endl;

                    cout << "\n¿Cuál es la nueva calificacion? " << endl;
                    double nuevaCali = errorTipoDatoCorrecto();

                    // Validar que la calificación sea válida entre 0 y 7
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

                    // Buscar la película seleccionada en la lista de videos
                    for (Video *video : videos)
                    {
                        // Objeto se vuelve temporalmente a tipo pelicula
                        Pelicula *peliculas = dynamic_cast<Pelicula *>(video);
                        if (peliculas)
                        {
                            // Verificar si es de la pelicula seleccionada
                            if (peliculas->getNombre() == peliCalifN)
                            {
                                // Sobrecarga '<<' en la clase pelicula
                                cout << *peliculas;

                                // Calificar la película
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

                // Mostrar los nombres de las series al usuario
                for (int i = 0; i < nombSeries.size(); i++)
                {
                    cout << i + 1 << ") " << nombSeries[i] << endl;
                }

                // Se escoje la serie
                int serieCalificar = errorTipoDatoCorrecto();
                int numEp = 1;
                if (serieCalificar > 0 && serieCalificar <= nombSeries.size())
                {
                    // Se obtiene el nombre de la serie seleccionada
                    cout << "\nSERIE: " << nombSeries[serieCalificar - 1] << "\n"
                         << endl;

                    cout << "¿Cual es el episodio a calificar? " << endl;

                    for (Video *video : videos)
                    {
                        // Objeto se vuelve temporalmente a tipo serie
                        Serie *series = dynamic_cast<Serie *>(video);
                        if (series)
                        {
                            // Verificar si es de la serie seleccionada
                            if (series->getNombre() == nombSeries[serieCalificar - 1])
                            {
                                // Se muestran los episodios al usuartio
                                cout << numEp << ") " << series->getNombreEp();
                                cout << endl;
                                numEp++;
                                episodioNombres.push_back(series->getNombreEp());
                            }
                        }
                    }

                    // Se escoje el episodio
                    int opcEp = errorTipoDatoCorrecto();

                    // Opcion valido solo en el rango de episodios válido
                    if (opcEp > 0 && opcEp <= episodioNombres.size())
                    {
                        // Se obtiene el nombre del episodio
                        string epiCalifN = episodioNombres[opcEp - 1];

                        cout << "Serie a calificar: " << epiCalifN << endl;

                        cout << "\n¿Cuál es la nueva calificacion? " << endl;
                        double nuevaCali = errorTipoDatoCorrecto();

                        // Validar que la calificación sea válida entre 0 y 7
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
                            // Objeto se vuelve temporalmente a tipo serie
                            Serie *series = dynamic_cast<Serie *>(video);
                            if (series)
                            {
                                // Verificar si es del episodio seleccionado
                                if (series->getNombreEp() == epiCalifN)
                                {
                                    // Sobrecarga '<<' en la clase pelicula
                                    cout << *series;

                                    // Se califica el episodio
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
            // Solicitar al usuario el nombre de la serie
            cout << "¿De qué serie te gustaría conocer el promedio de calificación?" << endl;
            vector<string> nombSeries = nombreSeries();
            vector<string> episodioNombres;

            // Mostrar los nombres de las series al usuario
            for (int i = 0; i < nombSeries.size(); i++)
            {
                cout << i + 1 << ") " << nombSeries[i] << endl;
            }

            // Selección de serie
            int seriePromedio = errorTipoDatoCorrecto();

            // Opcion valido solo en el rango de series válido
            if (seriePromedio > 0 && seriePromedio <= nombSeries.size())
            {
                // Se obtiene el nombre de la serie seleccionada
                string serieProm = nombSeries[seriePromedio - 1];
                cout << "\nSERIE: " << serieProm << "\n"
                     << endl;

                double sumaCalif = 0;

                for (Video *video : videos)
                {
                    // Objeto se vuelve temporalmente a tipo serie
                    Serie *series = dynamic_cast<Serie *>(video);
                    if (series)
                    {
                        // Verificar si el video es de la serie seleccionada
                        if (series->getNombre() == serieProm)
                        {
                            // Sumar la calificación del episodio a la suma total
                            sumaCalif += series->getCalif();
                            episodioNombres.push_back(series->getNombreEp());
                        }
                    }
                }

                // Calcular el promedio de calificación
                double promedio = sumaCalif / episodioNombres.size();

                // Muestra el promedio de calificación al usuario
                cout << "El promedio es de: " << promedio << endl;
            }
            else
            {
                cout << "El número ingresado no es válido" << endl;
            }
            break;
        }

        // Al ingresar una opción inválida
        default:
        {
            cout << "Ha ingresado una opción inválida" << endl;
            break;
        }
        }

        // Mostrar las opciones disponibles al usuario nuevamente
        cout << "\nElija alguna de las siguientes opciones para continuar."
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
    cout << "GRACIAS :)";

    return 0;
}

// Función para verificar si la opción ingresada es correcta (1 o 2)
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

// Función para verificar si el tipo de dato ingresado (int) es correcto
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

// Función para verificar si el string ingresado es correcto
string stringIncorrecto()
{
    string respuesta;
    bool correcto(false);
    while (!correcto)
    {
        cout << "\nIngrese el genero (sin acentos y con mayúscula al incio" << endl
             << "                     Ej. Accion): ";
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

// Dividir una línea de texto en componentes separados por comas
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

// Obtener los nombres de las series sin duplicación
vector<string> nombreSeries()
{
    vector<string> nombreSeries;
    for (Video *video : videos)
    {
        // Objeto se vuelve temporalmente a tipo serie
        Serie *series = dynamic_cast<Serie *>(video);
        if (series)
        {
            bool serieImpresa = false;
            for (string nombre : nombreSeries)
            {
                // Verificar si es de la serie seleccionada
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

// Obtener los nombres de las películas
vector<string> nombrePeli()
{
    vector<string> nombrePeli;
    int numPeli = 1;

    for (Video *video : videos)
    {
        // Objeto se vuelve temporalmente a tipo pelicula
        Pelicula *peliculas = dynamic_cast<Pelicula *>(video);
        if (peliculas)
        {
            nombrePeli.push_back(peliculas->getNombre());
        }
    }

    return nombrePeli;
}
