#include <stdio.h>
#include "aluno_view.h"
#include <string.h>
#include "utils.h"

void exibirListaAlunos(Aluno* lista, int quantidade){
    limparConsole();
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

            printf("Matricula: %d | Nome: %s | Sexo: %s | Data de Nascimento: %02d/%02d/%04d | CPF: %s\n", 
            lista[i].matricula, 
            lista[i].nome, 
            palavraSexo,         
            lista[i].dataNascimento.dia,
            lista[i].dataNascimento.mes,
            lista[i].dataNascimento.ano,
            lista[i].cpf);
        }

    }
    printf("----------------------------\n");
}

Aluno pedirDadosAluno() {
    Aluno aluno;

    limparConsole();
    printf("\n--- Cadastrar Aluno ---\n");
    lerNome(aluno.nome);
    aluno.sexo = lerSexo(aluno.sexo);
    lerDataNascimento(&aluno.dataNascimento);
    lerCPF(aluno.cpf);

    return aluno;
}

int pedirMatricula(const char* tipoMatricula){
    limparConsole();
    int matricula;
    printf("\nDigite a matricula %s: ", tipoMatricula);
    scanf("%d", &matricula);
    return matricula;
}

void exibirAluno(Aluno aluno){
    limparConsole();
    printf("\nCadastrado com sucesso! Segue os dados:\n");
    printf("\nMatricula: %d | Nome: %s | Sexo: %c | Data de Nascimento: %02d/%02d/%04d | CPF: %s\n", 
           aluno.matricula, 
           aluno.nome, 
           aluno.sexo, 
           aluno.dataNascimento.dia,
           aluno.dataNascimento.mes,
           aluno.dataNascimento.ano,
           aluno.cpf);
}