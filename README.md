# 👾 Game of Life 

A command-line implementation of John Conway's Game of Life, a cellular automaton and classic example of emergent computation.

## Game
### Rules
The Game of Life is a 0-player game played on a 2D plane (traditionally infinite, here toroidal). The plane is divided into an array of cells, which may either be living or dead. The board evolves using only simple rules:
- Any living cell with fewer than two live neighbours dies, as if by underpopulation
- Any live cell with two or three neighbours lives on to the next generation
- Any live cell with more than three neighbours dies, as if by overpopulation
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction

The player *plays* by setting up the initial state, and then observes the game evolve on its own. The Game is Turing Complete.

### Conway
John Horton Conway was a prolific English mathematician. His body of work involves diverse fields: number theory, geometry, game theory, knot theory, and seminal work in group theory.  Conway was not merely a generator of results but a maker of frameworks. He had a knack for seeing deep structures in seemingly trivial patterns and built entire mathematical disciplines around them. He inspired a generation of mathematicians to play with rigor — an ethos rare in an era increasingly marked by technical specialization. Growing up, mathematical heroes are sparse to find. Newton and Euler were distant, elevated to mythical status. Not Conway. Conway was, firstly, alive during my childhood, and secondly, he was vivid and colourful, and in interviews (such as on Numberphile) his enthusiasm is radiant, not surprising from a man dubbed "the world's most charismatic mathematician." He was as far as I was concerned, a giant.

Like many people whose body of work spans a variety of fields and exhibits deep and technical sophistication, such as Radiohead or Pattinson, John Conway too is popularly know by one of his simplest creations. The Game of Life, devised on pen and paper, propelled Conway to popular stardom. 

John Conway died on 11 April, 2020.

## Implementation
### Running the Game Yourself
If the executable file (`.exe`) does not exist, navigate to the root folder and type
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o game
```
and execute using
```bash
./game.exe
```
#### Interface

Upon starting, you will see a prompt asking for commands. There are three types of commands: 
- `p x y`: flips the cell at (x, y)
- `g [template] x y`: places a predefined template at (x, y)
- `r`: Run the automata continuosly from here

Valid values for `[template]` are:
```
glider lwss mwss hwss
toad beacon pulsar pentad
gosper diehard acorn
```

### Project Setup
```
sw-GameOfLife/
├── include/             
│   └── gameboard.hpp
│   └── renderer.hpp
│   └── gameconfig.hpp
│   └── utility.hpp
├── src/                 
│   └── main.cpp
│   └── gameboard.cpp
│   └── renderer.cpp
│   └── gameconfig.cpp
│   └── utility.cpp
├── README.md            
└── .gitignore
```

#### Gameboard & Gameconfig
The `gameboard.hpp` and gameconfig.hpp` provide the `GameBoard` and `GameBoardConfigurator` classes respectively. The `GameBoard` class implements the core logic of Conways's Game of Life, while `GameBoardConfigurator` provides the templates to generate a small selection of named patterns.
#### Renderer
The `renderer.hpp` header provides the `Renderer` class, which handles all logic for displaying of the game board (via `.renderGame(...)`) as well as associated text and lines. It currently has support for text (`.renderText(...)`), labelled numbers (`.renderMetric(...)`), horizontal (`.renderHLine()`) and empty (`.renderELine()`) lines and a clear function.
#### Cross-Platform CLI Support
The `utility.hpp` provides the `Util` class which provides the static method `::getTerminalSize()` which allows, at initialisation, the Game of Life to fit to any window it is being run on.
