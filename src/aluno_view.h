#include <stdio.h>

#ifndef ALUNO_VIEW_H
#define ALUNO_VIEW_H

#include "aluno_model.h"

int imprimirMenuAluno();
void mostrarMensagem(char* mensagem);
void exibirListaAlunos(Aluno* lista, int qtd);
Aluno pedirDadosAluno();
int pedirMatricula();
void mostrarMatriculaGerada(int matricula);

#endif
