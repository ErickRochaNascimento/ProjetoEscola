#include <stdio.h>
#include "aluno_view.h"
#include <string.h>

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
            char* palavraSexo;

            if (lista[i].sexo == 'M' || lista[i].sexo == 'm') {
                palavraSexo = "Masculino";
            } 

            else if (lista[i].sexo == 'F' || lista[i].sexo == 'f') {
                palavraSexo = "Feminino";
            } 

            else {
                palavraSexo = "Não Informado"; 
            }

            printf("Matricula: %d | Nome: %s | Sexo: %s | Data de Nascimento: %s | CPF: %s\n", 
            lista[i].matricula, 
            lista[i].nome, 
            palavraSexo,         
            lista[i].dataNascimento, 
            lista[i].cpf);
        }

    }
    printf("----------------------------\n");
}

Aluno pedirDadosAluno() {
    Aluno aluno;

    printf("Digite seu nome: ");
    scanf(" %100[^\n]", aluno.nome);  // Sem '&'. O %[^\n] permite ler nomes com espaço!

    printf("Digite seu sexo (M/F): ");
    scanf(" %c", &aluno.sexo);     // Tem '&' porque é apenas um char

    printf("Digite sua data de nascimento: ");
    scanf(" %s", aluno.dataNascimento); // Sem '&' porque é string (vetor)

    printf("Digite seu CPF: ");
    scanf(" %s", aluno.cpf); // Sem '&' porque é string (vetor)

    return aluno;
}

int pedirMatricula() {
    int matricula;
    printf("\nDigite a matricula: ");
    scanf("%d", &matricula);
    return matricula;
}

void mostrarMatriculaGerada(int matricula) {
    printf("Aluno cadastrado com sucesso! A matrícula gerada foi: %d\n", matricula);
}