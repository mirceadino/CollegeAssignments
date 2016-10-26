from input import *
from output import *

from add import *
from modify import *
from write import *
from obtain import *
from filter import *
from undo import *
from redo import *


def main():
    '''
    Implements user interface.
    '''

    # allTransactions is a list in which tuples of form (expense, type, apartment) are stored
    allTransactions = []

    # backupAllTransactions is a list containing different versions of allTransactions
    # backupAllTransactions[0] is the index of the current version
    backupAllTransactions = [1, []]

    system("clear")

    #init(allTransactions)

    while True:
        print_main_menu()
        option = read_natural_number("Write an option: ")

        if option == 1:
            add(allTransactions, backupAllTransactions)
        elif option == 2:
            modify(allTransactions, backupAllTransactions)
        elif option == 3:
            write(allTransactions)
        elif option == 4:
            obtain(allTransactions)
        elif option == 5:
            filter(allTransactions, backupAllTransactions)
        elif option == 6:
            undo(allTransactions, backupAllTransactions)
        elif option == 7:
            redo(allTransactions, backupAllTransactions)
        elif option == 23:
            system("clear")
            print(allTransactions) # secret option which prints the list of all expenses
        elif option == 0:
            break
        else:
            print("# This option doesn't exist.")

    print()
    print("# Have a nice day!")


def init(allTransactions):
    '''
    Creates an initial set of apartments and list of expenses
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    Returns: None
             allTransactions will contain more elements corresponding to the added expenses
    '''

    add_transaction(allTransactions, 20, 1, 1)
    add_transaction(allTransactions, 50, 1, 1)
    add_transaction(allTransactions, 10, 2, 1)
    add_transaction(allTransactions, 15, 3, 1)
    add_transaction(allTransactions, 25, 1, 2)
    add_transaction(allTransactions, 50, 1, 2)
    add_transaction(allTransactions, 60, 3, 2)
    add_transaction(allTransactions, 15, 3, 3)
    add_transaction(allTransactions, 25, 5, 4)