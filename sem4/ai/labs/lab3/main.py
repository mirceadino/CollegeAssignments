from problem import Problem
from algorithm import Algorithm
from individ import Individ
from statistics import mean, stdev
import sys


def main():
    problem = Problem()
    filename = sys.argv[1]
    problem.load_data(filename)

    bests = []

    for i in range(0, 30):
        print("Run #{0}:".format(i))
        algorithm = Algorithm(problem)
        algorithm.run()
        best = algorithm.get_best()
        bests.append(best)
        print("Best solution: {0}".format(str(best)))
        print("Best fitness: {0}".format(best.fitness))

    fitnesses = [i.fitness for i in bests]

    miu = mean(fitnesses)
    sigma = stdev(fitnesses)

    print("Mean of fitnesses is {0}".format(miu))
    print("Standard deviation is {0}".format(sigma))


if __name__ == "__main__":
    main()
