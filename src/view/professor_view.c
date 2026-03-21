#include "professor_view.h"
#include <stdio.h>

int exibirMenuProfessor()
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
    printf("Digite o nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    printf("Digite a data de nascimento: ");
    fgets(p.dataNascimento, sizeof(p.dataNascimento), stdin);
    printf("Digite o cpf: ");
    fgets(p.cpf, sizeof(p.cpf), stdin);
    printf("Digite a sexo: ");
    fgets(p.sexo, sizeof(p.sexo), stdin);
    return p;
}

void pedirMatriculaCadastroProfessor()
{
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    return matricula;
}

void exibirProfessor(Professor p)
{
    printf("Matricula: %d\n", p.matricula);
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

void exibirMensagem(const char *mensagem)
{
    printf("%s\n", mensagem);
}