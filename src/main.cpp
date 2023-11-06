#include <iostream>
#include "Vertice.hpp"

using namespace std;


void Troca(Vertice*& a, Vertice*& b){
    Vertice* aux = a;
    a = b;
    b = aux;
}

void Estabilizar(Vertice* vertices[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 1; j < n-i; j++){
            if(vertices[j]->cor == vertices[j-1]->cor){
                if(vertices[j]->id < vertices[j-1]->id){
                    Troca(vertices[j], vertices[j-1]);
                }
            }
        }
    }
}

void BubbleSort(Vertice* vertices[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 1; j < n-i; j++){
            if(vertices[j]->cor < vertices[j-1]->cor){
                Troca(vertices[j], vertices[j-1]);
            }
        }
    }
}

void SelectionSort(Vertice* vertices[], int n){
    int min;
    for(int i = 0; i < n-1; i++){
        min = i;
        for(int j = i+1; j < n; j++){
            if(vertices[j]-> cor < vertices[min]->cor){
                min = j;
            }
        }
        Troca(vertices[i], vertices[min]);
    }
    Estabilizar(vertices, n);
}

void InsertionSort(Vertice* vertices[], int n){
    Vertice* aux;
    for(int i = 1; i < n; i++){
        aux = vertices[i];
        int j = i - 1;
        while((j >= 0) && (aux->cor < vertices[j]->cor)){
            vertices[j+1] = vertices[j];
            j--;
        }
        vertices[j+1] = aux;
    }
}

void Particao(Vertice* vertices[], int esq, int dir, int* i, int* j){
    Vertice* x;
    *i = esq;
    *j = dir;
    x = vertices[(*i + *j)/2];

    do{
        while(x->cor > vertices[*i]->cor){
            (*i)++;
        }
        while(x->cor < vertices[*j]->cor){
            (*j)--;
        }
        if(*i <= *j){
            Troca(vertices[*i], vertices[*j]);
            (*i)++;
            (*j)--;
        }
    } while(*i <= *j);
}

void Ordena(Vertice* vertices[], int esq, int dir){
    int i, j;
    Particao(vertices, esq, dir, &i, &j);
    if(esq < j){
        Ordena(vertices, esq, j);
    }
    if(i < dir){
        Ordena(vertices, i, dir);
    }
}

void QuickSort(Vertice* vertices[], int n){
    Ordena(vertices, 0, n-1);
    Estabilizar(vertices, n);
}

void Merge(Vertice* vertices[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    Vertice* L[n1];
    Vertice* R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = vertices[esq + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vertices[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esq;

    while(i < n1 && j < n2){
        if(L[i]->cor <= R[j]->cor){
            vertices[k] = L[i];
            i++;
        } else {
            vertices[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        vertices[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        vertices[k] = R[j];
        j++;
        k++;
    }

}

void MergeSort(Vertice* vertices[], int esq, int dir) {
    if(esq < dir){
        int meio = esq + (dir - esq)/2;
        MergeSort(vertices, esq, meio);
        MergeSort(vertices, meio+1, dir);
        Merge(vertices, esq, meio, dir);
    }
}

void Heapify(Vertice* vertices[], int n, int i) {
    int max = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && vertices[esq]->cor > vertices[max]->cor) {
        max = esq;
    }

    if (dir < n && vertices[dir]->cor > vertices[max]->cor) {
        max = dir;
    }

    if (max != i) {
        Troca(vertices[i], vertices[max]);
        Heapify(vertices, n, max);
    }
}

void HeapSort(Vertice* vertices[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(vertices, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        Troca(vertices[0], vertices[i]);
        Heapify(vertices, i, 0);
    }
    Estabilizar(vertices, n);
}


void MySort(Vertice* vertices[], int n){ //confere as cores dos vertices e vai adicionando ao aux já na ordem correta (estável)
    Vertice* aux[n];
    int k = 0;

    for(int i = 1; i <= n; i++){ //para passar pelas possiveis cores
        for(int j = 0; j < n; j++){ //para passar por cada vertice
            if(vertices[j]->cor == i){ //se o vertice tiver a tal cor, entra
                aux[k] = vertices[j];
                k++;
            }
        }
    }

    for(int i = 0; i < n; i++){ 
        vertices[i] = aux[i];
    }
}


bool Guloso(Vertice* vertices[], int n) {
    for(int k = 0; k < n; k++){ //passar por todos os vertices e testar se é guloso
        bool caso[vertices[k]->cor-1] = {false};
        for(int i = 0; i < vertices[k]->grau; i++){
            for(int j = 0; j < vertices[k]->cor; j++){
                if(vertices[vertices[k]->listaAdj[i]]->cor == vertices[k]->cor-1-j){
                    caso[j] = true;
                }
            }
        }
        for(int i = 0; i < vertices[k]->cor-1; i++){
            if(caso[i] == false) {
                return false; 
            }
        }

    }
    return true;
}

int main (){

    char c;
    int n;

    cin >> c;
    cin >> n;

    Vertice* vertices[n];

    for(int i = 0; i < n; i++){
        int grau;
        cin >> grau;
        vertices[i] = new Vertice(grau);
        vertices[i]->id = i;
        for(int j = 0; j < grau; j++){
            cin >> vertices[i]->listaAdj[j];
        }
    }

    for(int i = 0; i < n; i++){
        cin >> vertices[i]->cor;
    }

    cout << Guloso(vertices, n) << " ";
    if(Guloso(vertices, n)) {
        switch(c) {
            case 'b':
                BubbleSort(vertices, n);
                break;
            case 's':
                SelectionSort(vertices, n);
                break;
            case 'i':
                InsertionSort(vertices, n);
                break;
            case 'q':
                QuickSort(vertices, n);
                break;
            case 'm':
                MergeSort(vertices, 0, n-1);
                break;
            case 'p':
                HeapSort(vertices, n);
                break;
            case 'y':
                MySort(vertices, n);
                break;
            default:
                cout << "Erro: comando inválido." << endl;
        }
        
        for(int i = 0; i < n; i++){
            cout << vertices[i]->id << " ";
        }
    }
    cout << endl;

    for(int i = 0; i < n; i++){
        delete vertices[i];
    }

    return 0;
}