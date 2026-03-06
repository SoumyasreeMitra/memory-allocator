# Custom Memory Allocator in C

## Overview

This project implements a **simplified dynamic memory allocator in C** that replicates the core functionality of `malloc()` and `free()`.

The allocator manages heap memory using a **free-list based allocation strategy** and interacts with the operating system using the `sbrk()` system call.

The goal of this project is to demonstrate fundamental concepts in:

- memory management
- operating systems
- systems programming
- pointer arithmetic
- dynamic memory allocation

---

# Key Features

- Custom implementation of `malloc()` and `free()`
- Free-list based heap memory management
- Heap expansion using the `sbrk()` system call
- Metadata tracking for each memory block
- Reuse of freed memory blocks
- Test program to validate allocator functionality

---

# Memory Layout

Each allocated block contains **metadata followed by user memory**.


| Block Metadata | User Memory |


### Metadata Structure

Each memory block stores the following information:


size → size of allocated memory
free → whether the block is available
next → pointer to next block


The allocator maintains a **linked list of memory blocks** representing the heap.

---

# Memory Allocation Visualization

The heap consists of multiple memory blocks connected as a linked list.

Initial heap state:


freeList
↓
[Block A] → [Block B] → [Block C]


Example allocation state:

Block	Status
A	Allocated
B	Free
C	Allocated

Memory block structure:


| Metadata | User Memory |


When a block is freed:

Before:


| Allocated | Allocated | Free |


After freeing one block:


| Allocated | Free | Free |


The allocator reuses freed blocks instead of requesting more heap memory.

---

# Allocation Flow

When a user requests memory using `my_malloc(size)`:


User Program
↓
my_malloc(size)
↓
Search free list
↓
Free block found?
/
Yes No
| |
Reuse Request memory
block using sbrk()


Steps:

1. Search free list for available block
2. If found → reuse it
3. If not found → expand heap using `sbrk()`
4. Return pointer to usable memory

---

# Project Structure


memory-allocator/
│
├── include/
│ └── allocator.h
│
├── src/
│ └── allocator.c
│
├── tests/
│ └── test_allocator.c
│
├── Makefile
│
└── README.md


### Folder Description

| Folder/File | Purpose |
|-------------|---------|
| include | allocator header file |
| src | allocator implementation |
| tests | test programs |
| Makefile | build automation |
| README | project documentation |

---

# Build Instructions

Compile the project:


make


---

# Run the Program


make run


Example output:


Testing custom allocator
0 10 20 30 40
Memory freed successfully


---

# Benchmark

The allocator was tested with multiple allocation and deallocation operations.

Example test workflow:

1. Allocate memory for integer arrays
2. Write values to allocated memory
3. Free allocated memory
4. Allocate new memory blocks

Example scenario:


for i in 1..10000
allocate memory
write values
free memory


This simulates repeated allocation workloads and verifies that freed blocks are reused correctly.

---

# Concepts Demonstrated

This project demonstrates important systems programming concepts:

- Heap memory management
- Dynamic memory allocation
- Free-list allocation strategy
- Pointer arithmetic
- Linked list data structures
- OS-level memory interface (`sbrk`)
- Fragmentation awareness

---

# Future Improvements

Potential enhancements include:

- Block splitting to improve memory utilization
- Block coalescing to reduce fragmentation
- Best-fit allocation strategy
- Memory usage statistics
- Thread-safe allocator using mutex locks
- Performance benchmarking tools

---

# Why This Project Matters

Understanding how memory allocators work is critical for:

- operating systems
- compilers
- systems programming
- performance optimization

Real-world memory allocators in languages like C and C++ follow similar principles.

This project provides a simplified but practical implementation of dynamic memory management.

---

# Author

Soumyasree Mitra

GitHub  
https://github.com/SoumyasreeMitra

LinkedIn  
https://www.linkedin.com/in/soumyasree-mitra/

---

# License

This project is intended for educational and learning purposes.