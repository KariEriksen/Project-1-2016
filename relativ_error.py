#!/usr/bin/env python
from math import exp, log10 
import os
import numpy as np
from matplotlib.pyplot import *

p = 10
points = np.linspace(10, 100000, p)
relative_error = []
step_lenght = []

for j in range(p):
    
    # Running Project_1 from terminal
    n = points[j]
    n = int(n)
    os.system("g++ project_1.cpp -o project_1_error")
    os.system("./project_1_error %d" % n)
   
    # Reading file data.dat
    infile = open('data.dat', 'r')
    infile.readline()
    values = []
    for line in infile:
        
        value = float(line)
        values.append(value)
        
    infile.close()
    
    # Inserting the boundary conditions v_0 and v_n+1 = 0
    values.insert(0, 0.0)
    values.append(0.0)

    # Makeing values an array
    v = np.array(values)
    
    # The analytic solution of u(x)
    h = 1./(n+1.)
    x = []
    u = []
    for i in range(n+2):

        x_i = i*h
        x.append(x_i)
        
        u_x = 1 - (1 - exp(-10))*x_i - exp(-10*x_i)
        u.append(u_x)

    # Makeing u an array
    U = np.array(u)

    # Calculating the relative error
    eps = np.zeros(n+1)
    eps = np.log10(np.abs((v[1:-1] - U[1:-1])/U[1:-1]))
    eps_max = max(eps)
    relative_error.append(eps_max)
    step_lenght.append(log10(h))
    


#print relative_error
#print step_lenght

#figure(1)
plot(step_lenght, relative_error)

title("The relative error." )

xlabel("Step lenght")
ylabel("Relative error")

show()
