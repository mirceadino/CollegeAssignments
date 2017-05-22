
def trapezoidal(x, a, b, c, d):
    """
    a, d = feet of the trapezoidal
    b, c = shoulders of the trapezoidal
    """
    return max(0, min((x-a)/(b-a), 1, (d-x)/(d-c)))


def triangular(x, a, b, c):
    """
    a, c = feet of the triangular
    b = peak of the triangular
    """
    return max(0, min((x-a)/(b-a), (c-x)/(c-b)))


def print_fuzz(text, fuzz):
    print(text, end='')
    for state in fuzz:
        print("{1} of {0} | ".format(state, fuzz[state]), end='')
    print()
