#include "professor_view.h"
#include <stdio.h>
#include <string.h>
#include "utils.h"


int imprimirMenuProfessor()
{
    printf("\n--- Módulo Professor ---\n");
    printf("0 - Voltar ao menu Principal\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    printf("Escolha uma opção: ");
    int opcaoProfessor = 0;
    scanf("%d", &opcaoProfessor);

    return opcaoProfessor;
}

Professor pedirDadosProfessor()
{
    Professor p;
    printf("Digite o nome: ");
    scanf(" %100[^\n]", p.nome);

    printf("Digite seu sexo (M/F): ");
    scanf(" %c", &p.sexo);

    printf("Digite a data de nascimento: ");
    scanf(" %s", p.dataNascimento);

    printf("Digite o cpf: ");
    scanf(" %s", p.cpf);

    
    return p;
}

int pedirMatriculaProfessor()
{
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    return matricula;
}

void exibirProfessor(Professor p)
{
    printf("Matricula: %d | Nome: %s | Sexo: %c | Data de Nascimento: %s | CPF: %s\n", p.matricula, p.nome, p.sexo, p.dataNascimento, p.cpf);
}

void exibirListaProfessores(Professor *lista, int qtd)
{
     for(int i = 0 ; i < qtd; i++){

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


