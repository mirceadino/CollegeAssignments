from domain.Route import Route
from domain.RouteValidator import RouteValidator
from domain.Exceptions import TrainException
from repository.RouteRepository import RouteRepository


class RouteController:

    '''
    Class used for handling the repositories.
    '''

    def __init__(self, repo):
        '''
        Constructor for class RouteController.
        :param repo: RouteRepository - repository of routes
        :return: object RouteController
        :raises TrainException: if file is corrupted
        '''
        self.__repo = repo
        self.__cart = []


    def add(self, route):
        '''
        Add a route to the repository.
        :param route: Route - route to be added
        :return: route is added
        :raises TrainException: if route is invalid or the same ID is already added
        '''
        self.__repo.add(route)


    def all_routes(self):
        '''
        A list of all routes is returned.
        :return: list of Routes
        '''
        return self.__repo.all_routes()


    def find(self, id):
        '''
        Checks if there's a route with the given id.
        :param id: int - id to be checked
        :return: True - found, False - not found
        '''
        return self.__repo.find(id)


    def cost_for_route(self, id):
        '''
        Computes the cost of the ticket on a route.
        :param id: int - id of the route
        :return: float - cost of the ticket
        :raises TrainException: if route doesn't exist
        '''
        return self.__repo.cost_for_route(id)


    def sell_ticket(self, id):
        '''
        Sell a ticket for a route.
        :param id: int - id of the route
        :return: number of available tickets of that route is decremented
        :raises TrainException: if route doesn't exist or there isn't any left ticket
        '''
        self.__repo.sell_ticket(id)
        self.__cart.append(id)


    def total_income(self):
        '''
        Total income of sold tickets.
        :return: float - cost of all sold tickets
        '''
        income = 0

        for id in self.__cart:
            income += self.__repo.cost_for_route(id)

        return round(income,2)


    def ordered_by_sells(self):
        '''
        Returns a list of routes ordered decreasingly by the number of sold tickets.
        :return: list of Routes - ordered list
        '''
        routes = self.all_routes()
        return sorted(routes, key=lambda x: self.tickets_for_route(x.id), reverse=True)


    def tickets_for_route(self, id):
        '''
        Returns the number of sold tickets for a route.
        :param id: int - id of the route
        :return: int - number of sold tickets
        '''
        sold = 0
        for ticket in self.__cart:
            if ticket == id:
                sold += 1
        return sold


def __test_add():
    repo = RouteRepository("", RouteValidator())
    ctrl = RouteController(repo)
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    C = Route(5, "BananaLand", "15:10", "AppleLand", "20:20", 100)
    ctrl.add(A)
    assert A in ctrl.all_routes()
    ctrl.add(B)
    assert B in repo.all_routes()

    try:
        repo.add(C)
        assert False
    except TrainException:
        assert True


def __test_find():
    repo = RouteRepository("", RouteValidator())
    ctrl = RouteController(repo)
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    ctrl.add(A)
    ctrl.add(B)
    assert ctrl.find(2)
    assert ctrl.find(5)
    assert not ctrl.find(1)


def __test_all_routes():
    repo = RouteRepository("", RouteValidator())
    ctrl = RouteController(repo)
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    ctrl.add(A)
    ctrl.add(B)
    assert ctrl.all_routes() == [A, B]


def __test_cost_for_route():
    repo = RouteRepository("", RouteValidator())
    ctrl = RouteController(repo)
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    ctrl.add(A)
    ctrl.add(B)
    assert ctrl.cost_for_route(2) == 10/60.0
    assert ctrl.cost_for_route(5) == (10*60+10)/60.0


def __test_sell_ticket_and_cart():
    repo = RouteRepository("", RouteValidator())
    ctrl = RouteController(repo)
    A = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    B = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    ctrl.add(A)
    ctrl.add(B)
    ctrl.sell_ticket(2)
    ctrl.sell_ticket(2)
    ctrl.sell_ticket(5)
    assert A.tickets == 98
    assert B.tickets == 99
    assert ctrl.total_income() == round(2*(10/60.0) + 1*((10*60+10)/60.0),2)
    assert ctrl.ordered_by_sells() == [A, B]
    ctrl.sell_ticket(5)
    ctrl.sell_ticket(5)
    assert A.tickets == 98
    assert B.tickets == 97
    assert ctrl.total_income() == round(2*(10/60.0) + 3*((10*60+10)/60.0),2)
    assert ctrl.ordered_by_sells() == [B, A]


if __name__ == "__main__":
    __test_add()
    __test_find()
    __test_all_routes()
    __test_cost_for_route()
    __test_sell_ticket_and_cart()