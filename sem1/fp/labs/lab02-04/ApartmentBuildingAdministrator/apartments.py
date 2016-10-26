def get_apartments(allTransactions):
    '''
    Computes the set of apartments which have expenses.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    Returns: allApartments - set which represents the current set of apartment numbers
    '''

    return set([x[2] for x in allTransactions])


def test_get_apartments():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    assert get_apartments(allTransactions) == set([25])
    add_transaction(allTransactions, 20, 1, 25)
    assert get_apartments(allTransactions) == set([25])
    add_transaction(allTransactions, 100, 4, 20)
    assert get_apartments(allTransactions) == set([20, 25])
    add_transaction(allTransactions, 50, 3, 20)
    assert get_apartments(allTransactions) == set([20, 25])
    add_transaction(allTransactions, 75, 2, 1)
    assert get_apartments(allTransactions) == set([1, 20, 25])


def compute_balance(allTransactions, apartment):
    '''
    Computes balance for an apartment (i.e. the total amount of expenses of all types).
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
          apartment - positive integer representing the number of an apartment for which we want its balance
    Returns: balance - natural number representing the balance of the apartment
    '''

    return sum([transaction[0] for transaction in allTransactions if transaction[2] == apartment])


def test_compute_balance():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    assert compute_balance(allTransactions, 25) == 20
    add_transaction(allTransactions, 20, 1, 25)
    assert compute_balance(allTransactions, 25) == 40
    add_transaction(allTransactions, 100, 4, 20)
    assert compute_balance(allTransactions, 20) == 100
    add_transaction(allTransactions, 50, 3, 20)
    assert compute_balance(allTransactions, 20) == 150
    add_transaction(allTransactions, 75, 2, 1)
    assert compute_balance(allTransactions, 1) == 75
    assert compute_balance(allTransactions, 20) == 150
    assert compute_balance(allTransactions, 25) == 40


def apartments_greater_than(allTransactions, value):
    '''
    Selects apartments with a balance greater than a certain value.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
          value - integer for which we want the list of apartments with whose balance is greater than this value
    Returns: apartmentSubset - set which represents the apartments with the desired property
    '''

    allApartments = get_apartments(allTransactions)

    return set([apartment for apartment in allApartments if compute_balance(allTransactions, apartment) > value])


def test_apartments_greater_than():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    assert apartments_greater_than(allTransactions, 0) == set([25])
    assert apartments_greater_than(allTransactions, 30) == set()
    add_transaction(allTransactions, 20, 1, 25)
    assert apartments_greater_than(allTransactions, 0) == set([25])
    assert apartments_greater_than(allTransactions, 30) == set([25])
    assert apartments_greater_than(allTransactions, 60) == set()
    add_transaction(allTransactions, 100, 4, 20)
    assert apartments_greater_than(allTransactions, 0) == set([25, 20])
    assert apartments_greater_than(allTransactions, 60) == set([20])
    assert apartments_greater_than(allTransactions, 100) == set()
    add_transaction(allTransactions, 50, 3, 20)
    assert apartments_greater_than(allTransactions, 0) == set([25, 20])
    assert apartments_greater_than(allTransactions, 60) == set([20])
    assert apartments_greater_than(allTransactions, 100) == set([20])
    add_transaction(allTransactions, 75, 2, 1)
    assert apartments_greater_than(allTransactions, 0) == set([25, 20, 1])
    assert apartments_greater_than(allTransactions, 60) == set([20, 1])
    assert apartments_greater_than(allTransactions, 100) == set([20])


def apartments_less_than(allTransactions, value):
    '''
    Selects apartments with a balance less than a certain value.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
          value - integer for which we want the list of apartments with whose balance is less than this value
    Returns: apartmentSubset - set which represents the apartments with the desired property
    '''

    allApartments = get_apartments(allTransactions)

    return set([apartment for apartment in allApartments if compute_balance(allTransactions, apartment) < value])


def test_apartments_less_than():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    assert apartments_less_than(allTransactions, 0) == set()
    assert apartments_less_than(allTransactions, 30) == set([25])
    add_transaction(allTransactions, 20, 1, 25)
    assert apartments_less_than(allTransactions, 0) == set()
    assert apartments_less_than(allTransactions, 30) == set()
    assert apartments_less_than(allTransactions, 60) == set([25])
    add_transaction(allTransactions, 100, 4, 20)
    assert apartments_less_than(allTransactions, 0) == set()
    assert apartments_less_than(allTransactions, 60) == set([25])
    assert apartments_less_than(allTransactions, 100) == set([25])
    assert apartments_less_than(allTransactions, 200) == set([25, 20])
    add_transaction(allTransactions, 50, 3, 20)
    assert apartments_less_than(allTransactions, 0) == set()
    assert apartments_less_than(allTransactions, 60) == set([25])
    assert apartments_less_than(allTransactions, 100) == set([25])
    assert apartments_less_than(allTransactions, 200) == set([25, 20])
    add_transaction(allTransactions, 75, 2, 1)
    assert apartments_less_than(allTransactions, 0) == set()
    assert apartments_less_than(allTransactions, 60) == set([25])
    assert apartments_less_than(allTransactions, 100) == set([25, 1])
    assert apartments_less_than(allTransactions, 200) == set([25, 20, 1])


def apartments_before(allApartments, value):
    '''
    Selects apartments before a certain number (whose number is less than or equal to a certain number).
    Gets: allApartments - set which represents the current set of apartment numbers
          value - integer for which we want the list of apartments with whose numbers are before this value
    Returns: apartmentSubset - set which represents the apartments with the desired property
    '''

    return set([apartment for apartment in allApartments if apartment <= value])


def test_apartments_before():
    allApartments = set()
    assert apartments_before(allApartments, 4) == set()

    allApartments = set([1, 2, 3, 4, 5, 20])
    assert apartments_before(allApartments, 4) == set([1, 2, 3, 4])
    assert apartments_before(allApartments, 10) == set([1, 2, 3, 4, 5])
    assert apartments_before(allApartments, 30) == set([1, 2, 3, 4, 5, 20])

    allApartments = set([1, 15, 30, 100, 1200])
    assert apartments_before(allApartments, 4) == set([1])
    assert apartments_before(allApartments, 10) == set([1])
    assert apartments_before(allApartments, 30) == set([1, 15, 30])


if __name__ == '__main__':
    from expenses import add_transaction

    test_get_apartments()
    test_compute_balance()
    test_apartments_greater_than()
    test_apartments_less_than()
    test_apartments_before()