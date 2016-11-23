from domain.Activity import Activity
from domain.NABException import NABException
from domain.Person import Person
from domain.ActivityValidator import ActivityValidator
from repository.PersonRepository import PersonRepository
from repository.PersonFileRepository import PersonFileRepository
from repository.ActivityRepository import ActivityRepository
from repository.ActivityFileRepository import ActivityFileRepository
from utils.Useful import sort, filter


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

        if not isinstance(personRepo, PersonRepository):
            raise NABException("The given repository of people is not valid.")

        if not isinstance(activityRepo, ActivityRepository):
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

        funct = lambda x: x.person.id == id
        L = filter(funct, self.__activityRepo)
        return sort(L, key=lambda x: x.description)


    def activities_for_person_by_date(self, id):
        '''
        Returns a list of activities performed by the person with the indicated ID by date.
        :param id: positive integer - person's ID
        :return: list of Activity as specified
        :exception NABException: if one of the parameters is not valid
        '''

        funct = lambda x: x.person.id == id
        L = filter(funct, self.__activityRepo)
        return sort(L, key=lambda x: x.date)


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

        funct = lambda x: len([a for a in self.__activityRepo if a.person == x and date1 <= a.date and a.date <= date2]) != 0
        L = filter(funct, self.__personRepo)
        return sort(L, key=lambda x: x.id)


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

        funct = lambda x: date1 <= x.date and x.date <= date2
        L = filter(funct, self.__activityRepo)
        return sort(L, key=lambda x: x.description)


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

        funct = lambda x: date1 <= x.date and x.date <= date2
        L = filter(funct, self.__activityRepo)
        return sort(L, key=lambda x: x.description)