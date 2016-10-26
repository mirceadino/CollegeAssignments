from apartments import *
from helpers import *


def print_main_menu():
    '''
    Prints the main menu
    '''

    print("# Main Menu # Pick one of the options below. ")
    print("# 1 - Add a new transaction into the list")
    print("# 2 - Modify expenses from the list")
    print("# 3 - Write the expenses having different properties")
    print("# 4 - Obtain different characteristics of expenses")
    print("# 5 - Filter expenses")
    print("# 6 - Undo last action that modified the list of expenses")
    print("# 7 - Redo last action that modified the list of expenses")
    print("# 0 - Exit")


def print_add_submenu():
    '''
    Prints the submenu for the "add" feature
    '''

    print("# You are going to add a new transaction into the list.")


def print_modify_submenu():
    '''
    Prints the submenu for the "modify" feature
    '''

    print("# You are going to modify expenses from the list.")
    print("# 1 - Remove all the expenses from a certain apartment")
    print("# 2 - Remove all the expenses from a certain range of apartments")
    print("# 3 - Remove all the expenses of a certain type from all the apartments")
    print("# 4 - Replace the value of an expense from the list")
    print("# 0 - Return to main menu")


def print_write_submenu():
    '''
    Prints the submenu for the "write" feature
    '''

    print("# You are going to be written the expenses having different properties.")
    print("# 1 - Write all the apartments with an overall expense greater than a certain value")
    print("# 2 - Write all the apartments from a certain subsequence with an overall expense less than a certain value")
    print("# 3 - Write all the expenses having a certain type")
    print("# 4 - Compute the balance for a certain apartment")
    print("# 0 - Return to main menu")


def print_obtain_submenu():
    '''
    Prints the submenu for the "obtain" feature
    '''

    print("# You are going to obtain different characteristics of expenses.")
    print("# 1 - Write the total amount for the expenses having a certain type")
    print("# 2 - Write the maximum expense for each type at a certain apartment")
    print("# 3 - Sorts the expenses for a certain apartment in ascending order")
    print("# 4 - Sorts the expenses of a certain type in descending order")
    print("# 0 - Return to main menu")


def print_filter_submenu():
    '''
    Prints the submenu for the "filter" feature
    '''

    print("# You are going to filter the expenses.")
    print("# 1 - Retain only the expenses having a certain type")
    print("# 2 - Retain only the overall expenses greater than a certain value")
    print("# 0 - Return to main menu")


def print_apartment(allTransactions, apartment):
    '''
    Prints the number and the balance of a certain apartment.
    Gets: allApartments - set which represents the current set of apartment numbers
          allTransactions - list containing tuples of form (expense, type, apartment)
          apartment - positive integer representing the number of an apartment for which we want to print its information
    '''

    balance = compute_balance(allTransactions, apartment)
    print("# Apartment {0} with balance {1}.".format(apartment, balance))


def print_transaction(transaction):
    '''
    Prints the details of a transaction.
    Gets: transaction - tuple of form (expense, type, apartment) which we want to print.
    '''

    expense = transaction[0]
    type = type_to_str(transaction[1])
    apartment = transaction[2]
    print("# Expense {0} for {1} at apartment {2}.".format(expense, type, apartment))


def print_transaction_with_index(transaction, index):
    '''
    Prints the details of a transaction.
    Gets: transaction - tuple of form (expense, type, apartment) which we want to print.
    '''

    expense = transaction[0]
    type = type_to_str(transaction[1])
    apartment = transaction[2]
    print("# {3}. Expense {0} for {1} at apartment {2}.".format(expense, type, apartment, index))