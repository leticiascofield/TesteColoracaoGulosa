#ifndef VERTICE_H
#define VERTICE_H

class Vertice{
    public:
    int id;
    int cor;
    int grau;
    int* listaAdj;

    Vertice();
    Vertice(int _grau);
    ~Vertice();
};

#endif