from swarm import Swarm


class Controller:

    def __init__(self, problem):
        self.load_params()
        self._swarm = Swarm(self._num_particles, problem)


    def iteration(self, problem):
        best_particle = self._swarm.get_best_particle(problem)
        for particle in self._swarm:
            # best_particle = self._swarm.get_best_neighbour(particle, problem)
            particle.update(best_particle, self._w, self._c1, self._c2)
            particle.evaluate(problem)


    def run(self, problem):
        for i in range(self._num_iterations):
            self.iteration(problem)


    def best_particle(self, problem):
        return self._swarm.get_best_particle(problem)


    def load_params(self):
        f = open("params.in")
        self._num_particles = int(f.readline())
        self._num_iterations = int(f.readline())
        self._w = float(f.readline())
        self._c1 = float(f.readline())
        self._c2 = float(f.readline())
