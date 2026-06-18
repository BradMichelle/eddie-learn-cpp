# C++ Learning Project

This project is set up so each coding exercise can live in its own source file and be built separately.

## Structure

- `main.cpp` → sample program
- `issues/` → one `.cpp` file per exercise

## Build all exercises

```bash
mkdir -p build
cmake -S . -B build
cmake --build build
```

## Run one exercise

For example, to run the first issue:

```bash
./build/01_hero_info
```

## Add a new exercise

1. Create a new file in `issues/`
2. Name it something like `02_my_exercise.cpp`
3. Re-run:

```bash
cmake -S . -B build
cmake --build build
```

