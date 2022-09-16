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
    Apontador ap;
    int ap1;
    Projeto pro;
    int opcao, ret;
    char op;

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
            // cin.ignore();
            // cin.getline(item.endereco.estado, 30);
            strcpy(item.endereco.estado, "Minas Gerais");
            cout << "Cidade: ";
            // cin.ignore();
            // cin.getline(item.endereco.cidade, 50);
            strcpy(item.endereco.cidade, "SJE");
            cout << "Bairro: ";
            // cin.ignore();
            // cin.getline(item.endereco.bairro, 50);
            strcpy(item.endereco.bairro, "Novo Sucesso");
            cout << "Rua: ";
            // cin.ignore();
            // cin.getline(item.endereco.rua, 50);
            strcpy(item.endereco.rua, "Maria Aurelia");
            cout << "Numero: ";
            // cin.ignore();
            // cin.getline(item.endereco.numero, 10);
            strcpy(item.endereco.numero, "139");
            cout << "Dependentes: ";
            cin >> item.dependentes;

            InsereListaUltimo(&lista, item);
            break;

        case 2:
            system("cls");
            int idFunc, verifica;
            cout << "Funcionario que voce deseja adcionar projeto: ";
            cin >> idFunc;
            verifica = VerificaFunc(idFunc, lista, &ap);
            if (verifica == 1)
            {
                cout << "Projeto" << endl;
                pro.id = codigo;
                cout << "Nome Projeto: ";
                cin >> pro.nome;
                cout << "Horas Projeto: ";
                cin >> pro.horasTrabalhadasSemanais;
                ap = PesquisaItemPorId(&lista, codigo);
                if (ap != NULL)
                {
                    CriaListaVaziaSequencial(&(ap->item.projeto));
                    InserirProjetos(&pro, &(ap->item.projeto));
                    system("pause");
                }
            }
            break;

        case 3:
            // system("cls");
            // cout << "--------------------------------\n";
            // cout << "       Exlusão de Projetos      \n";
            // cout << "--------------------------------\n";
            // unsigned int idProject;
            // cout << "ID: ";
            // cin >> idProject;
            // if (PesquisaItemPorId(&lista, idProject))
            // {
            //     ImprimeProjetoPorId(&lista, tpro, idProject);
            //     cout << "\n--------------------------------\n";
            //     cout << "Confirma a exclusão do projeto? (s/n): ";
            //     cin >> op;
            //     if (op == 'S' || op == 's')
            //     {
            //         RemoveProjectPorId(&tpro, idProject, &pro);
            //         cout << "\nContato excluído com sucesso!\n";
            //     }
            // }
            // else
            // {
            //     cout << "Contato não encontrado!\n";
            // }
            // system("PAUSE");
            break;

        case 4:
            system("cls");
            cout << "-----------------------------------\n";
            cout << "Exclusão de Funcionario sem projeto\n";
            cout << "-----------------------------------\n";
            int codigo;
            cout << "ID do Funcionario: ";
            cin >> codigo;
            ap = PesquisaItemPorId(&lista, codigo);
            if (ap != NULL)
            {
                // cout << &(ap->item.projeto.tamanho);
                if (ap->item.projeto.tamanho == 0)
                {
                    ImprimeItemPorId(&lista, codigo);
                    cout << "\n--------------------------------\n";
                    cout << "Confirma a exclusão do contato? (s/n): ";
                    cin >> op;
                    if (op == 'S' || op == 's')
                    {
                        RemoveItemPorId(&lista, codigo);
                        cout << "\nContato excluído com sucesso!\n";
                    }
                }
                else
                {
                    cout << "Funcionario possui projeto!" << endl;
                }
            }
            else
            {
                cout << "Funcionario não encontrado! " << endl;
            }
            AtualizaUltimo(&lista);
            system("PAUSE");
            break;

        case 5:
            system("cls");
            BusqueFunc(lista);
            system("pause");
            break;

        case 6:
            system("cls");
            ImprimirContraCheque(&lista);
            break;
        }
    } while (opcao != 0);
}