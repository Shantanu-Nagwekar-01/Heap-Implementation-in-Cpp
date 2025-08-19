# Heap Implementation in C++

This project demonstrates heap data structure operations in C++. It includes building a heap from an array and implementing a Max Heap with insertion, deletion, and heapify operations.

## Project Structure

```

.
├── output/                # Build output directory (ignored in git)
│   ├── Build-Heap-From-Array.cpp
│   ├── Build-Heap-From-Array.exe
│   ├── Max\_Heap.cpp
│   ├── Max\_Heap.exe
├── .gitignore
├── README.md

````

## Files

- **Build-Heap-From-Array.cpp**: Program to build a heap from an array.
- **Max_Heap.cpp**: Implementation of a Max Heap class with insert, remove, heapify, and print operations.
- **.gitignore**: Ensures that output binaries and build files are not pushed to the repository.

## Time and Space Complexity

- Insert: O(log n)
- Remove: O(log n)
- Heapify: O(log n)
- Top: O(1)
- Print: O(n)

Space Complexity: O(n) for storing heap elements

## Compilation and Execution

Compile using g++:

```bash
g++ Max_Heap.cpp -o Max_Heap
./Max_Heap
````

For building heap from array:

```bash
g++ Build-Heap-From-Array.cpp -o BuildHeap
./BuildHeap
```

