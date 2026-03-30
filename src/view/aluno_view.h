#include <stdio.h>

#ifndef ALUNO_VIEW_H
#define ALUNO_VIEW_H

#include "aluno_model.h"

void exibirListaAlunos(Aluno* lista, int qtd);
Aluno pedirDadosAluno();
int pedirMatricula(const char* tipoMatricula);
void exibirAluno(Aluno aluno);

#endif
