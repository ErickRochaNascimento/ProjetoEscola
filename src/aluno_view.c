#include <stdio.h>
#include "aluno_view.h"

int imprimirMenuAluno()
{
    int opcaoAluno;
    printf("0 - Voltar ao menu Principal\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");
    scanf("%d", &opcaoAluno);

    return opcaoAluno;
}

void mostrarMensagem(char* mensagem) {
    printf("%s\n", mensagem); 
}

void exibirListaAlunos(Aluno* lista, int quantidade){
    printf("\n ----- Lista de Alunos ----- \n");
    for(int i = 0 ; i < quantidade; i++){
        if(lista[i].ativo == 1){
            printf("Matricula: %d | Nome: %s | Sexo: %c | Data de Nascimento: %s | CPF: %s\n", lista[i].matricula, lista[i].nome, lista[i].sexo, lista[i].dataNascimento, lista[i].cpf);
        }
    }
    printf("----------------------------\n");
}

int pedirMatricula() {
    int matricula;
    printf("\nDigite a matrícula: ");
    scanf("%d", &matricula);
    return matricula;
}