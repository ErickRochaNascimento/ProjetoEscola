#include "professor_view.h"
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "data_model.h"

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
    lerNome(p.nome);

    printf("Digite seu sexo (M/F): ");
    scanf(" %c", &p.sexo);

    lerCPF(p.cpf);

    printf("Digite o dia de nascimento: ");
    scanf("%d", &p.dataNascimento.dia);

    printf("Digite o mêS de nascimento: ");
    scanf("%d", &p.dataNascimento.mes);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &p.dataNascimento.ano);

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
    printf("Matricula: %d | Nome: %s | Sexo: %c | Data de Nascimento:  %02d/%02d/%04d | CPF: %s\n", p.matricula, p.nome, p.sexo,
         p.cpf, p.dataNascimento.dia, p.dataNascimento.mes, p.dataNascimento.ano);
}

void exibirListaProfessores(Professor *lista, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {

        if (lista[i].ativo == 1)
        {
            char *palavraSexo;

            if (lista[i].sexo == 'M' || lista[i].sexo == 'm')
            {
                palavraSexo = "Masculino";
            }

            else if (lista[i].sexo == 'F' || lista[i].sexo == 'f')
            {
                palavraSexo = "Feminino";
            }

            else
            {
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
