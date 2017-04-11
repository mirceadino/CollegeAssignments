from problem import Problem
from population import Population


class Algorithm:

    def __init__(self, problem):
        self.problem = problem
        self._read_parms()
        self.population = Population()
        self.population.generate(problem, self.num_individs)


    def _read_parms(self):
        f = open("params.in")
        ignore = f.readline()
        self.pmutation = float(f.readline())
        self.pcrossover = float(f.readline())
        self.num_individs = int(f.readline())
        self.num_generations = int(f.readline())


    def iteration(self):
        size = self.population.num_individs

        new_population = self.population.recombinate(self.pcrossover, self.pmutation)
        self.population.reunite(new_population)
        self.population.evaluate(self.problem)
        self.population.select(self.problem, size)


    def run(self):
        print("Running for {0} generations...".format(self.num_generations))
        for i in range(0, self.num_generations):
            self.iteration()


    def get_best(self):
        self.population.evaluate(self.problem)
        best = self.population.individs[0]
        return best
