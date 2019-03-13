# bit-algorithms

[![CircleCI](https://circleci.com/gh/gress2/bit-algorithms.svg?style=svg)](https://circleci.com/gh/gress2/bit-algorithms)

An exploratory implementation of bit overloads of the C++ standard algorithms

## Description
While [The Bit Library](https://github.com/vreverdy/bit) is currently being proposed and reviewed by the ISO C++ Standards Committee, this repository is intended for exploratory developments on bit manipulation algorithm overloads based on the bit library. Once finalized, the algorithms will be merged to the main bit library repository and proposed for standardization to C++.

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
    



