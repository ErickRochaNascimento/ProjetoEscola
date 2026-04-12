#include "professor_view.h"
#include "professor_controller.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include "data_model.h"
#include <stdlib.h>

Professor pedirDadosProfessor()
{
    Professor p;
    lerNome(p.nome);

    p.sexo = lerSexo(p.sexo);

    lerCPF(p.cpf);

    lerDataNascimento(&p.dataNascimento);

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
    for (int i = 0; p.nome[i] != '\0'; i++)
    {
        p.nome[i] = toupper(p.nome[i]);
    }
    

    printf("Matricula: %d | Nome: %s | Sexo: %c | Data de Nascimento:  %02d/%02d/%04d | CPF: %s \n", p.matricula, p.nome, toupper(p.sexo), p.dataNascimento.dia, p.dataNascimento.mes, p.dataNascimento.ano,
           p.cpf);
}

void exibirListaProfessores(Professor *lista, int qtd)
{
    printf("\n ----- Lista de Professores ----- \n");
    for (int i = 0; i < qtd; i++)
    {
        if (lista[i].ativo == 1)
        {
            exibirProfessor(lista[i]);
        }
    }
    printf("----------------------------\n");
}

void exibirListaProfessoresPorSexo(Professor *lista, int qtd, char sexoFiltro)
{
    for (int i = 0; i < qtd; i++)
    {

        if (lista[i].ativo == 1 && lista[i].sexo == sexoFiltro)
        {
            exibirProfessor(lista[i]);
        }
    }
    printf("----------------------------\n");
}

int imprimirMenuRelatoriosProfessor()
{
    limparConsole();
    printf("---  Relatorios  ---\n");
    printf("0 - Voltar ao menu Principal \n");
    printf("1 - Imprimir por Sexo\n");
    printf("2 - Imprimir em ordem alfabetica\n");
    printf("3 - Imprimir por data de nascimento\n");
    return lerOpcao(3);
}

void exibirListaProfessoresAlfabetico(Professor *lista, int qtd)
{
    Professor *listaOrdenadaAlfabetica = listarProfessor(); 
    
    for (int i = 0; i < qtd; i++)
    {
        if (listaOrdenadaAlfabetica[i].ativo == 1)
        {
            exibirProfessor(listaOrdenadaAlfabetica[i]);
        }
    }
    printf("----------------------------\n");
    free(listaOrdenadaAlfabetica);
}

void exibirListaProfessoresPorNascimento(Professor *lista, int qtd)
{
    Professor listaOrdenada[100];
    for (int i = 0; i < qtd; i++)
    {
        listaOrdenada[i] = lista[i];
    }
    for (int i = 0; i < qtd; i++)
    {
        for (int j = i + 1; j < qtd; j++)
        {
            if (listaOrdenada[i].ativo == 1 && listaOrdenada[j].ativo == 1)
            {
                if ((listaOrdenada[i].dataNascimento.ano > listaOrdenada[j].dataNascimento.ano) || (listaOrdenada[i].dataNascimento.ano == listaOrdenada[j].dataNascimento.ano && listaOrdenada[i].dataNascimento.mes > listaOrdenada[j].dataNascimento.mes) || (listaOrdenada[i].dataNascimento.ano == listaOrdenada[j].dataNascimento.ano && listaOrdenada[i].dataNascimento.mes == listaOrdenada[j].dataNascimento.mes && listaOrdenada[i].dataNascimento.dia > listaOrdenada[j].dataNascimento.dia))
                {
                    Professor aux;
                    aux = listaOrdenada[i];
                    listaOrdenada[i] = listaOrdenada[j];
                    listaOrdenada[j] = aux;
                }
            }
        }
    }
    for (int i = 0; i < qtd; i++)
    {

        if (listaOrdenada[i].ativo == 1)
        {
            exibirProfessor(listaOrdenada[i]);
        }
    }
    printf("----------------------------\n");
}
