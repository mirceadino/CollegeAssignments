class Problem:

    def __init__(self):
        self.v = []
        self.e = []
        self.paths = []


    def num_vertices(self):
        return len(self.v)


    def num_edges(self):
        return len(self.e)


    def vertices(self):
        return self.v


    def edges(self):
        return self.e


    def is_edge(self, x, y):
        return (x,y) in self.e or (y,x) in self.e


    def is_path(self, x, y):
        if len(self.e) != 0 and len(self.paths) == 0:
            self.compute_paths()
        return (x,y) in self.paths or (y,x) in self.paths


    def compute_paths(self):
        for starting_x in self.v:
            visited = set([starting_x])
            queue = [starting_x]

            while len(queue) != 0:
                vertex = queue[0]
                queue = queue[1:]
                for (x,y) in self.e:
                    if x == vertex and y not in visited:
                        queue.append(y)
                        visited.add(y)
                    if y == vertex and x not in visited:
                        queue.append(x)
                        visited.add(x)

            for y in visited:
                self.paths.append((starting_x, y))


    def get_subgraph(self, v):
        graph = Problem()
        graph.v = v
        for (x,y) in self.e:
            if x in v and y in v:
                graph.e.append((x,y))
        return graph


    def load_data(self, filename):
        f = open(filename)
        n, m = map(int, f.readline().split())
        self.v = range(0, n)
        for line in f:
            x, y = map(int, line.split())
            self.e.append((x, y))
        print("Finished reading a graph with {0} vertices and {1} edges!".format(n, m))
