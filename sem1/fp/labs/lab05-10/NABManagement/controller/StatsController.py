from domain.Activity import Activity
from domain.NABException import NABException
from domain.Person import Person
from domain.ActivityValidator import ActivityValidator
from repository.PersonRepository import PersonRepository
from repository.PersonFileRepository import PersonFileRepository
from repository.ActivityRepository import ActivityRepository
from repository.ActivityFileRepository import ActivityFileRepository


class StatsController:
    """
    Class used for handling the operations regarding statistics.
    """

    def __init__(self, personRepo, activityRepo):
        '''
        Constructor for the class StatsController.
        :param personRepo: PersonRepository - repository containing people
        :param activityRepo: ActivityRepository- repository containing activities
        :exception NABException: if one of the parameters is not valid
        '''

        if type(personRepo) not in [PersonRepository, PersonFileRepository]:
            raise NABException("The given repository of people is not valid.")

        if type(activityRepo) not in [ActivityRepository, ActivityFileRepository]:
            raise NABException("The given repository of activities is not valid.")

        self.__personRepo = personRepo
        self.__activityRepo = activityRepo


    def activities_for_person_alphabetically(self, id):
        '''
        Returns a list of activities performed by the person with the indicated ID alphabetically by description.
        :param id: positive integer - person's ID
        :return: list of Activity as specified
        :exception NABException: if one of the parameters is not valid
        '''

        L = self.__activityRepo.find_by_person_id(id).all()
        L.sort(key = lambda x: x.description)
        return L


    def activities_for_person_by_date(self, id):
        '''
        Returns a list of activities performed by the person with the indicated ID by date.
        :param id: positive integer - person's ID
        :return: list of Activity as specified
        :exception NABException: if one of the parameters is not valid
        '''

        L = self.__activityRepo.find_by_person_id(id).all()
        L.sort(key = lambda x: x.date)
        return L


    def people_with_activities_in_interval(self, date1, date2):
        '''
        Returns a list of people who perform activities in the indicated interval.
        :param date1: string - start date in a valid format
        :param date1: string - end date in a valid format
        :return: list of Person as specified
        :exception NABException: if one of the parameters is not valid
        '''

        if date1 > date2:
            raise NABException("End date must be after the start date.")

        if not ActivityValidator.valid_date(date1) or not ActivityValidator.valid_date(date2):
            raise NABException("At least one of the dates is invalid.")

        L = []

        for p in self.__personRepo:
            isInInterval = False

            for a in self.__activityRepo:
                if a.person == p and date1 <= a.date and a.date <= date2:
                    isInInterval = True
                    break

            if isInInterval:
                L.append(p)

        L.sort(key = lambda x: x.id)

        return L


    def activities_in_interval_alphabetically(self, date1, date2):
        '''
        Returns a list of activities performed in the indicated interval alphabetically by description.
        :param date1: string - start date in a valid format
        :param date1: string - end date in a valid format
        :return: list of Activity as specified
        :exception NABException: if one of the parameters is not valid
        '''

        if date1 > date2:
            raise NABException("End date must be after the start date.")

        if not ActivityValidator.valid_date(date1) or not ActivityValidator.valid_date(date2):
            raise NABException("At least one of the dates is invalid.")

        L = []

        for a in self.__activityRepo:
            if date1 <= a.date and a.date <= date2:
                L.append(a)

        L.sort(key = lambda x: x.description)

        return L


    def activities_in_interval_by_date(self, date1, date2):
        '''
        Returns a list of activities performed in the indicated interval by date.
        :param date1: string - start date in a valid format
        :param date1: string - end date in a valid format
        :return: list of Activity as specified
        :exception NABException: if one of the parameters is not valid
        '''

        if date1 > date2:
            raise NABException("End date must be after the start date.")

        if not ActivityValidator.valid_date(date1) or not ActivityValidator.valid_date(date2):
            raise NABException("At least one of the dates is invalid.")

        L = []

        for a in self.__activityRepo:
            if date1 <= a.date and a.date <= date2:
                L.append(a)

        L.sort(key = lambda x: x.date)

        return L


