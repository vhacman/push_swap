# Push_swap 🚀

![Language](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-lightgrey)
![License](https://img.shields.io/badge/license-42%20Project-informational)
![Status](https://img.shields.io/badge/status-Completed-brightgreen)
![Version](https://img.shields.io/badge/version-1.0.0-blue)

> **Push_swap** è un progetto 42 che consiste nell'ordinare una lista di numeri interi utilizzando due stack (A e B) e un set limitato di operazioni, il tutto cercando di minimizzare il numero di mosse.

---

## 📚 Indice

- [Descrizione](#descrizione)
- [Obiettivi](#obiettivi)
- [Architettura del Progetto](#architettura-del-progetto)
- [Algoritmi Principali](#algoritmi-principali)
  - [Merge Sort](#merge-sort)
  - [Mini Sort](#mini-sort)
  - [Hybrid Sort](#hybrid-sort)
  - [Ultra Chunk Sort](#ultra-chunk-sort)
- [Funzioni Principali](#funzioni-principali)
- [Esempio di Utilizzo](#esempio-di-utilizzo)
- [Demo](#demo)
- [Come Contribuire](#come-contribuire)
- [Licenza](#licenza)
- [Contatti](#contatti)

---

## 📖 Descrizione

**Push_swap** è un progetto che sfida la logica e l'ottimizzazione, dove l'obiettivo è ordinare numeri interi utilizzando due stack e un set ristretto di istruzioni (es. `sa`, `ra`, `pb`, ecc.). L'approccio si basa su algoritmi di ordinamento come il merge sort e tecniche di chunking per minimizzare il numero di mosse.

---

## 🎯 Obiettivi

- **Ottimizzazione**: Ordinare input di diverse dimensioni (es. 3, 5, 100, 500 elementi) nel minor numero di mosse.
- **Tecniche Diverse**: Utilizzo di strategie differenti in base alla dimensione dell'input.
- **Approccio Innovativo**: Implementazione di algoritmi come merge sort, mini sort, hybrid sort e ultra chunk sort.

---

## 🧩 Architettura del Progetto

Il progetto è suddiviso in moduli, ognuno con una responsabilità specifica:

| File                           | Responsabilità                           |
|--------------------------------|------------------------------------------|
| `main.c`                       | Inizializzazione e sorting               |
| `validate_input.c`             | Parsing e validazione degli input        |
| `assign_indices.c`             | Assegnazione degli indici agli elementi  |
| `merge_algorithm.c`            | Merge sort su array temporaneo           |
| `mini_sort_a.c`                | Ordinamento di piccole liste              |
| `hybrid_sort.c`                | Ordinamento ibrido con chunking          |
| `ultra_chunk_sort.c`           | Strategia per input di grandi dimensioni   |
| `cost_utils.c`                 | Calcolo dei costi delle rotazioni        |
| `execute_optimal_moves.c`      | Esecuzione combinata delle mosse           |
| `stack_operations.c`           | Operazioni sugli stack (swap, push, ecc.)  |
| `operations.c`                 | Operazioni su array                        |
| `stack_utils.c`                | Utility per gestione degli stack           |
| `stack_check.c`                | Verifica dell'ordinamento e validità       |
| `debug.c`                      | Debug e visualizzazione degli stack        |

---

## 🔎 Algoritmi Principali

### 🧠 Merge Sort

Utilizzato per ordinare gli elementi e assegnare indici, garantendo una complessità `O(n log n)`.

### 🔧 Mini Sort

Ottimizzato per liste di 2-5 elementi, sfruttando semplici operazioni come `sa`, `ra` e `rra`.

### 🌀 Hybrid Sort

Adatto per input da 6 a 499 elementi, suddivide i dati in chunk e utilizza rotazioni combinate per ottimizzare il numero di mosse.

### 🚀 Ultra Chunk Sort

Ideale per 500 elementi: divide l'input in chunk più piccoli e ricostruisce l'ordine finale spostando gli elementi in modo strategico.

---

## 🛠️ Funzioni Principali

Alcune funzioni chiave includono:

```c
void assign_indices(t_stack_node *stack, int *sorted_array, int size);
void merge_sort(int *array, int size);
void mini_sort_a(t_stack_node **a, t_stack_node **b);
void hybrid_sort(t_stack_node **a, t_stack_node **b);
void ultra_chunk_sort(t_stack_node **a, t_stack_node **b, int total_size);
void rebuild_stack_a(t_stack_node **a, t_stack_node **b);
void final_rotate_a(t_stack_node **a);

```
🎬 Esempio di Utilizzo
Compilazione:

bash
Copia
make
Esecuzione:

bash
Copia
./push_swap 3 2 1 6 5 8
Output: Il programma mostrerà le mosse necessarie per ordinare i numeri.

📹 Demo
Guarda la demo online o dai un'occhiata a questo screenshot:


🤝 Come Contribuire
Fork il repository.

Crea un branch per la tua feature (git checkout -b feature/nome-feature).

Commit le tue modifiche (git commit -m 'Aggiungi nuova feature').

Push sul branch (git push origin feature/nome-feature).

Apri una Pull Request.

Ogni contributo è benvenuto! Controlla CONTRIBUTING.md per maggiori dettagli.

📝 Licenza
Questo progetto è distribuito sotto la licenza 42 Project.
