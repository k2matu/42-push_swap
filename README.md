# Push swap 125/100
**Push_swap** is a **sorting algorithm** project where the goal is to sort a stack of integers using two stacks and a set of predefined instructions to manipulate these stacks. The objective is to achieve the sorted order with the minimal number of moves.

## The rules
You have 2 stacks named A and B.

At the beginning the stack A contains a random amount of negative and/or positive numbers which cannot be duplicated. Stack B is empty.
The goal is to sort in ascending order numbers into stack A. 

#### Allowed moves:

- **sa** : swap a - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
- **sb** : swap b - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
- **ss** : sa and sb - Perform sa and sb at the same time.
- **pa** : push a - Take the first element at the top of stack B and put it at the top of stack A. Do nothing if stack B is empty.
- **pb** : push b - Take the first element at the top of stack A and put it at the top of stack B. Do nothing if stack A is empty.
- **ra** : rotate a - Shift up all elements of stack A by 1. The first element becomes the last one.
- **rb** : rotate b - Shift up all elements of stack B by 1. The first element becomes the last one.
- **rr** : ra and rb - Perform ra and rb at the same time.
- **rra** : reverse rotate a - Shift down all elements of stack A by 1. The last element becomes the first one.
- **rrb** : reverse rotate b - Shift down all elements of stack B by 1. The last element becomes the first one.
- **rrr** : rra and rrb - Perform rra and rrb at the same time.
At the end of the process, stack B must be empty and all integers must be in stack A, sorted in ascending order.


## Algorithm 
The sorting process combines the **Longest Increasing Subsequence (LIS) algorithm** and the **Turk algorithm**.

#### Steps:
1. All integers are initially placed on Stack A.

2. Find **Longest Increasing Subsequence (LIS)**: Identify the LIS of the integers using the Longest Increasing Subsequence algorithm.

3. Organize Stack B:

Push integers not in the LIS to Stack B.
Rotate Stack B once after each push if the number is below the mean. This results in two groups within Stack B:
- Numbers below the mean at the bottom.
- Numbers above the mean at the top.

4. Numbers remaining in Stack A are now sorted.

5. Move each number from Stack B back to Stack A, 
Utilize the **Turk algorithm** to move the "cheapest number" from Stack B back to Stack A.

6. Stack A will now contain all integers sorted in ascending order.

#### Data Structure
The integers are stored in a **Circular Doubly Linked List**.

## Prerequisites
- A C compiler (e.g., `gcc` or `clang`)
- `make`

## Compilation
1. Clone the repository:
```
git clone git@github.com:k2matu/42-push_swap.git push_swap
````
2. Navigate into the directory:
```
cd push_swap
```
3. Compile the library using make:
```
make
```

## Usage
To run the sorting algorithm, compile the program and execute it with the list of integers as command-line arguments.

Example:
```
./push_swap 3 100 4 32 65 49 2 62 15 31 5
```


## Appendix
Longest Increasing Subsequence (LIS): 
https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

Data Structure:
https://www.nesoacademy.org/cs/01-data-structures

Turk Algorithm:
https://medium.com/@ayogun/push-swap-c1f5d2d41e97


