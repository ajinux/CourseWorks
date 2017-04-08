from collections import defaultdict


class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = defaultdict(list)
        self.distances = {}

    def add_node(self, value):
        self.nodes.add(value)

    def add_edge(self, from_node, to_node, distance):
        self.edges[from_node].append(to_node)
        self.edges[to_node].append(from_node)
        self.distances[(from_node, to_node)] = distance
        self.distances[(to_node, from_node)] = distance


def dijsktra(graph, initial):
    visited = {initial: 0}
    path = {}

    nodes = set(graph.nodes)

    # iterate until end of each node
    while nodes:
        min_node = None
        # calculating the minimum of all node
        for node in nodes:
            if node in visited:
                if min_node is None:
                    min_node = node

        if min_node is None:
            break

        nodes.remove(min_node)
        current_weight = visited[min_node]

        for edge in graph.edges[min_node]:
            weight = current_weight + graph.distances[(min_node, edge)]
            if edge not in visited or weight < visited[edge]:
                visited[edge] = weight
                path[edge] = min_node

    return visited, path


graph = Graph()
graph.add_node('A')
graph.add_node('V')
graph.add_node('C')
graph.add_node('D')
graph.add_node('E')
graph.add_edge('A', 'B', 6)
graph.add_edge('A', 'D', 1)
graph.add_edge('B', 'C', 5)
graph.add_edge('B', 'D', 2)
graph.add_edge('B', 'E', 2)
graph.add_edge('D', 'E', 1)
graph.add_edge('E', 'C', 5)

print("Nodes :", graph.nodes)
print("Distances :", graph.distances)
print("Edges :", graph.edges)

print(dijsktra(graph, 'A'))
