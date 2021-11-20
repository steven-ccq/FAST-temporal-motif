# FAST-temporal-motif
*Fast-temporal-motif* is a algorithm proposed to count sub-graphs(*3 types, star, pair and triangle*) in temporal graphs. This repositority provide source code of the algorithm, which may help researchers have a better understanding of the algorithm. Besides, people can directly compile the project to have a quick start to verify the correctness and efficiency of the algorithm.

## Compile
### compile the project
1. download the project, the project looks like:
```bash
/FAST-temporal-motif
├── include
│   ├── global.h
│   ├── egeLoader.h
│   ├── starAndPairCount.h
│   ├── triangleCount.h
│   └── convertMartix.h
├── src
│   ├── global.cpp
│   ├── egeLoader.cpp
│   ├── starAndPairCount.cpp
│   ├── triangleCount.cpp
│   ├── convertMartix.cpp
│   └── main.cpp
├── makefile
└── README.md
```
3. do "make* to compile the project, and get FAST_temporal_motif.exe
```bash
make
```
3. you can do *make clean* to remove FAST_temporal_motif.exe and all .o files
### compile settings
you can modify *makefile* to change compile settings. The default settings:
1. compile the project without using OPENMP. You can set the *OMPFLAG* to true to compile the project into a openmp program if you want it work with multiple threads.
2. use -O2 Optimize.

## Command line arguments
```bash
FAST_temporal_motif -input -output -f -t -d -w
```
| Arguments    |  Type  | Meaning| Required |
|---------------------------|------------|-----------|----------------------------------|
| -input         | string   | the path of input data file               | Yes                         |
| -output         | string | the path of output file                       | Yes                         |
| -f           | int *1/0*  | use/not use OPENMP             | No default 0       |
| -t          | int   | the number of thread (when using OPENMP) |  No default 1              |
| -d           | int   | the thrd (when using OPENMP)                    | No default INT_MAX      |
| -w          | int   | time span                           | No default INT_MAX               |

## data file
n rows, each row represents a directed edge
3 data in each row, representing node 1, node 2, and timestamp
use space as separator
