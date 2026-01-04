
# Random Number Generator

A brief description of what this project does and who it's for.
Links to:  
[Mathematical description](#mathematical-principle)  
[Requirements](#requirements)  
[Local installation](#local-installation)  
[Documentation](#documentation)  
[Proof of concept file](#run-the-proof-of-concept-file)  

## Mathematical principle

The explanation of the mathematical principle for this rng

## Requirements

### For Linux :
- make
- gcc

#### Installation :

```bash
  sudo apt install make gcc
```

### For Windows, use the Windows Subsystem for Linux (WSL) :
- make
- gcc (if you want to run directly inside the WSL)
- mingw-w64 (if you want to create an executable for Windows)

#### Installation :

```bash
  sudo apt install make gcc mingw-w64
```

## Local installation

Clone the project

```bash
  git clone https://github.com/Rav3nPho3nix/Random-Number-Generator
```

## Documentation

The documentation of the project

## Run the proof of concept file

The proof of concept file show the basic version of the algorithm use to generate random numbers.  
Even if you are one Windows with the WSL, you can use the Linux-version of the program.  
However you have to compile it for Windows if you wnt to run it directly inside Windows.

### Compile the program

#### For Linux :

```bash
  make proof
```

#### For Windows :

```bash
  make proof-windows
```

### Launch the program

This build file is located inside the `build` directory.
Run one of these two commands depending on what operating system you are.

#### For Linux :

```bash
  ./build/proof
```

#### For Windows :

```bash
  ./build/proof.exe
```


