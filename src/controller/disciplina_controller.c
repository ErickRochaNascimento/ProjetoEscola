#include "disciplina_controller.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void ModuloDisciplina()
{
    int opcaoDisciplina;
    int sairDisciplina = 0;

    while (!sairDisciplina)
    {
        opcaoDisciplina = menuPessoa("Disciplina");

        switch (opcaoDisciplina)
        {
        case 0:
        {
            sairDisciplina = 1;
            mostrarMensagem("Voltando ao menu principal...");
            break;
        }
        case 1:
        { // Cadastrar Disciplina
            mostrarMensagem(" --- Cadastrar Disciplina --- ");
            Disciplina novaDisciplina = pedirDadosDisciplina();
            int resultadoBusca = cadastrarDisciplina(novaDisciplina);

            if (resultadoBusca > 0)
            {
                novaDisciplina.codigo = resultadoBusca;
                mostrarMensagem("Disciplina cadastrada com sucesso!");
                exibirDisciplina(novaDisciplina);
                pausarConsole();
            }

            else if (resultadoBusca == -1)
            {
                mostrarMensagem("Lista de Disciplinas cheia!");
            }

            else if (resultadoBusca == 0)
            {
                mostrarMensagem("Já existe uma Disciplina cadastrada com essa disciplina! ");
            }

            break;
        }
        case 2:
        { // Listar Disciplina
            mostrarMensagem(" --- Listar Disciplina --- ");
            int quantidade = obterQtdDisciplina();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Disciplinas Vazia!\nPrimeiro cadastre uma Disciplina.\n");
                pausarConsole();
                break;
            }
            else
            {
                Disciplina *listaCompleta = listarDisciplina();
                exibirListaDisciplinas(listaCompleta, quantidade);
                free(listaCompleta);
                pausarConsole();
            }
            break;
        }
        case 3:
        { // Atualizar Disciplina
            mostrarMensagem(" --- Atualizar Disciplina --- ");
            int quantidade = obterQtdDisciplina();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Disciplinas Vazia!\nPrimeiro cadastre uma Disciplina.\n");
                pausarConsole();
                break;
            }
            int codigoAntigo = lercodigo("antiga");
            int codigoNovo = lercodigo("nova");
            int resultadoAtualizacao = atualizarDisciplina(codigoAntigo, codigoNovo);

            if (resultadoAtualizacao == 1)
            {
                mostrarMensagem("Codigo atualizado com sucesso! ");
            }

            else if (resultadoAtualizacao == -1)
            {
                mostrarMensagem("Codigo antigo não encontrado. ");
            }

            else if (resultadoAtualizacao == -2)
            {
                mostrarMensagem("Codigo novo inválido. ");
            }

            else if (resultadoAtualizacao == 0)
            {
                mostrarMensagem("Já existe uma disciplina cadastrada com o novo codigo! ");
            }
            break;
        }
        case 4:
        { // Excluir Disciplina
            mostrarMensagem(" --- Excluir Disciplina --- ");
            int quantidade = obterQtdDisciplina();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Disciplinas Vazia!\nPrimeiro cadastre uma Disciplina.\n");
                pausarConsole();
                break;
            }

            int codigoExcluir = lercodigo("a excluir");

            int resultadoExclusao = excluirDisciplina(codigoExcluir);

            if (resultadoExclusao == 1)
            {
                mostrarMensagem("Disciplina excluída com sucesso!");
            }

            else if (resultadoExclusao == -2)
            {
                mostrarMensagem("Codigo inválido. ");
            }

            else if (resultadoExclusao == -1)
            {
                mostrarMensagem("Codigo não encontrado. ");
            }

            break;
        }
        case 5:
        { // Relatorios

            int sairMenu = 0;
            int quantidade = obterQtdDisciplina();
            if (quantidade == 0)
            {
                mostrarMensagem("Lista de Disciplinas Vazia!\nPrimeiro cadastre uma Disciplina.\n");
                pausarConsole();
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
                case 2:
                {
                    // Exibir lista alfabetica
                    Disciplina *listaAlfabetica = listarDisciplina();
                    if (listaAlfabetica != NULL)
                    {
                        exibirListaDisciplinasAlfabetico(listaAlfabetica, quantidade);
                        free(listaAlfabetica);
                    }
                    pausarConsole();
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