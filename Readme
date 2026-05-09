# README - Execução dos Programas Sequencial e Paralelo com OpenMP

## Descrição

Este projeto apresenta duas implementações do algoritmo recursivo de Fibonacci:

- Versão Sequencial;
- Versão Paralela utilizando OpenMP com tarefas (*tasks*).

O objetivo é comparar o desempenho entre as duas abordagens e analisar o comportamento do OpenMP em aplicações recursivas.

---

# Estrutura dos Arquivos

```text
.
├── Sequencial.c
├── Paralela.c
└── README.md
```

---

# Requisitos

É necessário possuir:

- GCC com suporte ao OpenMP;
- Sistema Linux ou ambiente compatível.

Verifique a instalação do GCC:

```bash
gcc --version
```

---

# Compilação e Execução

# 1. Versão Sequencial

## Compilar

```bash
gcc Sequencial.c -fopenmp -o sequencial
```

## Executar

```bash
./sequencial
```

## Saída Esperada

```text
Fibonacci(40) = 102334155
Tempo: 0.686421 segundos
```

---

# 2. Versão Paralela com OpenMP

## Compilar

```bash
gcc Paralela.c -fopenmp -o paralela
```

## Executar

```bash
./paralela
```

## Saída Esperada

```text
Resultado: 102334155
Tempo: 119.998794 segundos
```