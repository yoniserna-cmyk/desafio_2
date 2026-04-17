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



#endif // MAIN_H
