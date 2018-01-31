# TDSE

## Introduction
This is a collection of models demonstrating numerical solutions to Time Dependent Schrodinger Equation (TDSE). The methods explored include the leap-frog method and the Crank-Nicolson method.
## Instruction
Each folder contains a makefile, therefore typing make into the terminal would generate the potential free case. If one prefers different potentials, simply add an indicator after make e.g. ``make 1d_tun`` for the tunnelling case using the CN method in one dimension. After the make command, the terminal will ask for an input for the number of temporal step. The result will be generated into CSV files. 

### The list of options
For one dimensional leap frog,<br />
``1d_leap`` is the default<br />
``1d_ltun`` potential barrier with similar energy to the wave<br />
``1d_lpw`` potential wall<br />
``1d_lpc`` potential cliff<br />

The commands are similar for the one dimensional CN e.g. ``1d_pw`` for the CN potential wall.

For the two dimensional leap frog, <br />
``2d_leap`` potential free<br />
``2d_tun`` 2D uniform cylindrical potential barrier with similar energy to the wave<br />
``2d_pw`` potential wall<br />
``2d_pc`` potential cliff<br />

### Changing the potential
The potentials can be adjusted in the function files such as ``f.cpp``. In these cpp files, there is always a function called potential which defines the potential used in that particular model.

### Plotting the result
Each folder contains a commented ipython notebook which guides the user on how to plot and save the corresponding figures. Note that these ipython notebook can be exported as python scripts.
