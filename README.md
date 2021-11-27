# FAST-temporal-motif
This is the source code for our ICDE2022 submission:

*ID: 627, Title: Scalable Motif Counting for Large-scale Temporal Graphs.* 

Fast-temporal-motif is an algorithm proposed to count sub-graphs (i.e., motifs) in temporal graphs. This repository provides the source code of the algorithm. Besides, researchers can directly compile the project to have a quick start to verify the correctness and efficiency of the proposed algorithm.

## Compile
### Compile the project
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

2. execute "make* to compile the project, and get FAST_temporal_motif.exe
```bash
make
```

3. you can do *make clean* to remove FAST_temporal_motif.exe and all .o files
```bash
make clean
```

### Compile settings
you can modify *makefile* to change compile settings. The default settings:
1. compile the project without using OPENMP. You can set the *OMPFLAG* to true to compile the project into a openmp program if you want it work with multiple threads
2. use -O3 Optimize

## Command line arguments
```bash
FAST_temporal_motif -input -output -f -t -d -w
```
| Argument | Type      | Meaning                                               | Required           |
|----------|-----------|-------------------------------------------------------|--------------------|
| -input   | string    | the path of input data file                           | Yes                |
| -output  | string    | the path of output file                               | Yes                |
| -f       | int *0/1* | single/multiple threads                               | No default 0       |
| -t       | int       | the number of threads (when using multiple threads)   | No default 1      |
| -d       | int       | the threshold of degree (when using multiple threads) | No default INT_MAX |
| -w       | int       | time window                                           | No default INT_MAX |

for example, if you want to count all temporal-motifs within the time span of 600 in *input.txt*, with 8 threads, thrd=200000 and output results to *output.txt*, you can run the program as follows:
```bash
FAST_temporal_motif -input input.txt -output output.txt -f 1 -t 8 -d 200000 -w 600
```
The order of the arguments can be changed

## Data file
### Input data file
n rows, each row represents a directed edge

3 data in each row, representing node 1, node 2, and timestamp

use space as separator
### Output file
a 6\*6 martix, each element representing the number of motif instances for $M_{i,j}$ in our paper.
