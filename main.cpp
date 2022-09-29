#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "funcoes.cpp"

using namespace std;

void Menu()
{
    system("cls");
    cout << "--------------------------------\n";
    cout << "       DEPARTAMENTO PESSOAL     \n";
    cout << "--------------------------------\n";
    cout << "1. INCLUIR NOVO FUNCIONARIO\n";
    cout << "2. INCLUIR NOVOS PROJETOS\n";
    cout << "3. EXCLUIR PROJETOS\n";
    cout << "4. EXCLUIR FUNCIONARIOS SEM PROJETOS\n";
    cout << "5. CONSULTAR FUNCIONARIO\n";
    cout << "6. IMPRIMIR CONTRA-CHEQUE\n";
    cout << "0. Sair\n";
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista;
    TipoFuncionario item;
    TipoProjeto tpro;
    Apontador ap;
    Projeto pro;
    int opcao;

    FILE *arquivo;
    TipoFuncionario func;
    Apontador a = lista.primeiro;

    arquivo = fopen("funcionarios.bin", "rb");

    if(arquivo != NULL){
        while (fread(&func, sizeof(TipoFuncionario), 1, arquivo))
        {
            InsereListaUltimo(&lista, func);
        }
        fclose(arquivo);
    }else{
        cout << "Vazio!";
        system("pause");
    }

    CriaListaVazia(&lista);

    do
    {
        system("cls");
        Menu();
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("cls");
            cout << "--------------------------------\n";
            cout << "           FUNCIONARIO          \n";
            cout << "--------------------------------\n";
            cout << "Novo funcionario\n";
            cout << "--------------------------------\n";
            cout << "Nome: ";
            item.id = id;
            cin.ignore();
            cin.getline(item.nome, 40);
            cout << "Estado: ";
            cin.ignore();
            cin.getline(item.endereco.estado, 30);
            cout << "Cidade: ";
            cin.ignore();
            cin.getline(item.endereco.cidade, 50);
            cout << "Bairro: ";
            cin.ignore();
            cin.getline(item.endereco.bairro, 50);
            cout << "Rua: ";
            cin.ignore();
            cin.getline(item.endereco.rua, 50);
            cout << "Numero: ";
            cin.ignore();
            cin.getline(item.endereco.numero, 10);
            cout << "Dependentes: ";
            cin >> item.dependentes;

            CriaListaVaziaSequencial(&item.projeto);
            InsereListaUltimo(&lista, item);

            int opcaoFunc;
            cout << "Adcionar um projeto para funcionario? \n1-Sim 2-Não" << endl;
            cin >> opcaoFunc;
            if (opcaoFunc == 1)
            {
                int quantidadeProjeto, cont = 1;
                cout << "Quantos Projetos desejas adcionar nesse Funcionario? ";
                cin >> quantidadeProjeto;
                while (quantidadeProjeto < 0 || quantidadeProjeto > 5)
                {
                    cout << "Não pode adcionar essa quantidade de projetos no Funcionario! " << endl;
                    cout << "Informe novamente a quantidade de projetos: (1 à 5)" << endl;
                    cin >> quantidadeProjeto;
                }

                while (cont <= quantidadeProjeto)
                {
                    criaProjeto(&lista);
                    cont++;
                }
            }
            break;

        case 2:
            system("cls");
            int idFunc;
            criaProjeto(&lista);
            break;

        case 3:
            system("cls");
            excluiProjetoId(&lista);
            system("PAUSE");
            break;

        case 4:
            system("cls");
            apagaFuncionario(&lista);
            system("PAUSE");
            break;

        case 5:
            system("cls");
            BusqueFunc(lista);
            break;

        case 6:
            system("cls");
            ImprimirContraCheque(&lista);
            break;
        }
    }while (opcao != 0);

    arquivo = fopen("funcionarios.bin", "wb");

    while (a->prox != NULL)
    {
        func = a->prox->item;
        fwrite(&func, sizeof(TipoFuncionario), 1, arquivo);
        a = a->prox;
    }

    fclose(arquivo);
    desalocaLista(&lista);
    
    system("pause");
    return 0;
}