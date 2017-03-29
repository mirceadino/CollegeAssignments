from controller import Controller
from problem import Problem


class UI:
    def __init__(self, controller):
        self.controller = controller

    def run(self):
        file_index = input("Choose file [0; 1; 2; 3]: ").strip()
        if file_index not in ["0", "1", "2", "3"]:
            print("Invalid file")
            return

        filename = "input/0" + str(file_index) + ".txt"
        problem = Problem()
        problem.readFromFile(filename)

        solution = None
        method = input("Choose method [0 - dfs; 1 - gbfs]: ").strip()
        if method is "0":
            solution = self.controller.dfs(problem)
        elif method is "1":
            solution = self.controller.gbfs(problem)
        else:
            print("Invalid method")
            return
        if solution is not None:
            print("Found solution...")
            problem.print(solution)
        else:
            print("Couldn't find solution.")
