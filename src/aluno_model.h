#include <stdio.h>

#ifndef ALUNO_MODEL_H
#define ALUNO_MODEL_H
#define TAMANHO_NOME 50
#define TAMANHO_DATA 11
#define TAMANHO_CPF 15
#define TAM_ALUNO 3

typedef struct aluno
{
    int matricula;
    char nome [TAMANHO_NOME];
    char sexo;
    char dataNascimento [TAMANHO_DATA];
    char cpf [TAMANHO_CPF];
    int ativo;
} Aluno;



int cadastrarAluno(int matricula);
int atualizarAluno(int matricula_antiga, int matricula_nova);
int excluirAluno(int matricula);
Aluno* listarAlunos();
int obterQtdAlunos();

#endif