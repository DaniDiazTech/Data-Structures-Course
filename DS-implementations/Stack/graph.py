import subprocess
import random
import time
import numpy as np
import matplotlib.pyplot as plt

print("Getting 1000 data points")
print("N will be restricted: 1 <= n <= 10^6")

def simulate(n: int, run_command):
    # Write n to file
    to_write = bytes(str(n), "UTF-8")

    start = time.time()
    run_process = subprocess.Popen(run_command, shell=True, stdin=subprocess.PIPE)

    run_process.stdin.write(to_write)
    # Makes the process run before finishing
    run_process.communicate()

    end =time.time()
    return end - start

def produce_points(program_name, datapoints = 1000, separator = 50):
    # Produces 

    file_name = program_name + ".cpp"
    compile_command = ["g++", "-std=c++17", file_name, "-o", program_name]
    run_command = ["./" + program_name]
    compile_process = subprocess.run(compile_command)

    # Associate n with time taken by the program
    # Will use this data to create the graph
    x = []
    y = []

    l = 1
    
    for i in range(0, datapoints):
        time_taken = simulate(l, run_command=run_command)
        x.append(l)
        y.append(time_taken)
        datapoints -= 1
        l += separator

    return x, y

def graph():
    # Implementation of stack
    sim_points = 500
    x, y = produce_points("test-stack", datapoints=sim_points)

    # Stack from the standard library
    x2, y2 = produce_points("test-stack-std", datapoints=sim_points)

    # Cuadratic 
    # x2, y2 = produce_points("cuadratic", datapoints=sim_points)
    x3, y3 = produce_points("test-stack-linked-list", datapoints=sim_points)


    plt.rcParams['figure.figsize'] = [10, 6] # set size of plot

    plt.plot(x, y, 'or', label = "ArrayList implementation")
    plt.plot(x2, y2, 'ob', label = "STD")
    # plt.plot(x2, y2, 'ob', label = "Cuadratic algo")
    plt.plot(x3, y3, 'og', label = "LinkedList implementation")

    plt.legend()

    # Line that fits first dataset
    degree =1 
    # Coefficients
    coeff = np.polyfit(x, y, degree)
    print(coeff)
    p = np.poly1d(coeff)
    plt.plot(x, [p(n) for n in x], "-g")

    # Labels
    plt.xlabel("N: Number of elements")
    plt.ylabel("Time taken (s)")
    plt.title("Time required to push N elements")

    plt.show()

graph()