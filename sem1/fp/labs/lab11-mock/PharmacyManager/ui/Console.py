from domain.Product import Product
from repository.ProductRepository import ProductRepository
from controller.PharmacyController import PharmacyController
from os import system


class Console:

    def __init__(self, pharmCtrl):
        self.__pharmCtrl = pharmCtrl


    def print_main_menu(self):
        menu = ""
        menu += "# Pharmacy\n"
        menu += "1 - Search for products\n"
        menu += "2 - Add product to cart\n"
        menu += "3 - Compute amount from cart\n"
        menu += "0 - Exit\n"
        print(menu)


    def get_option(self, options):
        option = -1

        while True:
            line = input("# Type an option: ")

            try:
                option = int(line)

                if str(option) != line:
                    raise ValueError

                if option not in options:
                    raise ValueError

                return option

            except ValueError:
                print("# Not a valid option.")


    def search(self):
        system("clear")

        pattern = input("# Type the pattern: ")

        foundProducts = self.__pharmCtrl.find_by_pattern(pattern)

        print("# The following products have been found: ")

        if len(foundProducts) == 0:
            print("None.")

        for product in foundProducts:
            print(product)

        print()


    def add_to_cart(self):
        system("clear")

        name = input("# Type name of product: ")
        quantity = input("# Type quantity: ")

        try:
            self.__pharmCtrl.add_to_cart(name, quantity)
            print("# Product has been successfully added to the cart.")

        except ValueError as err:
            print(err)

        print()


    def compute_amount(self):
        system("clear")

        self.__pharmCtrl.print_cart()

        print("# Total amount of all products: {0}\n".format(self.__pharmCtrl.amount_cart()))


    def run(self):
        system("clear")

        while True:
            self.print_main_menu()
            option = self.get_option([0,1,2,3])

            if option == 0:
                break
            elif option == 1:
                self.search()
                continue
            elif option == 2:
                self.add_to_cart()
                continue
            elif option == 3:
                self.compute_amount()
                continue

        print("# Bye!")