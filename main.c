#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa
{
    char nome[50];
    char telefone[15];
    struct Pessoa *prox;
} Pessoa;

int menu()
{
    int op;
    printf(
        "1) Adicionar Pessoa\n"
        "2) Exibir Agenda\n"
        "3) Atualizar Pessoa\n"
        "4) Excluir Pessoa\n"
        "5) Sair\n"
        "Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

void inserirPessoa(Pessoa **inicio, char nome[], char telefone[])
{
    Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
    novo->prox = *inicio;
    *inicio = novo;
}

void exibirAgenda(Pessoa *inicio)
{
    printf("Agenda Telefônica:\n");
    while (inicio != NULL)
    {
        printf("Nome: %s, Telefone: %s\n", inicio->nome, inicio->telefone);
        inicio = inicio->prox;
    }
}

void atualizarPessoa(Pessoa *inicio, char nome[], char novoTelefone[])
{
    Pessoa *p = inicio;
    while (p != NULL)
    {
        if (strcmp(p->nome, nome) == 0)
        {
            strcpy(p->telefone, novoTelefone);
            printf("Informações atualizadas com sucesso.\n");
            return;
        }
        p = p->prox;
    }
    printf("Pessoa não encontrada na agenda.\n");
}

void excluirPessoa(Pessoa **inicio, char nome[])
{
    Pessoa *p = *inicio;
    Pessoa *anterior = NULL;

    while (p != NULL)
    {
        if (strcmp(p->nome, nome) == 0)
        {
            if (anterior == NULL)
            {
                *inicio = p->prox;
            }
            else
            {
                anterior->prox = p->prox;
            }
            free(p);
            printf("Pessoa excluída com sucesso.\n");
            return;
        }
        anterior = p;
        p = p->prox;
    }
    printf("Pessoa não encontrada na agenda.\n");
}

int main()
{
    Pessoa *agenda = NULL; // Inicializa a agenda como vazia
    int op;
    char nome[50];
    char telefone[15];
    char novoTelefone[15];

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Digite o nome: ");
            scanf("%s", nome);
            printf("Digite o telefone: ");
            scanf("%s", telefone);
            inserirPessoa(&agenda, nome, telefone);
            break;
        case 2:
            exibirAgenda(agenda);
            break;
        case 3:
            printf("Digite o nome da pessoa que deseja atualizar: ");
            scanf("%s", nome);
            printf("Digite o novo telefone: ");
            scanf("%s", novoTelefone);
            atualizarPessoa(agenda, nome, novoTelefone);
            break;
        case 4:
            printf("Digite o nome da pessoa que deseja excluir: ");
            scanf("%s", nome);
            excluirPessoa(&agenda, nome);
            break;
        case 5:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (op != 5);

    return 0;
}