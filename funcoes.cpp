#include <iostream>
#include <windows.h>
#include "lista.hpp"

#define MAXTAM 5

using namespace std;

void CriaListaVazia(TipoLista *lista)
{
    if (!listaCriada)
    {
        lista->primeiro = new TipoElemento;
        lista->ultimo = lista->primeiro;
        lista->primeiro->prox = NULL;
        listaCriada = true;
    }
    else
    {
        cout << "Lista já existe!";
    }
    Sleep(1500);
}

void CriaListaVaziaSequencial(TipoProjeto *lista)
{
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
    lista->tamanho = lista->primeiro;
}

bool VerificaListaVazia(TipoLista *lista)
{
    return (lista->primeiro == lista->ultimo);
}

bool VerificaListaVaziaProjetos(TipoProjeto *lista)
{
    return (lista->primeiro == lista->ultimo);
}

int TamanhoLista(TipoLista *lista)
{
    return lista->tamanho;
}

void AtualizaUltimo(TipoLista *lista)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void InsereListaUltimo(TipoLista *lista, TipoFuncionario item)
{
    lista->ultimo->prox = new TipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
    id++;
}

void ImprimeLista(TipoLista lista)
{
    if (VerificaListaVazia(&lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl;
        cout << "Estado: " << aux->item.endereco.estado << endl;
        cout << "Cidade: " << aux->item.endereco.cidade << endl;
        cout << "Bairro: " << aux->item.endereco.bairro << endl;
        cout << "Rua: " << aux->item.endereco.rua << endl;
        cout << "Numero: " << aux->item.endereco.numero << endl;
        cout << "Dependentes: " << aux->item.dependentes << endl;
        ImprimeProjectos(aux->item.projeto);
        aux = aux->prox;
    }
    system("pause");
}

bool PesquisaItem(TipoLista *lista, char nome[])
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (strcmp(aux->item.nome, nome) == 0)
        {
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

Apontador PesquisaItemPorId(TipoLista *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void ImprimeItem(TipoLista *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (lista->primeiro->item.id == id)
        {
            cout << "ID: " << aux->item.id << endl;
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Estado: " << aux->item.endereco.estado << endl;
            cout << "Cidade: " << aux->item.endereco.cidade << endl;
            cout << "Bairro: " << aux->item.endereco.bairro << endl;
            cout << "Rua: " << aux->item.endereco.rua << endl;
            cout << "Numero: " << aux->item.endereco.numero << endl;
            cout << "Dependentes: " << aux->item.dependentes << endl;

            ImprimeProjectos(aux->item.projeto);
            break;
        }
        aux = aux->prox;
    }
}

void BusqueFunc(TipoLista lista)
{
    int id, recebe;
    Apontador ap;

    cout << "--------------------------------\n";
    cout << "           Funcionario          \n";
    cout << "--------------------------------\n";
    cout << "Listar funcionario(s)\n";
    cout << "--------------------------------\n";
    int funcID;
    cout << "Informe o codigo do funcionario que desejas procurar: ";
    cin >> funcID;
    recebe = VerificaFunc(funcID, lista, &ap);

    if (recebe == 1)
    {
        cout << "ID: " << ap->prox->item.id << endl;
        cout << "Nome: " << ap->prox->item.nome << endl;
        cout << "Estado: " << ap->prox->item.endereco.estado << endl;
        cout << "Cidade: " << ap->prox->item.endereco.cidade << endl;
        cout << "Bairro: " << ap->prox->item.endereco.bairro << endl;
        cout << "Rua: " << ap->prox->item.endereco.rua << endl;
        cout << "Numero: " << ap->prox->item.endereco.numero << endl;
        cout << "Dependentes: " << ap->prox->item.dependentes << endl;

        ImprimeProjectos(ap->prox->item.projeto);

        system("pause");
    }
    else
    {
        cout << "Codigo Invalido!!" << endl;
        system("pause");
    }
}

void InserirProjetos(Projeto *pro, TipoProjeto *lista)
{
    if (lista->ultimo == MAX_TAM)
    {
        cout << "Maximo de Projetos cadastrados";
    }
    else
    {
        lista->projeto[lista->ultimo] = pro;
        lista->ultimo++;
        lista->tamanho++;
    }
    codigo++;
}

void ImprimeProjectos(TipoProjeto lista)
{
    cout << "Projeto(s)" << endl;
    for (int i = 0; i < lista.ultimo; i++)
    {
        cout << "ID projeto: " << lista.projeto[i]->id << endl;
        cout << "Nome Projeto: " << lista.projeto[i]->nome << endl;
        cout << "Horas Trabalhadas: " << lista.projeto[i]->horasTrabalhadasSemanais << endl;
    }
}

void ImprimeItemPorId(TipoLista *lista, int id)
{
    Apontador aux, ap;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Estado: " << aux->item.endereco.estado << endl;
            cout << "Cidade: " << aux->item.endereco.cidade << endl;
            cout << "Bairro: " << aux->item.endereco.bairro << endl;
            cout << "Rua: " << aux->item.endereco.rua << endl;
            cout << "Numero: " << aux->item.endereco.numero << endl;
            cout << "Dependentes: " << aux->item.dependentes << endl;

            cout << "Projeto" << endl;
            // ImprimeProjetoPorId(lista, ap->prox->item.projeto, id); 
            
            break;
        }
        aux = aux->prox;
    }
}

