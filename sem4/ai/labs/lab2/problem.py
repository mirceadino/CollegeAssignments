from state import State

class Problem:

    def __init__(self):
        self.initialState = State(0)
        self.digits = [i for i in range(0, 10)]
        self.chr_to_int = {}
        self.int_to_chr = {}
        self.cant_be_zero = []
        self.numbers = []
        self.lines = []

    def isFinalState(self, state):
        return self._isSet(state) and self._isValid(state)

    def _isSet(self, state):
        for i in range(0, len(state)):
            if state.isNotSet(i):
                return False
            elif state.digit(i) == 0 and i in self.cant_be_zero:
                return False
        return True

    def _isValid(self, state):
        numbers = []
        for number_list in self.numbers:
            number = 0
            for c in number_list:
                pos = self.chr_to_int[c]
                number = number * 10 + state.digit(pos)
            numbers.append(number)
        final = numbers[-1]
        numbers = numbers[:-1]
        return sum(numbers) == final

    def expand(self, state):
        states = []
        remaining_digits = []
        for digit in self.digits:
            if digit not in state.digits:
                remaining_digits.append(digit)
        for i in range(len(state)):
            if state.isNotSet(i):
                for digit in remaining_digits:
                    new_state = state.copy()
                    new_state.set(i, digit)
                    states.append(new_state)
        return states

    def readFromFile(self, filename):
        f = open(filename, "r")
        current_int = 0
        self.chr_to_int = {}
        self.int_to_chr = {}
        self.cant_be_zero = []
        print("Reading...")
        for line in f:
            line = line.rstrip()
            print(line)
            self.lines.append(line)
            line = line.lstrip()
            self.numbers.append([])
            current_number = []
            for c in line:
                if str.isalpha(c):
                    current_number.append(c)
                if str.isalpha(c) and c not in self.chr_to_int:
                    self.chr_to_int[c] = current_int
                    self.int_to_chr[current_int] = c
                    current_int += 1
            self.cant_be_zero.append(self.chr_to_int[line[0]])
            self.numbers.append(current_number)
        self.initialState = State(current_int)
        print("Done reading!")

    def print(self, state):
        for line in self.lines:
            for c in self.chr_to_int:
                pos = self.chr_to_int[c]
                digit = chr(ord('0') + state.digit(pos))
                line = line.replace(c, digit)
            print(line)
