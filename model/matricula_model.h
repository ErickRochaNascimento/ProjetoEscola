#ifndef DICIPLINA_MODEL_H
#define DICIPLINA_MODEL_H
#define TAM_MATRICULA 1000

typedef struct matricula
{
    int matriculaAluno;
    int codigoDisciplina;
    int ativo;
}Matricula;


int cadastrarAlunoDisciplina(Matricula novaMatricula);
int excluirAlunoDisciplina(int matriculaAluno, int codigoDisciplina);
int obterQtdMatricula();
Matricula *listarMatricula();

#endif