#include "Vertice.hpp"

    Vertice::Vertice(){}
    Vertice::Vertice(int _grau){
        grau = _grau;
        listaAdj = new int[_grau];
    }

    Vertice::~Vertice(){
        delete[] listaAdj;
    }
