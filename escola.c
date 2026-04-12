#include <stdio.h>
#include "aluno_controller.h"
#include "professor_controller.h"
#include "disciplina_controller.h"
#include "utils.h"
#include "matricula_controller.h"


int main()
{
    int opcao;
    int sair = 0;

    while (!sair)
    {
        limparConsole();
        printf("Projeto Escola\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");
        printf("4 - Matricular Aluno em Disciplina\n");
        printf("0 - sair\n");

        opcao = lerOpcao(4);

        switch (opcao)
        {
            case 0:
            {
                sair = 1;
                break;
            }
            
            case 1:
            {
                limparConsole();
                ModuloAluno();
                break;
            }

            case 2:
            {
                limparConsole();
                ModuloProfessor();
                break;
            }

            case 3:
            {
                limparConsole();
                ModuloDisciplina();
                break;
            }
            case 4:{
                limparConsole();
                ModuloMatricula();
            }
            default:
            {
                limparConsole();
                printf("Opção Inválida\n");
            }

        }
    }
    return 0;
}
