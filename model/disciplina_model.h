#ifndef DICIPLINA_MODEL_H
#define DICIPLINA_MODEL_H

#define TAM_DISCIPLINA 3
#define TAM_NOME 100
#define TAM_SEMESTRE 8

typedef struct disciplina
{
    int codigo;
    char nome[TAM_NOME];
    char semestre[TAM_SEMESTRE];
    int ativo;
    int matricula_professor;
} Disciplina;

int cadastrarDisciplina(Disciplina novaDisciplina);
int excluirDisciplina(int codigo);
Disciplina *listarDisciplina();
int obterQtdDisciplina();
int atualizarDisciplina(int codigo_antigo, int codigo_novo);
Disciplina* obterListaDisciplinasAlfabetica();


#endif