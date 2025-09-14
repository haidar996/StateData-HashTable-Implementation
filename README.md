# StateData-HashTable-Implementation
A C++ hash table implementation for storing U.S. state data (name, capital, admission year/order). Uses quadratic probing for collision resolution. Supports insert, delete, search, and display operations. Includes a custom hash function for state names.
## 🎯 Features

- 📥 Insert U.S. state records (name, capital, admission year, order)
- ❌ Delete records by state name
- 🔍 Search for a state by name
- 📄 Display all stored records with status
- 🧮 Custom hash function tailored for state names
- 🌀 Efficient **quadratic probing** for collision resolution

---

## 🧱 Code Structure

| File / Class       | Description                                                             |
|--------------------|-------------------------------------------------------------------------|
| `stateData` class  | Represents a U.S. state with `name`, `capital`, `admission year`, and `admission order` |
| `hasht<T>` class   | Generic hash table with insertion, deletion, search, and display logic |
| `main.cpp`         | Demonstrates how the hash table is used and tested                     |

---

## ⚙️ Hash Table Details

- Default table size: **100**
- Hash function processes characters in the state name to compute a numeric key
- **Quadratic probing formula**: `h(k) + i²` for resolving collisions
- Entry status:
  - `1` → Occupied
  - `-1` → Deleted
  - `0` → Empty (implicitly)

---

## 🕹️ How to Use

### 1. Compile the Program

```bash
g++ main.cpp -o stateHash
