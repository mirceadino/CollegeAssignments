from random import randint, random
from math import exp


class Particle:

    def __init__(self, problem):
        num_computers = problem.num_computers()
        num_tasks = problem.num_tasks()

        self._position = [randint(0, num_computers-1) for i in range(num_tasks)]
        self._velocity = [random() for i in range(num_tasks)]
        self._neighbours = []
        self._best_position = self._position
        self._best_fitness = self.fitness(problem)


    def add_neighbour(self, neighbour):
        self._neighbours.append(neighbour)


    def neighbours(self):
        return self._neighbours


    def position(self):
        return self._position


    def velocity(self):
        return self._velocity


    def fitness(self, problem):
        time = {}
        for task in range(len(self._position)):
            computer = self._position[task]
            if computer not in time:
                time[computer] = 0
            time[computer] += problem.time(task, computer)
        return max(time.values())


    def sigmoid(self, x):
        return 1/(1 + exp(-x))


    def update(self, particle, w, c1, c2):
        for i in range(len(self._velocity)):
            v = w * self._velocity[i] \
                    + c1 * random() * (self._best_position[i] - self._position[i]) \
                    + c2 * random() * (particle.position()[i] - self._position[i])
            self._velocity[i] = v

        for i in range(len(self._velocity)):
            if random() < self.sigmoid(self._velocity[i]):
                self._position[i] = particle.position()[i]


    def evaluate(self, problem):
        f = self.fitness(problem)
        if f < self._best_fitness:
            self._best_fitness = f
            self._best_position = self._position


    def best_position(self):
        return self._best_position


    def best_fitness(self):
        return self._best_fitness


    def __repr__(self):
        return repr([int(x) for x in self._position])
