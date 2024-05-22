import matplotlib.pyplot as plt
import random
import time
import paho.mqtt.client as mqtt

#  posição dos nós: Só para o teste
nodes = {
    "node1": (random.randint(0, 100), random.randint(0, 100)),
    "node2": (random.randint(0, 100), random.randint(0, 100)),
    "node3": (random.randint(0, 100), random.randint(0, 100)),
    "node4": (random.randint(0, 100), random.randint(0, 100)),
    "node5": (random.randint(0, 100), random.randint(0, 100))
}

# range
communication_range = 30  # qualquer numero: no range.py o numero menor que 4 é um bom exemplo

# distância entre dois nós
def distance(node1, node2):
    return ((node1[0] - node2[0])**2 + (node1[1] - node2[1])**2) ** 0.5

# verifica se dois nós estão dentro do range de comunicação
def in_communication_range(node1_pos, node2_pos, range):
    return distance(node1_pos, node2_pos) <= range

#  quando a mensagem é recebida: só para o teste, a tua versão é mais
def on_message(client, userdata, message):
    print(f"Received message: {message.payload.decode()} on topic {message.topic}")

# configurar um nó
def setup_node(node_name):
    client = mqtt.Client(node_name)
    client.on_message = on_message
    client.connect("mqtt.eclipseprojects.io", 1883, 60)  # Use um broker MQTT público
    client.loop_start()
    return client

# clientes MQTT para cada nó
clients = {node: setup_node(node) for node in nodes}

def send_message_if_in_range(clients, nodes, range):
    for node1_name, node1_pos in nodes.items():
        for node2_name, node2_pos in nodes.items():
            if node1_name != node2_name and in_communication_range(node1_pos, node2_pos, range):
                clients[node1_name].publish(node2_name, f"Message from {node1_name} to {node2_name}")

# Fazer plot dos nós e seus ranges de comunicação
#def plot_nodes(nodes, range):
#    plt.figure(figsize=(10, 10))
#    for node_name, (x, y) in nodes.items():
#        plt.scatter(x, y, label=node_name)
#        circle = plt.Circle((x, y), range, color='blue', fill=False, linestyle='dashed')
#        plt.gca().add_patch(circle)
#    plt.xlim(0, 100)
#    plt.ylim(0, 100)
#    plt.legend()
#    plt.grid(True)
#    plt.show()


# plot dos nós e seus ranges de comunicação versao remover no
def plot_nodes(nodes, range, removed_nodes=None):
    plt.figure(figsize=(10, 10))
    for node_name, (x, y) in nodes.items():
        if removed_nodes and node_name in removed_nodes:
            continue
        plt.scatter(x, y, label=node_name)
        circle = plt.Circle((x, y), range, color='blue', fill=False, linestyle='dashed')
        plt.gca().add_patch(circle)
    plt.xlim(0, 100)
    plt.ylim(0, 100)
    plt.legend()
    plt.grid(True)
    plt.show()


# Plot da posição inicial dos nós e seus ranges de comunicação
plot_nodes(nodes, communication_range)


# remover um nó
def remove_node(node_name, nodes, clients):
    if node_name in nodes:
        del nodes[node_name]
    if node_name in clients:
        clients[node_name].disconnect()
        del clients[node_name]

# Simulação de envio de mensagens com remoção de um nó
removed_nodes = []

try:
    while True:
        send_message_if_in_range(clients, nodes, communication_range)
        time.sleep(5)  #  sleep 5 segundos antes de verificar novamente

        # remover um nó aleatorio, temos de remover de acordo com a area de perigo. AInda nao percebi isso muito bem. 
        if len(removed_nodes) == 0:
            node_to_remove = random.choice(list(nodes.keys()))
            remove_node(node_to_remove, nodes, clients)
            removed_nodes.append(node_to_remove)
            print(f"{node_to_remove} has been removed")

        # Atualizar o gráfico depois de remover o no
        plot_nodes(nodes, communication_range, removed_nodes)

except KeyboardInterrupt:
    for client in clients.values():
        client.disconnect()
    print("Simulation ended.")

#  enviar de mensagens
#while True:
#   send_message_if_in_range(clients, nodes, communication_range)
#   time.sleep(5)  # Aguardando 5 segundos antes de verificar novamente


