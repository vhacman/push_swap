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
  - [🧠 Merge Sort](#merge-sort)
  - [🔧 Mini Sort](#mini-sort)
  - [🌀 Hybrid Sort](#hybrid-sort)
  - [🚀 Ultra Chunk Sort](#ultra-chunk-sort)
- [🛠️ Funzioni Principali](#funzioni-principali)
- [🎬 Esempio di Utilizzo](#esempio-di-utilizzo)
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
│   └── push_swap.h                # Header principale del progetto
├── main/
│   └── main.c                     # Entry point
├── src/
│   ├── algorithms/
│   │   ├── hybrid_sort.c          # Ordinamento <500 numeri
|   |   ├── merge_algorithm.c      # Merge Sort
│   │   ├── mini_sort_a.c          # Ordinamento ≤5 numeri
│   │   └── ultra_chunk_sort.c     # Ordinamento ottimizzato per >= 500 numeri
|   |
│   ├── error_handling/                     
│   │   ├── controls.c             # 
│   │   ├── error.c                #
│   │   ├── free.c                 #
│   │   └── validate_input.c       # Parsing e validazione
|   |
│   ├── execute_optimal_moves/
│   │   └── execute_optimal_moves.c
|   |
│   ├── libft/
│   │   ├── includes
|   |   |        
│   │   ├── src/
|   |   └──── ...   # Operazioni su stack reali
|   | 
│   ├── utils/
│   │   └── debug_functions/
|   |       └── debug.c
│   ├── stack_operations/         
│   │   └── print_operations/
│   │   |   ├── print_push_print_swap.c      
|   |   |   ├── print_rotate_print_rrotate.c 
│   │   |   └── print_stack_double_operations.c
│   │   |
│   |   ├── stack_double_operations.c
│   |   ├── stack_operations.c
├── Makefile
├── README.md
```
---

# Esempio di utilizzo
Supponiamo di avere in ingresso la sequenza "2 1 3 6 5 8". Il programma analizza l’input, assegna ad ogni numero un indice basato sull’ordine crescente e, applicando le operazioni predefinite (ad esempio, eseguendo operazioni come sa, pb, ra, ecc.), ordina lo stack in maniera ottimizzata. Durante l’esecuzione, operazioni come rebuild_stack_a.c aiutano a ricostruire la pila finale da stack b, garantendo che l’ordinamento sia corretto .
---

# Contatti

[![LinkedIn](https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/viorica-gabriela-hacman-63a412267/)
[![Facebook](https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white)](https://www.facebook.com/profile.php?id=100090802467237)
[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/_gabriela_aleirbag_/)

---

