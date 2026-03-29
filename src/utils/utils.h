#ifndef UTILS_H
#define UTILS_H
#include "data_model.h"

// Declaramos a função genérica para todo mundo usar
void mostrarMensagem(const char* mensagem);
void limparConsole();
int verificarCPF(const char *cpf);
char lerCPF( char *destino);
char lerNome( char *destino);
char lerSexo( char destino);
int verificarSexo(const char sexo);
char lerDataNascimento(Data *dataNascimento);
int verificarData(int d, int m, int a);
#endif