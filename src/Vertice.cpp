#include "Vertice.hpp"

Vertice::Vertice(){}

Vertice::Vertice(int _grau){
    this->grau = _grau;
    this->listaAdj = new int[_grau];
}

Vertice::~Vertice(){
    delete[] listaAdj;
}
