#ifndef LISTA_H
#define LISTA_H
#define MAX_TAM 5

typedef struct TipoEndereco
{
    char estado[30];
    char cidade[50];
    char bairro[50];
    char rua[50];
    char numero[10];
} TipoEndereco;

struct Projeto
{
    unsigned int id;
    char nome[50];
    double horasTrabalhadasSemanais;
};

struct TipoProjeto
{
    Projeto projeto[MAX_TAM];
    int primeiro = 0;
    int ultimo = 0;
    int tamanho = 0;
};

typedef struct TipoFuncionario
{
    unsigned int id;
    char nome[40];
    TipoEndereco endereco;
    int dependentes;
    TipoProjeto projeto;
} TipoFuncionario;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento
{
    TipoFuncionario item;
    Apontador prox;
} TipoElemento;

typedef struct TipoLista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
} TipoLista;

bool listaCriada = false;
int id = 1;
int codigo = 1;

void CriaListaVazia(TipoLista *lista);
void CriaListaVaziaSequencial(TipoProjeto *lista);
bool VerificaListaVazia(TipoLista *lista);
bool VerificaListaVaziaProjetos(TipoProjeto *lista);
void InsereListaUltimo(TipoLista *lista, TipoFuncionario *item);
void AtualizaUltimo(TipoLista *lista);
void ImprimeLista(TipoLista lista);
bool PesquisaItem(TipoLista *lista, char nome[]);
Apontador PesquisaItemPorId(TipoLista *lista, int id);
void ImprimeItem(TipoLista *lista, int id);
void ImprimeItemPorId(TipoLista *lista, int id);
void ImprimeProjetoPorId(TipoLista *lista, TipoProjeto *projeto, int id);
void RemoveListaPrimeiro(TipoLista *lista);
void RemoveListaUltimo(TipoLista *lista);
void RemoveItemPorId(TipoLista *lista, int id);
void RemoveProjectPorId(TipoProjeto *lista, int p, Projeto *proj, Apontador ap);
int TamanhoLista(TipoLista *lista);
int PequisaFuncPorId (TipoLista lista, int id);
void ImprimeProjectos(TipoProjeto lista);
int VerificaFunc(int id, TipoLista *lista, Apontador *ap);
void InserirProjetos(Projeto pro, TipoProjeto *lista);
void BusqueFunc (TipoLista lista);
int BusqueProjetos(int id, TipoProjeto projeto, int *a);
int VerificaProj(int id, TipoProjeto *lista);
void ImprimirContraCheque(TipoLista *lista);
void imprimeProjeto(Projeto projeto);
int pesquisaCodProjeto(TipoProjeto *tProjeto, int id);
void criaProjeto(TipoProjeto *tProjeto, TipoLista lista, int idFunc);
void excluiProjetoId(TipoProjeto *tProjeto, TipoLista lista, Projeto pro);
int excluiFuncionarioSemProjetos(TipoLista *lista);
void apagaFuncionario(TipoLista *lista);

#endif