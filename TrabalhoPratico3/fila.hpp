#ifndef FILA_H
#define FILA_H

typedef struct TipoMedico{
    char nome[20];
    char especialidade[100];
    char CRM[15];
    bool disponivel = true;
} tipoMedico;

typedef struct TipoPaciente{
    char nome[20];
    char Endereco[100];
    char idade[100];
    char sexo[15];
    char triagem[18];
    int prioridade;
    bool atendido = false;
    time_t horaChegada;
    time_t horaSaida;
    double tempo;
} tipoPaciente;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento{
    TipoMedico itemMedico;
    TipoPaciente itemPaciente;
    Apontador prox;
} TipoElemento;

typedef struct TipoFila{
    Apontador inicio, fim;
    int tamanho;
} TipoFila;


void menu();
void insereMedico(TipoFila *fila);
void inserePaciente(TipoPaciente *Item, int retornoTriagem);
void proximoContato(TipoFila *fila);
int triagem();
void retornotriagem(int retornoTriagem);
void atualizaUltimo(TipoFila *fila);
void removePacienteNome(TipoFila *fila, char nome[]);
void calculaTempo(TipoPaciente *paciente);
bool pesquisaPaciente(TipoFila fila, char nome[]);
void atenderPaciente(TipoFila *fila, TipoPaciente *paciente, TipoFila *fila2, TipoMedico *medico);
void inicializaFila(TipoFila *fila);
bool verificaFilaVazia(TipoFila *fila);
void enfileiraMedico(TipoFila *fila, TipoMedico item);
void enfileiraPaciente(TipoFila *fila, TipoPaciente item);
void desenfileiraMedico(TipoFila *fila, TipoMedico *item);
void desenfileiraPaciente(TipoFila *fila, TipoPaciente *item);
void esvaziaFila(TipoFila *fila);
void imprimeFilaMedicos(TipoFila *fila);
void imprimeFilaPacientes(TipoFila *fila);
int triagem(TipoFila *fila);
void insereAposElemento(Apontador anterior, Apontador novo, TipoFila *fila);
void enfileiraPrioridade(TipoFila *fila, TipoPaciente paciente);
void inserePacientePrimeiro(TipoFila *fila, TipoPaciente item);
void atualizar(TipoFila *filaPacientes, TipoFila *filaPacientesAtendidos, TipoFila *filamedicos, TipoFila *filaMedicosDisponiveis);

#endif