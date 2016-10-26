class PersonValidator:
    """
    Class used for validating various parameters and data.
    """

    @staticmethod
    def valid_id(id):
        '''
        Checks if the parameter represents a valid id, i.e. it's a positive integer.
        :param id: parameter to check
        :return: True - id is a positive integer; False - otherwise
        '''

        return (type(id) is int) and (id > 0)


def __test_valid_id():
    assert PersonValidator.valid_id(34) == True
    assert PersonValidator.valid_id(3) == True
    assert PersonValidator.valid_id(1) == True
    assert PersonValidator.valid_id(0) == False
    assert PersonValidator.valid_id(-5) == False
    assert PersonValidator.valid_id(0.5) == False
    assert PersonValidator.valid_id(1.0) == False
    assert PersonValidator.valid_id("banana") == False
    assert PersonValidator.valid_id([]) == False


if __name__ == "__main__":
    __test_valid_id()