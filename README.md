# [Advent of code 2025 - my solutions](https://adventofcode.com/2025)

## Repo structure
There is a directory for each day.\
They contain:
- the source code for both parts in files `part1.c` and `part2.c`
- `task.txt` with the description of the problem
- `input.txt` with the data for which result needs to be submited
- `testXXX.txt` which were prepared by me/taken from the description of a task to validate the solution
- `Makefile` which has targets for compiling and testing the solution

## Running & testing
- to compile the program
```bash
make
```
- to compile just part 1
```bash
make part1
```
- to compile just part 2
```bash
make part2
```
- to run the tests
```bash
make test
```
- to run the tests for part 1
```bash
make test1
```
- to run the tests for part 2
```bash
make test2
```
- **Please note that all of the above targets can be compiled with debug symbols and logs** \
To do so `make_debug=true` variable need to be set. For example this will compile both parts with debug info and logs.
```bash
make make_debug=true
```

## Debuging with VSCode
While logs can be usefull sometimes dynamic view into the application can be helpful. \
That's why I have set up VSCode debuger to allow for running both parts on either `input.txt` or `test0.txt`. \
To do so go to debuger tab and select the desired input file from the dropdown. Then open the file You want to debug, put a break point and launch the debuger.

As a byproduct of setting up debuging, You can also compile the current file and clean up artifacts in the dirrectory which contains it.\
It is available after You type `Tasks: Run Task` into command palete and select either `Build current file`, `Clean` or `All` if You want to delete all artifacts and build new ones in one step.