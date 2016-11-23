from domain.NABException import NABException
from domain.Person import Person
from repository.PersonRepository import PersonRepository
from repository.PersonFileRepository import PersonFileRepository
from controller.ChangeHistory import *
from copy import deepcopy


class PeopleController:
    """
    Class used for handling the operations regarding people.
    """

    def __init__(self, personRepo):
        '''
        Constructor for the class PeopleController.
        :param personRepo: PersonRepository - repository containing people
        :exception NABException: if one of the parameters is not valid
        '''

        if not isinstance(personRepo, PersonRepository):
            raise NABException("The given repository of people is not valid.")

        self.__personRepo = personRepo
        self.__operations = []
        self.__index = -1


    def number_of_people(self):
        '''
        Returns the numbers of people in the list.
        :return: natural number representing the number of people in the list
        '''

        return len(self.__personRepo)


    def add_person(self, person):
        '''
        Adds a person to the NAB.
        :param person: Person - person to be added to the NAB
        :return: person is added to the NAB
        :exception NABException: if one of the parameters is not valid or a person with that id already exists
        '''

        self.__personRepo.add(person)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append(AddOperation(deepcopy(person)))
        self.__index += 1


    def remove_person_by_id(self, id):
        '''
        Removes the person with the indicated ID from the list and their afferent activities.
        :param id: positive integer - ID of a person
        :return: the person with the indicated ID is removed as well as their afferent activities
        :exception NABException: if one of the parameters is not valid or no person with the given ID was found
        '''

        person = self.__personRepo.remove_by_id(id)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append(RemoveOperation(deepcopy(person)))
        self.__index += 1


    def update_person_name(self, person, name):
        '''
        Updates name of a person.
        :param person: Person to be updated
        :param name: new name for that person
        :return: person is updated
        :exception NABException: if one of the parameters is not valid or no person was found
        '''

        if person not in self.__personRepo:
            raise NABException("There's no such person in the list.")

        oldPerson = deepcopy(person)
        person.name = name
        newPerson = deepcopy(person)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append(UpdateOperation(oldPerson, newPerson))
        self.__index += 1


    def update_person_phone(self, person, phone):
        '''
        Updates phone of a person.
        :param person: Person to be updated
        :param phone: new phone for that person
        :return: person is updated
        :exception NABException: if one of the parameters is not valid or no person was found
        '''

        if person not in self.__personRepo:
            raise NABException("There's no such person in the list.")

        oldPerson = deepcopy(person)
        person.phone = phone
        newPerson = deepcopy(person)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append(UpdateOperation(oldPerson, newPerson))
        self.__index += 1


    def update_person_address(self, person, address):
        '''
        Updates address of a person.
        :param person: Person to be updated
        :param address: new address for that person
        :return: person is updated
        :exception NABException: if one of the parameters is not valid or no person was found
        '''

        if person not in self.__personRepo:
            raise NABException("There's no such person in the list.")

        oldPerson = deepcopy(person)
        person.address = address
        newPerson = deepcopy(person)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append(UpdateOperation(oldPerson, newPerson))
        self.__index += 1


    def undo(self):
        '''
        Undoes the last operation that modified the repositories.
        :return: repositories are modified accordingly
        :exception NABException: if no undo is possible
        '''

        if self.__index == -1:
            raise NABException("# There's nothing to undo.\n")

        lastOperation = self.__operations[self.__index]

        if type(lastOperation) == AddOperation:
            self.__personRepo.remove_by_id(lastOperation.object().id)
        elif type(lastOperation) == RemoveOperation:
            self.__personRepo.add(lastOperation.object())
        elif type(lastOperation) == UpdateOperation:
            person = self.__personRepo.find_by_id(lastOperation.new().id)
            person.name = lastOperation.old().name
            person.address = lastOperation.old().address
            person.phone = lastOperation.old().phone
        else:
            raise NABException("# Not an undoable operation.\n")

        self.__index -= 1


    def redo(self):
        '''
        Redoes the last undo.
        :return: repositories are modified accordingly
        :exception NABException: if no redo is possible
        '''

        if self.__index+1 == len(self.__operations):
            raise NABException("# There's nothing to redo.\n")

        self.__index += 1
        lastOperation = self.__operations[self.__index]

        if type(lastOperation) == AddOperation:
            self.__personRepo.add(lastOperation.object())
        elif type(lastOperation) == RemoveOperation:
            self.__personRepo.remove_by_id(lastOperation.object().id)
        elif type(lastOperation) == UpdateOperation:
            person = self.__personRepo.find_by_id(lastOperation.old().id)
            person.name = lastOperation.new().name
            person.address = lastOperation.new().address
            person.phone = lastOperation.new().phone
        else:
            raise NABException("# Not a redoable operation.\n")


    def find_person_by_id(self, id):
        '''
        Returns the person from the current list with the indicated ID.
        :param id: positive integer - ID of a person
        :return: Person - the person with the ID id
        :exception NABException: if one of the parameters is not valid or no person with the given ID was found
        '''

        return self.__personRepo.find_by_id(id)


    def find_people_by_name(self, name):
        '''
        Returns a PersonRepository which contains only people with the indicated substring as part of their name.
        :param name: string - name to find people
        :return: PersonRepository - people with the indicated substring as part of their name
        :exception NABException: if one of the parameters is not valid
        '''

        return self.__personRepo.find_by_name(name)


    def find_people_by_address(self, address):
        '''
        Returns a PersonRepository which contains only people with the indicated substring as part of their address.
        :param address: string - address to find people
        :return: PersonRepository - people with the indicated substring as part of their address
        :exception NABException: if one of the parameters is not valid
        '''

        return self.__personRepo.find_by_address(address)


    def find_people_by_phone(self, phone):
        '''
        Returns a PersonRepository which contains only people with the indicated substring as part of their phone number.
        :param phone: string - phone number to find people
        :return: PersonRepository - people with the indicated substring as part of their phone number
        :exception NABException: if one of the parameters is not valid
        '''

        return self.__personRepo.find_by_phone(phone)


    def people_to_string(self):
        '''
        Returns a string representing the list of people in their short representation.
        :return: string - list of people or "None" if the list is empty
        '''

        return str(self.__personRepo)