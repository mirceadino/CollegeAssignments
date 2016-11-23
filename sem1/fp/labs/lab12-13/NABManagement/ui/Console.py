from domain.Activity import Activity
from domain.ActivityValidator import ActivityValidator
from domain.NABException import NABException
from domain.Person import Person
from domain.PersonValidator import PersonValidator
from repository.PersonRepository import PersonRepository
from repository.ActivityRepository import ActivityRepository
from controller.PeopleController import PeopleController
from controller.ActivitiesController import ActivitiesController
from controller.StatsController import StatsController
from os import system


class Console:
    """
    Class used for handling the console-based UI.
    """

    def __init__(self, peopleController, activitiesController, statsController, undoRedoCtrl):
        '''
        Constructor for the class Console.
        :param controller: peopleController - people controller which controls the repository for people
        :param controller: activitiesController - activities controller which controls the repository for activities
        :param controller: mixedController - mixed controller which controls the repositories for people and activities simultaneously
        '''

        self.__peopleCtrl = peopleController
        self.__activitiesCtrl = activitiesController
        self.__statsCtrl = statsController
        self.__undoRedoCtrl = undoRedoCtrl


    # Main Menu

    @staticmethod
    def print_main_menu():
        '''
        Prints the main menu.
        '''

        menu = ""
        menu += "# Pick one of the options below:\n"
        menu += "1 - Add a person or an activity\n"
        menu += "2 - Remove a person or an activity\n"
        menu += "3 - Update information about a person or an activity\n"
        menu += "4 - Display people or activities\n"
        menu += "5 - Search people based on some criteria\n"
        menu += "6 - Search activities based on some criteria\n"
        menu += "7 - Display statistics about people or activities\n"
        menu += "8 - Undo last modification\n"
        menu += "9 - Redo last undo\n"
        menu += "0 - Exit\n"
        print(menu)


    def run(self):
        '''
        Runs the application.
        '''

        system("clear")

        while True:
            self.print_main_menu()

            option = Console.read_option([1, 2, 3, 4, 5, 6, 7, 8, 9, 0])

            if option == 1:
                self.add()
            elif option == 2:
                self.remove()
            elif option == 3:
                self.update()
            elif option == 4:
                self.display()
            elif option == 5:
                self.search_people()
            elif option == 6:
                self.search_activities()
            elif option == 7:
                self.statistics()
            elif option == 8:
                self.undo()
            elif option == 9:
                self.redo()
            elif option == 0:
                self.exit()
                break


    # "Add" Feature

    @staticmethod
    def print_add_menu():
        '''
        Prints the menu for the add feature.
        '''

        menu = ""
        menu += "# You have chosen to add a new person or a new activity.\n"
        menu += "1 - Add a person\n"
        menu += "2 - Add an activity\n"
        menu += "0 - Return to the main menu\n"

        print(menu)


    def add(self):
        system("clear")

        while True:
            self.print_add_menu()

            try:
                option = Console.read_option([1, 2, 0])

                if option == 1:
                    self.add_person()
                elif option == 2:
                    self.add_activity()
                else:
                    break
            except NABException as err:
                print(err)

            print()

        system("clear")


    def add_person(self):
        '''
        Reads information about a person and adds it to the NAB.
        '''

        system("clear")

        print("# You have chosen to add a new person.")

        print("ID must be a positive integer not existing in the list of people.")

        id = Console.read_positive_integer("Type the ID: ")
        name = input("Type the name: ")
        phoneNumber = input("Type the phone number: ")
        address = input("Type the address: ")

        try:
            system("clear")

            p = Person(id, name, phoneNumber, address)
            self.__peopleCtrl.add_person(p)
            self.__undoRedoCtrl.do_people()
            print("Person has been successfully added.")
        except NABException as err:
            print(err)


    def add_activity(self):
        '''
        Reads information about an activity and adds it to the NAB.
        '''

        system("clear")

        print("# You have chosen to add a new activity.")

        print("ID must be the one of a person already existing in the list of people.")
        id = Console.read_positive_integer("Type the ID of the person who performs the activity: ")
        print("Date must be one between {0} and {1}.".format(ActivityValidator.minDate(), ActivityValidator.maxDate()))
        date = input("Type the date of the activity in format {0}: ".format(ActivityValidator.dateFormat()))
        print("Time must be one between {0} and {1}.".format(ActivityValidator.minTime(), ActivityValidator.maxTime()))
        time = input("Type the time of the activity in format {0}: ".format(ActivityValidator.timeFormat()))
        description = input("Type the description of the activity: " )

        try:
            system("clear")

            person = self.__peopleCtrl.find_person_by_id(id)
            self.__activitiesCtrl.add_activity(Activity(person, date, time, description))
            self.__undoRedoCtrl.do_activities()
            print("Activity has been successfully added.")
        except NABException as err:
            print(err)


    # "Remove" Feature

    @staticmethod
    def print_remove_menu():
        '''
        Prints the menu for the remove feature.
        '''

        menu = ""
        menu += "# You have chosen to remove a person or an activity.\n"
        menu += "1 - Remove a person by ID\n"
        menu += "2 - Remove an activity by position\n"
        menu += "0 - Return to the main menu\n"

        print(menu)


    def remove(self):
        system("clear")

        while True:
            self.print_remove_menu()

            try:
                option = Console.read_option([1, 2, 0])

                if option == 1:
                    self.remove_person()
                elif option == 2:
                    self.remove_activity()
                else:
                    break
            except NABException as err:
                print(err)

            print()

        system("clear")


    def remove_person(self):
        '''
        Reads the ID of a person in order to remove it from the NAB.
        '''

        system("clear")

        print("# You have chosen to remove a person represented by their ID.")

        if self.__peopleCtrl.number_of_people() == 0:
            raise NABException("The list of people is empty.")

        print("By removing a person you also remove all activities that they perform.")

        print(self.__peopleCtrl.people_to_string())

        print("ID must be the one of a person already existing in the list of people.")
        id = Console.read_positive_integer("Type the ID: ")

        try:
            system("clear")

            self.__peopleCtrl.remove_person_by_id(id)
            self.__activitiesCtrl.remove_activities_by_person_id(id)
            self.__undoRedoCtrl.do_both()

            print("Person has been successfully removed.")
        except NABException as err:
            print(err)


    def remove_activity(self):
        '''
        Reads the position of an activity in order to remove it from the NAB.
        '''

        system("clear")

        print("# You have chosen to remove an activity based on its position in the list.")

        if self.__activitiesCtrl.number_of_activities() == 0:
            raise NABException("The list of activities is empty.")

        print(self.__activitiesCtrl.activities_to_string_with_positions())

        pos = Console.read_positive_integer("Type a position from the ones above: ")

        try:
            system("clear")

            self.__activitiesCtrl.remove_activity_by_position(pos-1)
            self.__undoRedoCtrl.do_activities()

            print("Activity has been successfully removed.")
        except NABException as err:
            print(err)


    # "Update" Feature

    @staticmethod
    def print_update_menu():
        '''
        Prints the menu for the update feature.
        '''

        menu = ""
        menu += "# You have chosen to update information about a person or an activity.\n"
        menu += "1 - Update a person\n"
        menu += "2 - Update an activity\n"
        menu += "0 - Return to the main menu\n"

        print(menu)


    def update(self):
        system("clear")

        while True:
            self.print_update_menu()

            try:
                option = Console.read_option([1, 2, 0])

                if option == 1:
                    self.update_person_submenu()
                elif option == 2:
                    self.update_activity_submenu()
                else:
                    break
            except NABException as err:
                system("clear")
                print(err)

        system("clear")


    def update_person_submenu(self):
        '''
        Reads the ID of a person in order to update information about it.
        '''

        system("clear")

        print("# You have chosen to update information about a person.")

        if self.__peopleCtrl.number_of_people() == 0:
            raise NABException("The list of people is empty.")

        print(self.__peopleCtrl.people_to_string())

        print("ID must be the one of a person already existing in the list of people.")
        id = Console.read_positive_integer("Type the ID: ")

        try:
            system("clear")

            person = self.__peopleCtrl.find_person_by_id(id)

            self.update_person(person)

        except NABException as err:
            print(err)


    def update_person(self, person):
        '''
        Reads information to update a person.
        '''

        system("clear")

        while True:
            print("# You have chosen to update information about this person:")
            print(person.to_string())
            print("1 - Update name")
            print("2 - Update phone number")
            print("3 - Update address")
            print("0 - Cancel")
            print()

            try:
                option = Console.read_option([1, 2, 3, 0])

                if option == 1:
                    newName = input("Type the new name: ")
                    self.__peopleCtrl.update_person_name(person, newName)
                    self.__undoRedoCtrl.do_people()

                elif option == 2:
                    newPhone = input("Type the new phone number: ")
                    self.__peopleCtrl.update_person_phone(person, newPhone)
                    self.__undoRedoCtrl.do_people()

                elif option == 3:
                    newAddress = input("Type the new address: ")
                    self.__peopleCtrl.update_person_address(person, newAddress)
                    self.__undoRedoCtrl.do_people()

                elif option == 0:
                    break

                system("clear")
                print("Person has been successfully updated.")

            except NABException as err:
                print(err)

            print()

        system("clear")


    def update_activity_submenu(self):
        '''
        Read the position of an activity in order to update information about it.
        '''

        system("clear")

        print("# You have chosen to update information about an activity.")

        if self.__activitiesCtrl.number_of_activities() == 0:
            raise NABException("The list of activities is empty.")

        print(self.__activitiesCtrl.activities_to_string_with_positions())

        pos = Console.read_positive_integer("Type a position from the ones above: ")

        try:
            system("clear")

            activity = self.__activitiesCtrl.find_activity_by_position(pos-1)

            self.update_activity(activity)

        except NABException as err:
            print(err)


    def update_activity(self, activity):
        '''
        Reads information to update an activity.
        '''

        system("clear")

        while True:
            print("# You have chosen to update information about this activity:")
            print(activity)
            print("1 - Update person")
            print("2 - Update date")
            print("3 - Update time")
            print("4 - Update description")
            print("0 - Cancel")
            print()

            try:
                option = Console.read_option([1, 2, 3, 4, 0])

                if option == 1:
                    newID = Console.read_positive_integer("Type the new person's ID: ")
                    newPerson = self.__peopleCtrl.find_person_by_id(newID)
                    self.__activitiesCtrl.update_activity_person(activity, newPerson)
                    self.__undoRedoCtrl.do_activities()

                elif option == 2:
                    newDate = input("Type the new date: ")
                    self.__activitiesCtrl.update_activity_date(activity, newDate)
                    self.__undoRedoCtrl.do_activities()

                elif option == 3:
                    newTime = input("Type the new time: ")
                    self.__activitiesCtrl.update_activity_time(activity, newTime)
                    self.__undoRedoCtrl.do_activities()

                elif option == 4:
                    newDescription = input("Type the new description: ")
                    self.__activitiesCtrl.update_activity_description(activity, newDescription)
                    self.__undoRedoCtrl.do_activities()

                elif option == 0:
                    break

                system("clear")
                print("Activity has been successfully updated.")

            except NABException as err:
                system("clear")
                print(err)

            print()

        system("clear")


    # "Display" Feature

    @staticmethod
    def print_display_menu():
        '''
        Prints the menu for the display feature.
        '''

        menu = ""
        menu += "# You have chosen to display people or activities.\n"
        menu += "1 - Display all people\n"
        menu += "2 - Display all activities\n"
        menu += "0 - Return to the main menu\n"

        print(menu)


    def display(self):
        system("clear")

        while True:
            self.print_display_menu()

            try:
                option = Console.read_option([1, 2, 0])

                if option == 1:
                    self.display_all_people()
                elif option == 2:
                    self.display_all_activities()
                else:
                    break
            except NABException as err:
                print(err)

            print()

        system("clear")


    def display_all_people(self):
        '''
        Prints the list of all the people in the NAB.
        '''

        system("clear")

        print("# You have chosen to display the list of all the people.")

        print(self.__peopleCtrl.people_to_string(), end='')


    def display_all_activities(self):
        '''
        Prints the list of all the activities in the NAB.
        '''

        system("clear")

        print("# You have chosen to display the list of all the activities.")

        print(self.__activitiesCtrl.activities_to_string(), end='')


    # "Search People" Feature

    @staticmethod
    def print_search_people_menu():
        '''
        Prints the menu for the search people feature.
        '''

        menu = ""
        menu += "# You have chosen to search people based on some criteria.\n"
        menu += "1 - Search by id\n"
        menu += "2 - Search by name\n"
        menu += "3 - Search by phone number\n"
        menu += "4 - Search by address\n"
        menu += "0 - Return to the main menu\n"

        print(menu)


    def search_people(self):
        system("clear")

        while True:
            self.print_search_people_menu()

            try:
                option = Console.read_option([1, 2, 3, 4, 0])

                if option == 1:
                    self.search_people_with_id()
                elif option == 2:
                    self.search_people_with_name()
                elif option == 3:
                    self.search_people_with_phone()
                elif option == 4:
                    self.search_people_with_address()
                else:
                    break
            except NABException as err:
                print(err)

            print()

        system("clear")


    def search_people_with_id(self):
        '''
        Read an ID and prints the person with that ID.
        '''

        system("clear")

        print("# You have chosen to search a person with an indicated ID.")

        if self.__peopleCtrl.number_of_people() == 0:
            raise NABException("The list of people is empty.")

        id = Console.read_positive_integer("Type the ID: ")

        try:
            system("clear")

            person = self.__peopleCtrl.find_person_by_id(id)

            print("# The following person has been found: ")
            print(person.to_string(), end='')

        except NABException as err:
            print(err)


    def search_people_with_name(self):
        '''
        Read a name and prints the people with that name.
        '''

        system("clear")

        print("# You have chosen to search people with an indicated name.")

        if self.__peopleCtrl.number_of_people() == 0:
            raise NABException("The list of people is empty.")

        name = input("Type the name: ")

        try:
            system("clear")

            foundPeople = self.__peopleCtrl.find_people_by_name(name)

            print("# The following people have been found: ")
            print(foundPeople, end='')

        except NABException as err:
            print(err)


    def search_people_with_address(self):
        '''
        Read an address and prints the people with that address.
        '''

        system("clear")

        print("# You have chosen to search people with an indicated address.")

        if self.__peopleCtrl.number_of_people() == 0:
            raise NABException("The list of people is empty.")

        address = input("Type the address: ")

        try:
            system("clear")

            foundPeople = self.__peopleCtrl.find_people_by_address(address)

            print("# The following people have been found: ")
            print(foundPeople, end='')

        except NABException as err:
            print(err)


    def search_people_with_phone(self):
        '''
        Read a phone number and prints the people with that phone number.
        '''

        system("clear")

        print("# You have chosen to search people with an indicated phone number.")

        if self.__peopleCtrl.number_of_people() == 0:
            raise NABException("The list of people is empty.")

        phone = input("Type the phone number: ")

        try:
            system("clear")

            foundPeople = self.__peopleCtrl.find_people_by_phone(phone)

            print("# The following people have been found: ")
            print(foundPeople, end='')

        except NABException as err:
            print(err)


    # "Search Activities" Feature

    @staticmethod
    def print_search_activities_menu():
        '''
        Prints the menu for the search activities feature.
        '''

        menu = ""
        menu += "# You have chosen to search activities based on some criteria.\n"
        menu += "1 - Search by a person's id\n"
        menu += "2 - Search by date\n"
        menu += "3 - Search by description\n"
        menu += "0 - Return to the main menu\n"

        print(menu)


    def search_activities(self):
        system("clear")

        while True:
            self.print_search_activities_menu()

            try:
                option = Console.read_option([1, 2, 3, 0])

                if option == 1:
                    self.search_activities_with_person_id()
                elif option == 2:
                    self.search_activities_with_date()
                elif option == 3:
                    self.search_activities_with_description()
                else:
                    break
            except NABException as err:
                print(err)

            print()

        system("clear")


    def search_activities_with_person_id(self):
        '''
        Read an ID and prints the activities performed by the person with that ID.
        '''

        system("clear")

        print("# You have chosen to search a activity performed by a person indicated by their ID.")

        if self.__activitiesCtrl.number_of_activities() == 0:
            raise NABException("The list of activities is empty.")

        id = Console.read_positive_integer("Type the ID: ")

        try:
            system("clear")

            foundActivities = self.__activitiesCtrl.find_activities_by_person_id(id)

            print("# The following activities has been found: ")
            print(foundActivities, end='')

        except NABException as err:
            print(err)


    def search_activities_with_date(self):
        '''
        Read a date and prints the activities taking place on that date.
        '''

        system("clear")

        print("# You have chosen to search activities which take place on a certain date.")

        if self.__activitiesCtrl.number_of_activities() == 0:
            raise NABException("The list of activities is empty.")

        date = input("Type the date in format {0}: ".format(ActivityValidator.dateFormat()))

        try:
            system("clear")

            foundActivities = self.__activitiesCtrl.find_activities_by_date(date)

            print("# The following activities have been found: ")
            print(foundActivities, end='')

        except NABException as err:
            print(err)


    def search_activities_with_description(self):
        '''
        Read a description and prints the activities with that description incorporated.
        '''

        system("clear")

        print("# You have chosen to search activities which contain a certain description.")

        if self.__activitiesCtrl.number_of_activities() == 0:
            raise NABException("The list of activities is empty.")

        description = input("Type the description: ")

        try:
            system("clear")

            foundActivities = self.__activitiesCtrl.find_activities_by_description(description)

            print("# The following activities have been found: ")
            print(foundActivities, end='')

        except NABException as err:
            print(err)


    # "Display Statistics" Feature

    @staticmethod
    def print_statistics_menu():
        '''
        Prints the menu for the statistics feature.
        '''

        menu = ""
        menu += "# You have chosen to display statistics based on some criteria.\n"
        menu += "1 - Activities for a certain person alphabetically by description\n"
        menu += "2 - Activities for a certain person by their date\n"
        menu += "3 - People performing activities in a certain interval\n"
        menu += "4 - Activities in a certain interval alphabetically by description\n"
        menu += "5 - Activities in a certain interval by their date\n"
        menu += "0 - Return to the main menu\n"

        print(menu)


    def statistics(self):
        system("clear")

        while True:
            self.print_statistics_menu()

            try:
                option = Console.read_option([1, 2, 3, 4, 5, 0])

                if option == 1:
                    self.statistics_activities_for_person_alphabetically()
                elif option == 2:
                    self.statistics_activities_for_person_by_date()
                elif option == 3:
                    self.statistics_people_with_activities_in_interval()
                elif option == 4:
                    self.statistics_activities_in_interval_alphabetically()
                elif option == 5:
                    self.statistics_activities_in_interval_by_date()
                else:
                    break
            except NABException as err:
                print(err)

            print()

        system("clear")


    def statistics_activities_for_person_alphabetically(self):
        '''
        Reads the ID of a person in order to show all the activities they perform alphabetically by description.
        '''

        system("clear")

        print("# You have chosen to display the activities performed by a person alphabetically by description.")

        if self.__peopleCtrl.number_of_people() == 0:
            raise NABException("The list of people is empty.")

        print(self.__peopleCtrl.people_to_string())

        print("ID must be the one of a person already existing in the list of people.")
        id = Console.read_positive_integer("Type the ID: ")

        try:
            system("clear")

            activitiesList = self.__statsCtrl.activities_for_person_alphabetically(id)

            print("# The following activities have been found:")

            if len(activitiesList) == 0:
                print("None")
            else:
                for x in activitiesList:
                    print(x, end='')

        except NABException as err:
            print(err)


    def statistics_activities_for_person_by_date(self):
        '''
        Reads the ID of a person in order to show all the activities they perform by date.
        '''

        system("clear")

        print("# You have chosen to display the activities performed by a person by date.")

        if self.__peopleCtrl.number_of_people() == 0:
            raise NABException("The list of people is empty.")

        print(self.__peopleCtrl.people_to_string())

        print("ID must be the one of a person already existing in the list of people.")
        id = Console.read_positive_integer("Type the ID: ")

        try:
            system("clear")

            activitiesList = self.__statsCtrl.activities_for_person_by_date(id)

            print("# The following activities have been found:")

            if len(activitiesList) == 0:
                print("None")
            else:
                for x in activitiesList:
                    print(x, end='')

        except NABException as err:
            print(err)


    def statistics_people_with_activities_in_interval(self):
        '''
        Reads two dates and displays all the people having activities in that interval.
        '''

        system("clear")

        print("# You have chosen to display the people performing activities in a certain interval.")

        print("Read the start and the end dates of the interval.")
        date1 = input("Type the start date: ")
        date2 = input("Type the end date: ")

        try:
            system("clear")

            peopleList = self.__statsCtrl.people_with_activities_in_interval(date1, date2)

            print("# The following people have been found:")

            if len(peopleList) == 0:
                print("None")
            else:
                for x in peopleList:
                    print(x, end='')

        except NABException as err:
            print(err)


    def statistics_activities_in_interval_alphabetically(self):
        '''
        Reads two dates and displays all the activities performed in that interval alphabetically by description.
        '''

        system("clear")

        print("# You have chosen to display the activities performed in that interval alphabetically by description.")

        print("Read the start and the end dates of the interval.")
        date1 = input("Type the start date: ")
        date2 = input("Type the end date: ")

        try:
            system("clear")

            activitiesList = self.__statsCtrl.activities_in_interval_alphabetically(date1, date2)

            print("# The following activities have been found:")

            if len(activitiesList) == 0:
                print("None")
            else:
                for x in activitiesList:
                    print(x, end='')

        except NABException as err:
            print(err)


    def statistics_activities_in_interval_by_date(self):
        '''
        Reads two dates and displays all the activities performed in that interval by date.
        '''

        system("clear")

        print("# You have chosen to display the activities performed in that interval by date.")

        print("Read the start and the end dates of the interval.")
        date1 = input("Type the start date: ")
        date2 = input("Type the end date: ")

        try:
            system("clear")

            activitiesList = self.__statsCtrl.activities_in_interval_by_date(date1, date2)

            print("# The following activities have been found:")

            if len(activitiesList) == 0:
                print("None")
            else:
                for x in activitiesList:
                    print(x, end='')

        except NABException as err:
            print(err)


    # Undo & Redo

    def undo(self):
        try:
            system("clear")

            self.__undoRedoCtrl.undo()

            print("# Successful undo.\n")
        except NABException as err:
            print(err)


    def redo(self):
        try:
            system("clear")

            self.__undoRedoCtrl.redo()

            print("# Successful redo.\n")
        except NABException as err:
            print(err)


    # Exit

    def exit(self):
        #system("clear")
        print()

        print("# You have chosen to exit the application.")
        print("# Have a nice day!")


    # Miscellaneous methods

    @staticmethod
    def read_natural_number(message):
        '''
        Reads a natural number.
        :param message: string - message to display to the user when inputting the natural number
        :return: natural number - valid natural number that has been read
        :exception NABException: if the typed input is not a natural number
        '''

        while True:
            user_input = input(message)

            try:
                value = int(user_input)
                if (value >= 0) and (str(value) == user_input):
                    return value

                print("That's not a natural number.")

            except ValueError:
                print("That's not a natural number.")


    @staticmethod
    def read_positive_integer(message):
        '''
        Reads a positive integer.
        :param message: string - message to display to the user when inputting the natural number
        :return: positive integer - valid positive integer that has been read
        '''

        while True:
            user_input = input(message)

            try:
                value = int(user_input)
                if (value > 0) and (str(value) == user_input):
                    return value

                print("That's not a positive integer.")

            except ValueError:
                print("That's not a positive integer.")


    @staticmethod
    def read_option(options):
        '''
        Reads a natural number representing an option from a list.
        :param options: list of natural numbers - possible options to be read
        :return: natural number - valid natural number that represents the read option
        '''

        while True:
            option = Console.read_natural_number("Type an option: ")

            if option not in options:
                print("The option does not exist.")
            else:
                return option
