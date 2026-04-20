#ifndef MAIN_H
#define MAIN_H
#include <iostream>
using namespace std;


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

    void agregargol(){

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
