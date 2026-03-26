#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Escrevemos a função uma única vez aqui!
void mostrarMensagem(const char* mensagem) {
    printf("%s\n", mensagem); 
}

void limparConsole(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}