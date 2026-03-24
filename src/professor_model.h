#ifndef PROFESSOR_MODEL_H
#define PROFESSOR_MODEL_H

#define TAM_PROFESSOR 3
#define TAM_DATANASCIMENTO 12
#define TAM_CPF 16
#define TAM_NOME 50

typedef struct professor
{
    int matricula;
    char nome[TAM_NOME];
    char dataNascimento[TAM_DATANASCIMENTO];
    char cpf[TAM_CPF];
    char sexo;
    int ativo;
} Professor;

int cadastrarProfessor(int matricula, char *nome, char *dataNasciemento, char *cpf, char sexo);
int excluirProfessor(int matricula);
Professor *listarProfessor();
int obterQtdProfessor();
int atualizarProfessor(int matricula_antiga, int matricula_nova);

#endif