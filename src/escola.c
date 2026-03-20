#include <stdio.h>
#define TAM_ALUNO 3
#define TAM_PROFESSOR 3

typedef struct alu
{
    int matricula;
    char sexo;
    int ativo;
} Aluno;

typedef struct professor
{
    int matricula;
    char sexo;
    int ativo;
} Professor;

int main()
{
    Aluno listaAluno[TAM_ALUNO];
    Professor listaProfessor[TAM_PROFESSOR];

    int opcao;
    int sair = 0;
    int qtdAluno = 0;

    int qtdProfessor = 0;

    int listarProfessor[TAM_PROFESSOR];

    while (!sair)
    {
        printf("Projeto Escola\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");
        printf("0 - sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
        {
            sair = 1;
            break;
        }
        case 1:
        {
            printf("Módulo Aluno\n");
            int sairAluno = 0;
            int opcaoAluno = 0;

            while (!sair)
            {

                printf("0 - Voltar ao menu Principal\n");
                printf("1 - Cadastrar Aluno\n");
                printf("2 - Listar Aluno\n");
                printf("3 - Atualizar Aluno\n");
                printf("4 - Excluir Aluno\n");
                scanf("%d", &opcaoAluno);

                switch (opcaoAluno)
                {
                case 0:
                {
                    sairAluno = 1;
                    break;
                }
                case 1:
                {
                    printf(" Cadastrar Aluno\n");
                    if (qtdAluno == TAM_ALUNO)
                    {
                        printf("Lista de Alunos cheia\n");
                    }
                    else
                    {
                        printf(" Digite a matrícula ");
                        int matricula;
                        scanf("%d", &matricula);
                        if (matricula < 0)
                        {
                            printf("Matrícula Inválida\n");
                        }
                        listaAluno[qtdAluno].matricula = matricula;
                        listaAluno[qtdAluno].ativo = 1;
                        qtdAluno++;
                        printf("Cadastrada com sucesso");
                    }
                    break;
                }
                case 2:
                {
                    printf(" Listar Aluno\n");
                    if (qtdAluno == 0)
                    {
                        printf(" Lista de alunos vazia\n");
                    }
                    else
                    {
                        for (int i = 0; i < qtdAluno; i++)
                        {
                            if (listaAluno[i].ativo == 1)
                            {
                                printf("Matrícula: %d\n", listaAluno[i].matricula);
                            }
                        }
                    }
                    break;
                }
                case 3:
                {
                    printf(" Atualizar Aluno\n");
                    printf(" Digite a matrícula ");
                    int matricula;
                    scanf("%d", &matricula);
                    int achou = 0;
                    if (matricula < 0)
                    {
                        printf("Matrícula Inválida\n");
                    }
                    else
                    {
                        for (int i = 0; i < qtdAluno; i++)
                        {
                            if (matricula == listaAluno[i].matricula && listaAluno[i].ativo)
                            {
                                // atualização
                                printf(" Digite a nova matrícula \n");
                                int novamatricula;
                                scanf("%d", &novamatricula);
                                listaAluno[j].matricula = matricula;
                                achou = 1;
                                break;
                            }
                        }
                        if (achou)
                        {
                            printf("Aluno atualizado com sucesso\n");
                        }
                        else
                        {
                            printf("Matrícula inexistente\n");
                        }
                    }
                    break;
                }
                case 4:
                {
                    printf(" Excluir Aluno\n");
                    printf(" Digite a matrícula ");
                    int matricula;
                    scanf("%d", &matricula);
                    int achou = 0;
                    if (matricula < 0)
                    {
                        printf("Matrícula Inválida\n");
                    }
                    else
                    {
                        for (int i = 0; i < qtdAluno; i++)
                        {
                            if (matricula == listaAluno[i].matricula)
                            {
                                // exclusao lógica
                                listaAluno[i].ativo = -1;

                                for (int j = i; j < qtdAluno - 1; j++)
                                { // shift
                                    listaAluno[j].matricula = listaAluno[j + 1].matricula;
                                    listaAluno[j].sexo = listaAluno[j + 1].sexo;
                                    listaAluno[j].ativo = listaAluno[j + 1].ativo;
                                }
                                qtdAluno--;
                                achou = 1;
                                break;
                            }
                        }
                        if (achou)
                        {
                            printf("Aluno Excluído com sucesso\n");
                        }
                        else
                        {
                            printf("Matrícula inexistente\n");
                        }
                    }
                    break;
                }
                default:
                {
                    printf("Opção Inválida\n");
                }
                }
            }
        }
        case 2:
        {
            printf("Módulo Professor\n");
            int sairProfessor = 0;
            int opcaoProfessor = 0;
            while (!sair)
            {
                printf("0 - Voltar ao menu Principal\n");
                printf("1 - Cadastrar Professor\n");
                printf("2 - Listar Professor\n");
                printf("3 - Atualizar Professor\n");
                printf("4 - Excluir Professor\n");
                scanf("%d", &opcaoProfessor);
                switch (opcaoProfessor)
                {
                case 0:
                {
                    sairProfessor = 1;
                    break;
                }
                case 1:
                {
                    printf("Cadastrar Professor\n");
                    if(qtdProfessor == TAM_PROFESSOR){
                        printf("Lista de Professor cheia\n");
                    }else{
                        printf("Digite a matricula\n");
                    int matricula;
                    scanf("%d", &matricula);
                    int achou = 0;
                    if (matricula < 0)
                    {
                        printf("Matricula Invalida\n");
                    }else{
                        for(int i = 0; i < qtdProfessor; i++){
                            if(matricula == listaProfessor[i].matricula && listaProfessor[i].ativo){
                                printf(" Matricula ja existe\n");
                                printf(" Cadastre uma nova\n");
                            }
                        }
                    }
                    listaProfessor[qtdProfessor].matricula = matricula;
                    listaProfessor[qtdProfessor].ativo = 1;
                            qtdProfessor++;
                            
                    }
                    
                    
                    

                    break;
                }
                case 2:
                {
                    printf("Listar Professor\n");
                    if(qtdProfessor == 0){
                        printf(" Lista de professores vazia\n");
                    }else{
                        for (int i = 0; i < qtdProfessor; i++)
                    {
                        if(listaProfessor[i].ativo == 1){
                        printf("Matricula: %d\n", listaProfessor[i]);
 
                        }
                    }
                    }
                    break;
                }
                case 3:
                {
                    printf(" Atualizar Professor\n");
                    printf(" Digite a matricula ");
                    int matricula;
                    scanf("%d", &matricula);
                    int achou = 0;
                    if(matricula < 0){
                        printf("Matricula Inválida\n");
                    }else{
                        for(int i = 0; i < qtdProfessor; i++){
                            if(matricula == listaProfessor[i].matricula && listaProfessor[i].ativo){
                                printf(" Digite a nova matricula \n");
                                int novamatricula;
                                scanf("%d", &novamatricula);
                                listaProfessor[i].matricula = matricula;
                                achou = 1;
                                break;
                            }
                        }
                        if(achou == 1){
                            printf("Professor atualizado com sucesso\n");
                        }else{
                            printf("Matrícula inexistente\n");
                        }
                    }
                    break;
                }
                case 4:
                {
                    printf(" Excluir Professor\n");
                    printf(" Digite a matrícula ");
                    int matricula;
                    scanf("%d", &matricula);
                    int achou = 0;
                    if (matricula < 0)
                    {
                        printf("Matrícula Inválida\n");
                    }
                    else{
                        for(int i = 0; i < qtdProfessor; i++){
                            if(matricula == listaProfessor[i].matricula){
                                listaProfessor[i].ativo = -1;
                                
                                for(int j = i; j < qtdProfessor - 1; j++){
                                   listaProfessor[j].matricula = listaProfessor[j + 1].matricula;
                                    listaProfessor[j].sexo = listaProfessor[j + 1].sexo;
                                    listaProfessor[j].ativo = listaProfessor[j + 1].ativo;
                                }
                                qtdProfessor--;
                                achou - 1;
                                break;
                            }
                        }
                    }
                    if(achou == 1){
                        printf("Professor excluido com sucesso\n");
                    }else{
                        printf("Matrícula inexistente\n");
                    }
                    break;
                }
                default:
                {
                    printf("Opção Inválida\n");
                }
                }
            }

            break;
        }
        case 3:
        {
            printf("Módulo Disciplina\n");
            break;
        }
        default:
        {
            printf("Opção Inválida\n");
        }
        }
    }
    return 0;
}
