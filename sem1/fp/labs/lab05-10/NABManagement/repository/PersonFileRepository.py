from domain.Person import Person
from repository.PersonRepository import PersonRepository


class PersonFileRepository(PersonRepository):
    """
    Class used for handling in-file storage for a PersonRepository.
    """

    def __init__(self, filename):
        '''
        Constructor for the class PersonFileRepository.
        '''

        PersonRepository.__init__(self)
        self.__filename = filename
        self.__separator = "|"
        self.__load_from_file()


    def __load_from_file(self):
        '''
        Loads content from a file.
        '''

        try:
            f = open(self.__filename, "r")
        except IOError:
            return

        for line in f:
            line = line.strip()
            attributes = line.split(self.__separator)

            if len(attributes) != 4:
                continue

            id = int(attributes[0].strip())
            name = attributes[1].strip()
            phone = attributes[2].strip()
            address = attributes[3].strip()

            PersonRepository.add(self, Person(id, name, phone, address))

        f.close()


    def store(self):
        '''
        Stores the content of the PersonRepository in a file.
        '''

        self.__store_to_file()


    def __store_to_file(self):
        '''
        Stores content to a file.
        '''

        f = open(self.__filename, "w")

        sep = " " + self.__separator + " "

        for p in self:
            repr = str(p.id) + sep
            repr += p.name + sep
            repr += p.phone + sep
            repr += p.address + '\n'
            f.write(repr)

        f.close()