def __ctrl_for_tests():
    pR = PersonRepository()
    aR = ActivityRepository()
    L = StatsController(pR, aR)
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")
    a1 = Activity(p, "2015.12.20", "12:12", "Swimming")
    a2 = Activity(p, "2016.01.20", "12:12", "Mapping")
    a3 = Activity(q, "2015.12.21", "12:12", "Swimming")
    a4 = Activity(q, "2015.12.20", "10:12", "Reading")

    pR.add(p)
    pR.add(q)
    aR.add(a1)
    aR.add(a2)
    aR.add(a3)
    aR.add(a4)

    return L


def __test_activities_for_person_alphabetically():
    L = __ctrl_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")
    a1 = Activity(p, "2015.12.20", "12:12", "Swimming")
    a2 = Activity(p, "2016.01.20", "12:12", "Mapping")
    a3 = Activity(q, "2015.12.21", "12:12", "Swimming")
    a4 = Activity(q, "2015.12.20", "10:12", "Reading")

    assert L.activities_for_person_alphabetically(1) == [a2, a1]
    assert L.activities_for_person_alphabetically(2) == [a4, a3]
    assert L.activities_for_person_alphabetically(4) == []


def __test_activities_for_person_by_date():
    L = __ctrl_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")
    a1 = Activity(p, "2015.12.20", "12:12", "Swimming")
    a2 = Activity(p, "2016.01.20", "12:12", "Mapping")
    a3 = Activity(q, "2015.12.21", "12:12", "Swimming")
    a4 = Activity(q, "2015.12.20", "10:12", "Reading")

    assert L.activities_for_person_by_date(1) == [a1, a2]
    assert L.activities_for_person_by_date(2) == [a4, a3]
    assert L.activities_for_person_by_date(4) == []


def __test_people_with_activities_in_interval():
    L = __ctrl_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    assert L.people_with_activities_in_interval("2015.12.20", "2016.01.01") == [p, q]
    assert L.people_with_activities_in_interval("2000.01.01", "2010.01.01") == []
    assert L.people_with_activities_in_interval("2016.01.01", "2017.01.01") == [p]
    assert L.people_with_activities_in_interval("2015.12.21", "2015.12.21") == [q]


def __test_activities_in_interval_alphabetically():
    L = __ctrl_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")
    a1 = Activity(p, "2015.12.20", "12:12", "Swimming")
    a2 = Activity(p, "2016.01.20", "12:12", "Mapping")
    a3 = Activity(q, "2015.12.21", "12:12", "Swimming")
    a4 = Activity(q, "2015.12.20", "10:12", "Reading")

    assert L.activities_in_interval_alphabetically("2015.12.20", "2016.01.01") == [a4, a1, a3]
    assert L.activities_in_interval_alphabetically("2000.01.01", "2010.01.01") == []
    assert L.activities_in_interval_alphabetically("2016.01.01", "2017.01.01") == [a2]
    assert L.activities_in_interval_alphabetically("2015.12.21", "2015.12.21") == [a3]


def __test_activities_in_interval_by_date():
    L = __ctrl_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")
    a1 = Activity(p, "2015.12.20", "12:12", "Swimming")
    a2 = Activity(p, "2016.01.20", "12:12", "Mapping")
    a3 = Activity(q, "2015.12.21", "12:12", "Swimming")
    a4 = Activity(q, "2015.12.20", "10:12", "Reading")

    assert L.activities_in_interval_by_date("2015.12.20", "2016.01.01") == [a4, a1, a3]
    assert L.activities_in_interval_by_date("2000.01.01", "2010.01.01") == []
    assert L.activities_in_interval_by_date("2016.01.01", "2017.01.01") == [a2]
    assert L.activities_in_interval_by_date("2015.12.21", "2015.12.21") == [a3]


if __name__ == '__main__':
    __test_activities_for_person_alphabetically()
    __test_activities_for_person_by_date()
    __test_people_with_activities_in_interval()
    __test_activities_in_interval_alphabetically()
    __test_activities_in_interval_by_date()