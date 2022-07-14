#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "colection.h"
#include "account.h"
#include <conio.h>

#define TRUE 1
#define FALSE 0

int main() {
    int i; // contadores
    int grau, grau2, grau3;
    char cliente[30];
    int numConta;
    int itens_max;
    float saldo;
    Colection *colection = NULL;
    account *conta;


    do {
        switch(grau) {

            case '1':

                system("@cls||clear");
                printf("Insira a quantidade de elementos deseja adicionar a colecao: ");
                scanf("%d", &itens_max);

                colection = colCreate(itens_max);

                if (colection == NULL) {
                    printf("Ops! Erro ao criar a colecao\n");
                    printf("Tente novamente.\n");
                } else {
                    printf("\nPARABENS! Colecao criada com exito!\n");
                }
                printf("\nPressione ENTER para continua ...");
                while(getchar() != '\n');
                getchar();

                break;

            case '2':

                system("@cls||clear");
                if (colection != NULL) {
                    if (colection->maxItens > colection->numItens) {
                        conta = (account*)malloc(sizeof(account));
                        if (conta != NULL) {
                            printf("Digite nome do cliente: ");
                            scanf("%s", conta->cliente);

                            printf("Digite numero da conta: ");                            ;
                            scanf("%d", &conta->numConta);

                            printf("Digite saldo da conta: R$ ");
                            scanf("%f", &conta->saldo);

                            colInsert(colection, (void*)conta);

                            printf("\nCliente: %s\nConta: %d\nSaldo: R$ %.2f\n", conta->cliente, conta->numConta, conta->saldo);

                        } else {
                            printf("Erro ao alocar conta!\n");
                            printf("Sinto muito, tente novamente.\n\n");
                        }     
                    } else {
                        printf("A colecao esgotada!\n");
                        printf("Sinto muito, tente novamente.\n\n");
                    }
                } else {
                    printf("Colecao nao encontrada! :( \n");
                    printf("Sinto muito, tente novamente.\n\n");
                }

                printf("\nPressione ENTER para continua ...");
                while(getchar() != '\n');
                getchar();
                break;
            
            case '3':

                system("@cls||clear");
                if (colection != NULL) {
                    if (colection->numItens > 0) {
                        for (i=0; i<colection->numItens; i++) {
                            conta = colection->itens[i];
                            printf("\n-----------------\n");
                            printf("Arquivo numero: %d\nCliente: %s\nConta: %d\nSaldo: R$ %.2f\n", i+1, conta->cliente, conta->numConta, conta->saldo);
                        }
                    } else {
                        printf("Ops! Nao foi encontrado nada na colecao!\n");
                        printf("Sinto muito, tente novamente.\n\n");
                    }
                } else {
                    printf("Colecao nao encontrada! :( \n");
                    printf("Sinto muito, tente novamente.\n\n");
                }
                printf("\nPressione ENTER para continua ...");
                while(getchar() != '\n');
                getchar();
                break;

            case '4':

                system("@cls||clear");
                if (colection != NULL) {
                    if (colection->numItens > 0) {
                        printf("Digite opcao que voce deseja procurar: \n\n");
                        printf("1 - Nome do Cliente\n");
                        printf("2 - Numero da conta\n");
                        printf("3 - Saldo da conta\n");
                        scanf("%d", &grau2);

                        switch (grau2) {
                        case 1:
                            
                            system("@cls||clear");
                            printf("Digite nome do cliente que voce deseja procurar: ");
                            scanf("%s", cliente);
                            conta = colQuery(colection, (void*)cliente, paraString);
                            break;
                        
                        case 2:

                            system("@cls||clear");
                            printf("Digite o numero da conta que voce deseja procurar: ");
                            scanf("%d", &numConta);
                            conta = colQuery(colection, (void*)&numConta, paraInt);
                            break;

                        case 3:

                            system("@cls||clear");
                            printf("Digite o saldo que voce deseja procurar: ");
                            scanf("%f", &saldo);
                            conta = colQuery(colection, (void*)&saldo, paraFloat);
                            break;
                        }

                        system("@cls||clear");
                        if (conta != NULL) {
                            printf("A sua conta foi encontrada: \n\n");
                            printf("------------------------\n");
                            printf("Cliente: %s\n", conta->cliente);
                            printf("Numero da conta: %d\n", conta->numConta);
                            printf("Saldo: R$ %.2f\n", conta->saldo);

                        } else {
                            printf("Sinto muito, mas sua conta nao foi encontrada! :( \n");
                            printf("Sinto muito, tente novamente.\n\n");
                        }
                    } else {
                        printf("Ops! Nao foi encontrado nada na colecao!\n");
                        printf("Sinto muito, tente novamente.\n\n");
                    }
                } else {
                    printf("Colecao nao encontrada! :( \n");
                    printf("Sinto muito, tente novamente.\n\n");
                }
                printf("\nPressione ENTER para continua ...");
                while(getchar() != '\n');
                getchar();
                break;

            case '5': 

                system("@cls||clear");
                if (colection != NULL) {
                    if (colection->numItens > 0) {
                        printf("Digite opcao que voce deseja procurar: \n");
                        printf("1 - Nome do Cliente\n");
                        printf("2 - Numero da conta\n");
                        printf("3 - Saldo da conta\n");
                        scanf("%d", &grau2);
                    
                    switch (grau2) {

                        case 1:

                            system("@cls||clear");
                            printf("Digite nome do cliente que voce deseja procurar: ");
                            scanf("%s", cliente);
                            conta = colQuery(colection, (void*)cliente, paraString);
                            break;
                        
                        case 2:

                            system("@cls||clear");
                            printf("Digite o numero da conta que voce deseja procurar: ");
                            scanf("%d", &numConta);
                            conta = colQuery(colection, (void*)&numConta, paraInt);
                            break;

                        case 3:

                            system("@cls||clear");
                            printf("Digite o saldo que voce deseja procurar: ");
                            scanf("%f", &saldo);
                            conta = colQuery(colection, (void*)&saldo, paraFloat);
                            break;
                        }

                    if (conta != NULL) {
                        printf("Voce realmente deseja remover essa conta?\n\n");
                        printf("----------------\n");
                        printf("Cliente: %s\n", conta->cliente);
                        printf("Numero da conta: %d\n", conta->numConta);
                        printf("Saldo: R$ %.2f\n", conta->saldo);
                        printf("\nDigite 1 para excluir a conta.\n");
                        scanf("%d", &grau3);
                        switch (grau3)
                        {
                        case 1:
                            colRemove(colection, conta);
                            printf("Conta removida com sucesso!!");
                        }
                    }

                    } else {
                        printf("Ops! Nao foi encontrado nada na colecao!\n");
                        printf("Sinto muito, tente novamente.\n\n");
                    }
                } else {
                    printf("Colecao nao encontrada! :( \n");
                    printf("Sinto muito, tente novamente.\n\n");
                }
                printf("\nPressione ENTER para continua ...");
                while(getchar() != '\n');
                getchar();
                break;
            
            case '6':

                system("@cls||clear");
                colClear(colection);
                if(colection->numItens == 0) {
                    printf("PARABENS! Colecao esvaziada com sucesso!!\n");
                }
                printf("\nPressione ENTER para continua ...");
                while(getchar() != '\n');
                getchar();
                break;
                
            case '7':

                system("@cls||clear");
                if (colection != NULL) {
                    if (colection->numItens == 0) {
                        colDestroy(colection);
                        colection = NULL;
                        printf("PARABENS! Colecao destruida com sucesso!!\n");
                    } else {
                        printf("Ops! A colecao tem que estar vazia!\n");
                        printf("Sinto muito, tente novamente.\n\n");
                    }
                } else {
                    printf("Colecao nao encontrada! :( \n");
                }
            
            printf("\nPressione ENTER para continua ...");
            while(getchar() != '\n');
            getchar();
            break;
        }
    system("@cls||clear");
    printf("\n\t\3MENU\3\n\n");
    printf("1 - Criar uma colecao\n");
    printf("2 - Adicionar um componente a colecao\n");
    printf("3 - Listar os componentes da colecao\n"); 
    printf("4 - Pesquisar um componente da colecao\n");
    printf("5 - Remover um componente da colecao\n");
    printf("6 - Esvaziar colecao\n"); 
    printf("7 - Destruir colecao se estiver vazia\n"); 

    } while ( (grau = getchar() ) != EOF );

    printf("Obrigado :) \3\n\n");

    return 0;
}