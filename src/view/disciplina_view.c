#include "disciplina_view.h"
#include "disciplina_controller.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include <stdlib.h>

Disciplina pedirDadosDisciplina()
{
    Disciplina p;


    lerNome(p.nome);

    return p;
}

int pedirCodigoDisciplina()
{
    printf("Digite a matrícula: ");
    int codigo;
    scanf("%d", &codigo);
    return codigo;
}

void exibirDisciplina(Disciplina p)
{
    for (int i = 0; p.nome[i] != '\0'; i++)
    {
        p.nome[i] = toupper(p.nome[i]);
    }
    

    printf("Codigo: %d | Nome: %s |\n", p.codigo, p.nome);
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


int imprimirMenuRelatorios()
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