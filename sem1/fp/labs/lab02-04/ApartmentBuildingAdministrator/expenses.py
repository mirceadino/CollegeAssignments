from copy import deepcopy
from apartments import *


def valid_transaction(expense, type, apartment):
    '''
	Check if a transaction is valid, i.e. expense is positive, type is existent and apartment is positive.
	Gets: expense - integer representing the value of the expense
		  type - integer representing the id number of a type of expense
		  apartment - integer representing the number of an apartment
	Returns: True - data is valid
			 False - data is invalid
	'''

    if expense <= 0:
        return False

    if type not in [1, 2, 3, 4, 5]:
        return False

    if apartment <= 0:
        return False

    return True


def test_valid_transaction():
    assert valid_transaction(20, 5, 200) == True
    assert valid_transaction(0, 5, 200) == False
    assert valid_transaction(20, 5, -1) == False
    assert valid_transaction(20, 7, 200) == False
    assert valid_transaction(20, 0, 200) == False
    assert valid_transaction(60, 1, 1) == True
    assert valid_transaction(256, 3, 16) == True


def add_transaction(allTransactions, expense, type, apartment):
    '''
	Adds an expense of a certain type to a certain apartment (valid transaction) in the list of expenses.
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
		  expense - positive integer representing the value of the expense to be added
		  type - positive integer representing the id number of a type of expense
		  apartment - positive integer representing the number of an apartment to which the expense is added
	Returns: None; allTransactions is appended the tuple corresponding to the added expense, so its length increases;
	'''

    allTransactions.append((expense, type, apartment))


def test_add_transaction():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    assert allTransactions == [(20, 1, 25)]
    add_transaction(allTransactions, 20, 1, 25)
    assert allTransactions == [(20, 1, 25), (20, 1, 25)]
    add_transaction(allTransactions, 100, 4, 20)
    assert allTransactions == [(20, 1, 25), (20, 1, 25), (100, 4, 20)]
    add_transaction(allTransactions, 50, 3, 20)
    assert allTransactions == [(20, 1, 25), (20, 1, 25), (100, 4, 20), (50, 3, 20)]
    add_transaction(allTransactions, 75, 2, 1)
    assert allTransactions == [(20, 1, 25), (20, 1, 25), (100, 4, 20), (50, 3, 20), (75, 2, 1)]


def expenses_of_type(allTransactions, type):
    '''
	Selects the expenses of a certain type.
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
		  type - positive integer representing the id number of a type of expense
	Returns: expensesSublist - list which contains the required expenses
	'''

    return [transaction for transaction in allTransactions if transaction[1] == type]


def test_expenses_of_type():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    assert expenses_of_type(allTransactions, 1) == [(20, 1, 25)]
    assert expenses_of_type(allTransactions, 2) == []
    assert expenses_of_type(allTransactions, 3) == []
    assert expenses_of_type(allTransactions, 4) == []
    assert expenses_of_type(allTransactions, 5) == []
    add_transaction(allTransactions, 20, 1, 25)
    assert expenses_of_type(allTransactions, 1) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_type(allTransactions, 2) == []
    assert expenses_of_type(allTransactions, 3) == []
    assert expenses_of_type(allTransactions, 4) == []
    assert expenses_of_type(allTransactions, 5) == []
    add_transaction(allTransactions, 100, 4, 20)
    assert expenses_of_type(allTransactions, 1) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_type(allTransactions, 2) == []
    assert expenses_of_type(allTransactions, 3) == []
    assert expenses_of_type(allTransactions, 4) == [(100, 4, 20)]
    assert expenses_of_type(allTransactions, 5) == []
    add_transaction(allTransactions, 50, 3, 20)
    assert expenses_of_type(allTransactions, 1) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_type(allTransactions, 2) == []
    assert expenses_of_type(allTransactions, 3) == [(50, 3, 20)]
    assert expenses_of_type(allTransactions, 4) == [(100, 4, 20)]
    assert expenses_of_type(allTransactions, 5) == []
    add_transaction(allTransactions, 75, 2, 1)
    assert expenses_of_type(allTransactions, 1) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_type(allTransactions, 2) == [(75, 2, 1)]
    assert expenses_of_type(allTransactions, 3) == [(50, 3, 20)]
    assert expenses_of_type(allTransactions, 4) == [(100, 4, 20)]
    assert expenses_of_type(allTransactions, 5) == []


def expenses_of_apartment(allTransactions, apartment):
    '''
	Selects the expenses of a certain apartment.
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
		  apartment - positive integer representing the number of an apartment
	Returns: expensesSublist - list which contains the required expenses
	'''

    return [transaction for transaction in allTransactions if transaction[2] == apartment]


