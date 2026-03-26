#ifndef PROFESSOR_VIEW_H
#define PROFESSOR_VIEW_H

#include "professor_model.h"

int imprimirMenuProfessor();
Professor pedirDadosProfessor();
int pedirMatriculaProfessor();
void exibirProfessor(Professor p);
void exibirListaProfessores(Professor *lista, int qtd);

#endif