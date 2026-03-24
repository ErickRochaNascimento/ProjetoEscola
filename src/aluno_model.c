#include <stdio.h>
#include "aluno_model.h"

Aluno listaAluno[TAM_ALUNO];
int qtdAluno = 0;

int cadastrarAluno(int matricula)
{
    if (qtdAluno == TAM_ALUNO)
        return -1; // Lista de matriculas cheia

    if (matricula < 0)
        return -2; /// Essa matricula é Inválida

    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == 1)
        {
            return 0; // já existe um aluno com essa matrícula
        }
    }

    listaAluno[qtdAluno].matricula = matricula;
    listaAluno[qtdAluno].ativo = 1;
    qtdAluno++;

    return 1; // matriculado com sucesso
}

Aluno *listarAlunos()
{
    return listaAluno;
}

int obterQtdAlunos() {
    return qtdAluno;
}

int atualizarAluno(int matricula_antiga, int matricula_nova)
{
    if (matricula_nova < 0)
        return -2; // matrícula inválida

    for (int i = 0; i < qtdAluno; i++){
        if (listaAluno[i].matricula == matricula_nova && listaAluno[i].ativo == 1){
            return 0; // alguem ja possui essa matricula
        }
    }

    for (int i = 0; i < qtdAluno; i++){
        if(listaAluno[i].matricula == matricula_antiga && listaAluno[i].ativo == 1){
            listaAluno[i].matricula = matricula_nova;
            return 1; // matricula atualizada
        }
    }

    return -1; // matrícula antiga não encontrada
}

int excluirAluno(int matricula)
{
    if (matricula < 0) return -2; // matricula invalida

    for (int i = 0; i < qtdAluno; i++){
        if(matricula == listaAluno[i].matricula && listaAluno[i].ativo){
            for(int j = i; j < qtdAluno - 1; j++){
                listaAluno[j] = listaAluno[j + 1];
            }
            qtdAluno--;
            return 1; // aluno excluido com sucesso
        }
    }
    
    return -1; // matricula não encontrada
}