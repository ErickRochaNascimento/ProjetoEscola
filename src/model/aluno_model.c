#include "aluno_model.h"

Aluno listaAluno[TAM_ALUNO];
int qtdAluno = 0;

int cadastrarAluno(int matricula)
{
    if (qtdAluno == TAM_ALUNO)
    {
        return -1;
    }
    if (matricula < 0)
    {
        return -2;
    }
    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == 1)
        {
            return 0;
        }
    }
    listaAluno[qtdAluno].matricula = matricula;
    listaAluno[qtdAluno].ativo = 1;
    qtdAluno++; 

    return 1; 
}