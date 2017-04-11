from copy import deepcopy
from random import shuffle, randint, random


class Individ:

    def __init__(self, size):
        self.permutation = [i for i in range(0, size)]
        self.size = size
        self.fitness = -1
        shuffle(self.permutation)


    def compute_fitness(self, problem):
        size = self.size

        graph_1 = problem.get_subgraph(self.permutation[0:size//2])
        fitness_1 = 0
        for x in graph_1.vertices():
            for y in graph_1.vertices():
                if graph_1.is_path(x,y):
                    fitness_1 += 1

        graph_2 = problem.get_subgraph(self.permutation[size//2: size])
        fitness_2 = 0
        for x in graph_2.vertices():
            for y in graph_2.vertices():
                if graph_2.is_path(x,y):
                    fitness_2 += 1

        self.fitness = fitness_1 + fitness_2
        self.fitness = self.size ** 2 // 2 - self.fitness

        return self.fitness


    def __str__(self):
        return str(self.permutation)


    def copy(self):
        new = deepcopy(self)
        return new


    def mutate(self, probability):
        if random() < probability:
            return self._inverse_mutation()
        return self


    def _swap_mutation(self):
        size = self.size
        i = randint(0, size-1)
        j = randint(0, size-1)
        swap(self[i], self[j])


    def _inverse_mutation(self):
        size = self.size
        i = randint(0, size-1)
        j = randint(0, size-1)
        if i > j:
            i, j = j, i
        self.permutation = self.permutation[0:i] + list(reversed(self.permutation[i:j])) + self.permutation[j:]


    def crossover(self, individ, probability):
        child = individ.copy()
        size = self.size
        p = randint(0, size-1)
        r = (p + size//2) % size
        if p < r:
            keep = child.permutation[p:r]
        else:
            keep = child.permutation[p:] + child.permutation[:r]

        j = r
        for i in range(r, size):
            if self.permutation[i] not in keep:
                child.permutation[j] = self.permutation[i]
                j = (j+1)%size
        for i in range(0, r):
            if self.permutation[i] not in keep:
                child.permutation[j] = self.permutation[i]
                j = (j+1)%size

        if random() < probability:
            return child
        else:
            return None
