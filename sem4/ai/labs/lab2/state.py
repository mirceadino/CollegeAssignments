from copy import deepcopy


class State:
    def __init__(self, num_digits):
        self.digits = [-1 for i in range(num_digits)]

    def isSet(self, i):
        return self.digits[i] != -1

    def isNotSet(self, i):
        return not self.isSet(i)

    def set(self, i, digit):
        self.digits[i] = digit

    def unset(self, i):
        self.digits[i] = -1

    def digit(self, i):
        return self.digits[i]

    def copy(self):
        return deepcopy(self)

    def __len__(self):
        return len(self.digits)

    def __eq__(self, other):
        return self.digits == other.digits

    def heuristic(self):
        return sum(self.digits)
