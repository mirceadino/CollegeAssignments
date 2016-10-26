from os import system

from input import *
from output import *
from expenses import *
from helpers import *


def filter(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to filter expenses from the list.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    while True:
        print_filter_submenu()
        suboption = read_natural_number("Write a suboption: ")

        if suboption == 1:
            filter_type(allTransactions, backupAllTransactions)
        elif suboption == 2:
            filter_overall_greater_than(allTransactions, backupAllTransactions)
        elif suboption == 0:
            break
        else:
            print("# This option doesn't exist.")

        print()

    system("clear")


def filter_type(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to write the total amount of the expenses of a specific type.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    type = read_type("Write type's number (1 for water, 2 for heating, 3 for illuminating, 4 for gas, 5 for others): ")
        
    system("clear")

    allTransactions[:] = expenses_of_type(allTransactions, type)

    print("# {0} expenses for {1} have been retained.".format(len(allTransactions), type_to_str(type)))

    backupAllTransactions.append(allTransactions[:])
    backupAllTransactions[0] += 1


def filter_overall_greater_than(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to write the maximum expense of each type for a certain apartment.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    value = read_natural_number("Write value: ")
        
    system("clear")

    overallExpenses = overall_expenses(allTransactions)
    allTransactions[:] = [x for x in overallExpenses if x[0] > value]

    print("# {0} overall expenses greater than {1} have been retained.".format(len(allTransactions), value))

    backupAllTransactions.append(allTransactions[:])
    backupAllTransactions[0] += 1