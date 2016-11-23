from domain.Activity import Activity
from domain.NABException import NABException
from domain.Person import Person
from repository.PersonRepository import PersonRepository
from repository.PersonFileRepository import PersonFileRepository
from repository.ActivityRepository import ActivityRepository
from repository.ActivityFileRepository import ActivityFileRepository
from controller.ChangeHistory import *
from copy import deepcopy


class ActivitiesController:
    """
    Class used for handling the operations regarding activities.
    """

    def __init__(self, personRepo, activityRepo):
        '''
        Constructor for the class ActivitiesController.
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
        self.__operations = []
        self.__index = -1


    def number_of_activities(self):
        '''
        Returns the numbers of activities in the list.
        :return: natural number representing the number of activities in the list
        '''

        return len(self.__activityRepo)


    def add_activity(self, activity):
        '''
        Adds an activity to the NAB, if the person performing the activity is in the list of people.
        :param activity: Activity - activity to be added to the NAB
        :return: activity is added to the NAB
        :exception NABException: if one of the parameters is not valid or person does not exist in the list of people
        '''

        if type(activity) is not Activity:
            raise NABException("The given activity is not valid.")

        if activity.person not in self.__personRepo:
            raise NABException("The person performing the given activity does not belong to the list.")

        self.__activityRepo.add(activity)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append([AddOperation(deepcopy(activity))])
        self.__index += 1


    def remove_activity_by_position(self, pos):
        '''
        Removes the activity with the indicated position from the list.
        :param pos: integer - position of the person in the current list, greater than or equal to 0 and strictly less than the length of the list
        :return: the activity with the indicated position is removed
        :exception NABException: if one of the parameters is not valid
        '''

        activity = self.__activityRepo.remove(pos)

        self.__operations.append([RemoveOperation(deepcopy(activity))])
        self.__index += 1
        self.__operations[:] = self.__operations[:self.__index+1]


    def find_activity(self, activity):
        '''
        Finds the first occurrence of an activity.
        :param activity: Activity to be found
        :return: -1 if no such activity was found or the position of the first occurrence of the activity
        '''

        for i in range(len(self.__activityRepo)):
            if self.__activityRepo.all()[i] == activity:
                return i

        return -1


    def remove_activities_by_person_id(self, id):
        '''
        Removes all the activities performed by the person with the indicated ID from the list.
        :param id: positive integer - ID of a person
        :return: all the activities performed by the person with the indicated ID are removed
        :exception NABException: if one of the parameters is not valid
        '''

        L = self.__activityRepo.remove_by_person_id(id)

        ops = []
        for activity in L:
            ops.append(RemoveOperation(deepcopy(activity)))

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append(ops)
        self.__index += 1


    def update_activity_person(self, activity, person):
        '''
        Updates person of an activity.
        :param activity: Activity to be updated
        :param person: new person for that activity
        :return: activity is updated
        :exception NABException: if one of the parameters is not valid, no person was found or no activity was found
        '''

        if activity not in self.__activityRepo:
            raise NABException("There's no such activity in the list.")

        if person not in self.__personRepo:
            raise NABException("There's no such person in the list.")

        oldAct = deepcopy(activity)
        activity.person = person
        newAct = deepcopy(activity)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append([UpdateOperation(oldAct, newAct)])
        self.__index += 1


    def update_activity_date(self, activity, date):
        '''
        Updates date of an activity.
        :param activity: Activity to be updated
        :param date: new date for that activity
        :return: activity is updated
        :exception NABException: if one of the parameters is not valid or no activity was found
        '''

        if activity not in self.__activityRepo:
            raise NABException("There's no such activity in the list.")

        oldAct = deepcopy(activity)
        activity.date = date
        newAct = deepcopy(activity)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append([UpdateOperation(oldAct, newAct)])
        self.__index += 1


    def update_activity_time(self, activity, time):
        '''
        Updates time of an activity.
        :param activity: Activity to be updated
        :param time: new time for that activity
        :return: activity is updated
        :exception NABException: if one of the parameters is not valid or no activity was found
        '''

        if activity not in self.__activityRepo:
            raise NABException("There's no such activity in the list.")

        oldAct = deepcopy(activity)
        activity.time = time
        newAct = deepcopy(activity)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append([UpdateOperation(oldAct, newAct)])
        self.__index += 1


    def update_activity_description(self, activity, description):
        '''
        Updates description of an activity.
        :param activity: Activity to be updated
        :param description: new description for that activity
        :return: activity is updated
        :exception NABException: if one of the parameters is not valid or no activity was found
        '''

        if activity not in self.__activityRepo:
            raise NABException("There's no such activity in the list.")

        oldAct = deepcopy(activity)
        activity.description = description
        newAct = deepcopy(activity)

        self.__operations[:] = self.__operations[:self.__index+1]
        self.__operations.append([UpdateOperation(oldAct, newAct)])
        self.__index += 1


    def undo(self):
        '''
        Undoes the last operation that modified the repositories.
        :return: repositories are modified accordingly
        :exception NABException: if no undo is possible
        '''

        if self.__index == -1:
            raise NABException("# There's nothing to undo.\n")

        for lastOperation in self.__operations[self.__index]:
            if type(lastOperation) == AddOperation:
                self.__activityRepo.remove(self.find_activity(lastOperation.object()))
            elif type(lastOperation) == RemoveOperation:
                self.__activityRepo.add(lastOperation.object())
            elif type(lastOperation) == UpdateOperation:
                pos = self.find_activity(lastOperation.new())
                activity = self.__activityRepo.find(pos)
                activity.person = lastOperation.old().person
                activity.date = lastOperation.old().date
                activity.time = lastOperation.old().time
                activity.description = lastOperation.old().description
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
        for lastOperation in self.__operations[self.__index]:
            if type(lastOperation) == AddOperation:
                self.__activityRepo.add(lastOperation.object())
            elif type(lastOperation) == RemoveOperation:
                    self.__activityRepo.remove(self.find_activity(lastOperation.object()))
            elif type(lastOperation) == UpdateOperation:
                pos = self.find_activity(lastOperation.old())
                activity = self.__activityRepo.find(pos)
                activity.person = lastOperation.new().person
                activity.date = lastOperation.new().date
                activity.time = lastOperation.new().time
                activity.description = lastOperation.new().description
            else:
                raise NABException("# Not a redoable operation.\n")


    def find_activity_by_position(self, pos):
        '''
        Returns the activity with the specified position.
        :param pos: integer - position of the person in the current list, greater than or equal to 0 and strictly less than the length of the list
        :return: Activity - the activity with the indicated position
        :exception NABException: if one of the parameters is not valid
        '''

        return self.__activityRepo.find(pos)


    def find_activities_by_person_id(self, id):
        '''
        Returns an ActivityRepository which contains only activities performed by the indicated person.
        :param id: positive integer - ID of a person
        :return: ActivityRepository - activities performed by the indicated person with the given ID
        :exception NABException: if one of the parameters is not valid
        '''

        return self.__activityRepo.find_by_person_id(id)


    def find_activities_by_date(self, date):
        '''
        Returns an ActivityRepository which contains only activities performed on the indicated date.
        :param date: string - day, month and year of the activity in the format "yyyy.mm.dd"
        :return: ActivityRepository - activities performed on the indicated date
        :exception NABException: if one of the parameters is not valid
        '''

        return self.__activityRepo.find_by_date(date)


    def find_activities_by_time(self, time):
        '''
        Returns an ActivityRepository which contains only activities performed on the indicated time.
        :param time: string - hour and minute of the activity in the format "hh:mm"
        :return: ActivityRepository - activities performed on the indicated time
        :exception NABException: if one of the parameters is not valid
        '''

        return self.__activityRepo.find_by_time(time)


    def find_activities_by_description(self, description):
        '''
        Returns an ActivityRepository which contains only activities with the indicated substring as part of their description.
        :param description: string - description of the activity
        :return: ActivityRepository - activities performed with the indicated substring as part of their description
        :exception NABException: if one of the parameters is not valid
        '''

        return self.__activityRepo.find_by_description(description)


    def activities_to_string(self):
        '''
        Returns a string representing the list of activities in their short representation.
        :return: string - list of activities or "None" if the list is empty
        '''

        return str(self.__activityRepo)


    def activities_to_string_with_positions(self):
        '''
        Returns a string representing the list of activities in their short representation with their afferent indices.
        :return: string - list of activities or "None" if the list is empty
        '''

        ret = ""

        for i in range(0, self.number_of_activities()):
            ret += "{0} - {1}".format(i + 1, self.find_activity_by_position(i))

        if ret == "":
            ret = "None\n"

        return ret