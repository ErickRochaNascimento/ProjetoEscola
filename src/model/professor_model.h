#ifndef PROFESSOR_MODEL_H
#define PROFESSOR_MODEL_H

#define TAM_PROFESSOR 3

typedef struct professor
{
    int matricula;
    char nome;
    char dataNascimento;
    char cpf;
    char sexo;
    int ativo;
} Professor;

int cadastrarProfessor(int matricula);
int atualizarProfessor(int matriculaAntiga, Professor novoProfessor);
int excluirProfessor(int matricula);
int listarProfessor(Professor lista, int qtd);

#endif