from domain.BacktrackingSetup import BacktrackingSetup


class BacktrackingIterative(BacktrackingSetup):

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
        Performs backtracking iteratively.
        '''
        self._stack.append(-1)
        indices = [0]

        while len(self._stack) > 0:
            consistent = False

            while not consistent and indices[-1] < len(self._pool):
                self._stack[-1] = self._pool[indices[-1]]
                consistent = self.is_consistent()
                indices[-1] += 1

            if consistent:
                if self.is_solution():
                    self.add_solution()
                self._stack.append(-1)
                indices.append(0)
            else:
                self._stack = self._stack[:-1]
                indices = indices[:-1]


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
    A = BacktrackingIterative(0, [-1, 0, 1])
    R = [[0]]
    assert _check(A.solutions(), R)

    A = BacktrackingIterative(1, [-1, 0, 1])
    R = [[0, -1, 0],
         [0, 1, 0]]
    assert _check(A.solutions(), R)

    A = BacktrackingIterative(2, [-1, 0, 1])
    R = [[0, -1, 0, -1, 0],
         [0, -1, 0, 1, 0],
         [0, -1, 1, -1, 0],
         [0, 1, 0, -1, 0],
         [0, 1, 0, 1, 0],
         [0, 1, -1, 1, 0]]
    assert _check(A.solutions(), R)


if __name__ == "__main__":
    test()