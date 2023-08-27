import subprocess
import random
import time
import numpy as np
import matplotlib.pyplot as plt

print("Getting 1000 data points")
print("N will be restricted: 1 <= n <= 10^6")

program_name = "stack"
file_name = program_name + ".cpp"

compile_command = ["g++", "-std=c++17", file_name, "-o", program_name]

run_command = ["./" + program_name]

compile_process = subprocess.run(compile_command)

datapoints = 1000 

MIN = 1
MAX = 1e7

# Associate n with time taken by the program
# Will use this data to create the graph
x = []
y = []

def simulate(n: int):
    # Write n to file
    to_write = bytes(str(n), "UTF-8")

    start = time.time()
    run_process = subprocess.Popen(run_command, shell=True, stdin=subprocess.PIPE)

    run_process.stdin.write(to_write)
    run_process.stdin.flush()

    end =time.time()
    return end - start

l = 1
while (datapoints > 0):
    time_taken = simulate(l)
    x.append(l)
    y.append(time_taken)
    datapoints -= 1
    l += 50

plt.rcParams['figure.figsize'] = [10, 6] # set size of plot
plt.plot(x, y, 'or')
plt.xlabel("N: Number of elements")
plt.ylabel("Time taken")

plt.title("Time required to push and pop N elements")
plt.show()