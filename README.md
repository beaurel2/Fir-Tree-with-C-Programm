# 🎄 ASCII Fir Tree Generator (C)

Small C project that generates and displays a decorated ASCII fir tree in the terminal.

## Features

- Dynamic tree size (width & height)
- Random decoration
- Colored output (via cursor control)
- Modular structure (generate, init, decorate, display)

## Project Structure
src/
├── main.c
├── Fir_tree.h
├── Cursor.h
├── Configuration.h

## Terminal
- mkdir "code name" && cd "code name"
- git clone https://github.com/beaurel2/Fir-Tree-with-C-Programm.git
- cd Fir_tree && make

If everything is OK, then I get the output on the terminal:
- gcc -Wall -Wextra -Werror -std=c11   -c -o src/main.o src/main.c
- gcc -Wall -Wextra -Werror -std=c11 -o fir_tree src/main.o
![alt text](image.png)

- If you change anything in the code, always please run <make clean> before <make>.
- then use the command <./fir_tree> to run the code

If you're on Windows, then use the WSL command
- wsl --install
- sudo apt install build-essential
