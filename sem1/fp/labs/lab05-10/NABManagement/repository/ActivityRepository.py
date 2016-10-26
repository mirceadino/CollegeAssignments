from domain.Activity import Activity
from domain.ActivityValidator import ActivityValidator
from domain.NABException import NABException
from domain.Person import Person
from domain.PersonValidator import PersonValidator


class ActivityRepository:
    """
    Class used for handling a list of activities and maintaining them sorted by date and time..
    """

    def __init__(self):
        '''
        Constructor for the class ActivityRepository.
        '''

        self.__list = []


    def __len__(self):
        '''
        Returns the length of the current list of activities.
        :return: integer - length of the current list of activities
        '''

        self.__list.sort(key = lambda x: str(x))

        return len(self.__list)


    def __iter__(self):
        '''
        Returns an iterator object for the repository.
        :return: iter(list) - iterator object
        '''

        self.__list.sort(key = lambda x: str(x))

        return iter(self.__list)


    def all(self):
        '''
        Returns a list containing all the people.
        :return: list of Person
        '''

        return self.__list


    def add(self, activity):
        '''
        Adds an activity to the current list of activities.
        :param activity: Activity - activity to be added
        :return: activity is added to the current list of activities
        :exception NABException: if one of the parameters is not valid
        '''

        if type(activity) is not Activity:
            raise NABException("The given activity is not valid.")

        self.__list.append(activity)
        self.__list.sort(key = lambda x: str(x))


    def find(self, pos):
        '''
        Returns the activity with the specified position.
        :param pos: integer - position of the person in the current list, greater than or equal to 0 and strictly less than the length of the list
        :return: Activity - the activity with the indicated position
        :exception NABException: if one of the parameters is not valid
        '''

        if (type(pos) is not int) or (pos < 0 or pos >= len(self.__list)):
            raise NABException("The given position is not valid.")

        return self.__list[pos]


    def find_by_person_id(self, id):
        '''
        Returns an ActivityRepository which contains only activities performed by the indicated person.
        :param id: positive integer - ID of a person
        :return: ActivityRepository - activities performed by the indicated person with the given ID
        :exception NABException: if one of the parameters is not valid
        '''

        if not PersonValidator.valid_id(id):
            raise NABException("The given ID is not a positive integer.")

        foundActivities = ActivityRepository()

        for activity in self.__list:
            if activity.person.id == id:
                foundActivities.add(activity)

        return foundActivities


    def find_by_date(self, date):
        '''
        Returns an ActivityRepository which contains only activities performed on the indicated date.
        :param date: string - day, month and year of the activity in the format "yyyy.mm.dd"
        :return: ActivityRepository - activities performed on the indicated date
        :exception NABException: if one of the parameters is not valid
        '''

        if not ActivityValidator.valid_date(date):
            raise NABException("The given date is not in a valid format.")

        foundActivities = ActivityRepository()

        for activity in self.__list:
            if activity.date == date:
                foundActivities.add(activity)

        return foundActivities


    def find_by_time(self, time):
        '''
        Returns an ActivityRepository which contains only activities performed on the indicated time.
        :param time: string - hour and minute of the activity in the format "hh:mm"
        :return: ActivityRepository - activities performed on the indicated time
        :exception NABException: if one of the parameters is not valid
        '''

        if not ActivityValidator.valid_time(time):
            raise NABException("The given time is not in a valid format.")

        foundActivities = ActivityRepository()

        for activity in self.__list:
            if activity.time == time:
                foundActivities.add(activity)

        return foundActivities


    def find_by_description(self, description):
        '''
        Returns an ActivityRepository which contains only activities with the indicated substring as part of their description.
        :param description: string - description of the activity
        :return: ActivityRepository - activities performed with the indicated substring as part of their description
        :exception NABException: if one of the parameters is not valid
        '''

        if type(description) is not str:
            raise NABException("The given description is not a string.")

        foundActivities = ActivityRepository()

        for activity in self.__list:
            if description in activity.description:
                foundActivities.add(activity)

        return foundActivities


    def remove(self, pos):
        '''
        Removes the the activities with the indicated position in the current list.
        :param pos: integer - position of the person in the current list, greater than or equal to 0 and strictly less than the length of the list
        :return: Activity - the activity at the position pos is popped out of the list
        :exception NABException: if one of the parameters is not valid
        '''

        if (type(pos) is not int) or (pos < 0 or pos >= len(self.__list)):
            raise NABException("The given position is not valid.")

        return self.__list.pop(pos)


    def remove_by_person_id(self, id):
        '''
        Removes all the activities performed by the person with the indicated ID from the list.
        :param id: positive integer - ID of a person
        :return: all the activities performed by the person with the indicated ID are removed
        :exception NABException: if one of the parameters is not valid
        '''

        if not PersonValidator.valid_id(id):
            raise NABException("The given ID is not a positive integer.")

        L = []

        for i in range(len(self)-1, -1, -1):
            a = self.__list[i]
            if a.person.id == id:
                L.append(self.remove(i))

        return L


    def __str__(self):
        '''
        Returns a string representing the list of activities in their short representation.
        :return: string - list of activities or "None" if the list is empty
        '''

        ret = ""

        for activity in self:
            ret += str(activity)

        if ret != "":
            return ret
        else:
            return "None\n"


def __repo_for_tests():
    L = ActivityRepository()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    L.add(Activity(p, "2015.12.20", "12:12", "Swimming"))
    L.add(Activity(p, "2016.01.20", "12:12", "Swimming"))
    L.add(Activity(q, "2015.12.21", "12:12", "Swimming"))
    L.add(Activity(q, "2015.12.20", "10:12", "Reading"))

    return L


