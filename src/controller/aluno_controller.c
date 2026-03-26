#include <stdio.h>
#include "aluno_controller.h"
#include "aluno_model.h"
#include "aluno_view.h"
#include "utils.h"

void ModuloAluno()
{
    int sairAluno = 0;
    int opcaoAluno;

    while (!sairAluno)
    {
        opcaoAluno = imprimirMenuAluno();

        switch (opcaoAluno)
        {
        case 0:
        {
            sairAluno = 1;
            break;
        }

        case 1:
        {
            Aluno novoAluno = pedirDadosAluno();

            int resultadoBusca = cadastrarAluno(novoAluno);

            if (resultadoBusca > 0)
            {
                novoAluno.matricula = resultadoBusca;                   
                exibirAluno(novoAluno);
            }

            else if (resultadoBusca == -1)
            {
                mostrarMensagem("Lista de alunos cheia!  ");
            }

            else if (resultadoBusca == 0)
            {
                mostrarMensagem("Já existe um aluno cadastrado com essa matrícula! ");
            }

            else if (resultadoBusca == -2)
            {
                mostrarMensagem("Sexo inválido. ");
            }

            break;
        }

        case 2:
        {
            int quantidade = obterQtdAlunos();

            if (quantidade == 0) {
                mostrarMensagem("Lista de alunos vazia! ");
            }
            else{
                Aluno *listaCompleta = listarAlunos();
                exibirListaAlunos(listaCompleta, quantidade);
            }
            break;
        }
        case 3:
        {
            mostrarMensagem("  --- Atualizar Aluno ---  ");
            int matriculaAntiga = pedirMatricula();

            int matriculaNova = pedirMatricula();

            int resultadoAtualizacao = atualizarAluno(matriculaAntiga, matriculaNova);

            if (resultadoAtualizacao == 1)
            {
                mostrarMensagem("Matrícula atualizada com sucesso! ");
            }

            else if (resultadoAtualizacao == -1)
            {
                mostrarMensagem("Matrícula antiga não encontrada. ");
            }

            else if (resultadoAtualizacao == -2)
            {
                mostrarMensagem("Matrícula nova inválida. ");
            }

            else if (resultadoAtualizacao == 0)
            {
                mostrarMensagem("Já existe um aluno cadastrado com a nova matrícula! ");
            }
            break;
        }

        case 4:
        {
            mostrarMensagem("  --- Excluir matricula de Aluno ---  ");

            int matriculaExcluir = pedirMatricula();

            int resultadoExclusao = excluirAluno(matriculaExcluir);

            if (resultadoExclusao == 1)
            {
                mostrarMensagem("Aluno excluído com sucesso! ");
            }

            else if (resultadoExclusao == -2)
            {
                mostrarMensagem("Matrícula inválida. ");
            }

            else if (resultadoExclusao == -1)
            {
                mostrarMensagem("Matrícula não encontrada. ");
            }
            break;
        }
        }
        if (opcaoAluno != 0) {
            pausarConsole();
        }
    }
}