def test_expenses_of_apartment():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    assert expenses_of_apartment(allTransactions, 25) == [(20, 1, 25)]
    assert expenses_of_apartment(allTransactions, 1) == []
    add_transaction(allTransactions, 20, 1, 25)
    assert expenses_of_apartment(allTransactions, 25) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_apartment(allTransactions, 1) == []
    add_transaction(allTransactions, 100, 4, 20)
    assert expenses_of_apartment(allTransactions, 25) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_apartment(allTransactions, 20) == [(100, 4, 20)]
    add_transaction(allTransactions, 50, 3, 20)
    assert expenses_of_apartment(allTransactions, 20) == [(100, 4, 20), (50, 3, 20)]
    add_transaction(allTransactions, 75, 2, 1)
    assert expenses_of_apartment(allTransactions, 25) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_apartment(allTransactions, 1) == [(75, 2, 1)]
    assert expenses_of_apartment(allTransactions, 20) == [(100, 4, 20), (50, 3, 20)]
    assert expenses_of_apartment(allTransactions, 17) == []


def expenses_of_amount(allTransactions, value):
    '''
	Selects the expenses of a certain amount.
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
		  value - positive integer representing the value of the amount
	Returns: expensesSublist - list which contains the required expenses
	'''

    return [transaction for transaction in allTransactions if transaction[0] == value]


def test_expenses_of_amount():
    allTransactions = []

    assert expenses_of_amount(allTransactions, 10) == []
    add_transaction(allTransactions, 20, 1, 25)
    assert expenses_of_amount(allTransactions, 20) == [(20, 1, 25)]
    assert expenses_of_amount(allTransactions, 10) == []
    add_transaction(allTransactions, 20, 1, 25)
    assert expenses_of_amount(allTransactions, 20) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_amount(allTransactions, 2) == []
    add_transaction(allTransactions, 100, 4, 20)
    assert expenses_of_amount(allTransactions, 20) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_amount(allTransactions, 100) == [(100, 4, 20)]
    add_transaction(allTransactions, 50, 3, 20)
    assert expenses_of_amount(allTransactions, 20) == [(20, 1, 25), (20, 1, 25)]
    assert expenses_of_amount(allTransactions, 50) == [(50, 3, 20)]
    assert expenses_of_amount(allTransactions, 100) == [(100, 4, 20)]
    add_transaction(allTransactions, 75, 2, 1)
    assert expenses_of_amount(allTransactions, 75) == [(75, 2, 1)]


def remove_expenses(allTransactions, expensesSublist):
    '''
	Removes a sublist of expenses from a larger list.
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
		  expensesSublist - list containing tuples of form (expense, type, apartment) which is a sublist of allTransactions
	Returns: True - all expenses from the sublist have been removed
			 False - some expenses have not been found in the larger list
			 allTransactions <- allTransactions \ expensesSublist
	'''

    allRemoved = True

    for transaction in expensesSublist:
        try:
            allTransactions.remove(transaction)
            removed = True
        except ValueError:
            allRemoved = False

    return allRemoved


def test_remove_expenses():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 100, 4, 20)
    add_transaction(allTransactions, 50, 3, 20)
    add_transaction(allTransactions, 75, 2, 1)

    expensesSublist = [(20, 1, 25)]
    assert remove_expenses(allTransactions, expensesSublist) == True
    assert len(allTransactions) == 4

    expensesSublist = [(20, 1, 25), (17, 1, 1)]
    assert remove_expenses(allTransactions, expensesSublist) == False
    assert len(allTransactions) == 3

    expensesSublist = [(20, 1, 25)]
    assert remove_expenses(allTransactions, expensesSublist) == False
    assert len(allTransactions) == 3

    expensesSublist = deepcopy(allTransactions)
    assert remove_expenses(allTransactions, expensesSublist) == True
    assert len(allTransactions) == 0


def sum_expenses_of_type(allTransactions, type):
    '''
	Obtains the sum of all the expenses of a certain type.
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
		  type - positive integer representing the id number of a type of expense
	Returns: sum - positive integer representing the sum of all expenses of the required type
	'''

    return sum([transaction[0] for transaction in allTransactions if transaction[1] == type])


def test_sum_expenses_of_type():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 100, 4, 20)
    add_transaction(allTransactions, 50, 3, 20)
    add_transaction(allTransactions, 75, 2, 1)

    assert sum_expenses_of_type(allTransactions, 1) == 40
    assert sum_expenses_of_type(allTransactions, 2) == 75
    assert sum_expenses_of_type(allTransactions, 3) == 50
    assert sum_expenses_of_type(allTransactions, 4) == 100
    assert sum_expenses_of_type(allTransactions, 5) == 0


def sort_ascending(allTransactions):
    '''
	Sorts all the expenses in ascending order
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
	Returns: None; allTransactions is sorted in ascending order
	'''

    allTransactions.sort()


def test_sort_ascending():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 100, 4, 20)
    add_transaction(allTransactions, 50, 3, 20)
    add_transaction(allTransactions, 75, 2, 1)

    sort_ascending(allTransactions)

    assert allTransactions == [(20, 1, 25), (20, 1, 25), (50, 3, 20), (75, 2, 1), (100, 4, 20)]


