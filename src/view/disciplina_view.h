#ifndef DISCIPLINA_VIEW_H
#define DISCIPLINA_VIEW_H

#include "disciplina_model.h"

Disciplina pedirDadosDisciplina();
int pedirCodigoDisciplina();
void exibirDisciplina(Disciplina p);
void exibirListaDisciplinas(Disciplina *lista, int qtd);
int imprimirMenuRelatorios();
void exibirListaDisciplinasAlfabetico(Disciplina *lista, int qtd);

#endif