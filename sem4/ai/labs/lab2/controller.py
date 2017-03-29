from state import State
from problem import Problem


class Controller:
    def __init__(self):
        pass

    def orderStates(self, states):
        states = sorted(states, key=lambda state: state.heuristic())
        return list(reversed(states))

    def dfs(self, problem):
        self._visited = []
        stack = [problem.initialState]
        self._visited.append(problem.initialState)
        while len(stack) > 0:
            state = stack.pop()
            self._visited.append(state)
            if problem.isFinalState(state):
                return state
            for child_state in problem.expand(state):
                if child_state not in self._visited and child_state not in stack:
                    stack.append(child_state)

    def gbfs(self, problem):
        self._visited = []
        stack = [problem.initialState]
        self._visited.append(problem.initialState)
        while len(stack) > 0:
            state = stack.pop()
            self._visited.append(state)
            if problem.isFinalState(state):
                return state
            for child_state in problem.expand(state):
                if child_state not in self._visited and child_state not in stack:
                    stack.append(child_state)
            stack = self.orderStates(stack)

