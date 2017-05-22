from problem import Problem
from controller import Controller
from statistics import mean, stdev
import sys


def main():
    filename = sys.argv[1]
    problem = Problem(filename)

    num_runs = int(sys.argv[2])
    bests = []

    for i in range(num_runs):
        controller = Controller(problem)
        controller.run(problem)
        best = controller.best_particle(problem)
        bests.append(best)
        print("Best solution: {0}".format(str(best)))
        print("Best fitness: {0}".format(best.fitness(problem)))

    fitnesses = [i.fitness(problem) for i in bests]

    miu = mean(fitnesses)
    sigma = stdev(fitnesses)

    print("Mean of fitnesses is {0}".format(miu))
    print("Standard deviation is {0}".format(sigma))


if __name__ == "__main__":
    main()
