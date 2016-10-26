class Route:
    '''
    Class used for handling information about a route.
    '''

    def __init__(self, id, departure_city, departure_time, arrival_city, arrival_time, tickets):
        '''
        Constructor for class Route.
        :param id: positive int - ID of the route
        :param departure_city: str - departure city
        :param departure_time: str - departure time
        :param arrival_city: str - arrival city
        :param arrival_time: str - arrival time
        :param tickets: positive int - number of available tickets
        :return: object Route
        '''
        self.__id = id
        self.__departure_city = departure_city
        self.__departure_time = departure_time
        self.__arrival_city = arrival_city
        self.__arrival_time = arrival_time
        self.__tickets = tickets


    @property
    def id(self):
        '''
        Getter for the id of the route.
        :return: positive integer - id
        '''
        return self.__id


    @property
    def departure_city(self):
        '''
        Getter for the departure city of the route.
        :return: str - departure city
        '''
        return self.__departure_city


    @property
    def departure_time(self):
        '''
        Getter for the departure time of the route.
        :return: str - departure time
        '''
        return self.__departure_time


    @property
    def arrival_city(self):
        '''
        Getter for the arrival city of the route.
        :return: str - arrival city
        '''
        return self.__arrival_city


    @property
    def arrival_time(self):
        '''
        Getter for the arrival time of the route.
        :return: str - arrival time
        '''
        return self.__arrival_time


    @property
    def tickets(self):
        '''
        Getter for the nr. of available tickets of the route.
        :return: int - available tickets
        '''
        return self.__tickets

    @tickets.setter
    def tickets(self, value):
        '''
        Setter for the nr. of available tickets of the route.
        :return: tickets is modified
        '''
        self.__tickets = value


    def minutes(self):
        '''
        Get number of minutes of the route.
        :return: int - number of minutes of the route
        '''
        h0, m0 = self.departure_time.split(":")
        h1, m1 = self.arrival_time.split(":")
        m0 = int(m0) + int(h0) * 60
        m1 = int(m1) + int(h1) * 60
        return m1 - m0


    def __str__(self):
        '''
        String representation of the route.
        :return: str - representation as a string for the route
        '''
        text = ""
        text += str(self.id) + " - "
        text += "From: " + self.departure_city + " at " + self.departure_time + " - "
        text += "To: " + self.arrival_city + " at " + self.arrival_time + " - "
        text += "Tickets: " + str(self.tickets)
        return text


def __test_setters():
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    assert A.id == 2
    assert A.departure_city == "BananaLand"
    assert A.departure_time == "10:10"
    assert A.arrival_city == "AppleLand"
    assert A.arrival_time == "10:20"
    assert A.tickets == 100


def __test_getters():
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    A.tickets = 90
    assert A.tickets == 90


def __test_minutes():
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    assert A.minutes() == 10
    assert B.minutes() == 10+10*60


if __name__ == "__main__":
    __test_setters()
    __test_getters()
    __test_minutes()