void ImprimeProjetoPorId(TipoLista *lista, TipoProjeto projeto, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            cout << "Projeto" << endl;
            cout << "ID: " << projeto.projeto[id]->id << endl;
            cout << "Nome: " << projeto.projeto[id]->nome << endl;
            cout << "Horas trabalhadas, semana: " << projeto.projeto[id]->horasTrabalhadasSemanais << endl;
            break;
        }
        aux = aux->prox;
    }
}

void RemoveListaPrimeiro(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }
    Apontador aux, atual;
    atual = lista->primeiro->prox;
    aux = lista->ultimo;
    while (atual->prox != lista->ultimo)
    {
        atual = atual->prox;
    }
    atual->prox = NULL;
    lista->ultimo = atual;
    delete aux;
    lista->tamanho--;
}

void RemoveItemPorId(TipoLista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }

    Apontador aux, anterior, x;

    aux = lista->primeiro->prox;

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == id)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void RemoveProjectPorId(TipoProjeto *lista, int p, Projeto *proj)
{
    int a, aux;
    Apontador ap;

    cout << "Informe o codigo do projeto: ";
    cin >> id;

    if (VerificaProj(id, ap->item.projeto, &a))
    {
        proj = lista->projeto[p];
        lista->ultimo--;
        for (int i = 3; i < 5; i++)
        {
            lista->projeto[i] = lista->projeto[i + 1];
        }
    }
}

int VerificaFunc(int id, TipoLista lista, Apontador *ap)
{
    Apontador aux;
    aux = lista.primeiro;
    int encontrou = 0;

    while ((!encontrou) && (aux->prox != NULL))
    {
        if (aux->prox->item.id == id)
        {
            encontrou = 1;
        }
        else
            aux = aux->prox;
    }
    *ap = aux;
    return encontrou;
}

int VerificaProj(int id, TipoProjeto lista, int *a)
{
    int x = lista.primeiro;
    int encontrou = 0;

    while ((!encontrou) && (x < lista.ultimo))
    {
        if (lista.projeto[x]->id == id)
        {
            encontrou = 1;
        }
        else
        {
            x++;
        }
    }
    return encontrou;
}

void ImprimirContraCheque(TipoLista *lista){
    Apontador aux = lista->primeiro->prox;

    int horasTotal = 0;
    float salarioBruto, inss, impostoRenda, salarioLiquido;

    while (aux)
    {
        cout << "ID Funcionario: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl;

        for(int i = 0; i < aux->item.projeto.ultimo; i++){
            horasTotal += aux->item.projeto.projeto[i]->horasTrabalhadasSemanais;
        }

        salarioBruto = ((45 * horasTotal) + (35 * aux->item.dependentes));
        inss = (salarioBruto * 0.085);
        impostoRenda = (salarioBruto * 0.15);
        salarioLiquido = (salarioBruto - (inss + impostoRenda));

        cout << "Horas Total: " << horasTotal << endl;
        cout << "Salario Bruto: " << salarioBruto << endl;
        cout << "INSS: " << inss << endl;
        cout << "Imposto de Renda: " << impostoRenda << endl;
        cout << "Salario Liquido: " << salarioLiquido << endl;

        horasTotal =0;
        salarioBruto = 0;
        inss = 0;
        impostoRenda = 0;
        salarioLiquido = 0;
        aux = aux->prox;
    }
    system("pause");
    system("cls");
}