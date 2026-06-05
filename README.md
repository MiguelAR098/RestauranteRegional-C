# Sistema de Gerenciamento de Restaurante Regional

Sistema de gerenciamento para restaurante regional desenvolvido em linguagem C como projeto acadêmico.

## 📋 Sobre o Projeto

O sistema tem como objetivo auxiliar o gerenciamento de um restaurante regional através do cadastro de clientes, cadastro de pratos, realização de pedidos e consulta de relatórios.

Todas as informações são armazenadas em arquivos texto, garantindo a persistência dos dados mesmo após o encerramento do programa.

---

## 🚀 Funcionalidades

### Administradores
- Cadastro de administradores
- Login de administradores
- Controle de acesso ao sistema
- Armazenamento em arquivo texto

### Clientes
- Cadastro de clientes
- Consulta de clientes cadastrados
- Armazenamento em arquivo texto

### Pratos
- Cadastro de pratos regionais
- Consulta de pratos cadastrados
- Armazenamento em arquivo texto

### Pedidos
- Realização de pedidos
- Associação de clientes aos pedidos
- Cálculo automático do valor total
- Armazenamento em arquivo texto

### Relatórios
- Listagem de clientes
- Listagem de pratos
- Listagem de pedidos
- Resumo de vendas

---

## 📂 Estrutura Atual do Projeto

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
├── Makefile
└── README.md
```

---

## 💾 Arquivos Utilizados

| Arquivo | Finalidade |
|----------|------------|
| administradores.txt | Armazena os dados dos administradores |
| clientes.txt | Armazena os dados dos clientes |
| pratos.txt | Armazena os dados dos pratos |
| pedidos.txt | Armazena os pedidos realizados |

---

## 🔐 Controle de Acesso

O sistema possui um módulo de autenticação para administradores.

### Funcionalidades

- Cadastro de administradores
- Login de administradores
- Persistência dos dados em arquivo texto
- Controle de acesso ao menu principal do sistema

### Formato dos Dados

```text
usuario;senha
```

Exemplo:

```text
admin;senha123
```

---

## 🧰 Utilitários do Sistema

O projeto possui um módulo utilitário responsável por funções auxiliares utilizadas em diversos módulos do sistema.

### Funções Disponíveis

- Limpeza de tela
- Pausa da execução para leitura de mensagens
- Limpeza do buffer de entrada
- Configuração de localização (locale)

### Objetivo

Padronizar comportamentos comuns e evitar repetição de código entre os módulos.

---

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- Manipulação de arquivos texto
- Estruturas de dados
- Modularização com arquivos `.c` e `.h`
- Biblioteca `locale.h`
- Makefile para automação da compilação

---

## 👥 Equipe

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/MiguelAR098">
        <img src="https://github.com/MiguelAR098.png" width="80px;" alt="Miguel"/><br>
        <sub><b>Miguel Arcanjo</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/Donkaua">
        <img src="https://github.com/Donkaua.png" width="80px;" alt="Kauã"/><br>
        <sub><b>Kauã César</b></sub>
      </a>
      <td align="center">
      <a href="https://github.com/Adrews1">
        <img src="https://github.com/Adrews1.png" width="80px;" alt="Adrews"/><br>
        <sub><b>Adrews Cordeiro</b></sub>
      </a>
        <td align="center">
      <a href="https://github.com/elisangelacsantos">
        <img src="https://github.com/elisangelacsantos.png" width="80px;" alt="Elisangela"/><br>
        <sub><b>Elisangela Cristina</b></sub>
      </a>
        <td align="center">
      <a href="https://github.com/misaelsilva1">
        <img src="https://github.com/misaelsilva1.png" width="80px;" alt="Misael"/><br>
        <sub><b>Misael José</b></sub>
      </a>
        <td align="center">
      <a href="https://github.com/Karen-aa12">
        <img src="https://github.com/Karen-aa12.png" width="80px;" alt="Karen"/><br>
        <sub><b>Karen Evelyn</b></sub>
      </a>
  </tr>
</table>

---

## 📌 Requisitos do Projeto

### Requisitos Funcionais

- RF01: Cadastrar administradores.
- RF02: Realizar login de administradores.
- RF03: Cadastrar clientes.
- RF04: Cadastrar pratos.
- RF05: Registrar pedidos.
- RF06: Consultar pedidos.
- RF07: Gerar relatórios.
- RF08: Salvar dados em arquivos texto.

### Requisitos Não Funcionais

- RNF01: O sistema deve ser executado em terminal.
- RNF02: Os dados devem ser persistidos em arquivos texto.
- RNF03: O sistema deve possuir interface simples e intuitiva.
- RNF04: O sistema deve ser desenvolvido em linguagem C.
- RNF05: O sistema deve utilizar modularização com arquivos `.c` e `.h`.

---

## 🏗️ Arquitetura do Sistema

O projeto foi organizado utilizando modularização em linguagem C.

| Módulo | Responsabilidade |
|----------|------------|
| main | Controle do fluxo principal do sistema |
| administradores | Cadastro e autenticação de administradores |
| clientes | Gerenciamento de clientes |
| pratos | Gerenciamento dos pratos do restaurante |
| pedidos | Registro e controle dos pedidos |
| relatorios | Geração de relatórios do sistema |
| utils | Funções auxiliares reutilizáveis |

Essa organização facilita a manutenção, reutilização de código e evolução futura do sistema.

---

## ⚙️ Compilação

O projeto utiliza Makefile para automatizar a compilação.

### Compilar

```bash
make
```

### Executar

Linux/macOS:

```bash
./restaurante
```

Windows:

```bash
restaurante.exe
```

### Limpar arquivos compilados

```bash
make clean
```

---

## 📖 Fluxo Geral

1. Inicializar o sistema.
2. Configurar locale para suporte a caracteres acentuados.
3. Exibir menu principal.
4. Permitir cadastro de administradores.
5. Realizar autenticação do administrador.
6. Exibir menu administrativo.
7. Permitir cadastro de clientes.
8. Permitir cadastro de pratos.
9. Permitir realização de pedidos.
10. Gerar relatórios.
11. Salvar alterações em arquivos texto.
12. Encerrar o sistema.

---

## 🎓 Projeto Acadêmico

Projeto desenvolvido para a disciplina de Lógica Matemática e Algoritmo.