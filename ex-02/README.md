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

- [ex-02.l](ex-02.l)
- [ex-02.y](ex-02.y)

### 1. Generate the Bison parser:

    ```sh
    bison -d ex-02.y
    ```

### 2. Generate the Flex scanner:

    ```sh
    flex ex-02.l
    ```

### 3. Compile the parser and scanner:

    ```sh
    gcc ex-02.tab.c lex.yy.c -o parser
    ```

### 4. Run the parser:

    ```sh
    ./parser
    ```

### Input/Output:

    ```sh
    $ ./parser
    $ Enter an expression: 10*10+10-10
    $ Result: 100
    ```
