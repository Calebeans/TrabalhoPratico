#ifndef FUNCOES
#define FUNCOES
#define MAXTAM 10
#define MAX_ENTREGA 7


typedef struct Pedido
{
    int pedido;
    int produtos[MAXTAM];
    double distancia;
    int tamPilha;
    float valorPedido = 0;
};

typedef struct TipoPilha
{
    Pedido pedido[MAX_ENTREGA];
    int topo;
    int tamanho;
};

int IDPedido = 0;
int IDProduto = 0;

bool TPilha_Inicializa(TipoPilha *pilha);
bool TPilha_Vazia(TipoPilha *pilha);
bool TPilha_Cheia(TipoPilha *pilha);
bool TPilha_Empilha(TipoPilha *pilha, Pedido ped);
void TPilha_Desempilha(TipoPilha *pilha, Pedido *ped);
void TPilha_Imprime(TipoPilha *pilha);
int Consulta(TipoPilha *pilha, int codigo);

#endif