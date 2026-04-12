#include "professor_model.h"
#include "utils.h"
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
    if(!strcmp(novoProfessor.cpf,"0")|| novoProfessor.sexo == '0'  || novoProfessor.dataNascimento.dia == 0 || novoProfessor.dataNascimento.mes == 0 || novoProfessor.dataNascimento.ano == 0){
        return -2;
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
        if (verificarMatricula(matricula_nova, 2))
        {
            return 0; // alguem ja possui essa matricula
        }
    }

    for (int i = 0; i < qtdProfessor; i++)
    {
        if (verificarMatricula(matricula_antiga, 2))
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
        if (verificarMatricula(matricula, 2))
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

    Professor *listaOrdenada = malloc(qtd * sizeof(Professor));
    
    if (listaOrdenada == NULL) {
        return NULL; 
    }

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