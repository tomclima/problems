# problems

Soluções de problemas de programação competitiva em **C++**, **C**, **Python** e **Java**, mais uma
biblioteca própria de algoritmos e estruturas de dados.

Uso o repositório como caderno de treino desde que entrei na universidade (2023): problemas de juízes
online, contests internos de seleção e listas de exercícios. Não é um arquivo de submissões — é onde
consolido as técnicas que uso depois em entrevista e em prova.

## O que tem aqui

398 arquivos-fonte no total.

| Pasta | Arquivos | O que é |
|---|---|---|
| `seletiva2026` | 166 | 9 contests + 9 listas de exercícios do processo seletivo interno de 2026 |
| `codeforces` | 64 | problemas do Codeforces |
| `progcomp` | 44 | prática geral de contest |
| `seletiva2025` | 41 | processo seletivo interno de 2025 |
| `CSES` | 21 | [CSES Problem Set](https://cses.fi/problemset/) |
| `lib` | 17 | **biblioteca própria** — ver abaixo |
| `atcoder` | 15 | problemas do AtCoder |
| `dsa maciano` | 14 | exercícios da disciplina de estruturas de dados |
| `VII UnBalloon Contest Mirror` | 5 | espelho de contest |
| `icpcin 2024`, `ICPCIN` | 6 | maratonas internas do CIn |
| `seletiva2021` | 4 | prova antiga de seletiva, resolvida como treino |
| `uva` | 1 | UVa Online Judge |

## A biblioteca (`lib/`)

Não é código de competição descartável — é o que eu reuso de fato. Cada arquivo é um template
copiável, escrito para eu lembrar da implementação e não precisar reescrever na prova.

```
lib/
├── algorithms/
│   ├── dsu.cpp                     union-find com compressão de caminho
│   ├── find negative cycle.cpp     detecção de ciclo negativo (Bellman-Ford)
│   ├── bsearch.cpp                 busca binária
│   ├── gcdlcm.cpp                  MDC/MMC
│   ├── custom_comparator.cpp       ordenação com comparador
│   ├── columnsum.cpp               soma de coluna (pré-processamento 2D)
│   ├── C - Anansis Cobweb.cpp      MST
│   └── M - Modulo MST.cpp          MST com pesos módulo
├── data structures/
│   └── segtree.cpp                 segment tree
├── math/
│   ├── aritmetica modular.cpp      aritmética modular
│   ├── fastexp.cpp                 exponenciação rápida
│   ├── primes.cpp                  crivo / primalidade
│   └── avlc.cpp                    árvore AVL
└── template/                       código-base de sessão
```

## Convenções

- Cada problema fica em sua própria pasta quando tem enunciado (`problem.md`) junto da solução.
- Soluções priorizam clareza de raciocínio sobre micro-otimização, exceto quando o limite de tempo exige.
- `lib/` é reutilizável; o resto é registro de treino.

## Como compilar

```bash
g++ -std=c++17 -O2 -Wall arquivo.cpp -o main
./main < input.txt
```

## Escopo

Participei de contests internos de seleção em 2023, 2025 e 2026, e resolvo problemas de juízes
online (Codeforces, CSES, AtCoder, UVa). Não competi em ICPC ou Maratona SBC — o objetivo aqui é
manter o hábito de resolver problema difícil sob restrição de tempo, que é o que a maratona treina.
