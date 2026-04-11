#include <stdio.h>
#include "disciplina_model.h"
#include <string.h>
#include <stdlib.h>

Disciplina listaDisciplina[TAM_DISCIPLINA];

int qtdDisciplina = 0;
int geradorCodigoDiciplina = 1;

int cadastrarDisciplina(Disciplina novaDisciplina)
{
    if (qtdDisciplina == TAM_DISCIPLINA)
    {
        return -1;
    }
    if(novaDisciplina.matricula_professor == 0){
        return -2;
    }
    int codigoCriado = geradorCodigoDiciplina;

    listaDisciplina[qtdDisciplina].codigo = geradorCodigoDiciplina;
    geradorCodigoDiciplina++;

    strcpy(listaDisciplina[qtdDisciplina].nome, novaDisciplina.nome);
    strcpy(listaDisciplina[qtdDisciplina].semestre, novaDisciplina.semestre);

    listaDisciplina[qtdDisciplina].ativo = 1;
    qtdDisciplina++;

    return codigoCriado;
}

Disciplina *listarDisciplina()
{
    Disciplina *listaOrdenada = obterListaDisciplinasAlfabetica();
    return listaOrdenada;
}

int obterQtdDisciplina()
{
    return qtdDisciplina;
}

int atualizarDisciplina(int codigo_antigo, int codigo_novo)
{
    if (codigo_novo < 0)
    {
        return -2; // codigo invalido
    }
    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (codigo_novo == listaDisciplina[i].codigo && listaDisciplina[i].ativo == 1)
        {
            return 0; // diciplina ja possui esse codigo
        }
    }

    for (int i = 0; i < qtdDisciplina; i++)
    {
        if (codigo_antigo == listaDisciplina[i].codigo && listaDisciplina[i].ativo == 1)
        {
            listaDisciplina[i].codigo = codigo_novo;
            return 1; // Codigo atualizado
        }
    }

    return -1; // Codigo  antigo não encontrada
}

int excluirDisciplina(int codigo)
{
    if (codigo < 0)
    {
        return -2; // Codigo invalida
    }

    for (int i = 0; i < qtdDisciplina; i++)
    {
       if (codigo == listaDisciplina[i].codigo && listaDisciplina[i].ativo)
        {
            for (int j = i; j < qtdDisciplina - 1; j++)
            {
                listaDisciplina[j] = listaDisciplina[j + 1];
            }
            qtdDisciplina--;
            return 1; // Disciplina excluida com sucesso
        }
    }
    return -1; //Codigo não encontrado
    
}

Disciplina* obterListaDisciplinasAlfabetica()
{
    int qtd = qtdDisciplina;

    // Criamos a cópia da lista dinamicamente usando malloc
    Disciplina *listaOrdenada = malloc(qtd * sizeof(Disciplina));
    
    if (listaOrdenada == NULL) {
        return NULL; 
    }

    // Copiando os dados da lista original para a nova
    for (int i = 0; i < qtd; i++)
    {
        listaOrdenada[i] = listaDisciplina[i];
    }

    for (int i = 0; i < qtd; i++)
    {
        for (int j = i + 1; j < qtd; j++)
        {
            if (listaOrdenada[i].ativo == 1 && listaOrdenada[j].ativo == 1)
            {
                if (strcmp(listaOrdenada[i].nome, listaOrdenada[j].nome) > 0)
                {
                    Disciplina aux = listaOrdenada[i];
                    listaOrdenada[i] = listaOrdenada[j];
                    listaOrdenada[j] = aux;
                }
            }
        }
    }
        return listaOrdenada;
}