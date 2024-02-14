# CSC5760 and CSC4760 Parallel Programming Homework

## Notes on running files on TN Tech Cluster
Sign in to login shell with your user account. 

### Accessing gpu nodes
Find what accounts you can access, run 
`sacctmgr show assoc format=account%20`
This should show that you can access an account named `csc4760-001-2024s`
To enter a node with GPU access, 
`hpcshell --cpus-per-task=2 --gres=gpu --account=csc4760-001-2024s`

### Running Kokkos programs with Cuda
Use the spack package manager to load the desired combination of Kokkos, gcc, and Cuda
`spack load kokkos%gcc@12 +cuda`

Enter the desired example or problem folder and run: 
`KOKKOS_DEVICES=Cuda    make`
This sets up all of the sources files.

To run the final executables:
`LD_LIBRARY_PATH=$(spack location -i cuda@12)/lib64 ./program_name.cuda`

### Running Kokkos without Cuda
To use without Cuda, you will want to load the Cuda-less Kokkos packages
`spack load kokkos%gcc@12 ~cuda`

Run these inside the desired example or problem
`KOKKOS_DEVICES=OpenMP    make`
`./program_name.host`

## Question 1

## Question 2

## Question 3

## Question 4 (Only required for Graduate Student Level 5760)

# License

[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

Under the terms of Contract DE-NA0003525 with NTESS,
the U.S. Government retains certain rights in this software.

The full license statement used in all headers is available [here](https://kokkos.github.io/kokkos-core-wiki/license.html) or
[here](https://github.com/kokkos/kokkos/blob/master/LICENSE).

This notice shows that this is a derivative work (if extensively changed) of the Kokkos tutorials and Kokkos repository. 
