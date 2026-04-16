# Projeto Escola

## Descrição

Este projeto consiste em um sistema de gerenciamento para uma escola, desenvolvido em linguagem C. Ele foi projetado para controlar diversas funcionalidades essenciais, como o cadastro de alunos, professores e disciplinas, além de oferecer uma série de relatórios para consulta e análise dos dados. O objetivo principal é demonstrar a aplicação de conceitos de programação modular e boas práticas de desenvolvimento em C.

## Funcionalidades

As principais funcionalidades implementadas neste sistema incluem:

### Cadastro

*   **Alunos**: Matrícula, Nome, Sexo, Data de Nascimento, CPF.
*   **Professores**: Matrícula, Nome, Sexo, Data de Nascimento, CPF.
*   **Disciplinas**: Nome, Código, Semestre, Professor.
    *   Inserir/Excluir aluno de uma disciplina.

### Relatórios

*   Listar Alunos.
*   Listar Professores.
*   Listar Disciplinas (apenas dados da disciplina).
*   Listar uma disciplina específica (dados da disciplina e alunos matriculados).
*   Listar Alunos por sexo (Masculino/Feminino).
*   Listar Alunos ordenados por Nome.
*   Listar Alunos ordenados por data de nascimento.
*   Listar Professores por sexo (Masculino/Feminino).
*   Listar Professores ordenados por Nome.
*   Listar Professores ordenados por data de nascimento.
*   Aniversariantes do mês.
*   Lista de pessoas (professor/aluno) a partir de uma string de busca (mínimo de três letras).
*   Lista de alunos matriculados em menos de 3 disciplinas.
*   Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas.

### Validações

*   Validação de campos necessários, como Data de Nascimento e CPF.

## Estrutura do Projeto

O projeto segue uma estrutura modular, organizada em diretórios para facilitar a manutenção e a reutilização de código:

```
ProjetoEscola/
├── Makefile
├── controller/
│   ├── aluno_controller.c
│   ├── aluno_controller.h
│   ├── busca_controller.c
│   ├── busca_controller.h
│   ├── disciplina_controller.c
│   ├── disciplina_controller.h
│   ├── matricula_controller.c
│   ├── matricula_controller.h
│   ├── professor_controller.c
│   └── professor_controller.h
├── escola.c
├── model/
│   ├── aluno_model.c
│   ├── aluno_model.h
│   ├── data_model.c
│   ├── data_model.h
│   ├── disciplina_model.c
│   ├── disciplina_model.h
│   ├── matricula_model.c
│   ├── matricula_model.h
│   ├── professor_model.c
│   └── professor_model.h
├── projeto_escola.exe (gerado após compilação)
├── utils/
│   ├── utils.c
│   └── utils.h
└── view/
    ├── aluno_view.c
    ├── aluno_view.h
    ├── disciplina_view.c
    ├── disciplina_view.h
    ├── matricula_view.c
    ├── matricula_view.h
    ├── professor_view.c
    └── professor_view.h
```

*   **`controller/`**: Contém a lógica de controle e manipulação dos dados, interagindo entre a `view` e o `model`.
*   **`model/`**: Define as estruturas de dados e as operações de persistência/manipulação de baixo nível.
*   **`view/`**: Responsável pela interface com o usuário, exibindo informações e coletando entradas.
*   **`utils/`**: Funções utilitárias diversas, como limpeza de console e leitura de opções.
*   **`escola.c`**: O arquivo principal que orquestra a execução do programa e o menu de opções.
*   **`Makefile`**: Script para automatizar o processo de compilação do projeto.

## Como Compilar e Executar

Para compilar e executar o projeto, siga os passos abaixo:

1.  **Pré-requisitos**: Certifique-se de ter um compilador C (como o GCC) instalado em seu sistema.

2.  **Navegue até o diretório do projeto**:
    ```bash
    cd ProjetoEscola
    ```

3.  **Compile o projeto**: Utilize o `Makefile` fornecido para compilar o código-fonte.
    ```bash
    make all
    ```
    Este comando irá compilar todos os arquivos `.c` e gerar um executável chamado `projeto_escola` (ou `projeto_escola.exe` em sistemas Windows).

4.  **Execute o programa**:
    ```bash
    ./projeto_escola
    ```
    O programa exibirá um menu principal, permitindo que você interaja com as funcionalidades do sistema.

5.  **Limpar arquivos de compilação**: Para remover o executável e outros arquivos gerados pela compilação, utilize:
    ```bash
    make clean
    ```

## Tecnologias Utilizadas

*   **Linguagem**: C
*   **Compilador**: GCC (GNU Compiler Collection)

## Autor

*   Manus AI

## Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo `LICENSE` (se disponível) para mais detalhes.
