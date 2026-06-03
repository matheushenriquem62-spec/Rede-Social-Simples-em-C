#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 10

int matriz[MAX_USUARIOS][MAX_USUARIOS];
char nomes[MAX_USUARIOS][50];
int total_usuarios = 0;

void inicializar() {
    int i, j;
    for (i = 0; i < MAX_USUARIOS; i++) {
        for (j = 0; j < MAX_USUARIOS; j++) {
            matriz[i][j] = 0;
        }
    }
}

void cadastrar_usuario() {
    if (total_usuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido!\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do usuario: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            printf("Usuario ja cadastrado!\n");
            return;
        }
    }

    strcpy(nomes[total_usuarios], nome);
    total_usuarios++;

    printf("Usuario '%s' cadastrado com sucesso!\n", nome);
}

void adicionar_amizade() {
    if (total_usuarios < 2) {
        printf("Precisa ter pelo menos 2 usuarios cadastrados.\n");
        return;
    }

    int id1, id2;
    printf("Digite o numero do primeiro usuario (1 a %d): ", total_usuarios);
    scanf("%d", &id1);

    printf("Digite o numero do segundo usuario (1 a %d): ", total_usuarios);
    scanf("%d", &id2);

    id1--;
    id2--;

    if (id1 < 0 || id1 >= total_usuarios || id2 < 0 || id2 >= total_usuarios) {
        printf("Usuario invalido!\n");
        return;
    }

    if (id1 == id2) {
        printf("Um usuario nao pode ser amigo de si mesmo!\n");
        return;
    }

    if (matriz[id1][id2] == 1) {
        printf("Esses usuarios ja sao amigos!\n");
        return;
    }

    matriz[id1][id2] = 1;
    matriz[id2][id1] = 1;

    printf("Amizade entre '%s' e '%s' adicionada!\n", nomes[id1], nomes[id2]);
}

void listar_usuarios() {
    if (total_usuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("\n=== Usuarios cadastrados ===\n");
    for (int i = 0; i < total_usuarios; i++) {
        printf("%d - %s\n", i + 1, nomes[i]);
    }
}

void mostrar_amizades() {
    if (total_usuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("\n=== Amizades ===\n");

    for (int i = 0; i < total_usuarios; i++) {
        printf("%s e amigo de: ", nomes[i]);

        int tem_amigo = 0;

        for (int j = 0; j < total_usuarios; j++) {
            if (matriz[i][j] == 1) {
                printf("%s ", nomes[j]);
                tem_amigo = 1;
            }
        }

        if (!tem_amigo) {
            printf("(nenhum amigo ainda)");
        }

        printf("\n");
    }
}

void exibir_matriz() {
    if (total_usuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("\n=== Matriz de Adjacencia ===\n");

    printf("%-15s", " ");

    for (int i = 0; i < total_usuarios; i++) {
        printf("%-10.8s", nomes[i]);
    }

    printf("\n");

    for (int i = 0; i < total_usuarios; i++) {
        printf("%-15.8s", nomes[i]);

        for (int j = 0; j < total_usuarios; j++) {
            printf("%-10d", matriz[i][j]);
        }

        printf("\n");
    }
}

void exibir_menu() {
    printf("\n=============================\n");
    printf(" Rede Social - Grafos\n");
    printf("=============================\n");
    printf("1 - Cadastrar usuario\n");
    printf("2 - Adicionar amizade\n");
    printf("3 - Listar usuarios\n");
    printf("4 - Mostrar amizades\n");
    printf("5 - Exibir matriz de adjacencia\n");
    printf("6 - Sair\n");
    printf("=============================\n");
    printf("Escolha uma opcao: ");
}

int main() {
    inicializar();

    int opcao;

    printf("Bem-vindo ao sistema de Rede Social com Grafos!\n");

    do {
        exibir_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_usuario();
                break;
            case 2:
                adicionar_amizade();
                break;
            case 3:
                listar_usuarios();
                break;
            case 4:
                mostrar_amizades();
                break;
            case 5:
                exibir_matriz();
                break;
            case 6:
                printf("Encerrando o programa. Ate logo!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}