from domain.ActivityValidator import ActivityValidator
from domain.NABException import NABException
from domain.Person import Person


class Activity:
    """
    Class used for handling activity and information about an activity.
    """

    def __init__(self, person, date, time, description):
        '''
        Constructor for the class Activity.
        :param person: Person - person who does the activity
        :param date: string - day, month and year of the activity in the format "yyyy.mm.dd"
        :param time: string - hour and minute of the activity in the format "hh:mm"
        :param description: string - description of the activity
        :exception NABException: if one of the parameters is not valid
        '''

        # Checks if parameters are valid.

        if type(person) is not Person:
            raise NABException("The given person is not valid.")

        if not ActivityValidator.valid_date(date):
            raise NABException("The given date is not in a valid format.")

        if not ActivityValidator.valid_time(time):
            raise NABException("The given time is not in a valid format.")

        if type(description) is not str:
            raise NABException("The given description is not a string.")

        # Constructs object.

        self.__person = person
        self.__date = date
        self.__time = time
        self.__description = description


    @property
    def person(self):
        '''
        Returns the person performing the current activity.
        :return: Person - person performing the current activity
        '''

        return self.__person


    @person.setter
    def person(self, newPerson):
        '''
        Sets a new person to perform the current activity.
        :param newPerson: Person - new person performing the current activity
        :return: the person performing the current activity is set to newPerson
        :exception NABException: if one of the parameters is not valid
        '''

        if type(newPerson) is not Person:
            raise NABException("The given person is not valid.")

        self.__person = newPerson


    @property
    def date(self):
        '''
        Returns the date of the current activity.
        :return: string - date of the current activity
        '''

        return self.__date


    @date.setter
    def date(self, newDate):
        '''
        Sets a new date of the current activity.
        :param newDate: string - new date of the current activity of format "dd:mm:yyyy"
        :return: the date of the current activity is set to newDate
        :exception NABException: if one of the parameters is not valid
        '''

        if not ActivityValidator.valid_date(newDate):
            raise NABException("The given date is not in a valid format.")

        self.__date = newDate


    @property
    def time(self):
        '''
        Returns the time of the current activity.
        :return: string - time of the current activity
        '''

        return self.__time


    @time.setter
    def time(self, newTime):
        '''
        Sets a new time of the current activity.
        :param newTime: string - new time of the current activity of format "hh:mm"
        :return: the time of the current activity is set to newTime
        :exception NABException: if one of the parameters is not valid
        '''

        if not ActivityValidator.valid_time(newTime):
            raise NABException("The given time is not in a valid format.")

        self.__time = newTime


    @property
    def description(self):
        '''
        Returns the description of the current activity.
        :return: string - description of the current activity
        '''

        return self.__description


    @description.setter
    def description(self, newDescription):
        '''
        Sets a new description of the current activity.
        :param newDescription: string - new description of the current activity
        :return: the description of the current activity is set to newDescription
        :exception NABException: if one of the parameters is not valid
        '''

        if type(newDescription) is not str:
            raise NABException("The given description is not a string.")

        self.__description = newDescription

    def __eq__(self, other):
        '''
        Checks if the current activity is the same as an other activity, i.e. they have identical attributes.
        :param other: Activity - person to check equality with
        :return: True - people are the same; False - otherwise
        '''

        if type(other) is not Activity:
            return False

        return (self.person == other.person) and (self.date == other.date) and (self.time == other.time) and (self.description == other.description)


    def __str__(self):
        '''
        Provides a short string representation of the information about an activity in format "date time: description by person.name".
        :return: string - short representation of the information about an activity
        '''

        ret = ""
        ret += self.__date + " "
        ret += self.__time + ": "
        ret += self.__description + " by "
        ret += self.__person.name + "\n"

        return ret


    def to_string(self):
        '''
        Provides a long string representation of the information about an activity in a lengthier format.
        :return: string - long representation of the information about an activity
        '''

        ret = ""
        ret += "What: {0}\n".format(self.__description)
        ret += "When: {0} {1}\n".format(self.__date, self.__time)
        ret += "Who: {0}\n".format(self.__person.name)

        return ret


def __test_constructor():
    p = Person(1, "Jimmy", "911", "1 Main Street")

    try:
        x = Activity(p, "2015.01.24", "23:59", "Swimming")
        assert True
    except NABException:
        assert False

    try:
        x = Activity([], "2015.01.24", "23:59", "Swimming")
        assert False
    except NABException:
        assert True

    try:
        x = Activity(p, "424.01.2015", "23:59", "Swimming")
        assert False
    except NABException:
        assert True

    try:
        x = Activity(p, "424.01.2015", "23:59", p)
        assert False
    except NABException:
        assert True


def __test_getters():
    p = Person(1, "Jimmy", "911", "1 Main Street")
    x = Activity(p, "2015.01.24", "23:59", "Swimming")

    assert x.person == p
    assert x.date == "2015.01.24"
    assert x.time == "23:59"
    assert x.description == "Swimming"


def __test_setters():
    p = Person(1, "Jimmy", "911", "1 Main Street")
    r = Person(4, "Mike", "911", "2 Main Street")
    x = Activity(p, "2015.01.24", "23:59", "Swimming")

    x.person = r
    x.date = "2015.01.22"
    x.time = "10:30"
    x.description = "Reading a magazine"

    assert x.person == r
    assert x.date == "2015.01.22"
    assert x.time == "10:30"
    assert x.description == "Reading a magazine"

    try:
        x.person = []
        assert False
    except NABException:
        assert True

    try:
        x.date = "23.23.2332"
        assert False
    except NABException:
        assert True

    try:
        x.time = 23.34
        assert False
    except NABException:
        assert True

    try:
        x.description = p
        assert False
    except NABException:
        assert True


if __name__ == "__main__":
    __test_constructor()
    __test_getters()
    __test_setters()
