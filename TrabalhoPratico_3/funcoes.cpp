#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include "fila.hpp"

using namespace std;

void inicializaFila(TipoFila *fila){
    fila->inicio = NULL;
    fila->fim = fila->inicio;
    fila->tamanho = 0;
}

bool verificaFilaVazia(TipoFila *fila){
    return (fila->inicio == NULL);
}

int tamanho(TipoFila *fila){
    return fila->tamanho;
}

void enfileiraMedico(TipoFila *fila, TipoMedico medico){
    Apontador aux = new TipoElemento;

    aux->itemMedico = medico;
    aux->prox = NULL;

    if (verificaFilaVazia(fila)){
        fila->inicio = aux;
    }else{
        fila->fim->prox = aux;
    }

    fila->fim = aux;
    fila->tamanho++;
}

void enfileiraPaciente(TipoFila *fila, TipoPaciente paciente){
    Apontador aux = new TipoElemento;
    aux->itemPaciente = paciente;
    aux->prox = NULL;
    if (verificaFilaVazia(fila)){
        fila->inicio = aux;
    }else{
        fila->fim->prox = aux;
    }

    fila->fim = aux;
    fila->tamanho++;
}

void inserePacientePrimeiro(TipoFila *fila, TipoPaciente paciente){
    Apontador aux = new TipoElemento;
    aux->itemPaciente = paciente;
    aux->prox = NULL;

    if (verificaFilaVazia(fila)){
        fila->inicio = aux;
        fila->fim = fila->inicio;
    }else{
        aux->prox = fila->inicio;
        fila->inicio = aux;
    }
    fila->tamanho++;
}

void insereAposElemento(Apontador ant, Apontador aux, TipoFila *fila){
    aux->prox = ant->prox;
    ant->prox = aux;
    fila->tamanho++;
}

void enfileiraPrioridade(TipoFila *fila, TipoPaciente paciente){
    if (verificaFilaVazia(fila)){
        inserePacientePrimeiro(fila, paciente);
        return;
    }

    if (paciente.prioridade < fila->inicio->itemPaciente.prioridade){
        inserePacientePrimeiro(fila, paciente);
        return;
    }

    Apontador ant = fila->inicio;
    Apontador atual = ant->prox;
    Apontador aux = new TipoElemento;
    aux->itemPaciente = paciente;
    aux->prox = NULL;

    while (atual != NULL){
        if (aux->itemPaciente.prioridade < atual->itemPaciente.prioridade){
            insereAposElemento(ant, aux, fila);
            return;
        }
        ant = atual;
        atual = atual->prox;
    }
    insereAposElemento(ant, aux, fila);
    fila->fim = aux;
}

