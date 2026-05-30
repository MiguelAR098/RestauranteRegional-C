Sistema de gerenciamento para restaurante regional desenvolvido em linguagem C como projeto acadêmico.

## 📋 Sobre o Projeto

O sistema tem como objetivo auxiliar o gerenciamento de um restaurante regional através do cadastro de clientes, cadastro de pratos, realização de pedidos e consulta de relatórios.

Todas as informações são armazenadas em arquivos texto, garantindo a persistência dos dados mesmo após o encerramento do programa.

---

## 🚀 Funcionalidades

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

## 📂 Estrutura de Arquivos

```text
RestauranteRegional-C/
│
├── src/
│   ├── main.c
│   ├── clientes.c
│   ├── pratos.c
│   ├── pedidos.c
│   └── relatorios.c
│
├── include/
│   ├── clientes.h
│   ├── pratos.h
│   ├── pedidos.h
│   └── relatorios.h
│
├── data/
│   ├── clientes.txt
│   ├── pratos.txt
│   └── pedidos.txt
│
└── README.md
```

---

## 💾 Arquivos Utilizados

| Arquivo | Finalidade |
|----------|------------|
| clientes.txt | Armazena os dados dos clientes |
| pratos.txt | Armazena os dados dos pratos |
| pedidos.txt | Armazena os pedidos realizados |

---

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- Manipulação de arquivos texto
- Estruturas de dados
- Modularização com arquivos .c e .h

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
  </tr>
</table>

---

## 📌 Requisitos do Projeto

### Requisitos Funcionais

- RF01: Cadastrar clientes.
- RF02: Cadastrar pratos.
- RF03: Registrar pedidos.
- RF04: Consultar pedidos.
- RF05: Gerar relatórios.
- RF06: Salvar dados em arquivos texto.

### Requisitos Não Funcionais

- RNF01: O sistema deve ser executado em terminal.
- RNF02: Os dados devem ser persistidos em arquivos texto.
- RNF03: O sistema deve possuir interface simples e intuitiva.
- RNF04: O sistema deve ser desenvolvido em linguagem C.

---

## ▶️ Como Executar

Compile o projeto:

```bash
gcc *.c -o restaurante
```

Execute:

```bash
./restaurante
```

---

## 📖 Fluxo Geral

1. Carregar dados dos arquivos.
2. Exibir menu principal.
3. Permitir cadastro de clientes.
4. Permitir cadastro de pratos.
5. Permitir realização de pedidos.
6. Gerar relatórios.
7. Salvar alterações antes de encerrar.

---

## 🎓 Projeto Acadêmico

Projeto desenvolvido para a disciplina de Programação em Linguagem C, utilizando conceitos de estruturas, funções, modularização e manipulação de arquivos.
