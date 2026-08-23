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

    No* insere(int valor, No* no) {
        
        // for(int i=0; i < num_nos; i++) {
            
            if(no == nullptr) {
                No* novoNo = new No(valor);
                if(raiz == nullptr) {
                    raiz = novoNo;  
                }
                return novoNo; 
            }
            if (valor < no->valor) {
                no->esq = insere(valor, no->esq);
            } else {
                no->dir = insere(valor, no->dir);
            }
        // }
        return no;
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

    bool pesquisa(No* no, int valor) {
        if(no == nullptr) {
            return false;
        } 
        if(no->valor == valor) {
            return true;
        }
        if (valor < no->valor) {
            return pesquisa(no->esq, valor);
        } else {
            return pesquisa(no->dir, valor);
        }
        return false;
    }

    No* max_esq(No* no) {
        while(no->dir !=nullptr) {
            no = no->dir;
        }
        return no;
    }

    No *remove(No* no, int valor) {
        if(no== nullptr) {
            return nullptr;
        }
        if(no->valor > valor) {
            no->esq = remove(no->esq, valor);
        } else if(no->valor < valor) {
            no->dir = remove(no->dir, valor);
        } else {
            if(no->esq == nullptr && no->dir == nullptr) {
                delete no;
                return nullptr;
            } else if(no->esq == nullptr) {
                No* no_aux = no->dir;
                delete no;
                return no_aux;
            } else if(no->dir == nullptr) {
                No* no_aux = no->esq;
                delete no;
                return no_aux;
            } else {
                No* antecessor = max_esq(no->esq);
                no->valor=antecessor->valor;
                no->esq = remove(no->esq, antecessor->valor);
            }
        }
        return no;
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
    ArvoreBinariaBusca abb;
    string comando;
    vector<int> ordem;
    while (getline(cin, comando)) {
        // cout << comando;
        if(comando[0] == 'I' && comando[1] == ' ') {
            // converte pra int
            int valor = stoi(comando.substr(2));
            abb.raiz = abb.insere(valor, abb.raiz);
        } else if(comando[0] == 'P' && comando[1] == ' ') {
            int valor = stoi(comando.substr(2));
            abb.pesquisa(abb.raiz, valor);
            if(abb.pesquisa(abb.raiz, valor)){
                cout << valor << " existe" << '\n';
            } else {
                cout << valor << " nao existe" << '\n';
            }
        } else if(comando[0] == 'R') {
            int valor = stoi(comando.substr(2));
            if(abb.pesquisa(abb.raiz, valor)){
                abb.raiz = abb.remove(abb.raiz, valor);
            }
            
        } else if(comando == "PREFIXA") {
            abb.prefixo(abb.raiz, ordem);
            abb.imprime(ordem);
            ordem.clear();
            cout << '\n';
        } else if(comando == "INFIXA") {
            abb.infixo(abb.raiz, ordem);
            abb.imprime(ordem);
            ordem.clear();
            cout << '\n';
        } else if(comando == "POSFIXA") {
            abb.posfixo(abb.raiz, ordem);
            abb.imprime(ordem);
            ordem.clear();
            cout << '\n';
        }
    }
    return 0;
}