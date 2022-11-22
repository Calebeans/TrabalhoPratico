#include <iostream>
#include <windows.h>
#include "fila.hpp"
#include "funcoes.cpp"
#include <time.h>
#include <ctime>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoFila filaMedicos;
    TipoFila filaMedicosDisponiveis;
    TipoFila filaPacientes;
    TipoFila filaPacientesAtendidos;
    TipoFila listafila;
    TipoPaciente paciente;
    TipoMedico medico;

    inicializaFila(&filaMedicos);
    inicializaFila(&filaMedicosDisponiveis);
    inicializaFila(&listafila);
    inicializaFila(&filaPacientes);
    inicializaFila(&filaPacientesAtendidos);

    int opcao = -1;
    do{
        system("cls");
        menu();
        if(opcao == -1){
            cout << "Opção: ";
            cin >> opcao;
        }else if(opcao < 0 || opcao > 4){
            cout << "Opcao invalida!" << endl;
            cout << endl << "Digite novamente: ";
            cin >> opcao;
        }else{
            cout << "Opção: ";
            cin >> opcao;
        }

        system("cls");
        switch (opcao){
        case 1:
            if (tamanho(&filaMedicos) > 4){

                cout << "Maximo de medicos cadastrados\n";
                system("PAUSE");
            }else{

                cout << "***********************************\n";
                cout << "        CADASTRO DE MEDICOS       \n";
                cout << "***********************************\n\n";
                insereMedico(&medico);
                enfileiraMedico(&filaMedicos, medico);
            }
            break;
        case 2:

            char op, retornoTriagem, vet[18];
            int valor;
            do{
                retornoTriagem = triagem();
                inserePaciente(&paciente, retornoTriagem);
                enfileiraPrioridade(&filaPacientes, paciente);
                cout << "Triagem realizada com sucesso\n";
                cout << "Deseja adicionar mais alguma triagem? S-sim N-nao\n";
                cin >> op;
            } while (op != 'N');

            system("PAUSE");

            break;
        case 3:
            char opcao;
            if (tamanho(&filaPacientes) == 0){
                cout << "Não existem pacientes para ser atendidos\n";
            }else if (tamanho(&filaMedicos) == 0){
                cout << "Não existem medicos cadastrados para atender, cadastre no minimo 1 medico\n";
            }else{

                atualizar(&filaPacientes, &filaPacientesAtendidos, &filaMedicos, &filaMedicosDisponiveis);

                cout << "Deseja atualizar: ";
                cin >> opcao;

                while (opcao == 'S'){
                    if (tamanho(&filaPacientesAtendidos) == tamanho(&filaPacientes)){
                        cout << "Todos os pacientes foram atendidos\n";
                        break;
                    }else{
                        atualizar(&filaPacientes, &filaPacientesAtendidos, &filaMedicos, &filaMedicosDisponiveis);
                        cout << "Deseja atualizar\n";
                        cin >> opcao;
                    }
                    break;
                }
            }

            system("PAUSE");
            break;
        case 4:

            system("cls");

            cout << "Registros" << endl;

            cout << "Pacientes Cadastrados: " << tamanho(&filaPacientes) << "\n";
            cout << "Pacientes Atendidos: " << tamanho(&filaPacientesAtendidos) << "\n";
            cout << "Medicos Cadastrados: " << tamanho(&filaMedicos) << "\n";
            cout << "Medicos Disponíveis: " << tamanho(&filaMedicosDisponiveis) << "\n" << endl;

            cout << "Lista de Pacientes Atendidos \n";
            imprimeFilaPacientes(&filaPacientesAtendidos);
            cout << endl;

            cout << "Lista de Pacientes \n";
            imprimeFilaPacientes(&filaPacientes);
            cout << endl;

            cout << "Lista de Medicos \n";
            imprimeFilaMedicos(&filaMedicos);
            cout << endl;
            system("PAUSE");
            break;
        }

    } while (opcao != 0);

    return 0;
}
