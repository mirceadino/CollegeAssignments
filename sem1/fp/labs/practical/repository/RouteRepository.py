from domain.Route import Route
from domain.RouteValidator import RouteValidator
from domain.Exceptions import TrainException


class RouteRepository:

    '''
    Class used for handling a collection of routes.
    '''

    def __init__(self, filename, route_validator):
        '''
        Constructor for class RouteRepository.
        :param filename: str - filename of stored data
        :param route_validator: RouteValidator - validator for routes
        :return: object RouteRepository
        '''
        self.__data = []
        self.__filename = filename
        self.__route_validator = route_validator
        self.__hourly_rate = 0
        self.__load()


    def __len__(self):
        '''
        Returns number of routes.
        :return: int - number of routes
        '''
        return len(self.__data)


    def __iter__(self):
        '''
        Returns iterable routes.
        :return: iter - iterable of routes
        '''
        return iter(self.__data)


    def __load(self):
        '''
        Loads from the file the data.
        :return: data is loaded; it does nothing if file doesn't exist;
                 if file does not open, hourly_date is automatically set to 1.00
        '''

        try:
            file = open(self.__filename, "r")
        except IOError:
            self.__hourly_rate = 1.00
            return

        lines = file.read().strip().split("\n")
        line = lines[0].strip()
        self.__hourly_rate = float(line)

        for line in lines[1:]:
            line = line.strip()
            tokens = line.split(";")

            try:
                if len(tokens) != 6:
                    raise ValueError()

                id = int(tokens[0].strip())
                departure_city = tokens[1].strip()
                departure_time = tokens[2].strip()
                arrival_city = tokens[3].strip()
                arrival_time = tokens[4].strip()
                tickets = int(tokens[5].strip())

                self.__data.append(Route(id, departure_city, departure_time, arrival_city, arrival_time, tickets))
            except (ValueError, IndexError):
                continue


    def __store(self):
        '''
        Stores to the file the data.
        '''
        try:
            file = open(self.__filename, "w")
        except IOError:
            return

        file.write(str(self.__hourly_rate) + "\n")

        for route in self.__data:
            rep = str(route.id) + ";"
            rep += str(route.departure_city) + ";"
            rep += str(route.departure_time) + ";"
            rep += str(route.arrival_city) + ";"
            rep += str(route.arrival_time) + ";"
            rep += str(route.tickets) + "\n"
            file.write(rep)


    def all_routes(self):
        '''
        A list of all routes is returned.
        :return: list of Routes
        '''
        return self.__data[:]


    def add(self, route):
        '''
        Add a route to the repository.
        :param route: Route - route to be added
        :return: route is added
        :raises TrainException: if route is invalid or the same ID is already added
        '''
        if not self.__route_validator.check(route):
            raise TrainException("Given route is invalid.")

        if self.find(route.id):
            raise TrainException("There's already a route with the given ID.")

        self.__data.append(route)

        self.__store()


    def find(self, id):
        '''
        Checks if there's a route with the given id.
        :param id: int - id to be checked
        :return: True - found, False - not found
        '''
        for route in self.__data:
            if route.id == id:
                return True
        return False


    def cost_for_route(self, id):
        '''
        Computes the cost of the ticket on a route.
        :param id: int - id of the route
        :return: float - cost of the ticket
        :raises TrainException: if route doesn't exist
        '''
        for route in self.__data:
            if route.id == id:
                return round(self.__hourly_rate * route.minutes() / 60.0, 2)

        raise TrainException("Route does not exist.")


    def sell_ticket(self, id):
        '''
        Sell a ticket for a route.
        :param id: int - id of the route
        :return: number of available tickets of that route is decremented
        :raises TrainException: if route doesn't exist or there isn't any left ticket
        '''
        for route in self.__data:
            if route.id == id:
                if route.tickets > 0:
                    route.tickets -= 1
                    self.__store()
                    return
                else:
                    raise TrainException("There isn't any left ticket for that route.")

        raise TrainException("Route does not exist.")


def __test_add():
    repo = RouteRepository("", RouteValidator())
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    C = Route(5, "BananaLand", "15:10", "AppleLand", "20:20", 100)
    repo.add(A)
    assert A in repo
    repo.add(B)
    assert B in repo

    try:
        repo.add(C)
        assert False
    except TrainException:
        assert True


def __test_find():
    repo = RouteRepository("", RouteValidator())
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    repo.add(A)
    repo.add(B)
    assert repo.find(2)
    assert repo.find(5)
    assert not repo.find(1)


def __test_all_routes():
    repo = RouteRepository("", RouteValidator())
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    repo.add(A)
    repo.add(B)
    assert repo.all_routes() == [A, B]


def __test_cost_for_route():
    repo = RouteRepository("", RouteValidator())
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    repo.add(A)
    repo.add(B)
    assert repo.cost_for_route(2) == 10/60.0
    assert repo.cost_for_route(5) == (10*60+10)/60.0


def __test_sell_ticket():
    repo = RouteRepository("", RouteValidator())
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    repo.add(A)
    repo.add(B)
    repo.sell_ticket(2)
    repo.sell_ticket(2)
    repo.sell_ticket(5)
    assert A.tickets == 98
    assert B.tickets == 99


if __name__ == "__main__":
    __test_add()
    __test_find()
    __test_all_routes()
    __test_cost_for_route()
    __test_sell_ticket()