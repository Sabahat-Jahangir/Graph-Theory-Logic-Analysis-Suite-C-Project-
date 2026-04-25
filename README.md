## Graph Theory & Logic Analysis Suite (C++ Project)

### Overview

This project is a collection of four independent C++ modules designed to solve fundamental problems in graph theory and propositional logic. Each module focuses on a specific computational problem, ranging from relation analysis in matrices to graph properties and logical expression equivalence.

The system is implemented in modular form using four separate `.cpp` files:

* `module1.cpp`
* `module2.cpp`
* `module3.cpp`
* `module4.cpp`

Each module is self-contained and demonstrates a different algorithmic concept using structured programming and data structures.

---

### Purpose

The purpose of this project is to strengthen understanding of:

* Graph theory concepts
* Matrix-based relation analysis
* BFS and DFS traversal techniques
* Logical expression evaluation using stacks
* Truth table generation and equivalence checking

It is essentially a toolkit of classical CS problems that look simple on paper but are extremely good at testing whether your logic is actually correct or just “looks correct.”

---

## Module 1: Matrix Relation Analyzer

### Overview

This module analyzes a square matrix to determine the type of relation it represents. It checks whether the relation is:

* Reflexive
* Symmetric
* Antisymmetric
* Transitive

It also identifies missing pairs required to satisfy a specific relation and provides a directed graph representation of the matrix.

---

### Flow of Execution

1. User inputs a square matrix
2. Program stores matrix and interprets it as a relation
3. Each relation type is checked independently using dedicated functions
4. Results are displayed showing:

   * Which properties are satisfied
   * Which are missing
   * Required modifications to achieve a relation
5. A directed graph representation is generated from the matrix

---

### Key Concepts Used

* Matrix representation of relations
* Independent relation-checking functions
* Logical condition evaluation
* Graph visualization (adjacency-based interpretation)

---

### Output Behavior

The program does not just say “yes or no.” It behaves more like a strict examiner:

* “Reflexive? No. Fix these pairs.”
* “Symmetric? Almost, but you missed this.”
* “Transitive? Not even close.”

---

## Module 2: Graph Property Analyzer

### Overview

This module takes a graph as input and determines whether it contains properties such as:

* Walk
* Closed Walk
* Circuit
* Simple Circuit
* Path
* Simple Path

It also checks graph connectivity using DFS and analyzes structure based on traversal results.

---

### Flow of Execution

1. User inputs vertices and edges
2. Graph is stored using an adjacency matrix
3. DFS is used to:

   * Check connectivity
   * Explore paths between nodes
4. Based on traversal patterns and edge usage:

   * Graph properties are classified
5. Final analysis report is generated

---

### Key Concepts Used

* Adjacency matrix representation
* Depth First Search (DFS)
* Graph traversal logic
* Property classification based on conditions

---

### Output Behavior

The program behaves like a detective:

* It checks how you move through the graph
* Then decides whether your movement is “legal,” “repetitive,” or “structured enough to be called a path”

---

## Module 3: Bipartite Graph Checker

### Overview

This module determines whether a graph is Bipartite. If not, it identifies the conflicting vertices responsible for the violation.

---

### Flow of Execution

1. User enters vertices and edges
2. Graph is stored in adjacency matrix form
3. BFS traversal is performed
4. Each vertex is assigned a color
5. If adjacent vertices share the same color:

   * Conflict is detected
6. Final result is displayed:

   * Bipartite or not
   * Conflicting vertices (if any)

---

### Key Concepts Used

* Breadth First Search (BFS)
* Graph coloring technique
* Conflict detection logic
* Adjacency matrix representation

---

### Output Behavior

If the graph is not bipartite, the program doesn’t just fail silently—it exposes the exact vertices causing chaos in your graph structure.

---

## Module 4: Logical Expression Equivalence Checker

### Overview

This module generates truth tables for two logical expressions and checks whether they are equivalent.

Supported operators:

* AND
* OR
* NOT
* XOR
* Implication
* Bi-Implication

---

### Flow of Execution

1. User inputs two logical expressions
2. Expressions are converted and processed using a stack-based system
3. Truth tables are generated for both expressions
4. Final columns are compared
5. Equivalence is determined

---

### Key Concepts Used

* Stack data structure
* Postfix expression evaluation
* Truth table generation
* Logical operator implementation

---

### Output Behavior

The program acts like a strict logic professor:

* It evaluates both expressions
* Then checks if they are “actually the same or just pretending to be”

---

## Design Highlights

### Modular Structure

Each module is independent:

* Separate `.cpp` files
* No unnecessary coupling
* Easier debugging and testing

### Core Algorithms Used

* BFS (Module 3)
* DFS (Module 2)
* Stack-based evaluation (Module 4)
* Matrix-based relation checking (Module 1)

---

### Common Design Approach

Across all modules:

* Input-driven execution
* Structured algorithmic processing
* Clear output formatting
* Step-by-step logical validation

---

## How to Run

Compile each module separately:

```bash
g++ module1.cpp -o module1
g++ module2.cpp -o module2
g++ module3.cpp -o module3
g++ module4.cpp -o module4
```

Run:

```bash
./module1
./module2
./module3
./module4
```

---

## Challenges Faced

* Handling edge cases in graph traversal
* Correctly classifying graph properties (especially circuits vs paths)
* Ensuring BFS coloring logic correctly detects conflicts
* Building a reliable truth table generator without breaking under complex expressions
* Keeping logic clean while avoiding overly complicated conditions

---

## What Makes This Project Interesting

This project combines multiple core CS concepts into separate modules:

* Graph theory (DFS, BFS, adjacency matrices)
* Relational algebra
* Logical expression evaluation
* Stack-based parsing

It is basically a reminder that graphs and logic are simple until you actually start implementing them.
