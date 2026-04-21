#ifndef MAIN_H
#define MAIN_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm> // necesario para max

using namespace std;

class equipo {
private:
    string pais;
    int rankingfifa;
    string confederacion;
    string tecnico;
    int golesafavor;
    int golesencontra;
    int ganados;
    int empatados;
    int perdidos;

public:
    equipo() {
        pais = "";
        rankingfifa = 0;
        confederacion = "";
        tecnico = "";
        golesafavor = 0;
        golesencontra = 0;
        ganados = 0;
        empatados = 0;
        perdidos = 0;
    }

    void cargarDatos(int ranking, const string& p, const string& dt, const string& conf,
                     int gf, int gc, int g, int e, int per) {
        rankingfifa = ranking;
        pais = p;
        tecnico = dt;
        confederacion = conf;
        golesafavor = gf;
        golesencontra = gc;
        ganados = g;
        empatados = e;
        perdidos = per;
    }

    string getPais() const { return pais; }
    string getTecnico() const { return tecnico; }
    int getRankingFifa() const { return rankingfifa; }
};

class jugador {
private:
    string nombre;
    string apellido;
    int numerocamiseta;
    int goles;
    int minjugados;
    int tarjetasamarillas;
    int tarjetasrojas;
    int faltas;
    int partidosjugados;

public:
    void actualizarestadisticas() {}
    void agregargol() {}
    void agregartarjeta() {}
    void agregarroja() {}
};

class info {
private:
    equipo* selecciones;
    int capacidad;
    int cantidadActual;

public:
    info(int cap) {
        capacidad = cap;
        selecciones = new equipo[capacidad];
        cantidadActual = 0;
    }

    ~info() {
        delete[] selecciones;
    }

    void datosarchivo(string nombrearchivo) {
        ifstream archivo(nombrearchivo);
        if (!archivo.is_open()) {
            cout << "No se pudo abrir el archivo" << endl;
            return;
        }

        string linea, temp;

        // Función auxiliar segura para convertir a entero
        auto convertirEntero = [](const string& texto) {
            try {
                if (texto.empty()) return 0;
                return stoi(texto);
            } catch (...) {
                return 0;
            }
        };

        // Saltar título y encabezado
        getline(archivo, linea);
        getline(archivo, linea);

        while (getline(archivo, linea) && cantidadActual < capacidad) {

            if (linea.empty()) continue; // evitar líneas vacías
            if (linea.find(";") == string::npos) continue; // evitar líneas inválidas

            stringstream ss(linea);

            int ranking = 0, golesFavor = 0, golesContra = 0;
            int ganados = 0, empatados = 0, perdidos = 0;
            string pais, tecnico, federacion, confederacion;

            // Ranking
            getline(ss, temp, ';');
            ranking = convertirEntero(temp);

            // Strings
            getline(ss, pais, ';');
            getline(ss, tecnico, ';');
            getline(ss, federacion, ';');    // columna extra
            getline(ss, confederacion, ';');

            // Números
            getline(ss, temp, ';');
            golesFavor = convertirEntero(temp);

            getline(ss, temp, ';');
            golesContra = convertirEntero(temp);

            getline(ss, temp, ';');
            ganados = convertirEntero(temp);

            getline(ss, temp, ';');
            empatados = convertirEntero(temp);

            getline(ss, temp, ';');
            perdidos = convertirEntero(temp);

            selecciones[cantidadActual].cargarDatos(
                ranking, pais, tecnico, confederacion,
                golesFavor, golesContra, ganados, empatados, perdidos
                );

            cantidadActual++;
        }

        archivo.close();
    }


    void mostrar(int indice) {
        if (indice >= 0 && indice < cantidadActual) {
            cout << "Pais: " << selecciones[indice].getPais()
            << " | DT: " << selecciones[indice].getTecnico()
            << " | Ranking: " << selecciones[indice].getRankingFifa()
            << endl;
        } else {
            cout << "Indice invalido" << endl;
        }
    }

    void mostrarTodos() {
        for (int i = 0; i < cantidadActual; i++) {
            cout << "Equipo " << i << ": "
                 << selecciones[i].getPais()
                 << " | DT: " << selecciones[i].getTecnico()
                 << " | Ranking: " << selecciones[i].getRankingFifa()
                 << endl;
        }
    }

    int getCantidadActual() {
        return cantidadActual;
    }
};

class partido {
public:
    void simularpartido(const equipo &e1, const equipo &e2) {
        int fuerza1 = max(1, 100 - e1.getRankingFifa());
        int fuerza2 = max(1, 100 - e2.getRankingFifa());

        int limite1 = (fuerza1 / 20) + 1;
        int limite2 = (fuerza2 / 20) + 1;

        int goles1 = rand() % limite1;
        int goles2 = rand() % limite2;

        cout << "\nRESULTADO\n";
        cout << e1.getPais() << " " << goles1 << " - "
             << goles2 << " " << e2.getPais() << endl;

        if (goles1 > goles2)
            cout << "Ganador: " << e1.getPais() << endl;
        else if (goles2 > goles1)
            cout << "Ganador: " << e2.getPais() << endl;
        else
            cout << "Resultado: Empate" << endl;
    }
};

class torneo{
private:
    string equipos; // tienen que ser 48 equipos
    string grupos;
    string partidos;
    string calendario;
public:
    void cargardatos(){

    }

    void crearbombos(){

    }

    void generargrupos(){

    }

    void simularfasegrupos(){

    }

    void clasificarequipos(){

    }

    void generareliminatorias(){

    }

    void simulareliminatorias(){

    }

    void mostrarresultados(){

    }

    void estadisticasfinales(){

    }

};

class grupo{
private:
    string letragrupo;
    int equipos; // son solo 4 por grupo
    string tablapociciones;
public:
    void agregarequipo(){

    }

    void generarpartidos(){

    }

    void calculartabla(){

    }

    void ordenarequipos(){

    }
};



#endif // MAIN_H


