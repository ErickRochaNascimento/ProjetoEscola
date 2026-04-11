#include "disciplina_view.h"
#include "disciplina_controller.h"
#include "professor_model.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include <stdlib.h>

Disciplina pedirDadosDisciplina()
{
    Disciplina d;

    lerNome(d.nome);
    lerSemestre(d.semestre);
    d.matricula_professor = lerMatriculaParaDisciplina("do professor da diciplina");

    return d;
}

void exibirDisciplina(Disciplina d)
{
    for (int i = 0; d.nome[i] != '\0'; i++)
    {
        d.nome[i] = toupper(d.nome[i]);
    }

    Professor *lista = listarProfessor();
    int qtd = obterQtdProfessor();
    for (int i = 0; i < qtd; i++)
    {
        if (lista[i].matricula == d.matricula_professor && lista[i].ativo == 1)
        {
            printf("Codigo: %d | Nome: %s | Semestre: %s | Professor Matricula: %d | Nome: %s\n", d.codigo, d.nome, d.semestre, d.matricula_professor, lista[i].nome);
        }
    }
}

void exibirDadosDiciplina(Disciplina d)
{
}

void exibirListaDisciplinas(Disciplina *lista, int qtd)
{
    printf("\n ----- Lista de Disciplinas ----- \n");
    for (int i = 0; i < qtd; i++)
    {
        if (lista[i].ativo == 1)
        {
            exibirDisciplina(lista[i]);
        }
    }
    printf("----------------------------\n");
}

int imprimirMenuRelatoriosDisciplina()
{
    limparConsole();
    int opcao;
    printf("---  Relatorios  ---\n");
    printf("0 - Voltar ao menu Principal \n");
    printf("2 - Imprimir em ordem alfabetica\n");
    scanf("%d", &opcao);
    return opcao;
}

void exibirListaDisciplinasAlfabetico(Disciplina *lista, int qtd)
{
    Disciplina *listaOrdenadaAlfabetica = listarDisciplina();

    for (int i = 0; i < qtd; i++)
    {
        if (listaOrdenadaAlfabetica[i].ativo == 1)
        {
            exibirDisciplina(listaOrdenadaAlfabetica[i]);
        }
    }
    printf("----------------------------\n");
    free(listaOrdenadaAlfabetica);
}

void lerSemestre(char *destino)
{
    while (1)
    {
        printf("Digite 0 para sair.\nDigite o semestre (ex: 2024.1): ");
        scanf("%s", destino);
        getchar();

        if (!strcmp(destino, "0"))
        {
            break;
        }

        if (verificarSemestre(destino) == 1)
        {
            break; 
        }
        else
        {
            printf("Semestre invalido! Use o formato correto (ex: 2024.1 ou 2023.2).\n\n");
        }
    }
}