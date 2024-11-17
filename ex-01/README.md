### Required Tools

- Flex
- Bison

#### Install Flex and Bison on Arch Linux:

```sh
pacman -S flex bison
```

#### Install Flex and Bison on Ubuntu:

```sh
sudo apt-get install flex bison
```

#### Install Flex and Bison on Windows:

```sh
choco install winflexbison
```

### Required Files

- [lexer.l](lexer.l)

### Build

```sh
flex lexer.l
gcc lex.yy.c -o lexer
```

### Run

```sh
./lexer
```
