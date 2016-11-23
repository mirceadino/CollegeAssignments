from domain.NABException import NABException
from domain.PersonValidator import PersonValidator


class Person:
    """
    Class used for handling people and information about a person.
    """

    def __init__(self, id, name, phoneNumber, address):
        '''
        Constructor for the class Person.
        :param id: positive integer - ID of a person
        :param name: string - full name of a person
        :param phoneNumber: string - phone number of a person
        :param address: string - address of a person
        :exception NABException: if one of the parameters is not valid
        '''

        # Checks if parameters are valid.

        if not PersonValidator.valid_id(id):
            raise NABException("The given ID is not a positive integer.")

        if not isinstance(name, str):
            raise NABException("The given name is not a string.")

        if not isinstance(phoneNumber, str):
            raise NABException("The given phone number is not a string.")

        if not isinstance(address, str):
            raise NABException("The given address is not a string.")

        # Constructs object.

        self.__id = id
        self.__name = name
        self.__phoneNumber = phoneNumber
        self.__address = address


    @property
    def id(self):
        '''
        Returns the ID of the current person.
        :return: positive integer - ID of the current person
        '''

        return self.__id


    @property
    def name(self):
        '''
        Returns the name of the current person.
        :return: string - name of the current person
        '''

        return self.__name


    @name.setter
    def name(self, newName):
        '''
        Sets a new value for the name of the current person.
        :param newName: string - new name
        :return: the name of the current person is set to newName
        :exception NABException: if one of the parameters is not valid
        '''

        if type(newName) is not str:
            raise NABException("The given name is not a string.")

        self.__name = newName


    @property
    def phone(self):
        '''
        Returns the phone number of the current person.
        :return: string - phone number of the current person
        '''

        return self.__phoneNumber


    @phone.setter
    def phone(self, newPhoneNumber):
        '''
        Sets a new value for the phone number of the current person.
        :param newPhoneNumber: string - new phone number
        :return: the phone number of the current person is set to newPhoneNumber
        :exception NABException: if one of the parameters is not valid
        '''

        if type(newPhoneNumber) is not str:
            raise NABException("The given phone number is not a string.")

        self.__phoneNumber = newPhoneNumber


    @property
    def address(self):
        '''
        Returns the address of the current person.
        :return: string - address of the current person
        '''

        return self.__address


    @address.setter
    def address(self, newAddress):
        '''
        Sets a new value for the address of the current person.
        :param newAddress: string - new address
        :return: the address of the current person is set to newAddress
        :exception NABException: if one of the parameters is not valid
        '''

        if type(newAddress) is not str:
            raise NABException("The given address is not a string.")

        self.__address = newAddress


    def __eq__(self, other):
        '''
        Checks if the current person is the same as an other person, i.e. they have identical attributes.
        :param other: Person - person to check equality with
        :return: True - people are the same; False - otherwise
        '''

        if type(other) is not Person:
            return False

        return (self.id == other.id) and (self.name == other.name) and (self.phone == other.phone) and (self.address) == (other.address)


    def __str__(self):
        '''
        Provides a short string representation of the information about a person in format "id - name - phone number - address".
        :return: string - short representation of the information about a person
        '''

        ret = ""
        ret += str(self.__id) + " - "
        ret += self.__name + " - "
        ret += self.__phoneNumber + " - "
        ret += self.__address + "\n"

        return ret


    def to_string(self):
        '''
        Provides a long string representation of the information about a person in a lengthier format.
        :return: string - long representation of the information about a person
        '''

        ret = ""
        ret += "ID: {0}\n".format(self.__id)
        ret += "Name: {0}\n".format(self.__name)
        ret += "Phone Number: {0}\n".format(self.__phoneNumber)
        ret += "Address: {0}\n".format(self.__address)

        return ret