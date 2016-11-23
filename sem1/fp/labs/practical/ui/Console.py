from os import system
from domain.Route import Route
from domain.Exceptions import TrainException


class Console:

    def __init__(self, ctrl):
        self.__ctrl = ctrl


    def print_main_menu(self):
        print(":: TRAIN TRAVEL INC. ::")
        print("1 - Add a new route")
        print("2 - Sell a ticket")
        print("3 - Show total income")
        print("4 - Show report")
        print("0 - Exit")


    def get_integer(self, message):
        line = input(message).strip()

        try:
            number = int(line)
            if str(number) == line:
                return number
        except ValueError:
            raise TrainException("Invalid command.")


    def run_add(self):
        id = input("Type route's unique ID: ")
        departure_city = input("Type departure city: ")
        departure_time = input("Type departure time: ")
        arrival_city = input("Type arrival city: ")
        arrival_time = input("Type arrival time: ")
        tickets = input("Type available number of tickets: ")

        try:
            id = int(id)
            tickets = int(tickets)
            if tickets < 1:
                raise ValueError()
        except ValueError:
            print("ID and number of tickets must be positive integers.\n")
            return

        try:

            self.__ctrl.add(Route(id, departure_city, departure_time, arrival_city, arrival_time, tickets))
            print("Route was successfully added.\n")
        except TrainException as err:
            print(str(err) + "\n")


    def run_sell(self):
        for route in self.__ctrl.all_routes():
            print(route)

        try:
            route_number = self.get_integer("Pick a route: ")

            if not self.__ctrl.find(route_number):
                raise TrainException("Invalid route number.")

            cost = self.__ctrl.cost_for_route(route_number)

            print("Cost for route is: " + str(cost))
            while True:
                command = input("Proceed with the purchase? Type Y/N: ").strip()
                if command in ["Y", "y"]:
                    try:
                        self.__ctrl.sell_ticket(route_number)
                        system("clear")
                        print("Ticket successfully sold.\n")
                    except TrainException as err:
                        print(str(err) + "\n")
                    return
                elif command in ["N", "n"]:
                    system("clear")
                    print("Purchase cancelled.\n")
                    return

        except TrainException as err:
            print(str(err) + "\n")


    def run_total_income(self):
        print("Total income is: {0}\n".format(self.__ctrl.total_income()))


    def run_report(self):
        routes = self.__ctrl.ordered_by_sells()

        for route in routes:
            text = ""
            text += str(route.id) + " - "
            text += "From: " + route.departure_city + " at " + route.departure_time + " - "
            text += "To: " + route.arrival_city + " at " + route.arrival_time + " - "
            text += "Sold tickets: " + str(self.__ctrl.tickets_for_route(route.id))
            print(text)

        print()


    def run(self):
        system("clear")

        while True:
            self.print_main_menu()

            while True:
                try:
                    command = self.get_integer("Type an option: ")
                    break
                except TrainException as err:
                    print(err)

            if command == 0:
                break
            elif command == 1:
                system("clear")
                self.run_add()
            elif command == 2:
                system("clear")
                self.run_sell()
            elif command == 3:
                system("clear")
                self.run_total_income()
            elif command == 4:
                system("clear")
                self.run_report()
            else:
                system("clear")
                print("Option does not exist.\n")

        print("\nBye!")