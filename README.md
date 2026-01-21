*This project has been created as part of the 42 curriculum by eride-ol.*

# Push Swap

## Description

Push Swap is a sorting algorithm project that implements an efficient solution for sorting integers using two stacks (a and b) with a limited set of operations. The goal is to sort the numbers in stack a in ascending order using the minimum number of operations possible.

The program validates inputs (integers only, no duplicates, within `int` limits) and outputs a minimal sequence of stack operations to achieve the sort.

The project demonstrates understanding of:
- Stack data structures and linked list operations
- Algorithm optimization and complexity analysis
- Memory management and error handling
- Modular programming and code organization

## Compilation

```bash
make            # Compile push_swap executable
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Clean and recompile
make bonus      # Compile checker bonus executable
```

**Note:** Uses `cc` compiler with flags `-Wall -Wextra -Werror`. Automatically compiles `libft/libft.a` as dependency.

## Usage

```bash
./push_swap [list of integers]
```

**Examples:**
```bash
# Sort 5 numbers
./push_swap 4 67 3 87 23

# Validate output with checker
./push_swap 2 1 3 | ./checker 2 1 3
# Output: OK

# Already sorted (no output)
./push_swap 1 2 3
# Output: (no output, exit 0)

# Error cases
./push_swap 0 one 2 3       # Error: non-numeric
./push_swap 1 2 2 3         # Error: duplicate
./push_swap 9999999999      # Error: overflow
./push_swap ""              # Error: empty string
```

**Behavior:**
- No arguments: no output, exit 0
- Already sorted: no output, exit 0
- On error: print "Error\n" to stderr, exit 1

## Operations

The program uses these 12 stack operations:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack a |
| `sb` | Swap first 2 elements of stack b |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push top of stack b to stack a |
| `pb` | Push top of stack a to stack b |
| `ra` | Rotate stack a (first becomes last) |
| `rb` | Rotate stack b (first becomes last) |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b (last becomes first) |
| `rrr` | Perform `rra` and `rrb` simultaneously |

## Technical Implementation

### Data Structures

#### Stack Node
```c
typedef struct s_stack
{
    int             value;       // Original integer value
    int             index;       // Normalized position (0 = smallest)
    int             pos;         // Current position in stack
    int             target_pos;  // Target position after sorting
    int             cost_a;      // Rotation cost in stack a
    int             cost_b;      // Rotation cost in stack b
    struct s_stack  *next;       // Linked list pointer
} t_stack;
```

**Field Details:**
- **value**: The actual input integer (for validation)
- **index**: Normalized rank from 0 to n-1 (enables efficient comparison regardless of input values)
- **pos/target_pos**: Current and destination positions (updated during algorithm execution)
- **cost_a/cost_b**: Pre-calculated rotation costs (used to find cheapest moves)

### Algorithm: Turk Algorithm with Progressive Chunks

The sorting process occurs in four phases:

#### Phase 1: Push Phase (Chunking)
- Divide dataset into progressive chunks
  - ≤100 elements: 5 chunks of ~20 each
  - >100 elements: 11 chunks of ~10 each
- Move elements from a to b where `index <= pushed + chunk_size`
- **Pre-rotation in B**: Elements below median are rotated to bottom using `rb`, keeping larger indices at top
  - Reduces rotation costs in reinsertion phase by ~5%
  - Better element distribution across stack

#### Phase 2: Sort Remaining 3
- Special `sort_three()` function optimally sorts remaining 3 elements in stack a with 2-3 operations

#### Phase 3: Reinsertion Loop
While stack b is not empty:
1. Recompute positions for all elements
2. Calculate target position: where will top of b land in sorted a?
3. Compute rotation costs:
   - Same direction: `max(|cost_a|, |cost_b|)` (uses `rr`/`rrr` for simultaneous execution)
   - Opposite directions: `|cost_a| + |cost_b|` (separate rotations needed)
4. Execute cheapest move and push to a

#### Phase 4: Final Alignment
- Rotate stack a to place the minimum element on top (if not already there)

### Performance Results

Tested with 10 random seeds each:

| Size | Min | Max | Average | Limit | Status |
|------|-----|-----|---------|-------|--------|
| 100 | 560 | 650 | **597** | <700 | ✅ 14.7% margin |
| 500 | 4295 | 4848 | **4469** | ≤5500 | ✅ 18.7% below |

**Optimizations Implemented:**
1. **Progressive chunks**: Better element distribution reduces rotation requirements
2. **Pre-rotation in B**: ~5% cost reduction through better positioning
3. **Real cost calculation**: Accounts for simultaneous operations (`rr`/`rrr`), ~10-15% improvement
4. **Combined effect**: ~19% overall improvement vs. naive implementation

