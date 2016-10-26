from os import system

from input import *
from output import *
from expenses import *
from helpers import *


def modify(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to modify expenses from the list.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    while True:
        print_modify_submenu()
        suboption = read_natural_number("Write a suboption: ")

        if suboption == 1:
            modify_remove(allTransactions, backupAllTransactions)
        elif suboption == 2:
            modify_remove_from(allTransactions, backupAllTransactions)
        elif suboption == 3:
            modify_remove_type(allTransactions, backupAllTransactions)
        elif suboption == 4:
            modify_replace(allTransactions, backupAllTransactions)
        elif suboption == 0:
            break
        else:
            print("# This option doesn't exist.")

        print()

    system("clear")


def modify_remove(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to remove all the expenses from a certain apartment.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    apartment = read_apartment("Write apartment: ")

    system("clear")

    expensesSublist = expenses_of_apartment(allTransactions, apartment)
    totalRemoved = 0

    if len(expensesSublist) == 0:
        print("# Apartment {0} has no expenses of any type.".format(apartment))

    else:
        remove_expenses(allTransactions, expensesSublist)

        for transaction in expensesSublist:
            print_transaction(transaction)

        totalRemoved += len(expensesSublist)

        backupAllTransactions.append(allTransactions[:])
        backupAllTransactions[0] += 1

    if totalRemoved == 0:
        print("# No expenses for apartment {0} have been removed.".format(apartment))
    elif totalRemoved == 1:
        print("# One expense for apartment {0} has been removed.".format(apartment))
    else:
        print("# A total of {0} expenses for apartment {1} have been removed.".format(totalRemoved, apartment))


def modify_remove_from(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to remove all the expenses from a certain range of apartments.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    minApartment = read_apartment("Write first apartment: ")
    maxApartment = read_apartment("Write last apartment: ")

    system("clear")

    if minApartment > maxApartment:
        print("# Range is invalid, first apartment must be below last apartment.")

    else:
        totalRemoved = 0

        for apartment in range(minApartment, maxApartment+1):
            expensesSublist = expenses_of_apartment(allTransactions, apartment)

            if len(expensesSublist) != 0:
                remove_expenses(allTransactions, expensesSublist)

                for transaction in expensesSublist:
                    print_transaction(transaction)

            totalRemoved += len(expensesSublist)

        backupAllTransactions.append(allTransactions[:])
        backupAllTransactions[0] += 1

        if totalRemoved == 0:
            print("# No expenses for apartments between {0} and {1} have been removed.".format(minApartment, maxApartment))

            backupAllTransactions.pop()
            backupAllTransactions[0] -= 1
        elif totalRemoved == 1:
            print("# One expense for apartments between {0} and {1} has been removed.".format(minApartment, maxApartment))
        else:
            print("# A total of {0} expenses for apartments between {1} and {2} have been removed.".format(totalRemoved, minApartment, maxApartment))


def modify_remove_type(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to remove all the expenses of a certain type from all apartments.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    type = read_type("Write type's number (1 for water, 2 for heating, 3 for illuminating, 4 for gas, 5 for others): ")

    system("clear")

    expensesSublist = expenses_of_type(allTransactions, type)
    totalRemoved = 0

    if len(expensesSublist) == 0:
        print("# There are no expenses for {0} in any apartment.".format(type_to_str(type)))

    else:
        remove_expenses(allTransactions, expensesSublist)

        for transaction in expensesSublist:
            print_transaction(transaction)

        totalRemoved += len(expensesSublist)

        backupAllTransactions.append(allTransactions[:])
        backupAllTransactions[0] += 1

    if totalRemoved == 0:
        print("# No expenses for {0} have been removed.".format(type_to_str(type)))
    elif totalRemoved == 1:
        print("# One expense for {0} has been removed.".format(type_to_str(type)))
    else:
        print("# A total of {0} expenses for {1} have been removed.".format(totalRemoved, type_to_str(type)))


def modify_replace(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to replace the amount of an expense.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    apartment = read_apartment("Write apartment: ")
    type = read_type("Write type's number (1 for water, 2 for heating, 3 for illuminating, 4 for gas, 5 for others): ")
    expense = read_natural_number("Write new expense: ")

    system("clear")

    expensesSublist = expenses_of_apartment(allTransactions, apartment)
    expensesSublist = expenses_of_type(expensesSublist, type)

    if len(expensesSublist) == 0:
        print("# Apartment {0} has no expenses for {1} to replace.".format(apartment, type_to_str(type)))

    elif len(expensesSublist) == 1:
        former_expense = expensesSublist[0][0]
        index = allTransactions.index(expensesSublist[0])

        replace_expense(allTransactions, index, expense)

        print("# Expense {0} for {1} has been replaced to {2} at apartment {3}.".format(former_expense, type_to_str(type), expense, apartment))

        backupAllTransactions.append(allTransactions[:])
        backupAllTransactions[0] += 1

    else:
        print("# We found multiple expenses for {0} at apartment {1}. Which one do you want to replace?".format(type_to_str(type), apartment))

        index = 0

        for transaction in expensesSublist:
            index += 1
            print_transaction_with_index(transaction, index)

        index = read_natural_number("Write index of the expense: ")

        if index not in range(1, len(expensesSublist)+1):
            print("# Invalid index.")
        else:
            former_expense = expensesSublist[index-1][0]
            index = allTransactions.index(expensesSublist[index-1])

            replace_expense(allTransactions, index, expense)

            print("# Expense {0} for {1} has been replaced to {2} at apartment {3}.".format(former_expense, type_to_str(type), expense, apartment))

        backupAllTransactions.append(allTransactions[:])
        backupAllTransactions[0] += 1