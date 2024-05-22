import heapq

def a_star_search(map, start, goal):
    def heuristic(a, b):
        return abs(a[0] - b[0]) + abs(a[1] - b[1])
    
    def get_neighbors(position):
        x, y = position
        neighbors = [
            (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1),
            (x + 1, y + 1), (x - 1, y + 1), (x + 1, y - 1), (x - 1, y - 1)
        ]
        # Filter out neighbors that are out of bounds or unsafe
        neighbors = [(nx, ny) for nx, ny in neighbors if 0 <= nx < len(map) and 0 <= ny < len(map[0]) and map[nx][ny] == 0]
        return neighbors
    
    open_set = []
    heapq.heappush(open_set, (0, start))
    
    came_from = {}
    g_score = {start: 0}
    f_score = {start: heuristic(start, goal)}
    
    while open_set:
        _, current = heapq.heappop(open_set)
        
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.reverse()
            return path
        
        for neighbor in get_neighbors(current):
            tentative_g_score = g_score[current] + 1
            
            if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = tentative_g_score + heuristic(neighbor, goal)
                heapq.heappush(open_set, (f_score[neighbor], neighbor))
    
    return []  # Retorna uma lista vazia se não houver caminho

def next_step(current_position, objective, map):
    path = a_star_search(map, current_position, objective)
    if path:
        return path[0]  # Retorna o próximo passo na rota
    else:
        return current_position  # Se não houver caminho, permanece na posição atual

# Exemplo de uso:
# 0 = seguro, 1 = inseguro
map = [
    [0, 0, 0, 1],
    [0, 1, 0, 1],
    [0, 1, 0, 0],
    [0, 0, 0, 0]
]
current_position = (0, 0)
objective = (3, 3)

print(next_step(current_position, objective, map))

