from individ import Individ
from problem import Problem
from random import shuffle


class Population:

    def __init__(self):
        self.num_individs = 0
        self.individs = []


    def add(self, individ):
        self.individs.append(individ)
        self.num_individs += 1


    def generate(self, problem, num_individs):
        self.num_individs = num_individs
        self.individs = []
        for i in range(0, self.num_individs):
            individ = Individ(problem.num_vertices())
            self.individs.append(individ)


    def recombinate(self, pcrossover, pmutation):
        shuffle(self.individs)
        new_population = Population()
        for i in range(0, self.num_individs-1, 2):
            child = self.individs[i].crossover(self.individs[i+1], pcrossover)
            if child is not None:
                new_population.add(child)
                child.mutate(pmutation)
        return new_population


    def evaluate(self, problem):
        for individ in self.individs:
            individ.compute_fitness(problem)


    def reunite(self, new_population):
        self.individs += new_population.individs
        self.num_individs += new_population.num_individs


    def select(self, problem, size):
        self.individs.sort(key=lambda x: x.fitness)
        self.individs = self.individs[:size]
        self.num_individs = size

