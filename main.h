#ifndef MAIN_H
#define MAIN_H

#include <iostream> //"C:\\Users\\Yudy2\\Documents\\desafio_2\\selecciones_clasificadas_mundial.csv"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

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
    void cargarDatos(int rank, string n, string t, string conf, int gf, int gc, int pg, int pe, int pp) {
        rankingfifa = rank;
        pais = n;
        tecnico = t;
        confederacion = conf;
        golesafavor = gf;
        golesencontra = gc;
        partidosganados = pg;
        empates = pe;
        perdidos = pp;
    }

    string getpais(){
        return pais;
    }

    int getrankingfifa(){
        return rankingfifa;
    }

    string getconfederacion(){
        return confederacion;
    }

    void calpromediogoles(){

    }

    void agregarjugador(){

    }

    void actualizarestadisticas(){

    }

    void jugtitulares(){

    }

};


struct nodo {
    equipo datos;
    nodo* siguiente;
};

nodo* leercsv(string csv) {
    ifstream file(csv);
    string line;
    nodo* inicio = NULL;
    nodo* ultimo = NULL;

    getline(file, line);
    getline(file, line);

    while(getline(file, line)) {
        stringstream ss(line);
        string r, p, dt, f, c, gf, gc, pg, pe, pp;

        getline(ss, r, ';');
        getline(ss, p, ';');
        getline(ss, dt, ';');
        getline(ss, f, ';');
        getline(ss, c, ';');
        getline(ss, gf, ';');
        getline(ss, gc, ';');
        getline(ss, pg, ';');
        getline(ss, pe, ';');
        getline(ss, pp, ';');

        nodo* nuevo = new nodo();

        nuevo->datos.cargarDatos(stoi(r), p, dt, c, stoi(gf), stoi(gc), stoi(pg), stoi(pe), stoi(pp));

        nuevo->siguiente = NULL;

        if (inicio == NULL) {
            inicio = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }

    }
    file.close();
    return inicio;
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
    void simularpartido(equipo &e1, equipo &e2){
        int r1 = e1.getrankingfifa();
        int r2 = e2.getrankingfifa();

        int fuerza1 = 100 - r1;
        int fuerza2 = 100 - r2;
        int goles1 = 0;
        int goles2 = 0;

        for(int i = 0; i < 5; i++){
            if((rand()%100) < (fuerza1 / 2)) goles1++;
            if((rand()%100) < (fuerza2 / 2)) goles2++;
        }
        cout << " RESULTADO FINAL " << endl;
        cout << e1.getpais() << " [" << r1 << "] " << goles1 << " - "
             << goles2 << " [" << r2 << "] " << e2.getpais() << endl;

        if (goles1 > goles2) cout << "Ganador: " << e1.getpais() << endl;
        else if (goles2 > goles1) cout << "Ganador: " << e2.getpais() << endl;
        else cout << " Empate " << endl;

    }

    void asignareventosjugadores(){

    }

    void actualizarestadisticas(){

    }
};

class grupo{
private:
    char letragrupo;
    equipo* integrantes[4]; // son solo 4 por grupo
    int cantidadactual = 0;;
public:

    grupo(char letra){
        letragrupo = letra;
        cantidadactual = 0;
    }
       // ofstream archivo;
        //archivo.open("grupos.txt", ios::out);
        //archivo.close();
    bool tieneConfederacion(string conf) {
        for (int i = 0; i < cantidadactual; i++) {
            if (integrantes[i]->getconfederacion() == conf) return true;
        }
        return false;
    }

    bool agregarequipo(equipo* e){
        if(cantidadactual < 4 && !tieneConfederacion(e->getconfederacion())){
            integrantes[cantidadactual] = e;
            cantidadactual++;
            return true;
        }
        return false;
    }

    void mostrarposiciones(){
        cout << "GRUPO " << letragrupo  << endl;
        cout << "pos | pais           | conf " << endl;
        for(int i = 0; i < cantidadactual; i++){
            cout << i + 1 << "   | " << integrantes[i]->getpais()
            << " | " << integrantes[i]->getconfederacion() << endl;
        }
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
