class Graph:
    def __init__(self, num_vertexes: int):
        self.graph = {}
        self._init_graph(num_vertexes)

    def _init_graph(self, num_vertexes: int):
        for vertex in range(num_vertexes):
            self.graph[vertex] = []

    def add_edges(self, edges: list):
        for vertex1, vertex2 in edges:
            self.graph[vertex1].append(vertex2)

    def dfs(self, start: int, end: int):
        visited = set()

        #initiate DFS
        return self.traverse(
            current=start,
            end=end,
            visited=visited
        )

    def traverse(self, current: int, end: int, visited: set):
        visited.add(current)

        for vertex in self.graph[current]:
            #if vertex is end condition
            if vertex == end:
                return True
            #else recursively search
            if vertex not in visited:
                tested = self.traverse(current=vertex, end=end, visited=visited)
                if tested:
                    return True
        #return false if no path to end through vertex current exists
        return False

def find_path(n: int, edges: list, start: int, end: int):
    graph = Graph(n)
    graph.add_edges(edges=edges)
    return graph.dfs(start, end)
