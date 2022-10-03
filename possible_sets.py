import matplotlib.pyplot as plt
import numpy as np
import math
f = open("D:\\Universidad\\5to Semestre\\Análisis de Algoritmos\\Semana 6\\possible_Sets\\computational times.txt", "r")
aux = (f.read()).split("\n")

x = []
y = []
for i in range(len(aux)-1):
    aux[i] = aux[i].split("\t")
    x.append(int(aux[i][0]))
    y.append(int(aux[i][1]))

config = ['c', 'xxx']
y = [math.log(elem,2) for elem in y]
plt.plot(x, y, color=config[0], label=config[1])

# plot
plt.title("Time")
plt.legend()
plt.xlabel("size number")
plt.ylabel("Time in microseconds")
plt.show()
