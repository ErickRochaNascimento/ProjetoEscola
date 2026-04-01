#ifndef PROFESSOR_VIEW_H
#define PROFESSOR_VIEW_H

#include "professor_model.h"

Professor pedirDadosProfessor();
int pedirMatriculaProfessor();
void exibirProfessor(Professor p);
void exibirListaProfessores(Professor *lista, int qtd);
int imprimirMenuRelatorios();
void exibirListaProfessoresPorSexo(Professor *lista, int qtd, char sexoFiltro);
void exibirListaProfessoresAlfabetico(Professor *lista, int qtd);

#endif