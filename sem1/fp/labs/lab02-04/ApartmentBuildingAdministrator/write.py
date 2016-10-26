from os import system

from input import *
from output import *
from expenses import *
from helpers import *


def write(allTransactions):
    '''
    Interacts with the user in order to write expenses with certain properties.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    while True:
        print_write_submenu()
        suboption = read_natural_number("Write a suboption: ")

        if suboption == 1:
            write_greater(allTransactions)
        elif suboption == 2:
            write_less(allTransactions)
        elif suboption == 3:
            write_all(allTransactions)
        elif suboption == 4:
            write_balance(allTransactions)
        elif suboption == 0:
            break
        else:
            print("# This option doesn't exist.")

        print()

    system("clear")


def write_greater(allTransactions):
    '''
    Interacts with the user in order to write the apartments whose balances are greater than a certain value.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    value = read_natural_number("Write value: ")
    
    system("clear")
    
    apartmentSubset = apartments_greater_than(allTransactions, value)

    if len(apartmentSubset) == 0:
        print("# No apartments have been found.")

    else:
        print("# We found: ")
        for apartment in apartmentSubset:
            print_apartment(allTransactions, apartment)


def write_less(allTransactions):
    '''
    Interacts with the user in order to write the apartments whose balances are less than a certain value and numbers
    are before a certain apartment.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    value = read_natural_number("Write value: ")
    maxApartment = read_apartment("Write apartment: ")

    system("clear")

    apartmentSubset = apartments_less_than(allTransactions, value)
    apartmentSubset = apartments_before(apartmentSubset, maxApartment)
    
    if len(apartmentSubset) == 0:
        print("# No apartments have been found.")

    else:
        print("# We found: ")
        for apartment in apartmentSubset:
            print_apartment(allTransactions, apartment)


def write_all(allTransactions):
    '''
    Interacts with the user in order to write the expenses with a certain type.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    type = read_type("Write type's number (1 for water, 2 for heating, 3 for illuminating, 4 for gas, 5 for others): ")

    system("clear")

    expensesSublist = expenses_of_type(allTransactions, type)

    if len(expensesSublist) == 0:
        print("# No expenses have been found.")

    else:
        print("# We found: ")
        for transaction in expensesSublist:
            print_transaction(transaction)


def write_balance(allTransactions):
    '''
    Interacts with the user in order to write the balance of a certain apartment.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    apartment = read_apartment("Write apartment: ")
        
    system("clear")

    if compute_balance(allTransactions, apartment) != 0:
        print_apartment(allTransactions, apartment)
    else:
        print("# No expenses for apartment {0}.".format(apartment))