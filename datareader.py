#!/usr/bin/env python
from math import exp, log10 
import os
import numpy as np

# Reading file data.dat, 

infile = open('data_2.dat', 'r')
n = infile.readline() 
n = int(n)
values = []
for line in infile:

    value = float(line)
    values.append(value)

infile.close()

# Defining variables, solving the analytic solution


h = 1./(n+1.)
x = []
u = []

for i in range(n+2):
    x_i = i*h
    x.append(x_i)

    # The analytic solution of u(x)
    u_x = 1 - (1 - exp(-10))*x_i - exp(-10*x_i)
    u.append(u_x)


# Inserting the boundary conditions v_0 and v_n+1 = 0

values.insert(0, 0.0)
values.append(0.0)



from matplotlib.pyplot import *


#figure(1)
plot1 = plot(x,values)
hold('on')
plot2 = plot(x, u)

title("Numerical and analytical solution, with n = %d" % n )

xlabel("Step lenght")
ylabel("Solution to u")

legend(("Numerical solution", "Analytic solution"), loc='upper right')

show()

