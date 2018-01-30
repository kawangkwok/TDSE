# TDSE

## Introduction
This is a collection of models demonstrating numerical solutions to Time Dependent Schrodinger Equation (TDSE). The methods explored include the leap-frog method and the Crank-Nicolson method.
## Instruction
Each folder contains a makefile, therefore typing make into the terminal would generate the potential free case. If one prefers different potentials, simply add an indicator after make e.g. make 1d_tun for the tunnelling case using the CN method in one dimension. After the make command, the terminal will ask for an input for the number of time step. The result will be generated into CSV files. 

### The list of options
For one dimensional leap frog,
"1d_leap" is the default
"1d_ltun" potential barrier with similar energy to the wave
"1d_lpw" potential wall
"1d_lpc" potential cliff

The commands are similar for the one dimensional CN e.g. "1d_pw" for the CN potential wall.

For the two dimensional leap frog, 
"2d_leap" potential free
"2d_tun" 2D uniform cylindrical potential barrier with similar energy to the wave
"2d_pw" potential wall
"2d_pc" potential cliff

### Changing the potential
The potentials can be adjusted in the function files such as "f.cpp". In these cpp files, there is always a function called potential which defines the potential used in that particular model.


