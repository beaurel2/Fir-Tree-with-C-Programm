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
```bash
$ mkdir "code name" && cd "code name"
$ git clone https://github.com/beaurel2/Fir-Tree-with-C-Programm.git
$ cd Fir_tree && make
```

If everything is OK, then I get the output on the terminal:
```bash
$ gcc -Wall -Wextra -Werror -std=c11   -c -o src/main.o src/main.c
$ gcc -Wall -Wextra -Werror -std=c11 -o fir_tree src/main.o
```

If you change anything in the code, always please run:
```bash 
$ make clean
$ make
```

then use this command to run the code:
```bash
$ ./fir_tree
```

If you're on Windows, then use the WSL command:
```bash
$ wsl --install
$ sudo apt install build-essential
```