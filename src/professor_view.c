#include "professor_view.h"
#include <stdio.h>

int imprimirMenuProfessor()
{
    printf("\n--- Módulo Professor ---\n");
    printf("0 - Voltar ao menu Principal\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    printf("Escolha uma opção: ");
    int opcaoProfessor = 0;
    scanf("%d", &opcaoProfessor);

    return opcaoProfessor;
}

Professor pedirDadosProfessor()
{
    Professor p;
    printf("Digite a matrícula: ");
    scanf("%d", &p.matricula);

    getchar(); // Limpar o buffer do teclado antes de usar o fgets!

    printf("Digite o nome: ");
    fgets(p.nome, TAM_NOME, stdin);
    //p.nome[strcspn(p.nome, "\n")] = 0; // Remover o 'Enter' (\n) que o fgets salva no final do nome

    printf("Digite a data de nascimento: ");
    scanf("%s", p.dataNascimento);

    printf("Digite o cpf: ");
    scanf("%s", p.cpf);

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &p.sexo);
    return p;
}

int pedirMatriculaProfessor()
{
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    return matricula;
}

void exibirProfessor(Professor p)
{
    printf("Matricula: %d | Nome: %s | Sexo: %c | Data de Nascimento: %s | CPF: %s\n", p.matricula, p.nome, p.sexo, p.dataNascimento, p.cpf);
}

void exibirListaProfessores(Professor *lista, int qtd)
{
    if (qtd == 0)
    {
        printf("Lista de professores vazia.\n");
        return;
    }
    printf("\n--- Lista de Professores ---\n");
    for (int i = 0; i < qtd; i++)
    {
        if (lista[i].ativo == 1)
        {
            exibirProfessor(lista[i]);
        }
    }
    printf("----------------------------\n");
}

void mostrarMensagem(const char *mensagem)
{
    printf("%s\n", mensagem);
}
