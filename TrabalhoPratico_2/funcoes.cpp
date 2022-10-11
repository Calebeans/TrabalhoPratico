#include <iostream>

#include "funcoes.hpp"

using namespace std;

bool TPilha_Inicializa(TipoPilha *pilha)
{
    pilha->topo = -1;
    pilha->tamanho = 0;
    return 0;
}

bool TPilha_Vazia(TipoPilha *pilha)
{
    if (pilha->tamanho == 0){
        return true;
    }
        return false;
}

bool TPilha_Cheia(TipoPilha *pilha)
{
    if (pilha->tamanho == MAX_ENTREGA){
        return true;
    }
        return false;
}

bool TPilha_Empilha(TipoPilha *pilha, Pedido pedido)
{
    if (TPilha_Cheia(pilha)){
        return false;
    }
        pilha->pedido[pilha->tamanho] = pedido;
        pilha->topo++;
        pilha->tamanho++;
        return true;
}

void TPilha_Desempilha(TipoPilha *pilha, Pedido *pedido)
{
    *pedido = pilha->pedido[pilha->tamanho - 1];
    pilha->pedido[pilha->tamanho - 1] = pilha->pedido[pilha->tamanho];
    pilha->tamanho--;
    pilha->topo--;
    return;
}

void TPilha_Imprime(TipoPilha *pilha){
    for (int i = pilha->topo; i >= 0; i--){
        cout << "Codigo do pedido: " << pilha->pedido[i].pedido << endl;
        cout << "Distancia do pedido: " << pilha->pedido[i].distancia << endl;
        cout << "Valor total do pedido: R$" << pilha->pedido[i].valorPedido << endl;
        cout << "Codigo dos pedidos: ";
        for (int j = 0; j < MAXTAM; j++){
                cout << pilha->pedido[i].produtos[j] << ", ";
        }
        cout << endl << endl;
    }
    cout << endl;
}

int Consulta(TipoPilha *pilha, int id){
    for (int i = 0; i < pilha->tamanho; i++){
        if (pilha->pedido[i].pedido == id){
            return i;
        }
    }
    return -1;
}