void desenfileiraMedico(TipoFila *fila, TipoMedico *item){
    if (verificaFilaVazia(fila)){
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;

    *item = aux->itemMedico;
    fila->inicio = aux->prox;
    delete aux;
    fila->tamanho--;
}

void desenfileiraPaciente(TipoFila *fila, TipoPaciente *item){
    if (verificaFilaVazia(fila)){
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;

    *item = aux->itemPaciente;
    fila->inicio = aux->prox;
    delete aux;
}

void imprimeFilaMedicos(TipoFila *fila){
    if (verificaFilaVazia(fila)){
        cout << "Nenhum médico cadastrado!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    while (aux != NULL){

        cout << endl << "Nome: " << aux->itemMedico.nome << endl;
        cout << "Especialidade: " << aux->itemMedico.especialidade << endl;
        cout << "CRM: " << aux->itemMedico.CRM << endl;
        cout << endl << "Disponivel(0-SIM, 1-NAO): " << aux->itemMedico.disponivel << endl;
        aux = aux->prox;
    }
    cout << endl;
}

void imprimeFilaPacientes(TipoFila *fila){

    if (verificaFilaVazia(fila)){
        cout << "Nenhum paciente cadastrado!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    while (aux != NULL){
        cout << endl << "Nome: " << aux->itemPaciente.nome << endl;
        cout << "Endereço: " << aux->itemPaciente.Endereco << endl;
        cout << "Idade: " << aux->itemPaciente.idade << endl;
        cout << "Sexo: " << aux->itemPaciente.sexo << endl;
        cout << "Prioridade: " << aux->itemPaciente.prioridade << endl;
        if(aux->itemPaciente.atendido == 0){
            cout << "Não foi atendido" << endl;
        }
        if (aux->itemPaciente.atendido == 1){
            cout << "Foi atendido:" << endl;
            cout << "Tempo de Atendimento: " << aux->itemPaciente.tempo << endl;
        }
        cout << "Hora que chegou: " << ctime(&aux->itemPaciente.horaChegada);

        aux = aux->prox;
    }
    cout << endl;
}

void menu(){
    cout << "   ______________________________________" << endl;
    cout << "  | 1 - Cadastro de Medico:              |" << endl;
    cout << "  | 2 - Novo Atendimento:                |" << endl;
    cout << "  | 3 - Saída de Dados:                  |" << endl;
    cout << "  | 4 - Registro de Hospital:            |" << endl;
    cout << "  | 0 - Sair:                            |" << endl;
    cout << "  |______________________________________|" << endl;
    cout << endl;
}

void insereMedico(TipoMedico *medico){

    cin.ignore();
    cout << "Nome: ";
    cin.getline(medico->nome, 20);
    cout << "Especialidade: ";
    cin.getline(medico->especialidade, 100);
    cout << "CRM: ";
    cin.getline(medico->CRM, 15);

    cout << "\nContato registrado com sucesso!\n\n";
    Sleep(1000);
    system("cls");
}

void inserePaciente(TipoPaciente *Item, int retornoTriagem){
    int prioridade;
    double tempoAtendimento;
    if (retornoTriagem <= 5){
        prioridade = 1;
        tempoAtendimento = 5;
    }else if (retornoTriagem > 5 && retornoTriagem < 11){
        prioridade = 2;
        tempoAtendimento = 4;
    }else if (retornoTriagem > 11 && retornoTriagem < 16){
        prioridade = 3;
        tempoAtendimento = 3;
    }else if (retornoTriagem > 16 && retornoTriagem < 18){
        prioridade = 4;
        tempoAtendimento = 2;
    }else{
        prioridade = 5;
        tempoAtendimento = 1;
    }
    cout << endl;
    cout << "        CADASTRO DE PACIENTES       " << endl;
    cin.ignore();

    cout << "Nome: ";
    cin.getline(Item->nome, 20);
    cout << "Endereço: ";
    cin.getline(Item->Endereco, 100);
    cout << "Idade: ";
    cin.getline(Item->idade, 100);
    cout << "sexo: ";
    cin.getline(Item->sexo, 15);
    Item->prioridade = prioridade;
    Item->horaChegada = time(NULL);
    Item->tempo = tempoAtendimento;
}

int triagem(){
    char vet[18];
    string perguntas[18] = {"Comprometimento da via aérea?","Respiração ineficaz?","Choque?",
                            "Não responde a estímulos?","Em convulsão?","Dor Severa?",
                            "Grande hemorragia incontrolável?","Alteração do estado de consciência?",
                            "Temperatura maior ou igual a 39°C?","Trauma craniano severo?","Dor moderada?",
                            "Pequena hemorragia incontrolável?","Vômito persistente?","Temperatura entre 38°C e 39°C?",
                            "Idoso ou grávida?","Dor leve?","Náuseas?","Temperatura entre 37°C e 38°C?"};
    TipoPaciente teste;
    TipoFila fila;
    cout << "             TRIAGEM            " << endl;
    cout << "________________________________" << endl;

    for (int i = 0; i < 5; i++){ 
        cout << "Pergunta " << i+1 << " " << endl << perguntas[i] << endl;
        cin >> vet[i];
        if (vet[i] == 'S' || vet[i] == 's')
        {
            return i;
        }
        system("cls");
    }
    for (int i = 5; i < 18; i++){ 
        cout << "Pergunta " << i+1 << endl << perguntas[i] << endl;
        cin >> vet[i];
        system("cls");
    }
    cout << "Ordem das Respostas \n ";
    for (int i = 0; i < 18; i++){
        cout << vet[i] << " ";
    }for (int i = 6; i < 18; i++){
        if (vet[i] == 'S'){
            return i;
        }
    }
    system("PAUSE");
    system("cls");
}

bool pesquisaPaciente(TipoFila fila, char nome[]){
    Apontador aux = fila.inicio;
    while (aux != NULL){
        if (strcmp(aux->itemPaciente.nome, nome) == 0){
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

void removePaciente(TipoFila *fila, char nome[]){
    if (verificaFilaVazia(fila)){
        return;
    }
    Apontador aux, aux2;
    aux = fila->inicio->prox;
    aux2 = fila->inicio;
    while (aux != NULL){
        if (strcmp(aux->itemPaciente.nome, nome) == 0){
            aux2->prox = aux->prox;
            delete aux;
            fila->tamanho--;
            break;
        }
        aux2 = aux;
        aux = aux->prox;
    }
    atualizaUltimo(fila);
}

void atualizaUltimo(TipoFila *fila){
    Apontador aux;
    aux = fila->inicio;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    fila->fim = aux;
}

void atualizar(TipoFila *filaPacientes, TipoFila *filaPacientesAtendidos, TipoFila *filamedicos, TipoFila *filaMedicosDisponiveis){

    Apontador aux = filaPacientes->inicio;
    Apontador aux2 = filamedicos->inicio;
    aux2->itemMedico.disponivel = true;

    for (int i = 0; i < filamedicos->tamanho; i++){

        aux->itemPaciente.horaSaida = time(NULL);
        aux->itemPaciente.tempo = aux->itemPaciente.horaSaida - aux->itemPaciente.horaChegada;

        cout << "Paciente: " << aux->itemPaciente.nome << endl;
        cout << "Foi atendido em: " << aux->itemPaciente.tempo << " minutos" << endl; 
        cout << "Pelo medico:" << aux2->itemMedico.nome << endl;

        cout << "Paciente atendido com sucesso!\n";
        aux->itemPaciente.atendido = true;
        aux2->itemMedico.disponivel = false;

        if (aux->itemPaciente.atendido == true){
            enfileiraPrioridade(filaPacientesAtendidos, aux->itemPaciente);
            desenfileiraPaciente(filaPacientes, &aux->itemPaciente);
        }
        if (filaPacientes->tamanho == filaPacientesAtendidos->tamanho){
            if (aux2->itemMedico.disponivel == true){
                enfileiraMedico(filaMedicosDisponiveis, aux2->itemMedico);
            }

            break;
        }
        aux2 = aux2->prox;
        aux = aux->prox;
        Sleep(1000);
    }
}