#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>

using namespace std;
namespace TLS
{
 
    template <typename T, int CAPACIDADE>
    struct TListaEstatica {
        T vetor[CAPACIDADE];
        int quantidade;
    };


   
    template <typename T, int CAPACIDADE>
    void imprimir_lista(TListaEstatica<T, CAPACIDADE>& lista) {
       


        cout << "\t\tJOGADORES";
        cout << "\n****************************************";
        
        for (int i = 0; i < lista.quantidade; i++) {
            cout << "\n\tJOGADOR: " << lista.vetor[i].num;
            cout << " | PONTUACAO: " << lista.vetor[i].pontuacao;
            

        };

        cout << "\n****************************************\n\n";
    

       
    }


    //INICIALIZAR
    template <typename T, int CAPACIDADE>
    void inicializa(TListaEstatica<T, CAPACIDADE>& lista) {
        lista.quantidade = 0;
    }



    //INSERIR
    template <typename T, int CAPACIDADE>
    void insere_inicio(TListaEstatica<T, CAPACIDADE>& lista, T dado) {
        if (lista.quantidade >= CAPACIDADE) {
            throw "Lista Cheia";
        }
        for (int i = lista.quantidade; 0 < i; i--) {
            lista.vetor[i] = lista.vetor[i - 1];
        }
        lista.vetor[0] = dado;
        lista.quantidade++;

    }


    template <typename T, int CAPACIDADE>
    void insere_posicao(TListaEstatica<T, CAPACIDADE>& lista, T dado, int posicao) {
        if (lista.quantidade >= CAPACIDADE) {
            throw "Lista Cheia";
        }
        for (int i = lista.quantidade; posicao < i; i--) {
            lista.vetor[i] = lista.vetor[i - 1];
        }
        lista.vetor[posicao] = dado;
        lista.quantidade++;
    }


    template <typename T, int CAPACIDADE>
    void insere_final(TListaEstatica<T, CAPACIDADE>& lista, T dado) {
        if (lista.quantidade >= CAPACIDADE) {
            throw "Lista Cheia";
        }
        lista.vetor[lista.quantidade] = dado;
        lista.quantidade++;
    }



    //REMOVER

    template <typename T, int CAPACIDADE>
    void remove_final(TListaEstatica<T, CAPACIDADE> lista) {
        lista.quantidade--;
    }


    template<typename T, int CAPACIDADE>
    void remove_inicio(TListaEstatica<T, CAPACIDADE>& lista) {
        if (lista.quantidade == 0) {
            throw "lista vazio!";
        };
        for (int i = 0; i < lista.quantidade; i++) {
            lista.vetor[i] = lista.vetor[i + 1];
        }
        lista.quantidade--;
    }


    template<typename T, int CAPACIDADE>
    void remove_posicao(TListaEstatica<T, CAPACIDADE>& lista, int index) {
        if (lista.quantidade == 0) {
            throw "lista vazio!";
        };
        for (int i = index; i < lista.quantidade; i++) {
            lista.vetor[i] = lista.vetor[i + 1];
        }
        lista.quantidade--;
    }



    //OBTER

    template<typename T, int CAPACIDADE>
    T& obter_item_lista(TListaEstatica<T, CAPACIDADE> lista, int posicao) {
        if (lista.quantidade == 0) {
            throw "lista Vazia!";
        }
        else if (lista.quantidade < posicao) {
            throw "Não há este index na lista!";
        }

        return lista.vetor[posicao];
    }



    //Contem não ta funcionando problema na linha 136 - em relação a sobrecarga do binário "=="


    template <typename T, int CAPACIDADE>
    bool contem_lista(TListaEstatica<T, CAPACIDADE> lista, T dado) {
        if (lista.quantidade == 0) {
            throw "lista Vazia!";
        }
        for (int i = 0; i < lista.quantidade; i++) {
            if (lista.vetor[i] == dado) {
                return true;
            }
        }
        return false;
    }

    template<typename T, int CAPACIDADE>
    void gerar_jogadores_estatica(TListaEstatica<T, CAPACIDADE> lista, T dado) {
        for (int i = 0; i < 10; i++) {
            dado.num = i+20;
            dado.pontuacao = rand() % 100;
            insere_final(lista, dado);
           
        }

    }
}

#endif

