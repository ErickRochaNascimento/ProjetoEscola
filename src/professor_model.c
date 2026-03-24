#include "professor_model.h"

Professor listaProfessor[TAM_PROFESSOR];
int qtdProfessor = 0;

int cadastrarProfessor(int matricula)
{
    if (qtdProfessor == TAM_PROFESSOR)
    {
        return -1; // Lista sem espaço
    }
    if (matricula < 0)
    {
        return -2;
    }
    for (int i = 0; i < qtdProfessor; i++)
    {
        if (listaProfessor[i].matricula == matricula && listaProfessor[1].ativo == 1)
        {
            return -2;
        }
    }
    listaProfessor[qtdProfessor].matricula = matricula;
    listaProfessor[qtdProfessor].ativo = 1;
    qtdProfessor++;

    return 1;
}

int atualizarProfessor(int matriculaAntiga, Professor novoProfessor)
{
    for (int i = 0; i < qtdProfessor; i++)
    {
        if (matriculaAntiga == listaProfessor[i].matricula && listaProfessor[i].ativo == 1)
        {
            listaProfessor[i].matricula = novoProfessor.matricula;
            return 1;
        }
    }
    return 0;
}

int excluirProfessor(int matricula)
{
    for (int i = 0; i < qtdProfessor; i++)
    {
        if (matricula == listaProfessor[i].matricula && listaProfessor[i].ativo == 1)
        {
            listaProfessor[i].ativo = -1;

            for (int j = i; j < qtdProfessor - 1; j++)
            {
                listaProfessor[j].matricula = listaProfessor[j + 1].matricula;
                listaProfessor[j].sexo = listaProfessor[j + 1].sexo;
                listaProfessor[j].ativo = listaProfessor[j + 1].ativo;
                listaProfessor[j].nome = listaProfessor[j + 1].nome;
                listaProfessor[j].dataNascimento = listaProfessor[j + 1].dataNascimento;
            }
            qtdProfessor--;
            return 1;
        }
    }
    return 0;
}

    void listarProfessor(Professor *lista, int *qtd){
        *qtd = qtdProfessor;
        for (int i = 0; i < qtdProfessor; i++)
        {
            lista[i] = listaProfessor[i];
        }
        
    }