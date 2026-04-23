#ifndef MAIN_H
#define MAIN_H

#include <iostream> //"C:\\Users\\Yudy2\\Documents\\desafio_2\\selecciones_clasificadas_mundial.csv"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct nodo{
    string ranking;
    string pais;
    string directortecnico;
    string federacion;
    string confederacion;
    string golesfavor;
    string golescontra;
    string partidosganados;
    string partidosperdidos;
    string partidosempatados;
    nodo* siguiente;
};

int leercsv(string csv){

    ifstream file(csv);
    string line;

    nodo* inicio = NULL;
    nodo* ultimo = NULL;

    getline(file, line);
    getline(file, line);

    while(getline(file, line)){
        stringstream ss(line);
        string r, p, dt,f,c,gf, gc, pg, pp, pe;

        getline(ss, r, ';');
        getline(ss, p, ';');
        getline(ss, dt, ';');
        getline(ss, f, ';');
        getline(ss, c, ';');
        getline(ss, gf, ';');
        getline(ss, gc, ';');
        getline(ss, pg, ';');
        getline(ss, pp, ';');
        getline(ss, pe, ';');
        nodo* nuevo = new nodo();
        nuevo->ranking = r;
        nuevo->pais = p;
        nuevo->directortecnico = dt;
        nuevo->federacion = f;
        nuevo->confederacion= c;
        nuevo->golesfavor = gf;
        nuevo->golescontra = gc;
        nuevo->partidosganados = pg;
        nuevo->partidosempatados = pe;
        nuevo->partidosperdidos = pp;
        nuevo->siguiente = NULL;

        if (inicio == NULL) {
            inicio= nuevo;
            ultimo = nuevo;
        } else {
            // Si no, lo pegamos al final y movemos el puntero 'ultimo'
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }
    file.close();

    nodo* actual = inicio;
    while (actual != NULL) {
        cout << "Ranking: " << actual->ranking << " | Pais: " << actual->pais << endl;
        actual = actual->siguiente; // Avanzamos al siguiente nodo
    }

    return 0;
}


class jugador{
private:
    string nombre;
    string apellido;
    int numerocamiseta;
    int goles;
    int minjugados;
    int targetasamarillas;
    int targetasrojas;
    int faltas ;
    int partidosjugados;
public:


    void actualizarestadisticas(){

    }

    void agregartargeta(){

    }

    void agregarroja(){

    }
};

class equipo{
private:
    string pais;
    int rankingfifa;
    string confederacion;
    string tecnico;
    string juadores; // puede ser una lista enlazada
    int golesafavor;
    int golesencontra;
    int partidosganados;
    int empates;
    int perdidos;
    int targetas;
    int faltas;
public:
    void calpromediogoles(){

    }

    void agregarjugador(){

    }

    void actualizarestadisticas(){

    }

    void jugtitulares(){

    }

};


class partido{
private:
    string equipo1;
    string equipo2;
    string fecha;
    string hora;
    string sede;
    string arbitros;
    int golesequipo1;
    int golesequipo2;
    int posecion;
    string jugadorescomvocados;

public:
    void simularpartido(){

    }

    void calculargoles(){

    }

    void asignareventosjugadores(){

    }

    void actualizarestadisticas(){

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



#endif // MAIN_H
