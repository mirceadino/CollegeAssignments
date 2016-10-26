from domain.Activity import Activity
from repository.ActivityRepository import ActivityRepository


class ActivityFileRepository(ActivityRepository):
    """
    Class used for handling in-file storage for a ActivityRepository.
    """

    def __init__(self, personRepo, filename):
        '''
        Constructor for the class ActivityFileRepository.
        '''

        ActivityRepository.__init__(self)
        self.__filename = filename
        self.__personRepo = personRepo
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
            date = attributes[1].strip()
            time = attributes[2].strip()
            description = attributes[3].strip()

            person = self.__personRepo.find_by_id(id)

            super().add(Activity(person, date, time, description))

        f.close()


    def store(self):
        '''
        Stores the content of the ActivityRepository in a file.
        '''

        self.__store_to_file()


    def __store_to_file(self):
        '''
        Stores content to a file.
        '''

        f = open(self.__filename, "w")

        sep = " " + self.__separator + " "

        for p in self:
            repr = str(p.person.id) + sep
            repr += p.date + sep
            repr += p.time + sep
            repr += p.description + '\n'
            f.write(repr)

        f.close()