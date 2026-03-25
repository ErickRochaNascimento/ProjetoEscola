#include "professor_view.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"


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
    scanf("%s", p.nome);

    printf("Digite a data de nascimento: ");
    scanf("%s", p.dataNascimento);

    printf("Digite o cpf: ");
    scanf("%s", p.cpf);

    printf("Qual o seu sexo (Para masculino digite M e para feminino F): ");
    scanf("%s", p.sexo);
    p.sexo[0] = toupper(p.sexo[0]);
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
    printf("Matricula: %d | Nome: %s | Sexo: %s | Data de Nascimento: %s | CPF: %s\n", p.matricula, p.nome, p.sexo, p.dataNascimento, p.cpf);
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


