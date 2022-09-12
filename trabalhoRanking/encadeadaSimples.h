#ifndef LISTA_ENCADEADA_SIMPLES_H_INCLUDED
#define LISTA_ENCADEADA_SIMPLES_H_INCLUDED
namespace TLDS
{
    template <typename TIPO>
    struct TElemento {
        TIPO dado;
        TElemento <TIPO>* proximo;
    };

    template <typename TIPO>
    struct TLista {
        TElemento <TIPO>* inicio;
    };


    //Inicia
    template <typename TIPO>
    void inicializar(TLista <TIPO>& p) {

        p.inicio = NULL;
    }


    //Cria elemento
    template <typename TIPO>
    TElemento <TIPO>* novo_elemento_lista(TIPO dado) {

        TElemento <TIPO>* novo = new TElemento<TIPO>;

        novo->dado = dado;
        novo->proximo = NULL;

        return novo;
    }


    //inserir
    template <typename TIPO>
    bool inserirInicio(TLista <TIPO>& lista, TIPO dado) {


        TElemento <TIPO>* novo = novo_elemento_lista(dado);

        if (lista.inicio == NULL) {
            lista.inicio = novo;
            return true;
        }
        else {

            novo->proximo = lista.inicio;
            lista.inicio = novo;
            return true;
        }
    }


    template <typename TIPO>
    bool inserePosicao(TLista <TIPO>& lista, TIPO dado, int p) {

        int i = 0;

        TElemento<TIPO>* novo = novo_elemento_lista(dado);
        TElemento<TIPO>* nav = lista.inicio;


        if (lista.inicio != NULL)
        {
            while (nav->proximo != NULL)
            {
                nav = nav->proximo;
                i++;
            }
            nav = lista.inicio;

            if (i < p)
            {
                cout << "posicao invalida" << endl;
                system("pause");
                return false;
            }
            else
            {
                if (p == 0)
                {
                    inserirInicio(lista, dado);
                    return true;
                }
                else
                {
                    i = 0;
                    while (i < p - 1)
                    {
                        nav = nav->proximo;
                        i++;
                    }
                    novo->proximo = nav->proximo;
                    nav->proximo = novo;
                }
            }
        }
        else
        {
            cout << "lista vazia" << endl;
            inserirInicio(lista, dado);
            cout << endl;
            return true;
        }
    }


    template <typename TIPO>
    bool insereFinal(TLista <TIPO>& lista, TIPO dado) {

        TElemento<TIPO>* nav = lista.inicio;

        if (lista.inicio != NULL) {

            while (nav->proximo != NULL)
                nav = nav->proximo;


            if (nav->proximo != NULL) {
                return false;

            }
            else {
                TElemento <TIPO>* novo = novo_elemento_lista(dado);
                novo->proximo = nav->proximo;
                nav->proximo = novo;
                return true;
            }

        }
        else {
            TElemento <TIPO>* novo = novo_elemento_lista(dado);
            novo->proximo = lista.inicio;
            lista.inicio = novo;
            return true;
        }


    }



    //Remover
    template <typename TIPO>
    bool removerInicio(TLista <TIPO>& lista) {
        if (lista.inicio == NULL) {
            return false;
        }
        else {
            TElemento<TIPO>* removedor = lista.inicio;
            lista.inicio = removedor->proximo;
            delete removedor;
            return true;
        }
    }



    template <typename TIPO>
    bool removerPosicao(TLista <TIPO>& lista, int p) {

        int i = 0;

        TElemento<TIPO>* nav = lista.inicio;
        TElemento<TIPO>* anterior = NULL;

        if (lista.inicio == NULL)
        {
            cout << "Lista vazia!" << endl;
            return true;
        }
        if (nav->proximo == NULL)
        {
            removerFinal(lista);
            return true;
        }
        if (p == 0)
        {
            removerInicio(lista);
            return true;
        }
        else
        {
            // verificar se a posicao e maior que a lista
            // ou se o nav e nulo
            while (i < p)
            {
                anterior = nav;
                nav = nav->proximo;
                i++;
            }
            anterior->proximo = nav->proximo;
            delete nav;
            return true;
        }
    }

    template <typename TIPO>
    bool removerFinal(TLista <TIPO>& lista) {
        TElemento<TIPO>* nav = lista.inicio;
        TElemento<TIPO>* copia = NULL;
        if (lista.inicio == NULL)
        {
            cout << "Lista vazia" << endl;
        }
        else
        {
            while (nav->proximo != NULL)
            {
                copia = nav;
                nav = nav->proximo;
            }
            copia->proximo = NULL;
            delete nav;
            return true;
        }
    }

   

    template<typename TIPO>
    void imprimir(TLista<TIPO> lista) {
        TElemento<TIPO>* nav = new TElemento<TIPO>;
        nav = lista.inicio;

        cout << "\t\tJOGADORES";
        cout << "\n****************************************";

        while (nav != NULL) {
            cout << "\n\tJOGADOR: " << nav->dado.num;
            cout << " | PONTUACAO: " << nav->dado.pontuacao;
     
            nav = nav->proximo;
        }
      
        cout << "\n****************************************\n\n";
    }



    template<typename TIPO>
    
    TIPO obterPosicao(TLista<TIPO> lista, int posicao)
    {
        int i = 0;
        TElemento<TIPO>* nav = new TElemento<TIPO>;
        nav = lista.inicio;

        while (i < posicao)
        {
            nav = nav->proximo;
            i++;
        }
        return nav->dado;
    }


    template<typename TIPO>
    bool contemItem(TLista<TIPO> lista, TIPO dado)
    {
        TElemento<TIPO>* nav = new TElemento<TIPO>;
        nav = lista.inicio;

        while (nav != NULL)
        {
            if (nav->dado.num == dado.num)
            {
                return true;
            }
            else
            {
                nav = nav->proximo;
            }
        }
        return false;
    }

    template<typename TIPO>
    int obterIndice(TLista<TIPO> lista, TIPO dado)
    {
        TElemento<TIPO>* nav = new TElemento<TIPO>;
        nav = lista.inicio;
        int i = 0;
        while (nav != NULL)
        {
            if (nav->dado.num == dado.num)
            {
                return i;
            }
            else
            {
                nav = nav->proximo;
                i++;
            }
        }
    }

}

#endif // LISTA_ENCADEADA_SIMPLES_H_INCLUDED

