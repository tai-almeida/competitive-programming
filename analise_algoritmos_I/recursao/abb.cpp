#include <bits/stdc++.h>

using namespace std;

class No {
    public:
        int valor;
        No* esq;
        No* dir;

        No(int valor) : valor(valor), esq(nullptr), dir(nullptr) {}
};

class ArvoreBinariaBusca {
    public:
    No* raiz;

    ArvoreBinariaBusca() : raiz(nullptr) {}

    No* abb(int valor, No* no) {
        
        // for(int i=0; i < num_nos; i++) {
            No* novoNo = new No(valor);
            if(raiz == nullptr) {
                raiz = novoNo;
                return raiz;
            }
            if (valor < no->valor) {
                if (no->esq == nullptr) {
                    no->esq = novoNo;
                } else {
                    abb(valor, no->esq);
                }
            } else {
                if (no->dir == nullptr) {
                    no->dir = novoNo;
                } else {
                    abb(valor, no->dir);
                }
            }
        // }
        return raiz;
    }

    void prefixo(No* no, vector<int>&   ordem) {
        if(no != nullptr) {
            ordem.push_back(no->valor);
            prefixo(no->esq, ordem);
            prefixo(no->dir, ordem);
        }
    }

    void infixo(No* no, vector<int>& ordem) {
        if(no != nullptr) {
            infixo(no->esq, ordem);
            ordem.push_back(no->valor);
            infixo(no->dir, ordem);
        }
        return;
    }
    void posfixo(No* no, vector<int>& ordem) {
        if(no != nullptr) {
            posfixo(no->esq, ordem);
            posfixo(no->dir, ordem);
            ordem.push_back(no->valor);
        }
        return;
    }

    void imprime(vector<int> ordem) {
        for(int j=0; j<ordem.size(); j++) {
            if(j < ordem.size() - 1) {
                cout << ordem[j] << ' ';
            } else {
                cout << ordem[j];
            }
        }
    }
};

int main() {
    
    int casos;
    
    cin >> casos;

    vector<int> num_nos(casos, 0);
    
    for(int i=0; i<casos; i++) {
        ArvoreBinariaBusca abb;
        cin >> num_nos[i];
        vector<int> valores(num_nos[i], 0);

        for(int j=0; j<num_nos[i]; j++) {
            cin >> valores[j];
        }

        for(int k=0; k<num_nos[i]; k++) {
            abb.abb(valores[k], abb.raiz);
            
        }
        vector<int> ordem;
        cout << "Case " << i+1 << ":\n";
        cout << "Pre.: ";
        abb.prefixo(abb.raiz, ordem);
        abb.imprime(ordem);
        ordem.clear();
        cout << '\n';
        cout << "In..: ";
        abb.infixo(abb.raiz, ordem);
        abb.imprime(ordem);
        ordem.clear();
        cout << '\n';
        cout << "Post: ";
        abb.posfixo(abb.raiz, ordem);
        abb.imprime(ordem);
        ordem.clear();
        cout << '\n';
        cout << '\n';
    }

    return 0;
}