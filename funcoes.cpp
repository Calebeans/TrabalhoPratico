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
        lista->ultimo->prox = NULL;
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
    aux = lista->primeiro;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void InsereListaUltimo(TipoLista *lista, TipoFuncionario *item)
{
    lista->ultimo->prox = new TipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
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
    return aux;
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
    int id, recebe = 0;
    Apontador ap;

    cout << "--------------------------------\n";
    cout << "           Funcionario          \n";
    cout << "--------------------------------\n";
    cout << "Listar funcionario(s)\n";
    cout << "--------------------------------\n";
    int funcID;
    cout << "Informe o codigo do funcionario que desejas procurar: ";
    cin >> funcID;
    recebe = VerificaFunc(funcID, &lista, &ap);

    if (recebe != 0)
    {
        cout << "ID: " << ap->prox->item.id << endl;
        cout << "Nome: " << ap->prox->item.nome << endl;
        cout << "Estado: " << ap->prox->item.endereco.estado << endl;
        cout << "Cidade: " << ap->prox->item.endereco.cidade << endl;
        cout << "Bairro: " << ap->prox->item.endereco.bairro << endl;
        cout << "Rua: " << ap->prox->item.endereco.rua << endl;
        cout << "Numero: " << ap->prox->item.endereco.numero << endl;
        cout << "Dependentes: " << ap->prox->item.dependentes << endl << endl;

        if(ap->prox->item.projeto.tamanho != 0){
            ImprimeProjectos(ap->prox->item.projeto);
        }else{
            cout << "Funcionario não possui projeto!" << endl;
        }
        system("pause");
    }
    else
    {
        cout << "Codigo Invalido!!" << endl;
        system("pause");
    }
}

int BusqueProjetos(int id, TipoProjeto projeto, int *a){
    int p = 0;
    int encontrou = 0;

    while ((!encontrou) && (p < projeto.ultimo))
    {
        if (projeto.projeto[p].id == id){
            encontrou = 1;
        } else {
            p++;
        }
        *a = p;
    }
    return encontrou;
}

void  InserirProjetos(Projeto pro, TipoProjeto *lista)
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

void criaProjeto(TipoProjeto *tProjeto, TipoLista lista, int idFunc){
    int recebeFunc;
    Projeto pro; 
    Apontador ap;
    recebeFunc = VerificaFunc(idFunc, &lista, &ap);
    if(recebeFunc > 0){
        pro.id = codigo;
        cout << "Nome do Projeto: ";
        cin >> pro.nome;
        cout << "Horas do Projeto: ";
        cin >> pro.horasTrabalhadasSemanais;

        InserirProjetos(pro, &(ap->prox->item.projeto));
    }
}

void ImprimeProjectos(TipoProjeto lista)
{
    cout << "Projeto(s)" << endl;
    for (int i = 0; i < lista.ultimo; i++)
    {
        cout << "ID projeto: " << lista.projeto[i].id << endl;
        cout << "Nome Projeto: " << lista.projeto[i].nome << endl;
        cout << "Horas Trabalhadas: " << lista.projeto[i].horasTrabalhadasSemanais << endl;
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
            ImprimeProjetoPorId(lista, &(ap->prox->item.projeto), id); 
            
            break;
        }
        aux = aux->prox;
    }
}

void ImprimeProjetoPorId(TipoLista *lista, TipoProjeto *projeto, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.projeto.projeto->id == id)
        {
            cout << "Projeto" << endl;
            cout << "ID: " << aux->item.projeto.projeto[id].id << endl;
            cout << "Nome: " << aux->item.projeto.projeto[id].nome << endl;
            cout << "Horas trabalhadas, semana: " << aux->item.projeto.projeto[id].horasTrabalhadasSemanais << endl;
            break;
        }
        aux = aux->prox;
    }
}

void imprimeProjeto(Projeto projeto){
        cout << projeto.id<< endl;
        cout << projeto.nome << endl;
        cout << projeto.horasTrabalhadasSemanais<< endl;
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
    }else{
        Apontador aux, anterior, x;

        cout << "removeFunc"<< endl;

        

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
        AtualizaUltimo(lista);
    }
}

