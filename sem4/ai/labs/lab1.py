import random
from statistics import mean, stdev


class Ball:
    def __init__(self, id, color, character):
        self.id = id
        self.color = color
        self.character = character

    def __repr__(self):
        return "{0}/{1}/{2}".format(self.id, self.color, self.character)


kVowels = ['a', 'e', 'i', 'o', 'u']

def main():
    n = int(input("Total number of balls = "))
    p = int(input("Number of white balls = "))

    balls = []
    for x in range(0, n):
        c = input("Type character of ball {0} = ".format(x))
        balls.append(Ball(x, "white" if x < p else "blue", c))
        print(balls[-1])

    k = int(input("Number of selected balls = "))
    a = int(input("Minimum number of white balls = "))
    num_samples = int(input("Number of samples = "))

    print("----")
    fitnesses = []
    for case in range(0, num_samples):
        solution = random.sample(balls, k)
        print(solution)

        if is_viable(solution, a):
            print("Solution is GOOD")
        else:
            print("Solution is BAD")

        f = fitness(solution, a)
        fitnesses.append(f)
        print("Fitness is {0}".format(f))

        if is_viable(solution, a) is (f == 0):
            print("Verdict corresponds with fitness!")
        else:
            print("Verdict DOESN'T correspond with finess!")
        print("---")

    miu = mean(fitnesses)
    sigma = stdev(fitnesses)

    print("Mean of fitnesses is {0}".format(miu))
    print("Standard deviation is {0}".format(sigma))


def is_viable(solution, a):
    num_white = sum([1 if x.color is "white" else 0 for x in solution])
    num_white_vowels = sum([1 if x.color is "white" and x.character in kVowels else 0 for x in solution])
    return num_white >= a and num_white_vowels >= 1


def fitness(solution, a):
    num_white = sum([1 if x.color is "white" else 0 for x in solution])
    num_white_vowels = sum([1 if x.color is "white" and x.character in kVowels else 0 for x in solution])
    return max(0, a - num_white) + (0 if num_white_vowels >= 1 else 1)


if __name__ == "__main__":
    main()
