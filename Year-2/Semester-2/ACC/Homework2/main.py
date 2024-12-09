import random

# Generate Graph
def generate_random_graph(num_vertices, edge_prob):
    graph = [[] for _ in range(num_vertices)]
    for i in range(num_vertices):
        for j in range(i + 1, num_vertices):
            if random.random() < edge_prob:
                graph[i].append(j)
                graph[j].append(i)
    return graph

# Show Graph
def print_adjacency_matrix(graph):
    num_vertices = len(graph)
    adjacency_matrix = [[0] * num_vertices for _ in range(num_vertices)]
    for i in range(num_vertices):
        for j in graph[i]:
            adjacency_matrix[i][j] = 1
    print("Adjacency Matrix:")
    for row in adjacency_matrix:
        print(row)

# The Fitness
def fitness(graph, solution):
    uncovered_edges = 0
    for vertex, neighbors in enumerate(graph):
        if vertex not in solution:
            uncovered_edges += len([neighbor for neighbor in neighbors if neighbor not in solution])
    return uncovered_edges

# The Selection
def selection(population, fitnesses, tournament_size):
    parents = []
    for _ in range(2):
        tournament = random.sample(list(zip(population, fitnesses)), tournament_size)
        winner = min(tournament, key=lambda x: x[1])[0]
        parents.append(winner)
    return parents

# The Crossover
def crossover(parent1, parent2):
    crossover_point = random.randint(0, min(len(parent1), len(parent2)) - 1)
    child = parent1[:crossover_point] + parent2[crossover_point:]
    return child


# The Mutation
def mutate(solution, mutation_rate):
    for i in range(len(solution)):
        if random.random() < mutation_rate:
            solution[i] = 1 - solution[i]  # flip bit
    return solution


# The Genetic Algorithm
def vertex_cover(graph, population_size, tournament_size, crossover_rate, mutation_rate, max_generations):
    population = [[random.randint(0, 1) for _ in range(len(graph))] for _ in range(population_size)]
    for generation in range(max_generations):
        fitness_result = [fitness(graph, solution) for solution in population]
        best_solution = population[fitness_result.index(min(fitness_result))]
        if min(fitness_result) == 0:
            return best_solution
        new_population = [best_solution]
        while len(new_population) < population_size:
            parent1, parent2 = selection(population, fitness_result, tournament_size)
            if random.random() < crossover_rate:
                child = crossover(parent1, parent2)
            else:
                child = parent1
            child = mutate(child, mutation_rate)
            new_population.append(child)
        population = new_population
    return best_solution


# For the Graph
num_vertices = 10
edge_probability = 0.5
graph = generate_random_graph(num_vertices, edge_probability)
# For the Genetic Algorithm
population_size = 50
tournament_size = 5
crossover_rate = 0.8
mutation_rate = 0.1
max_generations = 100
# Call the Genetic Algorithm
best_solution = vertex_cover(graph, population_size, tournament_size, crossover_rate, mutation_rate, max_generations)
#Show the graph and the result
print_adjacency_matrix(graph)
print("Result:", [vertex for vertex, bit in enumerate(best_solution) if bit == 1])
