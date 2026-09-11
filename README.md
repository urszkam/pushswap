*This project has been created as part of the 42 curriculum by urkamins, pausulzy.*

## # Table of Contents
- [Description](#description)
- [Instructions](#instructions)
    - [Prerequisites](#prerequisites)
    - [Clone the Repository](#clone-the-repository)
    - [Compile the Program](#compile-the-program)
    - [Usage](#usage)
    - [Cleanup](#cleanup)
- [Resources](#resources)
- [Visualizer Setup](#visualizer-setup)
- [Algorithms](#algorithms)
    - [Simple Sort](#simple-sort)
    - [Medium Sort](#medium-sort)
    - [Complex Sort](#complex-sort)
    - [Adaptive Sort](#adaptive-sort)
- [Attribution](#attribution)

## Description

**Push_swap** sorts integers using two stacks and a limited set of operations. The goal is to produce the shortest possible sequence of moves.

- **Push** (`pa`, `p`b`): moves a value from the top of one stack onto the top of the other
- **Swap** (`sa`, `sb`, `ss`): swaps the first two values on the top of a given stack
- **Rotate** (`ra`, `rb`, `rr`): "rotates" the stack, sending its top value to the bottom
- **Reverse rotate** (`rra`, `rrb`, `rrr`): the same in reverse, bringing the bottom value to the top

## Instructions
### Prerequisites
Ensure you have the following installed on your system:

- C Compiler (e.g., GCC)
- Make

### Clone the Repository
Clone the libft repository to your local machine:

```bash
git clone https://github.com/urszkam/pushswap.git pushswap
```

### Compile the Program
Navigate to the **/pushswap** directory and use the provided Makefile to compile the program:

```bash
cd pushswap
make
```

This command will compile the source files and create both the **libft.a** library and **push_swap** executable.

### Usage

Run the program with a list of distinct integers. Options must come before any numeric arguments:

```bash
./push_swap [OPTIONS] INTEGERS
```

Available optional flags:

- `--simple`, `--medium`, `--complex`: select a specific sorting algorithm
- `--adaptive`: choose an algorithm based on input disorder (default)
- `--bench`: print disorder, algorithm information and operation statistics to `stderr`

Examples:

```bash
./push_swap 7 4 9 2 1
./push_swap --complex --bench 7 4 9 2 1
```

### Cleanup
If needed, you can clean the generated files using:

```bash
make clean
```
This removes the object files but keeps the compiled library, **libft.a**, and executable, **push_swap**. To remove both object files as well as both the library and executable, use:

```bash
make fclean
```

## Resources
- [Stack implementation with linked lists](https://medium.com/@dev.siddiquee/stack-implementation-with-singly-linked-list-a-guide-e9fa2b1aa14a)
- [Sorting algorithms](https://www.programiz.com/dsa/sorting-algorithm)
- [Insertion Sort](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/)
- [Butterfly sort](https://dynamicdispat.ch/posts/2024/01/push-swap/#-butterfly-sort-2)
- [Merge sort](https://www.geeksforgeeks.org/dsa/merge-sort/)
- [Bottom-up merge sort](https://www.baeldung.com/cs/merge-sort-top-down-vs-bottom-up)
- AI was used to generate tests and search for possible optimizations, as well as to research algorithmic sorting in general

## Visualizer Setup

A [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) is helpful for monitoring program activity, but requires changing a few things to make sure it works on more modern versions of Ubuntu (disabling one warning and correcting the `cmake` call path). Note, make sure to edit `YOUR_USERNAME` to your actual username:
```bash
git clone https://github.com/o-reo/push_swap_visualizer
cd push_swap_visualizer
sed -i 's/-Werror>$/-Werror -Wno-ignored-attributes>/' src/CMakeLists.txt
export PATH=/usr/bin:/home/<YOUR_USERNAME>/.local/bin:$PATH
mkdir build
cd build
cmake ..
make
```
The resulting **push_swap_visualizer/build/bin** directory contains the visualizer files. Copy the folder to where the compiled **push_swap** program resides, and run it via `./visualizer`. There will be three settings tables: *Controls*, *Values*, and *Commands*. They might be overlapping, so just move the top one around to see if there's another underneath, then use the *Scale UI* bar to resize them. These table positions (but not resizing settings) will be saved in the **imgui.ini** file for next use.

In the *Values* container, enter a number into the *Count* input and click *Shuffle*, or enter your own list into the *Values* input. Ensure the the correct `../push_swap` file path is entered and select *Compute*. Now, in the *Controls* box, click *Start* to commence the visualization, and controlling *Speed* and playback actions as needed while it runs.

## Algorithms

Stacks are implemented as singly linked lists, which support dynamic sizing and avoid shifting other elements when the top is modified.

In the complexity estimates below, `n` denotes the input size, while the complexity (`O`) denotes the number of stack operations produced by the program × input size. The stacks require `O(n)` space for their nodes, while the algorithms use `O(1)` additional space by relinking the existing nodes.

### Simple Sort

Simple sort inserts each of the `n` values into `stack_b`. Finding the correct position may require up to `n` rotations per value, giving `O(n²)` operations in the worst case and `O(n)` in the best case. Insertion sort was chosen because it requires fewer moves on nearly sorted input. With an input of small disorder, successive values usually belong close to their final position, which limits the number of required rotations. This sort undergoes the following steps:

1. Move the first value from `stack_a` to `stack_b` and keep the current `maximum` in memory.
2. For each remaining value in `stack_a`, find its insertion position (more than next value, less than the previous one) in `stack_b`.
3. Rotate `stack_b` in the shorter direction, push the current value from `stack_a` and update the `maximum` value if necessary.
4. Once `stack_a` is empty, rotate `stack_b` until its `maximum` is on top (`stack_b` is kept in descending order).
5. Push every value back to `stack_a`, leaving it in ascending order.

![Simple sort visualization](https://github.com/urszkam/pushswap/blob/main/img/simple.jpg?raw=true)
*Visualizer of this insertion sort in three phases, passing values first to the second stack, then showing the second stack and its near-organized state a little before its return run, and finally showing the returning of the values to a final organized state to the original stack.*

### Medium Sort
Butterfly sort was chosen because it introduced some clever optimizations, namely a "bottomless window" and a clever "double sort" hack. Values are analyzed via rank on `stack_a` in constantly expanding chunks, with the chunk top limit growing by `1` with every value moved, while its bottom limit remaining at `0`. Values are then acted upon based on what category they fall into:

- Small, within chunk: pushed to the bottom of `stack_b`
- Large, within chunk: pushed to the top of `stack_b`
- Very large, outside chunk range: rotated to the bottom of `stack_a`

The first two steps show the double-sort mechanism, where values are further sorted on `stack_b` using its two ends as immediate, extra sorting points.

This first phase renders an asymmetrical, butterfly-shaped `stack_b` of all values, sorted into chunks and providing the heart of this `O(n√n)` complexity. The the next phase rotates `stack_b`, popping values off either its top or bottom and laying them onto `stack_a` in descending order, thereby slowly eating its way through to the smaller values in the middle of the hourglass until all are processed.

A helpful metaphor lies in imagining a teacher sorting a hundred exams by grade. They start by flipping through all exams and pulling out all results from 0-9%, putting the ones 4% and lower at the bottom of a new stack, and those from 4-9% at the top. If any exam is higher than 9%, it's just moved to the end of the original stack. They then follow through with 10-19%, 20-29%… 80-89%, 90-100%, and are left with a stack of exams sorted into 10% "chunks", each of which is easy to then organize through a second pass. The butterfly sort implemented here uses the additional "bottomless window" optimization outlined earlier, which would be hard for the teacher to perform but which a computer can do quite easily.

A final note about chunk window size: this was chosen simply through trial and error, as the numbers `15` and `30` worked well with the anticipated tests listed in the project outline.

![Medium sort visualization](https://github.com/urszkam/pushswap/blob/main/img/medium.jpg?raw=true)
*Visualizer of this butterfly sort showing the first pass ongoing, then the first pass complete and achieving its namesake shape, and lastly the second pass ongoing, nearing completion.*

### Complex Sort

Complex sort is implemented as a bottom-up merge sort algorithm. Each iteration doubles the processed run size, hence the target complexity is of `O(n log n)`. The bottom-up variant allows the merge direction to alternate between `stack_a` and `stack_b` as it goes from run size of `1` to run size of the initial stack size. It follows these general steps:

1. Split the input evenly between stacks to form the initial runs.
2. Take one run from each stack and merge their values in order into the
   destination stack.
3. Double the run size after each full iteration.
4. Repeat the merge until one sorted run of size (`stack_a`) remains.

![Complex sort visualization](https://github.com/urszkam/pushswap/blob/main/img/complex.jpg?raw=true)
*Visualizer of this bottom-up merge sort cascading values into increased order at three subsequent intervals as the program runs, swapping values back and forth between stacks.*

### Adaptive Sort

Adaptive sort chooses appropriate sorting strategy based in the input disorder. Disorder is calculated by running through the integer argument list and calculating how many subsequent values are smaller than their predecessors. This is then mapped to a number between `0` and `1`, telling how far the input is from being sorted. Algorithms are then chosen to be most efficient for this computed disorder level:
 - simple sort up to 20%
 - medium sort below 50%
 - complex sort for more than 50%

## Attribution

Sorting operations, simple and complex sorts, and flags were coded by *urkamins*; the validator and medium sort by *pausulzy*. The remainder was a collaborative effort.

---
