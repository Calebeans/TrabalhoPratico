#include <iostream>
#include <windows.h>
#include <fstream>
#include "funcoes.cpp"

using namespace std;

void ImprimeMenu(){
    cout << "\tMENU\t" << endl << endl;
    cout << "1-Novo Pedido" << endl;
    cout << "2-Lista de Pedidos" << endl;
    cout << "3-Cardapio" << endl;
    cout << "4-Consulta de Pedido" << endl;
    cout << "5-Organizar Pilha de Entrega" << endl;
    cout << "6-Entregar" << endl;
    cout << "7-Sair" << endl << endl;
}

void ImprimeCardapio(){
    cout << "|     Cardapio     |" << endl << endl;
    cout << "| 1 - Refri        |" << endl;
    cout << "| 2 - Pastel       |" << endl;
    cout << "| 3 - Cafe         |" << endl;
    cout << "| 4 - Bolacha      |" << endl;
}

int main()
{

    Pedido pedido;
    TipoPilha pilha;

    TPilha_Inicializa(&pilha);

    TipoPilha aux, aux1;
    int recebe;
    int tamanhoPilha;
    int tamanhoMochila;
    double precos[] = {4.0, 5.5, 1.5, 4.6};
    

    FILE *file = fopen("lanchonete.bin", "r");
    if (file != NULL)
    {
        while (fread(&pedido, sizeof(Pedido), 1, file))
        {
            if (pedido.pedido > IDPedido)
            {
                IDPedido = pedido.pedido;
            }
            TPilha_Empilha(&pilha, pedido);
        }
    }

    IDPedido++;
    system("cls");

    int op;

    do
    {
        ImprimeMenu();
        cout << "Escolha uma opcao: ";
        cin >> op;
        system("cls");
        switch (op)
        {

        case 1:

            pedido.pedido = IDPedido;
            pedido.tamPilha = 0;

            do
            {
                ImprimeCardapio();
                cout << "Escolha um produto: ";
                cin >> IDProduto;
                if (IDProduto > 4 || IDProduto < 1)
                {
                    cout << "Produto não existe." << endl;
                    system("pause");
                    system("cls");
                }
                else if (IDProduto != 0)
                {
                    pedido.produtos[pedido.tamPilha] = IDProduto;
                    pedido.tamPilha++;
                    pedido.valorPedido += precos[IDProduto];
                }
                system("cls");
            } while (IDProduto != 0 and pedido.tamPilha < MAXTAM);

            cout << "Distância da entrega: ";
            cin >> pedido.distancia;

            TPilha_Empilha(&pilha, pedido);
            IDPedido = IDPedido + 1;
            system("pause");
            system("cls");

            break;

        case 2:

            if (TPilha_Vazia(&pilha)){
                cout << "Lista de pedidos vazia." << endl;
                system("pause");
                system("cls");
            }
                TPilha_Imprime(&pilha);
                system("pause");
                system("cls");
            break;

        case 3:

            ImprimeCardapio();
            system("pause");
            system("cls");
            break;

        case 4:

            int id;

            cout << "Digite o ID do pedido: ";
            cin >> id;

            recebe = Consulta(&pilha, id);
            cout << "ID do pedido: " << pilha.pedido[recebe].pedido << endl;
            cout << "Distancia: " << pilha.pedido[recebe].distancia << endl;
            cout << "Valor total do pedido: R$" << pilha.pedido[recebe].valorPedido << endl;
            cout << "Código dos pedidos: ";
            for (int i = 0; i < MAXTAM; i++)
            {
                    cout << pilha.pedido[recebe].produtos[i] << "; ";
            }

            system("pause");
            system("cls");

            break;


        case 5:

            if (TPilha_Vazia(&pilha))
            {
                cout << "Pilha Vazia!" << endl;
                break;
            }

            TPilha_Inicializa(&aux);
            TPilha_Inicializa(&aux1);

            tamanhoPilha = pilha.tamanho;

            while (pilha.tamanho != 0)
            {
                TPilha_Desempilha(&pilha, &pedido);
                TPilha_Empilha(&aux, pedido);
            }

            for (int i = 0; i < tamanhoPilha; i++)
            {
                int distancia = -1;
                int idDistancia = 0;

                while (aux.tamanho != 0)
                {
                    TPilha_Desempilha(&aux, &pedido);
                    TPilha_Empilha(&aux1, pedido);
                    if (distancia < pedido.distancia)
                    {
                        distancia = pedido.distancia;
                        idDistancia = pedido.pedido;
                    }
                }
                while (aux1.tamanho != 0)
                {
                    TPilha_Desempilha(&aux1, &pedido);
                    if (pedido.pedido == idDistancia)
                    {
                        TPilha_Empilha(&pilha, pedido);
                    }
                    else
                    {
                        TPilha_Empilha(&aux, pedido);
                    }
                }
            }
            cout << "Lista Organiza com sucesso!"
                 << endl << endl;

            break;


        case 6:

            if (TPilha_Vazia(&pilha))
            {
                cout << "Pilha vazia.\n\n";
            }
            else
            {
                TPilha_Desempilha(&pilha, &pedido);
                cout << "Codigo do pedido entregue: " << pedido.pedido << endl
                     << endl;
            }
            system("pause");
            system("cls");

            break;

        default:

            cout << endl << "Concluido" << endl;
            system("pause");
        }

    } while (op != 7);

    file = fopen("lanchonete.bin", "w");
    tamanhoMochila = pilha.tamanho;
    for (int i = 0; i < tamanhoMochila; i++)
    {
        TPilha_Desempilha(&pilha, &pedido);
        fwrite(&pedido, sizeof(Pedido), 1, file);
    }
}