#ifndef ALUNO_MODEL_H
#define ALUNO_MODEL_H

#define TAM_ALUNO 3

typedef struct {
    int matricula;
    char sexo;
    int ativo;
} Aluno;


int cadastrarAluno(int matricula);

#endif