int excluiFuncionarioSemProjetos(TipoLista *lista){
    int cont = 0;
    Apontador ap;
    ap = lista->primeiro->prox;

    while (ap != NULL)
    {
        if(ap->item.projeto.tamanho == 0){
            RemoveItemPorId(lista, ap->item.id);
            cont++;
        }
        ap = ap->prox;
    }
    return cont;
}

void apagaFuncionario(TipoLista *lista){
    system("cls");
            cout << "-----------------------------------\n";
            cout << "Exclusão de Funcionario sem projeto\n";
            cout << "      1-Excluir um Funcionario     \n";
            cout << "   2-Excluir todos os Funcionarios \n";
            cout << "      3- Voltar Menu Principal     \n";
            cout << "-----------------------------------\n";
            int opcao;
            cout << "Escolha: ";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                Apontador apFunc;
                cout << "ID do Funcionario: ";
                int codigo;
                cin >> codigo;
                system("cls");

                apFunc = PesquisaItemPorId(lista, codigo);//implementando verificações de exclusão de funcionario

                if(apFunc == NULL){
                    cout << "Não existe Funcionario com esse ID" << endl;
                }else{
                    if(apFunc->item.projeto.tamanho != 0){
                        cout << "Funcionario não tem projetos" << endl;
                    }else {
                        ImprimeItemPorId(lista, codigo);
                        RemoveItemPorId(lista, codigo);
                    }
                }
                break;

            case 2:
                    cout << "Excluir todos os Funcionarios sem Projetos?\n1-Sim 2-Não" << endl;
                    int opApague;
                    cin >> opApague;

                    if(opApague == 1){
                        int a;
                        a = excluiFuncionarioSemProjetos(lista);
                        cout << a << " Funcionarios removidos" << endl;
                    }
                break;
            
            default:
                break;
            }
}

void RemoveProjectPorId(TipoProjeto *lista, int p, Projeto *proj, Apontador ap)
{
    int indice;
    indice = pesquisaCodProjeto(lista, p);
    cout << indice;
    cout << "remove" << endl;

    if(indice >= 0){
        cout << "remove dentro" << endl;
        *proj = lista->projeto[indice];
        for(int i = indice; i < lista->ultimo; i++){
            lista->projeto[i] = lista->projeto[i+1];
        }
        lista->tamanho--;
        lista->ultimo--;
    }
}

void excluiProjetoId(TipoProjeto *tProjeto, TipoLista lista, Projeto pro){
    cout << "--------------------------------\n";
    cout << "       Exlusão de Projetos      \n";
    cout << "--------------------------------\n";
    cout << "Funcionario que voce deseja adcionar projeto: ";
    int idFunc1, a;
    char op;
    Apontador ap;
    cin >> idFunc1;
    int idProject;
    if (PesquisaItemPorId(&lista, idFunc1))
    {
        cout << "ID: ";
        cin >> idProject;
        // if (BusqueProjetos(idProject, ap->item.projeto, &a))
        // {
            cout << "\n--------------------------------\n";
            cout << "Confirma a exclusão do projeto? (s/n): ";
            cin >> op;
            if (op == 'S' || op == 's')
            {
                cout << "teste1";
                RemoveProjectPorId(tProjeto, idProject, &pro, ap);
                cout << "Projeto excluído com sucesso!" << endl;
            }
        // }
    }
    else{
        cout << "Funcionario não encontrado!\n";
    }
}

int VerificaFunc(int id, TipoLista *lista, Apontador *ap)
{
    Apontador aux;
    aux = lista->primeiro;
    int encontrou = 0;

    while ((!encontrou) && (aux->prox != NULL))
    {
        if (aux->prox->item.id == id)
        {
            encontrou = id;
        }
        else
            aux = aux->prox;
    }
    *ap = aux;
    return encontrou;
}

int VerificaProj(int id, TipoProjeto *lista)
{
    for(int i = 0; i < lista->ultimo; i++){
        if (lista->projeto[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int pesquisaCodProjeto(TipoProjeto *tProjeto, int id){
    cout << "pesquisa";
    for (int i = 0; i < 5; i++){
        cout << "for\n";
        int a = tProjeto->projeto[id].id;
        cout << a;
        if(id == tProjeto->projeto->id){
            cout << "if";
            return i;
        }
    }
    return -1;
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
            horasTotal += aux->item.projeto.projeto[i].horasTrabalhadasSemanais;
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