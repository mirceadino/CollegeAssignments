from domain.NABException import NABException
from domain.Person import Person
from domain.PersonValidator import PersonValidator
from utils.Useful import sort


class PersonRepository:
    """
    Class used for handling a list of people and maintaining the people sorted by ID.
    """

    def __init__(self):
        '''
        Constructor for the class PersonRepository.
        '''

        self.__list = []


    def __len__(self):
        '''
        Returns the length of the current list of people.
        :return: integer - length of the current list of people
        '''

        self.__list[:] = sort(self.__list, key=lambda x: x.id)

        return len(self.__list)


    def __iter__(self):
        '''
        Returns an iterator object for the repository.
        :return: iter(list) - iterator object
        '''

        self.__list[:] = sort(self.__list, key=lambda x: x.id)

        return iter(self.__list)


    def all(self):
        '''
        Returns a list containing all the people.
        :return: list of Person
        '''

        return self.__list


    def add(self, person):
        '''
        Adds a person to the current list of people, if his ID does not already exist.
        :param person: Person - person to be added
        :return: person is added to the current list of people
        :exception NABException: if one of the parameters is not valid or a person with that ID already exists
        '''

        if type(person) is not Person:
            raise NABException("The given person is not valid.")

        if self.find(person.id) != -1:
            raise NABException("There's already a person with that ID.")

        self.__list.append(person)
        self.__list[:] = sort(self.__list, key=lambda x: x.id)


    def find(self, id):
        '''
        Returns the index of the person whose id is equal to the given one.
        :param id: positive integer - ID of a person
        :return: integer - position of the person or -1 if no person with the given ID was found
        :exception NABException: if one of the parameters is not valid
        '''

        if not PersonValidator.valid_id(id):
            raise NABException("The given ID is not a positive integer.")

        for i in range(len(self.__list)):
            if self.__list[i].id == id:
                return i

        return -1


    def find_by_id(self, id):
        '''
        Returns the person from the current list with the indicated ID.
        :param id: positive integer - ID of a person
        :return: Person - the person with the ID id
        :exception NABException: if one of the parameters is not valid or no person with the given ID was found
        '''

        if not PersonValidator.valid_id(id):
            raise NABException("The given ID is not a positive integer.")

        pos = self.find(id)

        if pos != -1:
            return self.__list[pos]
        else:
            raise NABException("No person with the given ID was found.")


    def find_by_name(self, name):
        '''
        Returns a PersonRepository which contains only people with the indicated substring as part of their name.
        :param name: string - name to find people
        :return: PersonRepository - people with the indicated substring as part of their name
        :exception NABException: if one of the parameters is not valid
        '''

        if type(name) is not str:
            raise NABException("The given name is not a string.")

        foundPeople = PersonRepository()

        for person in self.__list:
            if name in person.name:
                foundPeople.add(person)

        return foundPeople


    def find_by_address(self, address):
        '''
        Returns a PersonRepository which contains only people with the indicated substring as part of their address.
        :param address: string - address to find people
        :return: PersonRepository - people with the indicated substring as part of their address
        :exception NABException: if one of the parameters is not valid
        '''

        if type(address) is not str:
            raise NABException("The given address is not a string.")

        foundPeople = PersonRepository()

        for person in self.__list:
            if address in person.address:
                foundPeople.add(person)

        return foundPeople


    def find_by_phone(self, phone):
        '''
        Returns a PersonRepository which contains only people with the indicated substring as part of their phone number.
        :param phone: string - phone number to find people
        :return: PersonRepository - people with the indicated substring as part of their phone number
        :exception NABException: if one of the parameters is not valid
        '''

        if type(phone) is not str:
            raise NABException("The given phone number is not a string.")

        foundPeople = PersonRepository()

        for person in self.__list:
            if phone in person.phone:
                foundPeople.add(person)

        return foundPeople


    def remove(self, pos):
        '''
        Removes the person with the indicated position in the current list.
        :param pos: integer - position of the person in the current list, greater than or equal to 0 and strictly less than the length of the list
        :return: Person - the person at the position pos is popped out of the list
        :exception NABException: if one of the parameters is not valid
        '''

        if (type(pos) is not int) or (pos < 0 or pos >= len(self.__list)):
            raise NABException("The given position is not valid.")

        return self.__list.pop(pos)


    def remove_by_id(self, id):
        '''
        Removes the person with the indicated ID from the list.
        :param id: positive integer - ID of a person
        :return: the person with the indicated ID is removed
        :exception NABException: if one of the parameters is not valid or no person with the given ID was found
        '''

        if not PersonValidator.valid_id(id):
            raise NABException("The given ID is not a positive integer.")

        pos = self.find(id)

        if pos != - 1:
            return self.remove(pos)
        else:
            raise NABException("No person with the given ID was found.")


    def __str__(self):
        '''
        Returns a string representing the list of people in their short representation.
        :return: string - list of people or "None" if the list is empty
        '''

        ret = ""

        for person in self.__list:
            ret += str(person)

        if ret != "":
            return ret
        else:
            return "None\n"