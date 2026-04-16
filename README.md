# Projeto Escola

## Descrição

O Projeto Escola é um sistema de gerenciamento educacional desenvolvido em linguagem C, projetado para demonstrar a aplicação de princípios de programação modular e boas práticas de desenvolvimento. Ele oferece funcionalidades essenciais para a administração de dados de alunos, professores e disciplinas, além de um conjunto robusto de relatórios para análise e consulta. A arquitetura do sistema segue um padrão que se assemelha ao MVC (Model-View-Controller), promovendo a separação de responsabilidades e facilitando a manutenção e escalabilidade do código.

## Funcionalidades

O sistema implementa as seguintes funcionalidades principais:

### Gestão de Cadastros

*   **Alunos**: Matrícula, Nome, Sexo, Data de Nascimento, CPF.
*   **Professores**: Matrícula, Nome, Sexo, Data de Nascimento, CPF.
*   **Disciplinas**: Nome, Código, Semestre, Professor.
    *   Inserir/Excluir aluno de uma disciplina.

### Gestão de Matrículas

*   **Matrícula de Alunos em Disciplinas**: Permite vincular alunos a disciplinas, controlando a capacidade das turmas e evitando matrículas duplicadas. As operações de matrícula e exclusão de matrícula atualizam automaticamente os contadores de alunos por disciplina e disciplinas por aluno.
*   **Exclusão de Matrículas**: Possibilita a remoção de um aluno de uma disciplina específica ou a exclusão de todas as matrículas de um aluno ao ser removido do sistema.

### Relatórios Abrangentes

O sistema oferece uma variedade de relatórios para consulta e análise dos dados:

*   **Listagem Geral**: Alunos, Professores e Disciplinas.
*   **Listagem Detalhada de Disciplina**: Exibe os dados de uma disciplina específica e todos os alunos nela matriculados.
*   **Relatórios por Sexo**: Lista Alunos e Professores separados por sexo (Masculino/Feminino).
*   **Ordenação Alfabética**: Lista Alunos e Professores ordenados por Nome.
*   **Ordenação por Data de Nascimento**: Lista Alunos e Professores ordenados por data de nascimento.
*   **Aniversariantes do Mês**: Identifica e lista alunos e professores que fazem aniversário em um mês específico.
*   **Busca de Pessoas**: Permite buscar alunos e professores por uma string de texto no nome (requer mínimo de três letras).
*   **Alunos com Poucas Disciplinas**: Lista alunos matriculados em menos de 3 disciplinas.
*   **Disciplinas com Excesso de Vagas**: Lista disciplinas que excedem 40 vagas (indicando potencial para otimização ou atenção).

### Validações

O sistema inclui validações para garantir a integridade dos dados:

*   **CPF**: Validação de formato e consistência.
*   **Data de Nascimento**: Verificação de datas válidas.
*   **Semestre**: Validação do formato `AAAA.S` (ex: `2023.1`, `2024.2`).
*   **Matrículas**: Prevenção de matrículas duplicadas em uma mesma disciplina e controle de capacidade.

## Estrutura do Projeto

O projeto é organizado em diretórios que refletem uma arquitetura modular, facilitando a compreensão, manutenção e expansão:

```
ProjetoEscola/
├── Makefile
├── controller/       # Lógica de negócio e orquestração entre Model e View
├── escola.c          # Ponto de entrada principal e menu de navegação
├── model/            # Estruturas de dados e lógica de persistência/manipulação de baixo nível
├── projeto_escola.exe (gerado após compilação)
├── utils/            # Funções utilitárias diversas (validações, I/O de console)
└── view/             # Interface com o usuário (exibição de dados e coleta de entradas)
```

*   **`controller/`**: Contém a lógica de controle e manipulação dos dados, interagindo entre a `view` e o `model`.
*   **`model/`**: Define as estruturas de dados e as operações de persistência/manipulação de baixo nível.
*   **`view/`**: Responsável pela interface com o usuário, exibindo informações e coletando entradas.
*   **`utils/`**: Funções utilitárias diversas, como limpeza de console e leitura de opções.
*   **`escola.c`**: O arquivo principal que orquestra a execução do programa e o menu de opções.
*   **`Makefile`**: Script para automatizar o processo de compilação do projeto.

## Como Compilar e Executar

Para compilar e executar o projeto, siga os passos abaixo:

1.  **Pré-requisitos**: Certifique-se de ter um compilador C (como o GCC) instalado em seu sistema operacional.

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
    O programa exibirá um menu principal interativo, permitindo que você explore todas as funcionalidades do sistema.

## Tecnologias Utilizadas

*   **Linguagem**: C
*   **Compilador**: GCC (GNU Compiler Collection)

## Autor

* **Erick Rocha Nascimento**  
🔗 [LinkedIn](https://www.linkedin.com/in/erickrochanascimento) | [GitHub](https://github.com/ErickRochaNascimento)
* **Gabriel Viniciús**  
🔗 [LinkedIn](https://www.linkedin.com/in/gabriel-vinici%C3%BAs-8539521b7/) | [GitHub](https://github.com/ProgrammerGV)
