from domain.BacktrackingRecursive import BacktrackingRecursive
from domain.BacktrackingIterative import BacktrackingIterative


def get_dim():
    '''
    Gets a natural number from the input. Reread the input if it's not a natural number.
    :return: natural number - read number
    '''
    try:
        buffer = input("N = ")
        buffer = buffer.strip()
        n = int(buffer)
        if n < 0 or str(n) != buffer:
            raise ValueError()
        return n
    except:
        return get_dim()


if __name__ == "__main__":
    pool = [-1, 0, 1]
    n = get_dim()
    A = BacktrackingRecursive(n, pool)
    B = BacktrackingIterative(n, pool)
    print(A)