def __test_add():
    L = ActivityRepository()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    assert len(L) == 0
    L.add(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert len(L) == 1
    assert str(L.find(0)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    L.add(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert len(L) == 2
    assert str(L.find(0)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert str(L.find(1)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    L.add(Activity(q, "2015.12.20", "12:12", "Swimming"))
    assert len(L) == 3
    assert str(L.find(0)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert str(L.find(1)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert str(L.find(2)) == str(Activity(q, "2015.12.20", "12:12", "Swimming"))
    L.add(Activity(q, "2015.12.20", "10:12", "Reading"))
    assert len(L) == 4
    assert str(L.find(0)) == str(Activity(q, "2015.12.20", "10:12", "Reading"))
    assert str(L.find(1)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert str(L.find(2)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert str(L.find(3)) == str(Activity(q, "2015.12.20", "12:12", "Swimming"))

    try:
        L.add(p)
        assert False
    except NABException:
        assert len(L) == 4
        assert True


def __test_find():
    L = __repo_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    assert str(L.find(0)) == str(Activity(q, "2015.12.20", "10:12", "Reading"))
    assert str(L.find(1)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert str(L.find(2)) == str(Activity(q, "2015.12.21", "12:12", "Swimming"))
    assert str(L.find(3)) == str(Activity(p, "2016.01.20", "12:12", "Swimming"))

    try:
        L.find(-1)
        assert False
    except NABException:
        assert True

    try:
        L.find(p)
        assert False
    except NABException:
        assert True


def __test_find_by_person_id():
    L = __repo_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    P = L.find_by_person_id(p.id)
    assert len(P) == 2
    assert str(P.find(0)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert str(P.find(1)) == str(Activity(p, "2016.01.20", "12:12", "Swimming"))

    P = L.find_by_person_id(q.id)
    assert len(P) == 2
    assert str(P.find(0)) == str(Activity(q, "2015.12.20", "10:12", "Reading"))
    assert str(P.find(1)) == str(Activity(q, "2015.12.21", "12:12", "Swimming"))

    P = L.find_by_person_id(9)
    assert len(P) == 0

    try:
        L.find_by_person_id(-1)
        assert False
    except NABException:
        assert True

    try:
        L.find_by_person_id(p)
        assert False
    except NABException:
        assert True


def __test_find_by_date():
    L = __repo_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    P = L.find_by_date("2015.12.20")
    assert len(P) == 2
    assert str(P.find(0)) == str(Activity(q, "2015.12.20", "10:12", "Reading"))
    assert str(P.find(1)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))

    P = L.find_by_date("2015.12.21")
    assert len(P) == 1
    assert str(P.find(0)) == str(Activity(q, "2015.12.21", "12:12", "Swimming"))

    P = L.find_by_date("2015.05.17")
    assert len(P) == 0

    try:
        P = L.find_by_date("3404.43.44")
        assert False
    except NABException:
        assert True

    try:
        P = L.find_by_date(p)
        assert False
    except NABException:
        assert True


def __test_find_by_time():
    L = __repo_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    P = L.find_by_time("10:12")
    assert len(P) == 1
    assert str(P.find(0)) == str(Activity(q, "2015.12.20", "10:12", "Reading"))

    P = L.find_by_time("12:12")
    assert len(P) == 3
    assert str(P.find(0)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert str(P.find(1)) == str(Activity(q, "2015.12.21", "12:12", "Swimming"))
    assert str(P.find(2)) == str(Activity(p, "2016.01.20", "12:12", "Swimming"))

    P = L.find_by_time("11:12")
    assert len(P) == 0

    try:
        P = L.find_by_time("3404.43.44")
        assert False
    except NABException:
        assert True

    try:
        P = L.find_by_time(p)
        assert False
    except NABException:
        assert True


def __test_find_by_description():
    L = __repo_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    P = L.find_by_description("Reading")
    assert len(P) == 1
    assert str(P.find(0)) == str(Activity(q, "2015.12.20", "10:12", "Reading"))

    P = L.find_by_description("Swimming")
    assert len(P) == 3
    assert str(P.find(0)) == str(Activity(p, "2015.12.20", "12:12", "Swimming"))
    assert str(P.find(1)) == str(Activity(q, "2015.12.21", "12:12", "Swimming"))
    assert str(P.find(2)) == str(Activity(p, "2016.01.20", "12:12", "Swimming"))

    P = L.find_by_description("11:12")
    assert len(P) == 0

    try:
        P = L.find_by_description([])
        assert False
    except NABException:
        assert True

    try:
        P = L.find_by_description(p)
        assert False
    except NABException:
        assert True


def __test_remove():
    L = __repo_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    assert str(L.remove(0)) == str(Activity(q, "2015.12.20", "10:12", "Reading"))
    assert len(L) == 3

    assert str(L.remove(2)) == str(Activity(p, "2016.01.20", "12:12", "Swimming"))
    assert len(L) == 2

    try:
        L.remove(2)
        assert False
    except NABException:
        assert True


def __test_remove_by_person_id():
    L = __repo_for_tests()
    p = Person(1, "John", "1", "A")
    q = Person(2, "Mary", "1", "B")

    L.remove_by_person_id(1)
    assert len(L) == 2
    assert len(L.find_by_person_id(1)) == 0

    L.remove_by_person_id(1)
    assert len(L) == 2
    assert len(L.find_by_person_id(1)) == 0

    try:
        L.remove_by_person_id([])
        assert False
    except NABException:
        assert True

    L.remove_by_person_id(2)
    assert len(L) == 0
    assert len(L.find_by_person_id(2)) == 0


if __name__ == "__main__":
    __test_add()
    __test_find()
    __test_find_by_person_id()
    __test_find_by_date()
    __test_find_by_time()
    __test_find_by_description()
    __test_remove()
    __test_remove_by_person_id()