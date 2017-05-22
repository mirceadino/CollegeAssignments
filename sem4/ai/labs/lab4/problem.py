from random import randint


class Problem:

    def __init__(self, filename):
        self.load_problem(filename)


    def num_tasks(self):
        return self._num_tasks


    def num_computers(self):
        return self._num_computers


    def time(self, task, computer):
        return self._times[task][computer]


    def load_problem(self, filename):
        f = open(filename)
        self._num_tasks = int(f.readline())
        self._num_computers = int(f.readline())
        self._times = []
        for i in range(self._num_tasks):
            line = f.readline()
            self._times.append(list(map(int, line.split())))


    def generate_problem(self):
        self._num_tasks = 10
        self._num_computers = 4
        self._times = [[randint(1, 10) for j in range(self._num_computers)] for i in range(self._num_tasks)]


    def save_problem(self, filename):
        f = open(filename, "w")
        f.write(str(self._num_tasks) + "\n")
        f.write(str(self._num_computers) + "\n")
        for i in self._times:
            for j in i:
                f.write(str(j) + " " )
            f.write("\n")
