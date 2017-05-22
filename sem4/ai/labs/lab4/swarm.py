from particle import Particle


class Swarm:

    def __init__(self, num_particles, problem):
        self._particles = [Particle(problem) for i in range(num_particles)]
        self._particles.append(self._particles[0])
        for i in range(num_particles):
            self._particles[i].add_neighbour(self._particles[i-1])
            self._particles[i].add_neighbour(self._particles[i+1])
        self._particles.pop()


    def __iter__(self):
        return iter(self._particles)


    def get_best_particle(self, problem):
        return min(self._particles, key=lambda x: x.fitness(problem))


    def get_best_neighbour(self, particle, problem):
        return min(particle.neighbours(), key=lambda x: x.fitness(problem))
