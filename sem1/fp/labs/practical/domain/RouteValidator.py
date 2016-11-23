from domain.Route import Route


class RouteValidator:

    '''
    Class used for handling route's validating.
    '''

    def __init__(self):
        '''
        Constructor for class RouteValidator.
        '''
        pass


    def check(self, route):
        '''
        Checks if route is a valid Route.
        :param route: Route - to be checked
        :return: True - okay; False - not okay
        '''
        if not isinstance(route, Route):
            return False

        if route.departure_city == route.arrival_city:
            return False

        if route.departure_time >= route.arrival_time:
            return False

        if route.id < 1:
            return False

        if route.tickets < 0:
            return False

        if not self.valid_time(route.departure_time):
            return False

        if not self.valid_time(route.arrival_time):
            return False

        return True


    def valid_time(self, time):
        '''
        Checks if time is valid.
        :param time: str - form hh:mm
        :return: True - okay; False - not okay
        '''

        try:
            h, m = time.split(":")
            h = int(h)
            m = int(m)
            assert h in range(0, 24)
            assert m in range(0, 60)
            assert (str(h) + ":" + str(m) == time) or ("0" + str(h) + ":" + str(m) == time) or ("0" + str(h) + ":" + "0" + str(m) == time) or (str(h) + ":" + "0" + str(m) == time)
            return True
        except:
            return False


def __test_valid_time():
    V = RouteValidator()
    assert V.valid_time("10:30")
    assert V.valid_time("1:30")
    assert V.valid_time("10:3")
    assert not V.valid_time("25:30")
    assert not V.valid_time("fdfds")
    assert not V.valid_time("30:30:30")


def __test_check():
    V = RouteValidator()
    R = Route(3, 4, 4, 4, 4, 4)
    assert not V.check(R)
    R = Route(2, "BananaLand", "10:10", "AppleLand", "10:20", 100)
    assert V.check(R)
    R = Route(5, "BananaLand", "10:10", "AppleLand", "20:20", 100)
    assert V.check(R)
    R = Route(5, "BananaLand", "25:10", "AppleLand", "20:20", 100)
    assert not V.check(R)
    R = Route(5, "BananaLand", "20:10", "AppleLand", "20:00", 100)
    assert not V.check(R)


if __name__ == "__main__":
    __test_valid_time()
    __test_check()