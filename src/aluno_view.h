#include <stdio.h>

#ifndef ALUNO_VIEW_H
#define ALUNO_VIEW_H

#include "aluno_model.h"

int imprimirMenuAluno();
void mostrarMensagem(char* mensagem);
void exibirListaAlunos(Aluno* lista, int qtd);
int pedirMatricula();

#endif
