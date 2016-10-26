def read_natural_number(message):
    '''
    Reads a natural number.
    Gets: message - string representing a message to show the user when reading the input
    Returns: value - integer representing the natural number that was read
    '''

    value = -1
 
    while not value >= 0:
        user_input = input(message)
        
        try:
            value = int(user_input)
            if (value < 0) or (str(value) != user_input):
                print("That's not a natural number.")
                value = -1

        except ValueError:
            print("That's not a natural number.")

    return value


def read_apartment(message):
    '''
    Read the number of an apartment.
    Gets: message - string representing a message to show the user when reading the input
    Returns: value - positive integer representing the number of an apartment that was read
    '''

    apartment = read_natural_number(message)

    while apartment < 1:
        print("# Apartment must be positive.")
        apartment = read_natural_number(message)

    return apartment


def read_type(message):
    '''
    Read the type of an expense.
    Gets: message - string representing a message to show the user when reading the input
    Returns: type - positive integer between 1 and 5 representing the type of an expense
    '''

    type = read_natural_number(message)
    
    while type not in [1, 2, 3, 4, 5]:
        print("# Type is not valid.")
        type = read_natural_number(message)

    return type