def sort_descending(allTransactions):
    '''
	Sorts all the expenses in descending order
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
	Returns: None; allTransactions is sorted in descending order
	'''

    allTransactions.sort(reverse=True)


def test_sort_descending():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 100, 4, 20)
    add_transaction(allTransactions, 50, 3, 20)
    add_transaction(allTransactions, 75, 2, 1)

    sort_descending(allTransactions)

    assert allTransactions == [(100, 4, 20), (75, 2, 1), (50, 3, 20), (20, 1, 25), (20, 1, 25)]


def max_expense(allTransactions):
    '''
	Obtains the maximum expense from the list of expenses.
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
	Returns: a tuple representing a transaction of maximal amount
			 Raises ValueError if the list is empty
	'''

    if len(allTransactions) == 0:
        raise ValueError()

    return max(allTransactions)


def test_max_expense():
    allTransactions = []

    try:
        assert max_expense(allTransactions) == None
        assert False
    except ValueError:
        assert True

    add_transaction(allTransactions, 20, 1, 25)
    assert max_expense(allTransactions) == (20, 1, 25)

    add_transaction(allTransactions, 20, 1, 25)
    assert max_expense(allTransactions) == (20, 1, 25)

    add_transaction(allTransactions, 100, 4, 20)
    assert max_expense(allTransactions) == (100, 4, 20)

    add_transaction(allTransactions, 50, 3, 20)
    assert max_expense(allTransactions) == (100, 4, 20)

    add_transaction(allTransactions, 75, 2, 1)
    assert max_expense(allTransactions) == (100, 4, 20)


def replace_expense(allTransactions, index, amount):
    '''
	Replaces an expense from a certain position with another amount.
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
		  index - positive integer representing the position of the expense to be replaced
		  expense - positive integer representing the value of the new amount
	Returns: None; 
			 The element on the position index is replaced with a new tuple corresponding to the replaced expense
			 Raises ValueError if index is out of the range [0, len(allTransactions))
	'''

    if index not in range(0, len(allTransactions)):
        raise ValueError

    else:
        type = allTransactions[index][1]
        apartment = allTransactions[index][2]

        allTransactions.pop(index)
        allTransactions.insert(index, (amount, type, apartment))


def test_replace_expense():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 20, 1, 25)
    add_transaction(allTransactions, 100, 4, 20)
    add_transaction(allTransactions, 50, 3, 20)
    add_transaction(allTransactions, 75, 2, 1)

    try:
        replace_expense(allTransactions, 5, 15)
        assert False
    except ValueError:
        assert True

    replace_expense(allTransactions, 0, 15)
    assert allTransactions[0] == (15, 1, 25)

    replace_expense(allTransactions, 0, 15)
    assert allTransactions[0] == (15, 1, 25)

    replace_expense(allTransactions, 4, 105)
    assert allTransactions[4] == (105, 2, 1)

    replace_expense(allTransactions, 4, 1605)
    assert allTransactions[4] == (1605, 2, 1)


def overall_expenses(allTransactions):
    '''
	Groups the expenses of the same apartment and type into one expense.
	Gets: allTransactions - list containing tuples of form (expense, type, apartment)
	Returns: expensesSublist - list which contains the required expenses
	'''

    expensesSublist = []

    allApartments = get_apartments(allTransactions)

    for apartment in allApartments:
        for type in range(1,6):
            expense = sum_expenses_of_type(expenses_of_apartment(allTransactions, apartment), type)
            if valid_transaction(expense, type, apartment):
                add_transaction(expensesSublist, expense, type, apartment)

    return expensesSublist


def test_overall_expenses():
    allTransactions = []

    add_transaction(allTransactions, 20, 1, 25)
    assert sorted(overall_expenses(allTransactions)) == sorted([(20, 1, 25)])

    add_transaction(allTransactions, 20, 1, 25)
    assert sorted(overall_expenses(allTransactions)) == sorted([(40, 1, 25)])

    add_transaction(allTransactions, 100, 4, 20)
    assert sorted(overall_expenses(allTransactions)) == sorted([(40, 1, 25), (100, 4, 20)])

    add_transaction(allTransactions, 50, 3, 20)
    add_transaction(allTransactions, 75, 2, 1)
    assert sorted(overall_expenses(allTransactions)) == sorted([(40, 1, 25), (100, 4, 20), (50, 3, 20), (75, 2, 1)])


if __name__ == '__main__':
    test_valid_transaction()
    test_add_transaction()
    test_expenses_of_type()
    test_expenses_of_apartment()
    test_expenses_of_amount()
    test_remove_expenses()
    test_sum_expenses_of_type()
    test_sort_ascending()
    test_sort_descending()
    test_max_expense()
    test_replace_expense()
    test_overall_expenses()
