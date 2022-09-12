
#ifndef GAME_H
#define GAME_H

#include "estatica.h"
#include "jogador.h"
#include "encadeadaSimples.h"
#include "encadeadaDupla.h"


#include <iostream>
using namespace std;

void init() {
    TLS::TListaEstatica<Jogador, 10> jogadores;
    TLDS::TLista<Jogador> players;
    TLDD::TLista<Jogador> playersDupla;

    
    gerar_jogadores_estatica(jogadores);

    TLS::imprimir_lista(jogadores);

 
}

void gerar_jogadores_dinam(TLDS::TLista<Jogador>, int tam) {
    for (int i = 0; i < tam; i++) {

        Jogador a;
        a.num = 1;
        a.pontuacao = 1;

     
    };
}


void gerar_jogadores_estatica(TLS::TListaEstatica<Jogador, 10>& lista) {
    for (int i = 0; i < 10; i++) {
        Jogador a;
        a.num = 1;
        a.pontuacao = rand() % 1000;
        TLS::insere_final(lista, a);
    };
}

#endif

