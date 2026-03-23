#ifndef PROFESSOR_VIEW_H
#define PROFESSOR_VIEW_H

#include "../model/professor_model.h"


int exibirMenuProfessor();
Professor pedirDadosProfessor();
int pedirMatriculaProfessor();
void exibirProfessor(Professor p);
void exibirListaProfessores(Professor *lista, int qtd);
void exibirMensagem(const char *mensagem);



#endif
