from domain.BacktrackingSetup import BacktrackingSetup


class BacktrackingRecursive(BacktrackingSetup):

    def __init__(self, n, pool):
        '''
        Constructor for the class BacktrackingRecursive.
        :param n: int - dimension
        :param pool: list - pool of elements for the backtracking
        '''
        BacktrackingSetup.__init__(self, n, pool)
        self._backtracking()


    def _backtracking(self):
        '''
        Performs backtracking recursively.
        '''
        self._stack.append(0)

        for i in self._pool:
            self._stack[-1] = i

            if self.is_consistent():
                self._backtracking()

            if self.is_solution():
                self.add_solution()

        self._stack.pop()


def _check(L, R):
    L.sort()
    R.sort()
    if len(L) != len(R):
        return False
    for i in range(len(L)):
        try:
            assert str(L[i]) == str(R[i])
        except AssertionError:
            return False
    return True


def test():
    A = BacktrackingRecursive(0, [-1, 0, 1])
    R = [[0]]
    assert _check(A.solutions(), R)

    A = BacktrackingRecursive(1, [-1, 0, 1])
    R = [[0, -1, 0],
         [0, 1, 0]]
    assert _check(A.solutions(), R)

    A = BacktrackingRecursive(2, [-1, 0, 1])
    R = [[0, -1, 0, -1, 0],
         [0, -1, 0, 1, 0],
         [0, -1, 1, -1, 0],
         [0, 1, 0, -1, 0],
         [0, 1, 0, 1, 0],
         [0, 1, -1, 1, 0]]
    assert _check(A.solutions(), R)


if __name__ == "__main__":
    test()