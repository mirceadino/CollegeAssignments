from os import system

from input import *
from output import *
from expenses import *
from helpers import *


def obtain(allTransactions):
    '''
    Interacts with the user in order to obtain expenses from the list with certain characteristics.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    while True:
        print_obtain_submenu()
        suboption = read_natural_number("Write a suboption: ")

        if suboption == 1:
            obtain_sum(allTransactions)
        elif suboption == 2:
            obtain_max(allTransactions)
        elif suboption == 3:
            obtain_asc(allTransactions)
        elif suboption == 4:
            obtain_desc(allTransactions)
        elif suboption == 0:
            break
        else:
            print("# This option doesn't exist.")

        print()

    system("clear")


def obtain_sum(allTransactions):
    '''
    Interacts with the user in order to write the total amount of the expenses of a specific type.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    type = read_type("Write type's number (1 for water, 2 for heating, 3 for illuminating, 4 for gas, 5 for others): ")
        
    system("clear")

    print("# Total amount for {0} is {1}.".format(type_to_str(type), sum_expenses_of_type(allTransactions, type)))


def obtain_max(allTransactions):
    '''
    Interacts with the user in order to write the maximum expense of each type for a certain apartment.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    apartment = read_apartment("Write apartment: ")
        
    system("clear")

    expensesOfApartment = expenses_of_apartment(allTransactions, apartment) 

    print("# The maximum expenses per type for apartment {0} are:".format(apartment))

    for type in [1, 2, 3, 4, 5]:
        expensesSublist = expenses_of_type(expensesOfApartment, type)

        try:
            maximum = max_expense(expensesSublist)
            print_transaction(maximum)
        except ValueError:
            print("# There are no expenses for {0} at apartment {1}.".format(type_to_str(type), apartment))


def obtain_asc(allTransactions):
    '''
    Interacts with the user in order to sort the total expenses for a certain apartment in an ascending order.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    apartment = read_apartment("Write apartment: ")
        
    system("clear")

    expensesSublist = expenses_of_apartment(allTransactions, apartment) 
    sort_ascending(expensesSublist)

    if len(expensesSublist) == 0:
        print("# There are no expenses for apartment {0} to sort.".format(apartment))

    else:
        print("# The expenses for apartment {0} in ascending order are:".format(apartment))

        for transaction in expensesSublist:
            print_transaction(transaction)


def obtain_desc(allTransactions):
    '''
    Interacts with the user in order to sort the total expenses for a certain type in a descending order.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    type = read_type("Write type's number (1 for water, 2 for heating, 3 for illuminating, 4 for gas, 5 for others): ")
        
    system("clear")

    expensesSublist = expenses_of_type(allTransactions, type) 
    sort_descending(expensesSublist)

    if len(expensesSublist) == 0:
        print("# There are no expenses for {0} to sort.".format(type_to_str(type)))

    else:
        print("# The expenses for {0} in descending order are:".format(type_to_str(type)))

        for transaction in expensesSublist:
            print_transaction(transaction)