#include "professor_controller.h"

#include <stdio.h>
void gerenciarProfessor() {
    int opcaoProfessor;
    int sairProfessor = 0;

    while (!sairProfessor) {
        exibirMenuProfessor();
        scanf("%d", &opcaoProfessor);

        switch (opcaoProfessor) {
            case 0: {
                sairProfessor = 1;
                exibirMensagem("Voltando ao menu principal...");
                break;
            }
            case 1: { // Cadastrar Professor
                Professor novoProfessor = pedirDadosProfessor();
                if (novoProfessor.matricula < 0) {
                    exibirMensagem("Matrícula Inválida!");
                } else {
                    int resultado = cadastrarProfessorModel(novoProfessor);
                    if (resultado == 1) {
                        exibirMensagem("Professor cadastrado com sucesso!");
                    } else if (resultado == -1) {
                        exibirMensagem("Lista de professores cheia!");
                    } else if (resultado == -2) {
                        exibirMensagem("Matrícula já existe!");
                    }
                }
                break;
            }
            case 2: { // Listar Professor
                Professor professores[TAM_PROFESSOR];
                int qtd = 0;
                listarProfessoresModel(professores, &qtd);
                exibirListaProfessores(professores, qtd);
                break;
            }
            case 3: { // Atualizar Professor
                int matriculaAntiga = pedirMatriculaProfessor();
                if (matriculaAntiga < 0) {
                    exibirMensagem("Matrícula Inválida!");
                    break;
                }
                Professor* professorExistente = buscarProfessorPorMatriculaModel(matriculaAntiga);
                if (professorExistente == NULL || professorExistente->ativo == -1) {
                    exibirMensagem("Professor não encontrado ou inativo.");
                } else {
                    exibirMensagem("Professor encontrado. Digite a nova matrícula:");
                    Professor novaProfessor = pedirDadosProfessor(); // Pede a nova matrícula
                    if (novaProfessor.matricula < 0) {
                        exibirMensagem("Nova matrícula inválida!");
                    } else {
                        int resultado = atualizarProfessorModel(matriculaAntiga, novaProfessor);
                        if (resultado == 1) {
                            exibirMensagem("Professor atualizado com sucesso!");
                        } else {
                            exibirMensagem("Erro ao atualizar professor.");
                        }
                    }
                }
                break;
            }
            case 4: { // Excluir Professor
                int matriculaParaExcluir = pedirMatriculaProfessor();
                if (matriculaParaExcluir < 0) {
                    exibirMensagem("Matrícula Inválida!");
                    break;
                }
                int resultado = excluirProfessorModel(matriculaParaExcluir);
                if (resultado == 1) {
                    exibirMensagem("Professor excluído com sucesso!");
                } else {
                    exibirMensagem("Professor não encontrado.");
                }
                break;
            }
            default: {
                exibirMensagem("Opção Inválida!");
                break;
            }
        }
    }
}


// Implementação da função buscarProfessorPorMatriculaModel (necessária para o controller)
Professor* buscarProfessorPorMatriculaModel(int matricula) {
    extern Professor listaProfessor[TAM_PROFESSOR]; // Declarar como extern para acessar a global
    extern int qtdProfessor; // Declarar como extern para acessar a global

    for (int i = 0; i < qtdProfessor; i++) {
        if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo == 1) {
            return &listaProfessor[i];
        }
    }
    return NULL;
}