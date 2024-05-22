import matplotlib.pyplot as plt
import numpy as np

# distância
def distance(node1, node2):
    return np.sqrt((node1[0] - node2[0])**2 + (node1[1] - node2[1])**2)

#  verificar se os nós estão dentro do alcance de comunicação
def in_communication_range(node1, node2, comm_range):
    return distance(node1, node2) <= comm_range

#  plot dos nós e o alcance de comunicação
def plot_nodes(node1, node2, comm_range):
    fig, ax = plt.subplots()
    ax.set_aspect('equal')
    
    # Plot dos nós
    ax.plot(node1[0], node1[1], 'bo', label='Node 1')
    ax.plot(node2[0], node2[1], 'ro', label='Node 2')
    
    # Plot do alcance de comunicação
    comm_circle1 = plt.Circle(node1, comm_range, color='blue', fill=False, linestyle='--', label='Comm Range Node 1')
    comm_circle2 = plt.Circle(node2, comm_range, color='red', fill=False, linestyle='--', label='Comm Range Node 2')
    
    ax.add_artist(comm_circle1)
    ax.add_artist(comm_circle2)
    
    # Verificar se os camaradas ( nós) estão dentro do alcance de comunicação
    if in_communication_range(node1, node2, comm_range):
        plt.title('Nodes are within communication range')
    else:
        plt.title('Nodes are out of communication range')
    
    plt.legend()
    plt.xlim(0, 10)
    plt.ylim(0, 10)
    plt.xlabel('X Coordinate')
    plt.ylabel('Y Coordinate')
    plt.grid(True)
    plt.show()

#teste
node1 = (2, 3)
node2 = (5, 7)
comm_range = 3

plot_nodes(node1, node2, comm_range)

