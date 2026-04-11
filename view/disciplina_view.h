#ifndef DISCIPLINA_VIEW_H
#define DISCIPLINA_VIEW_H

#include "disciplina_model.h"

Disciplina pedirDadosDisciplina();
void exibirDisciplina(Disciplina d);
void exibirListaDisciplinas(Disciplina *lista, int qtd);
int imprimirMenuRelatoriosDisciplina();
void exibirListaDisciplinasAlfabetico(Disciplina *lista, int qtd);
void exibirDadosDiciplina(Disciplina d);
void lerSemestre(char *destino);

#endif