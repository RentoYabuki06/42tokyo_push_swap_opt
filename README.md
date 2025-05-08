# Push Swap

Push Swap is a sorting algorithm project that focuses on efficiently sorting data on a stack, with a limited set of operations and using the lowest possible number of actions.

## Project Overview

The goal of this project is to sort a stack of integers using two stacks (stack A and stack B) and a limited set of operations. The program outputs the series of operations needed to sort stack A in ascending order.

**Important Note**: Unlike traditional sorting algorithms that aim to minimize computational complexity (time or space), Push Swap specifically targets minimizing the number of operations executed (sa, sb, ss, pa, pb, etc.). The challenge is not about creating the fastest algorithm in terms of execution time, but rather finding the solution that requires the fewest stack operations to achieve sorted order.

## Implementation

### Data Structure

- Uses a doubly linked list implementation for both stacks
- Each node contains:
  - Integer value
  - Position information (index, above_median)
  - Target node information
  - Cost calculations for move optimization

### Sorting Strategy

The implementation uses different sorting strategies based on the number of elements:

- For 2-3 elements: Direct comparison and swap
- For 4-5 elements: Special optimized cases
- For larger sets: Uses a complex algorithm that:
  1. Pushes elements from stack A to stack B in a strategic order
  2. Calculates the cheapest moves for each element
  3. Finds optimal rotation strategies (rotate both stacks, reverse rotate both, or separate moves)
  4. Places elements back in stack A in sorted order

### Available Operations

- `sa`, `sb`, `ss`: Swap the top two elements of stack A, B, or both
- `pa`, `pb`: Push the top element from one stack to the other
- `ra`, `rb`, `rr`: Rotate stack A, B, or both (top element goes to bottom)
- `rra`, `rrb`, `rrr`: Reverse rotate stack A, B, or both (bottom element goes to top)

## Usage

### Compilation

```sh
# Compile main program
make

# Compile bonus checker program
make bonus
```

### Running

```sh
# Sort a list of integers
./push_swap 3 1 5 2 4

# Use with checker to verify sorting operations
ARG="3 1 5 2 4"; ./push_swap $ARG | ./checker $ARG
```

### Testing

The project includes a test script [`test.py`](test.py) that can test the sorting algorithm with various sizes of random number sets:

```sh
# Run default tests (100 iterations for each size: 3, 5, 100, 500)
python3 test.py

# Run specific tests with custom iterations
python3 test.py -n 3 5 100 500 -i 50
```

## Performance

The algorithm is optimized to perform within these approximate operation counts:
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: < 700 operations
- 500 numbers: < 5500 operations

## Bonus Part

The bonus part implements a `checker` program that:
1. Takes a stack of integers as arguments
2. Reads sorting instructions from standard input
3. Executes these instructions
4. Displays "OK" if the stack is sorted or "KO" if not

Run the checker with:

```sh
./checker 3 1 5 2 4
```
Then input operations (e.g., "sa", "pb", etc.) followed by Enter, and terminate with Ctrl+D.

## Error Handling

The program handles various error cases:
- Non-numeric arguments
- Arguments exceeding integer limits
- Duplicate numbers

In case of error, it outputs "Error" to standard error.

## Author

yabukirento