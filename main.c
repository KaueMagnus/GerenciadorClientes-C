#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {
    char nome[100];
    char email[100];
};

int main() {

    struct Cliente clientes[100];
    int opcao, numClientes = 0;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1- Adicionar clientes:\n");
        printf("2- Visualizar clientes\n");
        printf("3- Editar clientes\n");
        printf("4- Deletar clientes\n");
        printf("5- Encerrar\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                printf("Digite o nome do cliente: ");
                getchar();
                fgets(clientes[numClientes].nome, sizeof(clientes[numClientes].nome), stdin);

                printf("Digite o email do cliente: ");
                fgets(clientes[numClientes].email, sizeof(clientes[numClientes].email), stdin);

                numClientes++;

                printf("\nCliente registrado com sucesso.\n\n");
                break;
            }
            case 2: {
                printf("\nClientes registrados:\n\n");

                for(int i = 0; i < numClientes; i++) {
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Email: %s\n", clientes[i].email);
                    printf("---------------------\n");
                }
                break;
            }
            case 3: {
                char nome[100];

                printf("Digite o nome do cliente que deseja editar: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                int clienteEncontrado = -1;

                for(int i = 0; i < numClientes; i++) {
                    if(strstr(clientes[i].nome, nome) != NULL) {
                        clienteEncontrado = i;
                        break;
                    }
                }
                if (clienteEncontrado != -1) {
                        printf("Digite o novo nome do cliente: ");
                        fgets(clientes[clienteEncontrado].nome, sizeof(clientes[clienteEncontrado].nome), stdin);
                        clientes[clienteEncontrado].nome[strcspn(clientes[clienteEncontrado].nome, "\n")] = '\0';

                        printf("Digite o novo email do cliente: ");
                        fgets(clientes[clienteEncontrado].email, sizeof(clientes[clienteEncontrado].email), stdin);
                        clientes[clienteEncontrado].email[strcspn(clientes[clienteEncontrado].email, "\n")] = '\0';

                        printf("Cliente editado com sucesso.\n");
                    } else {
                        printf("Cliente não encontrado.\n");
                    }

                    break;
            }
            case 4: {
                char nome[100];

                printf("Digite o nome do cliente que deseja deletar: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                int clienteEncontrado = -1;

                for(int i = 0; i < numClientes; i++) {
                    if(strstr(clientes[i].nome, nome) != NULL) {
                            clienteEncontrado = i;
                            break;
                        }
                }

                if (clienteEncontrado != -1) {
                    for(int j = clienteEncontrado; j < numClientes - 1; j++) {
                        clientes[j] = clientes[j + 1];
                    }
                    numClientes--;

                    printf("Cliente deletado com sucesso.\n");
                } else {
                    printf("Cliente não encontrado.\n");
                }

                break;

            }
            case 5:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }
     while (opcao != 5);

     return 0;
}
