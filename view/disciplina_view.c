#include "disciplina_view.h"
#include "disciplina_controller.h"
#include "professor_model.h"
#include "matricula_model.h"
#include "aluno_model.h"
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
    d.matricula_professor = lerMatriculaWhile("a matricula do professor da disciplina", 2);

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

void exibirAlunosDisciplina(int codigoDisciplina)
{
    Aluno *listaAluno = listarAlunos();
    Disciplina *listaDisciplina = listarDisciplina();
    Matricula *listaMatricula = listarMatricula();

    int qtdDisciplinas = obterQtdDisciplina();
    int qtdAlunos = obterQtdAlunos();
    int qtdMatriculas = obterQtdMatricula(); 

    int indiceDisciplina = -1;

    for (int i = 0; i < qtdDisciplinas; i++)
    {
        if (listaDisciplina[i].codigo == codigoDisciplina && listaDisciplina[i].ativo == 1)
        {
            indiceDisciplina = i;
            break;
        }
    }

    if (indiceDisciplina == -1)
    {
        printf("Erro: Disciplina nao encontrada!\n");
        return;
    }

    printf("\n--- Alunos da Disciplina: %s | Codigo: %d ---\n", listaDisciplina[indiceDisciplina].nome, listaDisciplina[indiceDisciplina].codigo);

    int contadorAlunos = 0; 

    for (int i = 0; i < qtdMatriculas; i++)
    {
        if (listaMatricula[i].codigoDisciplina == codigoDisciplina && listaMatricula[i].ativo == 1)
        {
            for (int j = 0; j < qtdAlunos; j++)
            {
                if (listaAluno[j].matricula == listaMatricula[i].matriculaAluno && listaAluno[j].ativo == 1)
                {
                    printf("Matricula: %d | Nome: %s\n", listaAluno[j].matricula, listaAluno[j].nome);
                    contadorAlunos++;
                    break; 
                }
            }
        }
    }

    if (contadorAlunos == 0)
    {
        printf("Nenhum aluno matriculado nesta disciplina ainda.\n");
    }
    printf("-----------------------------------\n");
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
    printf("---  Relatorios  ---\n");
    printf("0 - Voltar ao menu Principal \n");
    printf("2 - Imprimir em ordem alfabetica\n");
    printf("3 - Imprimir disciplina com alunos\n");
    return lerOpcao(3);
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