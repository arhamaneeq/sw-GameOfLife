# Game of Life 👾

An Implementation of Conway's Game of Life

**Directory Structure**
```
sw-GameOfLife/
├── include/             # Header files (.hpp)
│   └── gameboard.hpp
│   └── renderer.hpp
├── src/                 # Source files (.cpp)
│   └── main.cpp
│   └── gameboard.cpp
│   └── renderer.cpp
├── build/               # Build output (executables, object files)
├── Makefile             # Build instructions using make
└── README.md            # Project overview and instructions
```

Build using

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o game
```

and execute using

```bash
./game.exe
```