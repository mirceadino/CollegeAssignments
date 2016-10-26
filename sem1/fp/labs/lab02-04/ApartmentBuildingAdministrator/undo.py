from os import system


def undo(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to undo the previous modification.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    if backupAllTransactions[0] == 1:
        print("# There's no action to undo.")

    else:
        backupAllTransactions[0] -= 1
        allTransactions[:] = backupAllTransactions[backupAllTransactions[0]]

        print("# Last modification has been undone.")