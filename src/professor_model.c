#include "professor_model.h"
#include <string.h>

Professor listaProfessor[TAM_PROFESSOR];
int qtdProfessor = 0;

int cadastrarProfessor(Professor novoProfessor)
{
    if (qtdProfessor == TAM_PROFESSOR)
    {
        return -1; // Lista sem espaço
    }
    if (novoProfessor.matricula < 0)
    {
        return -2; // Essa matricula é Inválida
    }
    for (int i = 0; i < qtdProfessor; i++)
    {
        if (listaProfessor[i].matricula == novoProfessor.matricula && listaProfessor[i].ativo == 1)
        {
            return 0; // já existe um professor com essa matrícula
        }
    }

    listaProfessor[qtdProfessor].matricula = novoProfessor.matricula;

    strcpy(listaProfessor[qtdProfessor].nome, novoProfessor.nome);
    strcpy(listaProfessor[qtdProfessor].dataNascimento, novoProfessor.dataNascimento);
    strcpy(listaProfessor[qtdProfessor].cpf, novoProfessor.cpf);
   
    char tempSexo[10] = "Masculino";
    if (!strcmp(novoProfessor.sexo, "F"))
    {
        strcpy(tempSexo, "Feminino");
    }
    strcpy(listaProfessor[qtdProfessor].sexo, tempSexo);

    listaProfessor[qtdProfessor].ativo = 1;
    qtdProfessor++;

    return 1; // matriculado com sucesso
}

Professor *listarProfessor()
{
    return listaProfessor;
}

int obterQtdProfessor()
{
    return qtdProfessor;
}

int atualizarProfessor(int matricula_antiga, int matricula_nova)
{
    if (matricula_nova < 0)
    {
        return -2; // matrícula inválida
    }
    for (int i = 0; i < qtdProfessor; i++)
    {
        if (matricula_nova == listaProfessor[i].matricula && listaProfessor[i].ativo == 1)
        {
            return 0; // alguem ja possui essa matricula
        }
    }

    for (int i = 0; i < qtdProfessor; i++)
    {
        if (matricula_antiga == listaProfessor[i].matricula && listaProfessor[i].ativo == 1)
        {
            listaProfessor[i].matricula = matricula_nova;
            return 1; // Matricula atualizada
        }
    }

    return -1; // Matricula antiga não encontrada
}

int excluirProfessor(int matricula)
{
    if (matricula < 0)
        return -2; // Matricula invalida

    for (int i = 0; i < qtdProfessor; i++)
    {
        if (matricula == listaProfessor[i].matricula && listaProfessor[i].ativo)
        {
            for (int j = i; j < qtdProfessor - 1; j++)
            {
                listaProfessor[j] = listaProfessor[j + 1];
            }
            qtdProfessor--;
            return 1; // Professor excluido com sucesso
        }
    }
    return -1; // matricula não encontrada
}
