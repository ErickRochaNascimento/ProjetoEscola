#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Escrevemos a função uma única vez aqui!
void mostrarMensagem(const char *mensagem)
{
    printf("%s\n", mensagem);
}

void limparConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int verificarCPF(const char *cpf)
{
    int todosDigitos = 0;
    // Verificar se o CPF tem 11 dígitos
    if (strlen(cpf) != 11)
    {
        return -1; // CPF Invalido
    }

    // Verificar se todos os caracteres são dígitos

    for (int i = 0; i < 11; i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9')
        {
            return 0;
        }
    }

    int somaCPF1 = 0;
    for (int j = 0; j < 9; j++)
    {
        somaCPF1 += (cpf[j] - '0') * (10 - j);
    }

    int moduloCPF1 = somaCPF1 % 11;
    int primeiroVerificador = (moduloCPF1 < 2) ? 0 : 11 - moduloCPF1;

    int somaCPF2 = 0;
    for (int j = 0; j < 10; j++)
    {
        somaCPF2 += (cpf[j] - '0') * (11 - j);
    }

    int moduloCPF2 = somaCPF2 % 11;
    int segundoVerificador = (moduloCPF2 < 2) ? 0 : 11 - moduloCPF2;

    if (primeiroVerificador == (cpf[9] - '0') && segundoVerificador == (cpf[10] - '0'))
    {
        return 1; // CPF válido
    }
}

char lerCPF(const char *destino)
{
    while (1)
    {
        printf("Digite o CPF (apenas numeros):");
        scanf("%s", destino);
        getchar();
        if (verificarCPF(destino))
        {
            break;
        }
        else
        {
            printf("CPF invalido.\n");
        }
    }
}

char lerNome(const char *destino)
{
    printf("Digite o nome: ");
    scanf(" %100[^\n]", destino);
    getchar();
}