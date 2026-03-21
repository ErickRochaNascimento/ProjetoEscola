#ifndef PROFESSOR_VIEW_H
#define PROFESSOR_VIEW_H

#include "professor_model.h"


void exibirMenuProfessor();
Professor pedirDadosProfessor();
int pedirMatriculaProfessor();
void exibirProfessor(Professor p);
void exibirListaProfessores(Professor *lista, int qtd);
void exibirMensagem(const char *mensagem);



#endif
