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

void pausarConsole() {
    printf("\nPressione qualquer tecla para continuar...\n");
    system("pause");
}

int menuPessoa(const char* tipoPessoa) {

    limparConsole();    
    int opcaoPessoa;
    printf("---- Modulo %s ----\n", tipoPessoa);
    printf("\n0 - Voltar ao menu Principal \n");
    printf("1 - Cadastrar %s\n", tipoPessoa);
    printf("2 - Listar %s\n", tipoPessoa);
    printf("3 - Atualizar %s\n", tipoPessoa);
    printf("4 - Excluir %s\n", tipoPessoa);
    scanf("%d", &opcaoPessoa);

    return opcaoPessoa;
}
