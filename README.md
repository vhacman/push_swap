# 📦 Push_swap

![Language](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-lightgrey)
![License](https://img.shields.io/badge/license-42%20Project-informational)
![Status](https://img.shields.io/badge/status-Completed-brightgreen)

---

## 📚 Indice

- [📖 Descrizione](#descrizione)
- [🎯 Obiettivi](#obiettivi)
- [🧩 Architettura del progetto](#architettura-del-progetto)
- [🔎 Algoritmi principali](#algoritmi-principali)
  - [🧠 Merge Sort](#merge-sort)
  - [🔧 Mini Sort](#mini-sort)
  - [🌀 Hybrid Sort](#hybrid-sort)
  - [🚀 Ultra Chunk Sort](#ultra-chunk-sort)
- [🛠️ Funzioni principali](#funzioni-principali)
- [🧪 Esempio di utilizzo](#esempio-di-utilizzo)
- [⚙️ Makefile](#makefile)
- [🧵 Evoluzione del progetto](#evoluzione-del-progetto)
- [🧭 Diagramma logico](#diagramma-logico)
- [📫 Contatti](#contatti)

---

## 📖 Descrizione

**Push_swap** è un progetto 42 che consiste nell’ordinare una lista di numeri interi utilizzando due stack (A e B) e un insieme limitato di istruzioni. L’obiettivo è farlo con **il minor numero possibile di mosse**, rispettando vincoli tecnici come il divieto di usare cicli `for`, operatori ternari o strutture boolean.

---

## 🎯 Obiettivi

- ✨ Ordinare input di dimensione variabile (3, 5, 100, 500 elementi…)
- 🔁 Minimizzare il numero totale di istruzioni
- ⚡ Utilizzare strategie differenti in base alla dimensione
- 🧠 Ottimizzare tramite merge sort, chunking e approccio greedy

---

## 🧩 Architettura del progetto

### 📂 Struttura per moduli

| File                   | Responsabilità principale                                      |
|------------------------|---------------------------------------------------------------|
| `main.c`               | Inizializzazione e sorting                                    |
| `validate_input.c`     | Parsing, validazione, error handling                          |
| `assign_indices.c`     | Assegnazione indici ordinati ai valori                        |
| `merge_algorithm.c`    | Merge sort su array temporaneo                                |
| `mini_sort_a.c`        | Ordinamento fino a 5 elementi                                 |
| `hybrid_sort.c`        | Ordinamento ibrido con chunk e rotazioni combinate            |
| `ultra_chunk_sort.c`   | Strategia ottimizzata per 500 elementi                        |
| `cost_utils.c`         | Calcolo costi di rotazione                                    |
| `execute_optimal_moves.c` | Esecuzione combinata di mosse ottimali                   |
| `stack_operations.c`   | Operazioni `sa`, `ra`, `pb`, etc. su stack reali              |
| `operations.c`         | Operazioni su array fittizi                                   |
| `stack_utils.c`        | Utility: creazione, conversione, free                         |
| `stack_check.c`        | Verifica ordinamento e stack vuoto                            |
| `debug.c`              | Debugging visuale (stampa stack e indici)                     |

---

## 🔎 Algoritmi principali

### 🧠 Merge Sort

Usato per assegnare indici ordinati ai valori in input. Ordinamento stabile con complessità `O(n log n)` su array temporaneo.

### 🔧 Mini Sort

Ottimizzato per 2–5 elementi:
- Se 2: swap se necessario
- Se 3: gestisce 5 casi con `sa`, `ra`, `rra`
- Se 4 o 5: sposta i minimi in B, ordina i restanti in A, poi `pa`

### 🌀 Hybrid Sort

Per 6–499 numeri:
- Divide in chunk: `chunk_size = size / 5.5` o `size / 17`
- Calcola il costo di ogni possibile `pb`
- Usa `rr` e `rrr` per rotazioni combinate
- Ricostruisce A da B partendo dal massimo

### 🚀 Ultra Chunk Sort

Per 500 numeri:
- Chunk di dimensione `size / 9`
- Sposta su B in base al chunk corrente
- Poi ricostruisce ordinatamente A da B usando il massimo a ogni step

---

## 🛠️ Funzioni principali

```c
void assign_indices(t_stack_node *stack, int *sorted_array, int size);
void merge_sort(int *array, int size);
void mini_sort_a(t_stack_node **a, t_stack_node **b);
void hybrid_sort(t_stack_node **a, t_stack_node **b);
void ultra_chunk_sort(t_stack_node **a, t_stack_node **b, int total_size);
void rebuild_stack_a(t_stack_node **a, t_stack_node **b);
void final_rotate_a(t_stack_node **a);

🧪 Esempio di utilizzo
bash
Copia
Modifica
$ make
$ ./push_swap 3 2 1
sa ra
Test efficienza:
bash
Copia
Modifica
ARG="4 2 5 3 1"; ./push_swap $ARG | wc -l
