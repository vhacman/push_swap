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
L'algoritmo usa un approccio "ibrido" che adatta la strategia in base alla dimensione dell’input:

🔹 Insiemi piccoli (≤ 5 elementi): viene usato un ordinamento diretto (mini_sort).

🔸 Insiemi medio-piccoli (da 6 a 499 elementi): entra in gioco hybrid_sort, che lavora a chunk.

L'idea è quella di suddividere lo stack in gruppi (chunk) e spostare gli elementi da stack_a a stack_b in modo ottimizzato, calcolando per ciascun elemento il costo minimo di spostamento.

  ## 📊 Calcolo dei costi e scelta del movimento migliore
  
Per minimizzare le mosse, l’algoritmo calcola per ogni elemento:

📍 Distanza dalla cima dello stack → calcolata con distance_to_top()

🎯 Posizione ideale nello stack B → trovata con find_target_position_b()

🔁 Direzione e numero di rotazioni → determinati da set_rotations(), che decide se usare rotazioni normali (ra, rb) o inverse (rra, rrb) in base alla posizione

🔎 La funzione calculate_move_cost() utilizza queste informazioni per calcolare il costo totale (in numero di operazioni) per spostare ogni elemento.

🎯 Aggiornamento del target e spostamento ottimale

La funzione update_if_better_target():

Scorre lo stack_a

Analizza solo gli elementi con indice entro il limite del chunk corrente

Calcola il costo per ciascuno

## 📈 Aggiorna il target da spostare se trova un'opzione più economica in termini di mosse

Una volta scelto il candidato ottimale, viene chiamata execute_combo_move():

🔄 Esegue le rotazioni necessarie su entrambi gli stack

📤 Sposta l’elemento da a a b (pb)

🔁 La funzione move_chunks() gestisce l’intero ciclo:

Finché a non è vuoto, cerca e sposta i migliori candidati

Se il chunk corrente non contiene elementi validi, aumenta il limite per ampliare la ricerca
🧱 Ricomposizione e operazioni di base

Dopo aver popolato stack_b:
✅ Se stack_b è già ordinato, viene svuotato in a con pa, seguito da una rotazione finale con final_rotate_a()

🔁 Altrimenti, viene utilizzata rebuild_stack_a() per reinserire gli elementi in a partendo dal più grande, seguita sempre da final_rotate_a()

## ⚙️ Operazioni fondamentali
Le operazioni di base sono implementate in logic_operations.c e agiscono direttamente sugli array che rappresentano gli stack:

🔄 swap: scambia i primi due elementi

📤 push: sposta il primo elemento da uno stack all’altro

🔃 rotate: porta il primo elemento in fondo allo stack

🔁 reverse_rotate: porta l’ultimo elemento in cima

Inoltre, double_logic_operations.c contiene operazioni "doppie" che agiscono contemporaneamente su entrambi gli stack, ottimizzando le rotazioni:

🔁 rr: ra + rb

🔃 rrr: rra + rrb

🔀 ss: sa + sb

Questo diagramma illustra il flusso logico dell’algoritmo `hybrid_sort`, dalla scelta iniziale fino alla ricostruzione dello stack A:

![Hybrid Sort Flowchart](./docs/hybrid_sort_flowchart.png)
---
## Merge Sort
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

