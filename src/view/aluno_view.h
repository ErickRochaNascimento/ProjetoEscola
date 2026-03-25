#include <stdio.h>

#ifndef ALUNO_VIEW_H
#define ALUNO_VIEW_H

#include "aluno_model.h"

int imprimirMenuAluno();
void exibirListaAlunos(Aluno* lista, int qtd);
Aluno pedirDadosAluno();
int pedirMatricula();
void exibirAluno(Aluno aluno);

#endif
