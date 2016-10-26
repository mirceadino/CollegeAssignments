from os import system

from input import *
from output import *
from expenses import *
from helpers import *


def add(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to add a transaction into the list.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    print_add_submenu()

    expense = read_natural_number("Write expense: ")
    type = read_type("Write type's number (1 for water, 2 for heating, 3 for illuminating, 4 for gas, 5 for others): ")
    apartment = read_apartment("Write apartment: ")

    system("clear")

    if valid_transaction(expense, type, apartment):
        add_transaction(allTransactions, expense, type, apartment)
        print("# Transaction {0} for {1} has been successfully added at apartment {2}.".format(expense, type_to_str(type), apartment))

        backupAllTransactions.append(allTransactions[:])
        backupAllTransactions[0] += 1

    else:
        print("# Transaction is not valid.")
        print("# Expense and apartment must be positive, type must be one of the types below.")

    print()