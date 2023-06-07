# IZLO - Project 1: SAT Solvers

## Introduction
In this project, we consider the problem of a student trying to plan the order in which they will enroll in subjects during their studies. However, the subjects have various prerequisites, and it is not clear if there is a way to enroll in all the chosen subjects while satisfying all the prerequisites. We will solve this problem by converting it into a satisfiability problem in propositional logic and using a SAT solver.

<br>

----
<br>

## Compiling the Code

To compile the code, go to the code folder and run the following command:

```
make
```

<br>

----
<br>




## Input Format
The problem instance is described in the following text format. The first line of the file contains the header, which consists of three natural numbers: the total number of subjects, the total number of semesters, and the total number of prerequisites. The prerequisites are listed in the following lines, where each line contains a pair of numbers:

```
<number_of_subjects> <number_of_semesters> <number_of_prerequisites>
<earlier_1> <later_1>
<earlier_2> <later_2>
...
```


Here, `<earlier_x> <later_x>` represents a prerequisite that the subject `<earlier_x>` must be enrolled before the subject `<later_x>`. `<number_of_prerequisites>` is the number of desired requirements. For example, a sample input file may look like this:

```
3 2 3
0 1
1 2
2 0
```


The header indicates that we need to enroll in `3` subjects in `2` semesters. It is also specified that subject `0` must be enrolled before subject `1`, subject `1` before subject `2`, and subject `2` before subject `0`. This input has no solution since the prerequisites form a cycle. Remember that the input file must be in the same folder as the executable file.

<br>

----
<br>

## Generating Output

To generate an output, after compiling the program and setting the input file, go to the code folder and run the following command:

```
./run.sh <file>
```
Where `<file>` is the name of the input file. 

<br>

----
<br>

## Example

For example, if we want to run the program with the input file `input.txt`:

```
4 4 3

0 1
1 2
2 3
```

We would run the following command:

```
./run.sh input.txt
```

The output would be:

```
SAT
Model:
Semestr 1:
  předmět 0
Semestr 2:
  předmět 1
Semestr 3:
  předmět 2
Semestr 4:
  předmět 3
```

Which is in English:

```
SAT
Model:
Semester 1:
  subject 0
Semester 2:
  subject 1
Semester 3:
  subject 2
Semester 4:
  subject 3
```

`SAT` indicates that the model is satisfiable and there is a solution to the problem and we can have a `model`.

<br>

----
<br>


## Disclaimer

I only changed the code in the `add_conditions.c` file, the rest of the code was provided by the course staff.