#include <iostream>

using namespace std;

class Vertice{
    public:
    int id;
    int cor;
    int grau;
    int* listaAdj;

    Vertice(){}
    Vertice(int _grau){
        grau = _grau;
        listaAdj = new int[_grau];
    }

    ~Vertice(){
        delete[] listaAdj;
    }
};

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
        for(int i = 0; i < sizeof(caso); i++){
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

    //cin >> c;
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

    for(int i = 0; i < n; i++){
        cout << "Vértice " << i << ", grau " << vertices[i]->grau
        << " e cor " << vertices[i]->cor << endl;
        cout << "Lista Adj: ";
        for(int j = 0; j < vertices[i]->grau; j++){
            cout << vertices[i]->listaAdj[j] << " ";
        }
        cout << endl;
    }

    cout << "É guloso? " << Guloso(vertices, n) << endl;

    for(int i = 0; i < n; i++){
        delete vertices[i];
    }

    return 0;
}