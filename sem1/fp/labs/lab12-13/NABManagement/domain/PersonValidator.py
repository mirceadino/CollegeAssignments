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