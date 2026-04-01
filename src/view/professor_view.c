#include "professor_view.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include "data_model.h"

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
    for (int i = 0; i < qtd; i++)
    {

        if (lista[i].ativo == 1)
        {
            char *palavraSexo;

            if (lista[i].sexo == 'M' || lista[i].sexo == 'm')
            {
                palavraSexo = "Masculino";
            }

            else if (lista[i].sexo == 'F' || lista[i].sexo == 'f')
            {
                palavraSexo = "Feminino";
            }

            else
            {
                palavraSexo = "Não Informado";
            }

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

int imprimirMenuRelatorios()
{
    limparConsole();
    int opcao;
    printf("---  Relatorios  ---\n");
    printf("0 - Voltar ao menu Principal \n");
    printf("1 - Imprimir por Sexo\n");
    printf("2 - Imprimir em ordem alfabetica\n");
    scanf("%d", &opcao);
    return opcao;
}

void exibirListaProfessoresAlfabetico(Professor *lista, int qtd)
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
                if (strcmp(listaOrdenada[i].nome, listaOrdenada[j].nome) > 0)
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
