#include <stdio.h>
#include "aluno_model.h"
#include <string.h>

Aluno listaAluno[TAM_ALUNO];
int qtdAluno = 0;

int cadastrarAluno(Aluno novoAluno)
{
    if (qtdAluno == TAM_ALUNO)
        return -1; 

    if (novoAluno.matricula < 0)
        return -2;

    for (int i = 0; i < qtdAluno; i++)
    {
        if (listaAluno[i].matricula == novoAluno.matricula && listaAluno[i].ativo == 1)
        {
            return 0;
        }
    }
    if(novoAluno.sexo != 'M' && novoAluno.sexo != 'm' && novoAluno.sexo != 'F' && novoAluno.sexo != 'f'){
        return -3;
    }
    


    listaAluno[qtdAluno].matricula = novoAluno.matricula;
    listaAluno[qtdAluno].sexo = novoAluno.sexo;
    strcpy(listaAluno[qtdAluno].nome, novoAluno.nome);
    strcpy(listaAluno[qtdAluno].dataNascimento, novoAluno.dataNascimento);
    strcpy(listaAluno[qtdAluno].cpf, novoAluno.cpf);
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