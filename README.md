# 🚀 Push-Swap

[![42 Project](https://img.shields.io/badge/42%20Project-Pipex-blue?style=for-the-badge&logo=42)](https://github.com/vhacman/push_swap)  
[![C Language](https://img.shields.io/badge/Made%20with-C-00599C?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))  
[![Norminette Approved](https://img.shields.io/badge/Norminette-OK-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)  
[![Memory Leak Free](https://img.shields.io/badge/Leaks-Free-success?style=for-the-badge)](https://valgrind.org/)  
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-lightgrey)
![License](https://img.shields.io/badge/license-42%20Project-informational)
![Status](https://img.shields.io/badge/42%20status-Completed-brightgreen)
---

## 📚 Indice
- [📖 Descrizione](#descrizione)
- [🎯 Obiettivi](#obiettivi)
- [📁 Architettura del Progetto](#architettura-del-progetto)
- [🔎 Algoritmi Principali](#algoritmi-principali)
  - [🌀 Hybrid Sort](#hybrid-sort)
  - [🧠 Merge Sort](#merge-sort)
  - [🔧 Mini Sort](#mini-sort)
  - [🚀 Ultra Chunk Sort](#ultra-chunk-sort)
- [🛠️ Funzioni Principali](#funzioni-principali)
- [🎬 Esempio di Utilizzo](#esempio-di-utilizzo)
- [🛠️ Build](#build)
- [📝 Licenza](#licenza)
- [🧑‍💻 Contatti](#contatti)
---

# Descrizione
L’obiettivo principale è scrivere un programma che, dato un input con numeri interi (stack a) e partendo da uno stack b vuoto, calcoli e visualizzi la sequenza minima di operazioni necessarie per ordinare stack a in ordine ascendente.

## Input e Validazione:
Il programma riceve una lista di numeri interi come argomenti e, attraverso funzioni dedicate (come quelle viste in validate_input.c), verifica la correttezza dell’input, gestendo errori quali valori non numerici, duplicati o numeri fuori dai limiti.

## Assegnazione degli Indici:
Utilizzando tecniche di ordinamento (ad esempio, merge sort implementato in merge_algorithm.c) si converte lo stack in un array ordinato, assegnando a ciascun nodo un indice corrispondente alla sua posizione nell’ordine crescente .

## 📐 Strategie di Ordinamento 📐
Per numeri di piccole dimensioni si impiegano algoritmi semplificati (come in mini_sort_a.c), mentre per dataset più grandi vengono utilizzati approcci ibridi o a chunk (vedi hybrid_sort.c e ultra_chunk_sort.c) per minimizzare il numero di operazioni, con ulteriori ottimizzazioni attraverso il calcolo del “costo” delle mosse (gestito in cost_utils.c e execute_optimal_moves.c).

## Esecuzione delle Operazioni:
Le funzioni implementate per eseguire operazioni di base (swap, push, rotate, reverse rotate) e le loro versioni doppie (in stack_double_operations.c e double_operations.c) manipolano le pile per spostare e ordinare gli elementi.
---
# Obiettivi
---
# Architettura del Progetto
```bash
push_swap/
├── include/
│   └── push_swap.h                # Header principale: struct, prototype, define generici
├── main/
│   └── main.c                     # Entry point: inizializza, seleziona algoritmo, libera stack
├── src/
│   ├── algorithms/
│   │   ├── hybrid_sort.c          # Ordinamento per ≤500 numeri (chunk dinamici, greedy)
│   │   ├── merge_algorithm.c      # Merge Sort: ordinamento array temporaneo per gli indici
│   │   ├── mini_sort_a.c          # Ordinamento per 2–5 elementi (rotazioni manuali)
│   │   └── ultra_chunk_sort.c     # Ordinamento ottimizzato per ≥500 numeri (chunk statici)
│   │
│   ├── error_handling/                     
│   │   ├── controls.c             # Controlli extra (es. is_sorted, is_valid, ecc.)
│   │   ├── error.c                # Gestione errori critici e exit
│   │   ├── free.c                 # Funzioni per liberare stack, array, costi, ecc.
│   │   └── validate_input.c       # Parsing input, gestione duplicati, overflow, caratteri non numerici
│   │
│   ├── execute_optimal_moves/
│   │   └── execute_optimal_moves.c  # Rotazioni combinate (rr, rrr), push intelligente
│   │
│   ├── libft/
│   │   ├── includes               # Header della libft
│   │   ├── src/                   # Tutti i file implementativi della libft
│   │   └──── ...                  # Es. ft_split.c, ft_atoi.c, ft_strlen.c
│   │ 
│   ├── utils/
│   │   └── debug_functions/
│   │       └── debug.c            # Stampa stato degli stack, indici, informazioni di debug
│   │
│   ├── stack_operations/         
│   │   └── print_operations/
│   │   │   ├── print_push_print_swap.c        # Stampa `sa`, `sb`, `pa`, `pb`
│   │   │   ├── print_rotate_print_rrotate.c   # Stampa `ra`, `rb`, `rra`, `rrb`
│   │   │   └── print_stack_double_operations.c# Stampa `ss`, `rr`, `rrr`
│   │   │
│   │   ├── stack_double_operations.c # Esecuzione di `ss`, `rr`, `rrr` su stack reali
│   │   └── stack_operations.c        # Operazioni base `sa`, `ra`, `pb`, `pa`, ecc.
├── Makefile                          # Compilazione: definisce regole e target (`make`, `clean`, `fclean`, ecc.)
└── README.md                         # Documentazione generale del progetto

```
---
# Algoritmi principali

## Hybrid Sort

L'algoritmo usa un approccio **"ibrido"** che adatta la strategia in base alla dimensione dell’input:

🔹 **Insiemi piccoli (≤ 5 elementi)**: viene usato un ordinamento diretto (`mini_sort`).

🔸 **Insiemi medio-piccoli (da 6 a 499 elementi)**: entra in gioco `hybrid_sort`, che lavora a **chunk**.

L'idea è quella di suddividere lo stack in gruppi (chunk) e spostare gli elementi da `stack_a` a `stack_b` in modo ottimizzato, calcolando per ciascun elemento il **costo minimo di spostamento**.

### 📊 Calcolo dei costi e scelta del movimento migliore

- 📍 `distance_to_top()` → Distanza dalla cima dello stack
- 🎯 `find_target_position_b()` → Posizione ideale nello stack B
- 🔁 `set_rotations()` → Direzione e numero di rotazioni (ra/rra, rb/rrb)
- 🔎 `calculate_move_cost()` → Calcola il costo totale delle mosse

### 🎯 Aggiornamento del target e spostamento ottimale

- 🔄 `update_if_better_target()` → Cerca il miglior candidato nel chunk corrente
- 📤 `execute_combo_move()` → Esegue rotazioni combinate e `pb`
- 🔁 `move_chunks()` → Cicla fino a svuotare `stack_a`, aggiornando i chunk dinamicamente

### 🧱 Ricomposizione e operazioni di base

- ✅ Se `stack_b` è ordinato → `pa` + `final_rotate_a()`
- 🔁 Altrimenti → `rebuild_stack_a()` + `final_rotate_a()`

### ⚙️ Operazioni fondamentali

- 🔄 `swap`: scambia i primi due elementi
- 📤 `push`: sposta il primo elemento tra gli stack
- 🔃 `rotate`: primo → fondo
- 🔁 `reverse_rotate`: ultimo → in cima
- 🔁 `rr`, 🔃 `rrr`, 🔀 `ss`: rotazioni doppie
---
Questo diagramma illustra il flusso logico dell’algoritmo `hybrid_sort`, dalla scelta iniziale fino alla ricostruzione dello stack A:

![Hybrid Sort Flowchart](hybrid_sort_flowchart.png)
---

## Merge Sort

L'algoritmo **Merge Sort** viene utilizzato in `push_swap` per **ordinare un array temporaneo** e assegnare correttamente gli **indici ordinati** agli elementi dello stack.

🔹 È un algoritmo ricorsivo basato sulla strategia **divide et impera**.

---

### 🔁 Suddivisione ricorsiva e fusione

- ✂️ Divide l’array in due metà
- 🔁 Applica ricorsione su entrambe
- 🔗 `merge_arrays()` → fonde due sottosequenze ordinate
- 🧾 `copy_temp_to_array()` → aggiorna il segmento ordinato nell’array principale

---

### 🔀 Fusione degli array ordinati

- 📍 Confronta due sottosequenze ordinate
- 🧩 Inserisce i valori in `arr_temp`
- 📦 Copia i rimanenti una volta terminato uno dei segmenti

---

### 📥 Copia nel vero array

- 📤 Copia ordinata da `arr_temp` a `array`
- 🧼 Modifica solo il segmento in questione

---

### 🚪 Ingresso nell’algoritmo

- 🧠 `merge_sort()` è l’entry point
- 🔧 Alloca `arr_temp`
- 📞 Avvia la ricorsione
- 🗑 Libera la memoria alla fine

---

### 📌 Esempio pratico

```c
int array[] = {4, 2, 5, 1, 3};
merge_sort(array, 5);
```

Risultato: `[1, 2, 3, 4, 5]`

---

### ⏱️ Complessità

- ⏳ Tempo: O(n log n)
- 📦 Spazio: O(n)

---

### 📁 Moduli coinvolti

- `merge_algorithm.c`
  - `merge_sort()`
  - `merge_sort_recursive()`
  - `merge_arrays()`
  - `copy_temp_to_array()`

Questo diagramma illustra il flusso logico dell’algoritmo `merge_sort`

![Merge Sort Flowchart](merge_sort_flowchart.png)
---

# Esempio di utilizzo
Supponiamo di avere in ingresso la sequenza "2 1 3 6 5 8". Il programma analizza l’input, assegna ad ogni numero un indice basato sull’ordine crescente e, applicando le operazioni predefinite (ad esempio, eseguendo operazioni come sa, pb, ra, ecc.), ordina lo stack in maniera ottimizzata. Durante l’esecuzione, operazioni come rebuild_stack_a.c aiutano a ricostruire la pila finale da stack b, garantendo che l’ordinamento sia corretto .
---

## Build

```bash
make            # compila push_swap
make clean      # rimuove .o
make fclean     # rimuove .o e binario
make check      # manda in run checker_linux (da implementare dopo l'evaluation)
make valgrind   # check su memory leak
```

# Contatti

[![LinkedIn](https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/viorica-gabriela-hacman-63a412267/)
[![Facebook](https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white)](https://www.facebook.com/profile.php?id=100090802467237)
[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/_gabriela_aleirbag_/)

---

