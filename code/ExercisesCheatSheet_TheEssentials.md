HEP C++ Course cheat sheet
==========================

List of exercises per day, with preferred order and solution overview.
Each exercise is in its own directory and referred to in the following by the name of the directory
For each day, the exercises are given in order in which they should be done.

Day 1 - Basics Exercises
------------------------

### Hello World (directory: `hello`)

Just try to compile and run `./hello` to make sure that everything is set up correctly.

### Functions (directory: `functions`)

pass by copy / pass by reference

- Write a `printFiveCharacters(SlowToCopy)` function using the existing function as a model. Change its name
  if overloading isn't desired.
- Call it in `main()`.
- Make sure that the signature is `(SlowToCopy const & a)` to avoid copies.
- Try to modify the data in the structs. Compare what happens for each of `(SlowToCopy a), (SlowToCopy & a), (SlowToCopyy const & a)`.

### Control Structures (directory: `control`)

The idea of this exercise is to play with all kinds of possible loops and control structures and to understand how they work.

- change from a C++98 style for loop to range-based loop
- replace if / else statement with conditional operator
- change from a for loop to while and do/while loop
- change an if statement to a switch statement

### Auto & Refercences (directory: `loopsRefsAuto`)

- Write an indexed for loop to initialise the members of the structs. The program should not print garbage numbers.
- Use `auto const &` to prevent copies in the second loop.
- Understand the difference to `auto &`, get in the habit of using const references.


Day 2 - Tools Exercises
-----------------------


The tools exercises of day 2 are special as they will have been played (quickly) during the course. But people should replay them and discover the tools by themselves.


### Compiler

Based on the functions exercise, we are replaying the compilation steps manually.

A "break the ice" exercise here would be to ask people to do the first step (preprocessor) and make a poll on how many lines of C++ are present in the output. It will vary depending on setups, versions, OS, etc...

Then the important part is to play with nm and the -C option of C++filt to be able to decode symbols, find them and thus address a build error that mentions missing symbols.

Another important bit is ldd and inspecting library dependencies.

Notes:
- `--std=` >= c++11 is needed to initialise the structs.
- The Makefile skips the generation of the object file for functions.cpp. This might surprise some people.

### Debugging (directory: `debug`)

The goal there is really to play, look around and try things. Tutors may have a lot of questions here on "how do you...".

The solution of the crash is simply an inversion of 2 lines in the code where definition of v and it's randomization are inverted.

### Clang format (any directory)

The students can try this on any example.
Please warn the students: If they want to revert later, they should pick an example with no local changes.
Just follow the instructions on the slide deck.
It is also fine if the mentor demonstrates it quickly.
Please advise the students they should use `.clang-format` files from their projects before they start developing their own one.

Day 2 - OO Exercises
--------------------

### Polymorphism (directory: `polymorphism`)

First create a Pentagon and an Hexagon and call computePerimeter. Can be used to break the ice.
Second step is to call parent's computePerimeter methods meaning :

```cpp
Polygon *poly = new Hexagon(1.0);
poly->computePerimeter();
```
and check what is called, in regular and virtual method case

### Virtual inheritance (directory: `virtual_inheritance`)

First create a TextBox and try to call draw.
There will be an error that the member is ambiguous, due to multiple inheritance.
Fix code by calling it on both parents using types :

```cpp
  TextBox *tb = new TextBox(...)
  Rectangle *r = tb;
  r->draw();
```

See the output and check the ids printed, 2 different ones.

Retry with virtual inheritance.
See and solve the compilation issue about missing Drawable constructor. Understand that it's now called directly from TextBox constructor and call it explicitly from there with a new id.
See the new id being printed twice.


### Operators (directory: `operators`)

This exercise is about making `main` run successfully by completing the implementation of `Fraction`.
Implement a constructor for `Fraction` and add two integer data members for numerator and denominator.
Comment out everything in `main` except the first two LOCs.
This should compile now and print nothing.

Then uncomment the `std::cout` statements and implement `operator<<` for `Fraction`.
Compile and run.

Proceed this way through the entire exercise.
There are multiple possibilities to implement some operators, e.g. as members, as hidden friends, or as free functions.
Also when and where to normalize a fraction is up to the students.
All solutions are fine, as long as the `main` function runs successfully.

Day 3 - Modern C++ Exercises
----------------------------

### Constness (directory: `constness`)

The idea is to find out which lines are not correct, due to constness.
Ideal to break the ice as can be organized as a quizz of which line would fail or not with correction under the form of compiler validation.

### Generic programming (directory: `templates`)

This exercise has several levels. People not at ease can stop after first level and go to next exercise. Alternatively, they may do level 1 and 3 and skip 2.

Level 1 : just use the given Complex class in OrderedVector and see it works out of the box thanks to generic code in OrderedVector.

** stop after level 1, the rest is for the advanced course **

### Smart pointers (directory: `smartPointers`)

Here we have four code snippets that will benefit from using smart pointers.

 - `problem1` is a simple case of usage of `make_unique` with an observer pattern where the raw pointer should be used.
 - `problem2` is an example of a collection of pointers. Use `emplace_back` to transfer ownership of newly created objects to the container. You might need to briefly explain what `std::move` does, if needed.
 - ** problem 3 and 4 is for the advanced course **

### Standard algorithms and lambdas (directory: `stl`)

The goal is to use STL algorithms. I would advise to start in this order :

  - random_shuffle
  - adjacent_difference
  - first accumulate (the one for sums)
  - second accumulate (using lambda to compute sum of squares)
  - generate (involves a state to be captured by reference)
