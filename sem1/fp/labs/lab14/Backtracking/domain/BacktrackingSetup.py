
class BacktrackingSetup():

    def __init__(self, n, pool):
        '''
        Constructor for the class BacktrackingSetup.
        :param n: int - dimension
        :param pool: list - pool of elements for the backtracking
        '''
        self._solutions = []
        self._stack = []
        self._n = n
        self._pool = pool


    def __str__(self):
        '''
        String with all the solutions.
        :return: str - all solutions
        '''
        ret = ""
        for solution in self._solutions:
            ret += str(solution) + "\n"
        return ret


    def solutions(self):
        '''
        List with all the solutions.
        :return: list - all solutions
        '''
        return self._solutions[:]


    def is_consistent(self):
        '''
        Checks if the stack is consistent.
        :return: True - stack is consistent; False - otherwise
        '''
        if len(self._stack) > 2 * self._n + 1:
            return False

        if len(self._stack) == 0:
            return False

        if self._stack[0] != 0:
            return False

        if len(self._stack) == 1:
            return True

        last = self._stack[len(self._stack)-1]
        before_last = self._stack[len(self._stack)-2]

        return 1 <= abs(last - before_last) <= 2


    def is_solution(self):
        '''
        Checks if the stack holds a valid solution.
        :return: True - stack is a solution; False - otherwise
        '''
        return self.is_consistent() and len(self._stack) == 2 * self._n + 1 and self._stack[-1] == 0


    def add_solution(self):
        '''
        Adds the stack to the set of solutions.
        '''
        self._solutions.append(self._stack[:])


    def _backtracking(self):
        '''
        Method to be overridden for the backtracking.
        '''
        pass