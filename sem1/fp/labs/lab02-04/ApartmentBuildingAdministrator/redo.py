from os import system


def redo(allTransactions, backupAllTransactions):
    '''
    Interacts with the user in order to redo the last undone modification.
    Gets: allTransactions - list containing tuples of form (expense, type, apartment)
    '''

    system("clear")

    if backupAllTransactions[0] + 1 == len(backupAllTransactions):
        print("# There's no action to redo.")

    else:
        backupAllTransactions[0] += 1
        allTransactions[:] = backupAllTransactions[backupAllTransactions[0]]
        backupAllTransactions[:] = backupAllTransactions[:backupAllTransactions[0]+1]

        print("# Last modification has been redone.")