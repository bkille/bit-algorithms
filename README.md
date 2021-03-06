# bit-algorithms

[![CircleCI](https://circleci.com/gh/vreverdy/bit-algorithms.svg?style=svg)](https://circleci.com/gh/vreverdy/bit-algorithms)

An exploratory implementation of bit overloads of the C++ standard algorithms

## Description
While [The Bit Library](https://github.com/vreverdy/bit) is currently being proposed and reviewed by the ISO C++ Standards Committee, this repository is intended for exploratory developments on bit manipulation algorithm overloads based on the bit library. Once finalized, the algorithms will be merged to the main bit library repository and proposed for standardization to C++.

Overloading all of the routines in [<algorithm>](https://en.cppreference.com/w/cpp/algorithm) for bit iterators is an immense task. We aim to focus on the routines which (1) would benefit most from bit-parallel computation and (2) are commonly used in a bitwise setting. That being said, there are those out there who would benefit from an implementation of `sort` or `partition` which partitions all of the bits. Please open an issue if there is an routine in the <algorithm> header that you would like implemented in our library. Additionally, it may be useful to create a separate set of routines not present in <algorithm> that would be useful to the community. If you feel there is a popular bitwise algorithm on containers which cannot be efficiently implemented using the bit overloads for the <algorithm> library, please open an issue to let us know.

## Performance Benchmarks
We used Google's [benchmark](https://github.com/google/benchmark) library for computing benchmarks. Each benchmark is formatted as `{bit, std}::function` (size) [(alignment-tags)].

* `bit` is for this library, `std` is the standard library operating on the infamous `vector<bool>`. 
* (size) denotes the size of the container in bits. `small = 1 << 4`, `large = 1 << 16`
* (alignment-tags) refers to the memory alignment of the bit-iterators. `U` means the iterator does not fall on a word boundary, `R` means the iterator is placed at random, and `A` means the iterator is aligned with a word boundary.

For example, `bit::rotate (large) (ARA)` refers to our library's implementation of the `rotate` algorithm operating on a container of 32768 bits, where `first` and `last` are aligned but `n_first` is selected at random.

```
Run on (64 X 2300 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x32)
  L1 Instruction 32 KiB (x32)
  L2 Unified 1024 KiB (x32)
  L3 Unified 22528 KiB (x2)
Load Average: 0.41, 0.67, 0.73
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
--------------------------------------------------------------------
Benchmark                          Time             CPU   Iterations
--------------------------------------------------------------------
bit::shift_left (small) (UU)        3.77 ns         3.77 ns    185649261
std::shift_left (small)             45.6 ns         45.6 ns     15359502
bit::shift_left (large) (AA)         254 ns          254 ns      2760779
std::shift_left (large)           195023 ns       195021 ns         3590
bit::shift_right (small) (UU)       3.77 ns         3.77 ns    185654156
std::shift_right (small)            34.6 ns         34.6 ns     20218713
bit::shift_right (large) (AA)        240 ns          240 ns      2921340
std::shift_right (large)          131946 ns       131946 ns         5294
bit::reverse (small) (UU)           8.87 ns         8.87 ns     78851173
std::reverse (small)                39.1 ns         39.1 ns     17922588
bit::reverse (large) (AA)            962 ns          962 ns       727702
std::reverse (large)              246764 ns       246770 ns         2844
bit::rotate (small) (ARA)           6.76 ns         6.76 ns    105597804
std::rotate (small)                 71.5 ns         71.5 ns      8798226
bit::rotate (large) (ARA)           7577 ns         7577 ns        93948
std::rotate (large)               505214 ns       505212 ns         1383
bit::count (small) (AA)             1.16 ns         1.16 ns    603331880
std::count (small)                  17.9 ns         17.9 ns     39219825
bit::count (large) (AA)              664 ns          664 ns      1054400
std::count (large)                 72859 ns        72860 ns         9610
```

| Benchmark | Size  | Speedup |
|-----------|-------|---------|
| shift     | small | 10.6x   |
| shift     | large | 662x    |
| reverse   | small | 4.4x    |
| reverse   | large | 258x    |
| rotate    | small | 9.7x    |
| rotate    | large | 66.7x   |
| count     | small | 15.4x   |
| count     | large | 110x    |


## Structure
The structure of the repository is the following:
* **`bit-algorithms`**: main project directory
    * **`bin`**: all compiled executable files, including tests and benchmarks
    * **`build`**: temporary files generated by the compilation process, including tests and benchmarks
    * **`config`**: configuration files
    * **`data`**: data files, inputs and outputs
      * **`input`**: input files
      * **`output`**: output files
    * **`doc`**: all documents on the projects including papers, standardization documents, documentation and tutorials
        * **`papers`**: 
            * **`pdf`**: pdf files of technical and scientific papers
            * **`src`**: source files of technical and scientific papers
               * **`figures`**: figures to be included in documents
               * **`packages`**: additional latex packages
        * **`wg21`**: standardization documents for the ISO WG21 standards committee
            * **`html`**: html files of standardization documents
            * **`pdf`**: pdf files of standardization documents
            * **`src`**: source files of standardization documents
               * **`figures`**: figures to be included in documents
               * **`packages`**: additional latex packages
    * **`ext`**:
        * **`bit`**: a local copy of the bit library
        * **`cplusplus`**: a local copy of the required files from the C++ standard
    * **`include`**: main directory, containing the implementation of all the bit algorithms as header files
    * **`lib`**: library files, if any
    * **`src`**: source files including examples, tests, and benchmarks
        * **`benchmarks`**: benchmarking utilities
        * **`examples`**: examples of use of bit algorithms
        * **`manager`**: project manager to automatically generate algorithms files
        * **`tests`**: unit tests for the algorithms
    * `LICENSE`: information on the licensing terms of the project
    * `make.sh`: main makefile to compile different components of the project
    * `README.md`: this file, with the main basic documentation
    
## Style
Every source file follows a strict layout. If you are a contributor please make sure you follow this common style.
* C++ files
    * Indentation: 4 spaces
    * Line width: 80 characters
    * Separators: every file is divided in parts, these parts being delimited by separators
        * Separator styles:
            * 1: `// ========================================================================== //`
            * 2: `/* ************************************************************************** */`
            * 3: `// -------------------------------------------------------------------------- //`
        * Separator styles description:
            * 1: general purpose
            * 2: declarations and types, classes, structures
            * 3: implementation
        * Each section begins with a separator and a title
        * The title is in capital letters, centered, with a white space before and after, without underscores
        * Each section ends with a separator
        * Sections are separated by 3 lines
    * Class members: class members are grouped together
        * Each group corresponds to a category of members (eg: `Types`, `Lifecycle`, `Access`, `Operators`...)
        * In the class definition, each group starts with a comment with the name of the group
        * Each group specifies the class access modifier (eg: public, protected, private)
        * Groups related to implementation details are marked by `Implementation details`
        * The separator titles should specify the path of the group they correspond to:
            * `CLASS NAME: GROUP NAME`, `
            * `CLASS NAME: IMPLEMENTATION DETAILS: GROUP NAME`
    * Every file starts with the following information:
        * `// =============================== FILE NAME ================================ //`
        * `// Project:         The Experimental Bit Algorithms Library`
        * `// Name:            file_name.hpp`
        * `// Description:     1 line description of the file`
        * `// Creator:         Vincent Reverdy`
        * `// Contributor(s):  Vincent Reverdy [2019]`
        * `//                  ContributorFirstName ContributorLastName [FirstYear-LastYear]`
        * `// License:         BSD 3-Clause License`
        * `// ========================================================================== //`
        * `#ifndef _FILE_NAME_HPP_INCLUDED`
        * `#define _FILE_NAME_HPP_INCLUDED`
        * `// ========================================================================== //`
        * The alignment of the second column is 20
    * Every file is followed by a preamble, typically for file inclusion:
        * `// ================================ PREAMBLE ================================ //`
        * `// C++ standard library`
        * `#include <something>` (if any)
        * `// Project sources`
        * `#include "something.hpp` (if any)
        * `// Third-party libraries`
        * `#include "ext/something.hpp` (if any)
        * `// Miscellaneous`
        * `#define something` (if any)
        * `namespace something {` (if any)
        * `// ========================================================================== //`
    * Every file ends with:
        * `// ========================================================================== //`
        * `} // namespace something` (if any)
        * `#endif // _FILE_NAME_HPP_INCLUDED`
        * `// ========================================================================== //`
        
        
    
    


    



