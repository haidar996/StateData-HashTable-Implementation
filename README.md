# StateData-HashTable-Implementation
A C++ hash table implementation for storing U.S. state data (name, capital, admission year/order). Uses quadratic probing for collision resolution. Supports insert, delete, search, and display operations. Includes a custom hash function for state names.
StateData HashTable Implementation
Overview
This project implements a hash table in C++ to store and manage U.S. state information. Each state record includes:

State name

Capital

Year of admission to the Union

Order of admission

The hash table uses quadratic probing for collision resolution and provides basic operations such as insertion, deletion, searching, and printing.

Features
Hash table with quadratic probing

Insertion and deletion of state records

Search for states by name

Display all stored state records

Custom hash function for state names

Files
main.cpp: Contains the implementation of the stateData class and the hash table template class.

How to Use
Compile the code using a C++ compiler (e.g., g++):

bash
g++ main.cpp -o stateHash
Run the executable:

bash
./stateHash
The program will insert sample state records, remove one, and print the remaining records.

Example Output
The program outputs the hash table indices, state names, and their status (1 for occupied, -1 for deleted). For example:

text
4 Arkansas  1  
29 Colorado  1  
31 Arizona  1  
46 Alabama  1  
82 Alaska  1  
92 California -1  
Notes
The hash table size is set to 100 by default.

The hash function processes state names by breaking them into segments and computing a weighted sum.
