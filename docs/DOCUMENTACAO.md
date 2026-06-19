# SISTEMA SABORNORDESTE

## 1. CAPA

**Instituição:** Faculdade Católica Imaculada Conceição do Recife (FICR)

**Disciplina:** Lógica Matemática e Algoritmo

**Projeto:** SaborNordeste – Sistema de Gerenciamento para Restaurantes Regionais

**Integrantes:**
- Miguel Arcanjo
- Kauã César
- Karen Evelyn
- Elisangela Cristina
- Adrews Cordeiro
- Misael José

**Professor:** Jonatas da Silva Junior

---

# 2. INTRODUÇÃO

O SaborNordeste é um sistema de gerenciamento para restaurantes regionais desenvolvido em linguagem C. O sistema permite o cadastro de clientes, cadastro de pratos, realização de pedidos e geração de relatórios gerenciais. As informações são armazenadas em arquivos texto, garantindo a persistência dos dados entre diferentes execuções do programa.

O projeto foi desenvolvido com o objetivo de aplicar conceitos fundamentais de programação estruturada, modularização, manipulação de arquivos e estruturas de dados utilizando a linguagem C.

## Tecnologias Utilizadas

- Linguagem C
- Manipulação de arquivos texto
- Modularização com arquivos .c e .h
- Biblioteca locale.h
- Makefile
- Estruturas de dados
- Persistência de dados

---

# 3. OBJETIVOS DO PROJETO

## Objetivo Geral

Desenvolver um sistema de gerenciamento para restaurantes regionais utilizando a linguagem C e armazenamento persistente em arquivos texto.

## Objetivos Específicos

- Cadastrar clientes.
- Consultar clientes cadastrados.
- Cadastrar pratos do restaurante.
- Consultar pratos disponíveis.
- Registrar pedidos realizados.
- Calcular automaticamente o valor total dos pedidos.
- Salvar informações em arquivos texto.
- Gerar relatórios de vendas.
- Permitir a recuperação dos dados em futuras execuções.

---

# 4. DESCRIÇÃO DO SISTEMA

O sistema SaborNordeste possui um menu principal que permite ao usuário acessar diferentes funcionalidades do restaurante.

Entre as funcionalidades disponíveis estão:

- Cadastro de administradores;
- Login de administradores;
- Cadastro de clientes;
- Consulta de clientes;
- Cadastro de pratos;
- Consulta de pratos;
- Registro de pedidos;
- Relatórios de vendas.

Todos os dados são armazenados em arquivos texto para garantir a persistência das informações.

---

# 5. REQUISITOS FUNCIONAIS

| Código | Descrição |
|---------|------------|
| RF01 | Cadastrar administradores |
| RF02 | Realizar login de administradores |
| RF03 | Cadastrar clientes |
| RF04 | Consultar clientes cadastrados |
| RF05 | Cadastrar pratos |
| RF06 | Consultar pratos disponíveis |
| RF07 | Registrar pedidos |
| RF08 | Calcular valor total dos pedidos |
| RF09 | Gerar relatórios |
| RF10 | Salvar dados em arquivos texto |

---

# 6. REQUISITOS NÃO FUNCIONAIS

| Código | Descrição |
|---------|------------|
| RNF01 | O sistema deve ser executado no terminal |
| RNF02 | Os dados devem ser persistidos em arquivos texto |
| RNF03 | O sistema deve possuir interface simples e intuitiva |
| RNF04 | O sistema deve ser desenvolvido em linguagem C |
| RNF05 | O sistema deve utilizar modularização com arquivos .c e .h |

---

# 7. HISTÓRIAS DE USUÁRIO

### HU01
Como atendente, quero cadastrar clientes para facilitar o registro dos pedidos.

### HU02
Como atendente, quero cadastrar pratos para disponibilizá-los no sistema.

### HU03
Como atendente, quero registrar pedidos para controlar as vendas do restaurante.

### HU04
Como gerente, quero visualizar relatórios para acompanhar o desempenho do restaurante.

### HU05
Como usuário, quero que os dados sejam salvos para não perder informações ao fechar o sistema.

