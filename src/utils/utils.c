#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Escrevemos a função uma única vez aqui!
void mostrarMensagem(const char *mensagem)
{
    printf("%s\n", mensagem);
}



int verificarCPF(const char *cpf)
{
    int todosDigitos = 0;
    // Verificar se o CPF tem 11 dígitos
    if (strlen(cpf) != 11)
    {
        return 0; // CPF Invalido
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

char lerCPF(char *destino)
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

char lerNome(char *destino)
{
    printf("Digite o nome: ");
    scanf(" %100[^\n]", destino);
    getchar();
}

int verificarSexo(const char sexo)
{

    if (sexo == 'M' || sexo == 'F' || sexo == 'm' || sexo == 'f')
    {
        return 1;
    }
    return 0;
}

char lerSexo(char destino)
{
    while (1)
    {
        printf("Digite seu sexo (M/F): ");
        scanf(" %c", &destino);
        if (verificarSexo(destino))
        {
            return destino;
            break;
        }
        else
        {
            printf("Sexo invalido!\n");
        }
    }
}

int verificarData(int d, int m, int a)
{
    if (a < 1900 || a > 2026)
        return 0; // Ano fora da realidade
    if (m < 1 || m > 12)
        return 0; // Mês inexistente
    if (d < 1 || d > 31)
        return 0; // Dia impossível

    // 2. Meses com 30 dias
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return 0;

    // 3. Verificação de Fevereiro e Ano Bissexto
    if (m == 2)
    {
        // Regra do Bissexto: divisível por 4 e (não por 100 ou divisível por 400)
        int bissexto = (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
        if (bissexto)
        {
            if (d > 29)
                return 0;
        }
        else
        {
            if (d > 28)
                return 0;
        }
    }

    return 1; // Se passou por tudo, a data é válida!
}

char lerDataNascimento(Data *dataNascimento)
{
    while (1)
    {
        printf("Digite o dia de nascimento: ");
        scanf("%d", &dataNascimento->dia);

        printf("Digite o mêS de nascimento: ");
        scanf("%d", &dataNascimento->mes);

        printf("Digite o ano de nascimento: ");
        scanf("%d", &dataNascimento->ano);
        if (verificarData(dataNascimento->dia, dataNascimento->mes, dataNascimento->ano))
        {
            break; // Data válida!
        }
        else
        {
            printf("Data invalida! Tente novamente.\n");
        }
    }
}


void limparConsole(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausarConsole() {
    printf("\nPressione qualquer tecla para continuar...\n");
    system("pause");
}

int menuPessoa(const char* tipoPessoa) {

    limparConsole();    
    int opcaoPessoa;
    printf("---- Modulo %s ----\n", tipoPessoa);
    printf("\n0 - Voltar ao menu Principal \n");
    printf("1 - Cadastrar %s\n", tipoPessoa);
    printf("2 - Listar %s\n", tipoPessoa);
    printf("3 - Atualizar %s\n", tipoPessoa);
    printf("4 - Excluir %s\n", tipoPessoa);
    scanf("%d", &opcaoPessoa);

    return opcaoPessoa;
}

int lerMatricula(const char* tipoMatricula){
    limparConsole();
    int matricula;
    printf("\nDigite a matricula %s: ", tipoMatricula);
    scanf("%d", &matricula);
    return matricula;
}