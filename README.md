_*This project has been created as part of 42 curriculum by erick.*_

# Push Swap

## Description

Push Swap is a sorting algorithm project that implements an efficient solution for sorting integers using two stacks (a and b) with a limited set of operations. The goal is to sort the numbers in stack a in ascending order using the minimum number of operations possible.

The project demonstrates understanding of:
- Stack data structures and operations
- Algorithm optimization and complexity analysis
- Memory management and error handling
- Modular programming and code organization

## Instructions

### Compilation
```bash
make                # Compile the project
make clean          # Remove object files
make fclean         # Remove object files and executable
make re             # Clean and recompile
make debug          # Compile with address sanitizer for debugging
```

### Usage
```bash
./push_swap [list of integers]
```

**Examples:**
```bash
# Sort 4 numbers
./push_swap 4 67 3 87 23
# Output: 9 operations

# Error cases
./push_swap 0 one 2 3
# Output: Error

./push_swap ""
# Output: Error
```

### Operations Available
- **sa**: Swap first 2 elements at top of stack a
- **sb**: Swap first 2 elements at top of stack b  
- **ss**: sa and sb at same time
- **pa**: Push first element from b to top of a
- **pb**: Push first element from a to top of b
- **ra**: Rotate stack a (first element becomes last)
- **rb**: Rotate stack b (first element becomes last)
- **rr**: ra and rb at same time
- **rra**: Reverse rotate stack a (last element becomes first)
- **rrb**: Reverse rotate stack b (last element becomes first)
- **rrr**: rra and rrb at same time

## Technical Implementation

### 1. Data Structures

#### Stack Node Structure
```c
typedef struct s_stack
{
    int value;          // The actual integer value
    int index;          // Normalized position (0 = smallest)
    struct s_stack *next;
} t_stack;
```

#### Why Two Fields?
- **value**: Original integer for final output
- **index**: Normalized position for efficient comparison
- **Normalization**: Converts arbitrary values to 0,1,2,... for algorithm efficiency
*This project has been created as part of the 42 curriculum by eride-ol.*

# Push Swap

## Description
Sorting integers using two stacks (`a` and `b`) with a limited set of stack operations. The program outputs a minimal sequence that sorts stack `a` in ascending order, validating inputs (integers only, no duplicates, within `int` limits).

## What to Submit
- `Makefile` (`all`, `clean`, `fclean`, `re`; no relink)
- Project `*.c` / `*.h`
- `libft/` sources and its `Makefile`
- **Do not submit** auxiliary testers/scripts (Push-Swap-Tester binaries, run_ops.py, run_tester wrappers, etc.).

## Instructions
### Build & Run
```bash
make            # build push_swap
make clean      # remove objects
make fclean     # remove objects and binary
make re         # rebuild
./push_swap 2 1 3 6 5 8
```
- No args: no output, exit 0
- On error: print "Error" to stderr (bad number, overflow, duplicates, empty arg)

## Operations
`sa sb ss pa pb ra rb rr rra rrb rrr`
- swap top 2, push between stacks, rotate (top to bottom), reverse rotate (bottom to top); combined ops act on both stacks.

## Algorithm (current implementation)
- Each node: `value`, `index`, `pos`, `target_pos`, `cost_a`, `cost_b`.
- Push phase: move from `a` to `b` all nodes with `index <= size-3` until 3 remain in `a` (no chunking).
- Sort 3: `sort_three` on the remaining 3 in `a`.
- Reinsertion loop (while `b` not empty):
  1) recompute positions;
  2) `get_target_positions` chooses where each `b` node lands in `a`;
  3) `calculate_costs` finds minimal rotations for `a`/`b`;
  4) `execute_cheapest_move` rotates (favoring shared direction) and `pa`.
- Final align: `shift_stack` rotates `a` to put the smallest on top if needed.

## Performance (20 seeds, 0–19, via run_ops.py)
- 100 numbers: min/max/avg = 580 / 657 / 617.10 ; p95 ≈ 656.35 (limit < 700 ✅)
- 500 numbers: min/max/avg = 5322 / 5667 / 5505.05 ; p95 ≈ 5666.70 (limit 5500: maioria ok, alguns casos ~5.66k)

### Usage Examples
```bash
./push_swap 3 2 1
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
ARG="4 67 3 87 23"; ./push_swap $ARG | ./Push-Swap-Tester/checker_linux $ARG
```

### Testing Aids (local, não subir)
- Estatísticas rápidas: `python3 run_ops.py` (20 seeds de 100/500 elementos).
- Wrapper oficial: `bash run_official_tester.sh` (conveniência para Push-Swap-Tester).

## Error Handling
- Rejeita entradas não numéricas, vazias, duplicadas ou fora de `int` com `Error\n` em stderr.
- Se já estiver ordenado ou tiver 0/1 elemento, não imprime nada.

## Resources
- 42 push_swap subject (PDF)
- Referências de operações de pilha e algoritmos de ordenação
- AI usage: apoio em documentação, pequenos ajustes de código e scripts de validação/benchmarks; algoritmos centrais, parsing e operações implementados manualmente.
    else if ((*stack)->next->index == max)