### HU06
Como gerente, quero consultar os pedidos realizados para acompanhar o histórico de vendas.

### HU07
Como atendente, quero pesquisar clientes cadastrados para agilizar o atendimento.

## Controle de Acesso

O sistema possui autenticação de administradores.

Arquivo:

```text
administradores.txt
```

Formato:

```text
usuario;senha
```

---

# 8. FLUXOGRAMA DO SISTEMA

![Fluxograma do Sistema](/docs/images/fluxograma.png)

---

# 9. ESTRUTURA DOS ARQUIVOS

## administradores.txt

```text
usuario;senha
```

## clientes.txt

```text
ID;Nome;CPF;Telefone
```

Exemplo:

```text
1;Maria Silva;12345000;40028922
```

## pratos.txt

```text
ID;Nome;Preço;Categoria
```

Exemplo:

```text
1;Baião de Dois;25.00;Prato Principal
```

## pedidos.txt

```text
IDPedido;IDCliente;ValorTotal
```

Exemplo:

```text
1;3;58.00
```

---

# 10. MÉTRICAS DO SISTEMA

| Métrica | Descrição |
|----------|------------|
| Número de clientes cadastrados | Total de clientes registrados |
| Número de pratos cadastrados | Total de pratos disponíveis |
| Número de pedidos realizados | Quantidade de vendas registradas |
| Valor total vendido | Soma financeira de todos os pedidos |
| Ticket médio | Valor médio gasto por pedido |

Fórmula:

```text
Ticket Médio = Valor Total das Vendas ÷ Quantidade de Pedidos
```

---

# 11. DIVISÃO DAS TAREFAS

| Integrante | Responsabilidade |
|------------|------------------|
| Miguel Arcanjo | Manipulação de Arquivos e Documentação |
| Kauã César | Cadastro de Clientes |
| Karen Evelyn | Cadastro de Pratos |
| Elisangela Cristina | Relatórios e Métricas |
| Adrews Cordeiro | Registro de Pedidos |
| Misael José | Testes e Integração |

---

# 12. ESTRUTURA ATUAL DO PROJETO

```text
RestauranteRegional-C/
│
├── src/
│   ├── main.c
│   ├── administradores.c
│   ├── clientes.c
│   ├── pratos.c
│   ├── pedidos.c
│   ├── relatorios.c
│   └── utils.c
│
├── include/
│   ├── administradores.h
│   ├── clientes.h
│   ├── pratos.h
│   ├── pedidos.h
│   ├── relatorios.h
│   └── utils.h
│
├── data/
│   ├── administradores.txt
│   ├── clientes.txt
│   ├── pratos.txt
│   └── pedidos.txt
│
├── docs/
│   ├── images/
│   │       └──fluxograma.png
│   └── DOCUMENTACAO.md
│
├── Makefile
└── README.md
```

## Arquitetura do Sistema

| Módulo | Responsabilidade |
|---------|------------|
| main | Controle do fluxo principal |
| administradores | Cadastro e autenticação |
| clientes | Gerenciamento de clientes |
| pratos | Gerenciamento dos pratos |
| pedidos | Registro de pedidos |
| relatorios | Geração de relatórios |
| utils | Funções auxiliares |

## Principais Funções

- registrarAdministrador()
- loginAdministrador()
- iniciarSistema()
- realizarLogin()
- menuLogin()
- menuAdministrador()
- limparTela()
- pausar()
- limparBuffer()
- configurarLocale()

---

# 13. COMPILAÇÃO E EXECUÇÃO

## Compilar

```bash
make
```

## Executar

Linux/macOS:

```bash
./restaurante
```

Windows:

```bash
restaurante.exe
```

---

# 14. CONCLUSÃO

O desenvolvimento do sistema SaborNordeste possibilitou a aplicação prática dos conceitos estudados na disciplina de Programação em Linguagem C.

Durante a implementação foram utilizados recursos como estruturas, funções, modularização, manipulação de arquivos texto, autenticação de usuários, utilização de Makefile e organização de dados.

O sistema atende aos requisitos propostos e permite o gerenciamento básico de um restaurante regional por meio do cadastro de administradores, clientes, pratos, pedidos e geração de relatórios.
