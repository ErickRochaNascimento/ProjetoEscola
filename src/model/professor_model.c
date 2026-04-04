#include "professor_model.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Professor listaProfessor[TAM_PROFESSOR];
int qtdProfessor = 0;
int geradorMAtriculaProfessor = 1;

int cadastrarProfessor(Professor novoProfessor)
{
    if (qtdProfessor == TAM_PROFESSOR)
    {
        return -1; // Lista sem espaço
    }
    if (novoProfessor.sexo != 'M' && novoProfessor.sexo != 'm' && novoProfessor.sexo != 'F' && novoProfessor.sexo != 'f')
    {
        return -3;
    }

    int matriculaCriada = geradorMAtriculaProfessor;

    listaProfessor[qtdProfessor].matricula = geradorMAtriculaProfessor;
    geradorMAtriculaProfessor++;

    listaProfessor[qtdProfessor].sexo = novoProfessor.sexo;

    strcpy(listaProfessor[qtdProfessor].nome, novoProfessor.nome);

    strcpy(listaProfessor[qtdProfessor].cpf, novoProfessor.cpf);
    listaProfessor[qtdProfessor].dataNascimento.dia = novoProfessor.dataNascimento.dia;
    listaProfessor[qtdProfessor].dataNascimento.mes = novoProfessor.dataNascimento.mes;
    listaProfessor[qtdProfessor].dataNascimento.ano = novoProfessor.dataNascimento.ano;

    listaProfessor[qtdProfessor].ativo = 1;
    qtdProfessor++;

    return matriculaCriada; // matriculado com sucesso
}

Professor *listarProfessor()
{
    Professor *listaOrdenada = obterListaProfessoresAlfabetica();
    return listaOrdenada;
}

int obterQtdProfessor()
{
    return qtdProfessor;
}

int atualizarProfessor(int matricula_antiga, int matricula_nova)
{
    if (matricula_nova < 0)
    {
        return -2; // matrícula inválida
    }
    for (int i = 0; i < qtdProfessor; i++)
    {
        if (matricula_nova == listaProfessor[i].matricula && listaProfessor[i].ativo == 1)
        {
            return 0; // alguem ja possui essa matricula
        }
    }

    for (int i = 0; i < qtdProfessor; i++)
    {
        if (matricula_antiga == listaProfessor[i].matricula && listaProfessor[i].ativo == 1)
        {
            listaProfessor[i].matricula = matricula_nova;
            return 1; // Matricula atualizada
        }
    }

    return -1; // Matricula antiga não encontrada
}

int excluirProfessor(int matricula)
{
    if (matricula < 0)
        return -2; // Matricula invalida

    for (int i = 0; i < qtdProfessor; i++)
    {
        if (matricula == listaProfessor[i].matricula && listaProfessor[i].ativo)
        {
            for (int j = i; j < qtdProfessor - 1; j++)
            {
                listaProfessor[j] = listaProfessor[j + 1];
            }
            qtdProfessor--;
            return 1; // Professor excluido com sucesso
        }
    }
    return -1; // matricula não encontrada
}

Professor* obterListaProfessoresAlfabetica()
{
    int qtd = qtdProfessor;

    // Criamos a cópia da lista dinamicamente usando malloc
    Professor *listaOrdenada = malloc(qtd * sizeof(Professor));
    
    if (listaOrdenada == NULL) {
        return NULL; 
    }

    // Copiando os dados da lista original para a nova
    for (int i = 0; i < qtd; i++)
    {
        listaOrdenada[i] = listaProfessor[i];
    }

    for (int i = 0; i < qtd; i++)
    {
        for (int j = i + 1; j < qtd; j++)
        {
            if (listaOrdenada[i].ativo == 1 && listaOrdenada[j].ativo == 1)
            {
                if (strcmp(listaOrdenada[i].nome, listaOrdenada[j].nome) > 0)
                {
                    Professor aux = listaOrdenada[i];
                    listaOrdenada[i] = listaOrdenada[j];
                    listaOrdenada[j] = aux;
                }
            }
        }
    }
        return listaOrdenada;
}