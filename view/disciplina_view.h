#ifndef DISCIPLINA_VIEW_H
#define DISCIPLINA_VIEW_H

#include "disciplina_model.h"

Disciplina pedirDadosDisciplina();
int pedirCodigoDisciplina();
void exibirDisciplina(Disciplina p);
void exibirListaDisciplinas(Disciplina *lista, int qtd);
int imprimirMenuRelatoriosDisciplina();
void exibirListaDisciplinasAlfabetico(Disciplina *lista, int qtd);

#endif