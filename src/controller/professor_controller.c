#include "professor_controller.h"
#include "utils.h"
#include <stdio.h>

void ModuloProfessor()
{
    int opcaoProfessor;
    int sairProfessor = 0;

    while (!sairProfessor)
    {
        opcaoProfessor = menuPessoa("Professor");

        switch (opcaoProfessor)
        {
        case 0:
        {
            sairProfessor = 1;
            mostrarMensagem("Voltando ao menu principal...");
            break;
        }
        case 1:
        { // Cadastrar Professor
            mostrarMensagem(" --- Cadastrar Professor --- ");
            Professor novoProfessor = pedirDadosProfessor();
            int resultadoBusca = cadastrarProfessor(novoProfessor);

            if (resultadoBusca > 0)
            {
                novoProfessor.matricula = resultadoBusca;
                mostrarMensagem("Professor cadastrado com sucesso!");
                exibirProfessor(novoProfessor);
            }

            else if (resultadoBusca == -1)
            {
                mostrarMensagem("Lista de professores cheia!");
            }

            else if (resultadoBusca == -2)
            {
                mostrarMensagem("Sexo invalido. ");
            }

            else if (resultadoBusca == 0)
            {
                mostrarMensagem("Já existe um professor cadastrado com essa matrícula! ");
            }

            break;
        }
        case 2:
        { // Listar Professor
            mostrarMensagem(" --- Listar Professor --- ");
            int quantidade = obterQtdProfessor();

            if (quantidade == 0)
            {
                mostrarMensagem("Lista de professores vazia!");
            }
            else
            {
                Professor *listaCompleta = listarProfessor();
                exibirListaProfessores(listaCompleta, quantidade);
            }
            break;
        }
        case 3:
        { // Atualizar Professor
            mostrarMensagem(" --- Atualizar Professor --- ");
            int quantidade = obterQtdProfessor();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Professores Vazia!");
                break;
            }
            int matriculaAntiga = lerMatricula("antiga");
            int matriculaNova = lerMatricula("nova");
            int resultadoAtualizacao = atualizarProfessor(matriculaAntiga, matriculaNova);

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
                mostrarMensagem("Já existe um professor cadastrado com a nova matrícula! ");
            }
            break;
        }
        case 4:
        { // Excluir Professor
            mostrarMensagem(" --- Excluir Professor --- ");
            int quantidade = obterQtdProfessor();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Professores Vazia!");
                break;
            }

            int matriculaExcluir = lerMatricula("a excluir");

            int resultadoExclusao = excluirProfessor(matriculaExcluir);

            if (resultadoExclusao == 1)
            {
                mostrarMensagem("Professor excluído com sucesso!");
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
        case 5:
        { // Relatorios

            int sairMenu = 0;
            int quantidade = obterQtdProfessor();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Professores Vazia!");
                break;
            }

            while (!sairMenu)
            {
                int opcao = imprimirMenuRelatorios();

                switch (opcao)
                {
                case 0:
                {
                    sairMenu = 1;
                    mostrarMensagem("Voltando ao menu principal...");
                    break;
                }
                case 1:
                {
                    char sexoRelatorio = lerSexo(sexoRelatorio);

                    Professor *listaCompleta = listarProfessor();
                    exibirListaProfessoresPorSexo(listaCompleta, quantidade, sexoRelatorio);

                    break;
                }

                default:
                    break;
                }
            }
        }
        default:
        {
            mostrarMensagem("Opção Inválida!");
            break;
        }
        }
    }
}
