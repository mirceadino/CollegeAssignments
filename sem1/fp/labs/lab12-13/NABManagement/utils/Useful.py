from copy import deepcopy


def sort(myIterable, *, cmp=lambda x,y: x<y, key=lambda x: x, reverse=False):
    '''
    Returns a sorted sequence with respect to a comparison function or a key function or a reverse parameter.
    :param myIterable: iterable - iterable sequence to be sorted
    :param cmp: boolean binary function - function that compares two elements and returns True if two elements are in good order and False otherwise
    :param key: unary function - function that assigns a key used in sorting for sequence's elements
    :param reverse: bool - whether the sequence must be sorted accordingly or deafeningly
    :return: iterable - iterable sequence in sorted order
    '''

    sortedIterable = deepcopy(myIterable)

    gap = len(sortedIterable)
    shrinkCoef = 1.3
    isOrdered = False

    while gap > 1 or isOrdered == False:
        gap = max(1, int(gap/shrinkCoef))
        isOrdered = True

        for i in range(0, len(sortedIterable)-gap):
            if (not reverse) and cmp(key(sortedIterable[i+gap]), key(sortedIterable[i])):
                sortedIterable[i], sortedIterable[i+gap] = sortedIterable[i+gap], sortedIterable[i]
                isOrdered = False
            elif reverse and cmp(key(sortedIterable[i]), key(sortedIterable[i+gap])):
                sortedIterable[i], sortedIterable[i+gap] = sortedIterable[i+gap], sortedIterable[i]
                isOrdered = False

    return sortedIterable


def filter(funct, myIterable):
    '''
    Returns a list of elements from a list with pass a certain filter.
    :param funct: boolean unary function - function that returns True if an elements passes the filter and False otherwise
    :param myIterable: iterable - iterable sequence to be filtered
    :return: list - list of filtered elements
    '''

    return [x for x in myIterable if funct(x)]