### Code Organization

**Sorting Algorithm:**
- [turk_algorithm.c](turk_algorithm.c) - Main orchestration and phase control
- [turk_target.c](turk_target.c) - Target position calculation
- [turk_cost.c](turk_cost.c) - Cost analysis and cheapest move execution
- [turk_shift.c](turk_shift.c) - Final stack alignment

**Sorting Operations:**
- [sort_small.c](sort_small.c) - Optimized sorting for 2-5 elements
- [operations.c](operations.c) - Push and swap operations (sa, sb, ss, pa, pb)
- [rotate_operations.c](rotate_operations.c) - Rotation operations (ra, rb, rr)
- [reverse_operations.c](reverse_operations.c) - Reverse rotation operations (rra, rrb, rrr)

**Supporting Infrastructure:**
- [validation.c](validation.c) - Input validation and error handling
- [parse_args.c](parse_args.c) - Argument parsing with overflow detection
- [parse_int.c](parse_int.c) - Integer parsing utilities
- [stack_utils.c](stack_utils.c) - Stack creation, navigation, and manipulation
- [index.c](index.c) - Index/rank calculation and normalization
- [utils.c](utils.c) - Memory management and utility functions

**Main Program:**
- [main.c](main.c) - Entry point and orchestration
- [push_swap.h](push_swap.h) - Header with all function declarations

## Bonus: Checker

The checker program validates push_swap output:

```bash
./push_swap [numbers] | ./checker [numbers]
```

**Output:**
- `OK` - Stack a is properly sorted
- `KO` - Stack a is not sorted or operation sequence is invalid
- `Error` - Invalid input

Compiled as `checker` target via `make bonus`

## Error Handling

The program validates all inputs and rejects with "Error\n" on stderr for:
- Non-numeric arguments
- Values outside the int range (overflow)
- Duplicate values
- Empty string arguments

If the input is already sorted or contains 0-1 elements, no operations are output (exit 0).

## Directory Structure

```
push_swap/
├── Makefile              # Build configuration
├── push_swap.h           # Header file with function declarations
├── main.c               # Entry point
├── validation.c         # Input validation
├── parse_args.c         # Argument parsing
├── parse_int.c          # Integer parsing
├── stack_utils.c        # Stack operations
├── index.c              # Index calculation
├── utils.c              # Utilities
├── operations.c         # Push/swap operations
├── rotate_operations.c  # Rotation operations
├── reverse_operations.c # Reverse rotation operations
├── sort_small.c         # Small sort optimization
├── sort_utils.c         # Sorting utilities
├── turk_algorithm.c     # Main algorithm
├── turk_target.c        # Target position calculation
├── turk_cost.c          # Cost analysis
├── turk_shift.c         # Final alignment
├── checker_bonus.c      # Checker bonus program
├── libft/               # Custom C library
│   ├── Makefile
│   ├── libft.h
│   └── *.c              # Standard library functions
└── tests/               # Testing utilities (local development only)
    ├── README.md
    ├── Makefile
    └── *.sh             # Test scripts
```

## Testing

A comprehensive test suite is available in the `tests/` folder for local development:

```bash
cd tests
make help           # List available tests
make run_basic      # Basic functionality (10 cases)
make run_checker    # Checker validation (8 cases)
make run_extended   # Extended integration (8 cases)
make run_all        # All tests (26 cases)
make run_stress     # Stress test (500+ cases with memory check)
```

See [tests/README.md](tests/README.md) for detailed testing documentation.

## Resources

### Classic References
- **42 School Push Swap Subject** - Official project specification and requirements
- **Introduction to Algorithms** (Cormen, Leiserson, Rivest, Stein) - Sorting algorithms and complexity analysis
- **The C Programming Language** (Kernighan & Ritchie) - Standard C library and best practices
- **Data Structures and Algorithm Analysis in C** (Weiss) - Stack operations and algorithm 
- **Push_swap_tutorial** (https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)

### Algorithm References
- **Sorting and Searching** - Knuth's foundational work on sorting techniques
- **Linked Lists** - MIT OpenCourseWare materials on linked data structures
- **Stack-based Algorithms** - Understanding stack operations and their applications

### AI Usage

AI was used for the create tasks:

## Notes

- Tests are not part of the official submission; they exist in `tests/` for local development
- Project follows 42 school curriculum standards
- All source code must be submitted with Makefile and libft
- The checker bonus is optional but recommended for testing
