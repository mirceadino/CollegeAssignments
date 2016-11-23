from domain.Product import Product
from repository.ProductRepository import ProductRepository
from repository.CartRepository import CartRepository


class PharmacyController:
    '''
    Class used for handling the pharmacy.
    '''

    def __init__(self, prodRepo):
        '''
        Constructor for the class PharmacyController.
        :param prodRepo: ProductRepository - repository with all the products
        '''
        self.__prodRepo = prodRepo
        self.__cart = CartRepository()


    def find_by_pattern(self, pattern):
        '''
        Finds all the products whose names begin with a pattern.
        :param pattern: string - pattern to search upon
        :return: list - all the products whose names begin with the pattern
        '''
        return self.__prodRepo.find_by_pattern(pattern)


    def find_by_name(self, name):
        '''
        Finds the product with a specific name.
        :param name: string - name to search upon
        :return: Product - found product with the specific name, if it exists
        :raises ValueError: if no product was found
        '''
        for product in self.__prodRepo:
            if product.get_name() == name:
                return product

        raise ValueError("# Product with that name has not been found.")


    def add_to_cart(self, name, quantity):
        '''
        Adds a product with a quantity to the cart.
        :param name: string - name to be added
        :param quantity: integer - quantity to be added
        :return: product and quantity are added to the cart
        :raises ValueError: if quantity is not a positive number or product does not exist in the list
        '''
        try:
            quantity = int(quantity)
        except ValueError:
            raise ValueError("# Invalid quantity - it should be positive.")

        if quantity <= 0:
            raise ValueError("# Invalid quantity - it should be positive.")

        product = self.find_by_name(name)
        self.__cart.add(product, quantity)


    def amount_cart(self):
        '''
        Returns the total amount from the cart.
        :return: integer - total amount of all the products and quantities
        '''
        cartProducts = self.__cart.get_all()
        sum = 0

        for product in cartProducts:
            name = product[0]
            quantity = product[1]
            product = self.find_by_name(name)
            sum += quantity * product.get_price()

        return sum


    def print_cart(self):
        '''
        Prints the cart's content.
        '''
        cartProducts = self.__cart.get_all()

        if len(cartProducts) == 0:
            print("# Cart is empty.")

        for product in cartProducts:
            name = product[0]
            quantity = product[1]
            product = self.find_by_name(name)

            ret = ""
            ret += "Name: " + name + "\n"
            ret += "Quantity: " + str(quantity) + "\n"
            ret += "Price/product: " + str(product.get_price()) + "\n"
            ret += "Total amount: " + str(quantity * product.get_price()) + "\n"

            print(ret)


def __test_find_by_pattern():
    repo = ProductRepository()
    repo.add(Product(2, "Aspirin", 3))
    repo.add(Product(3, "VitaminC", 3))
    repo.add(Product(4, "VitaminD", 3))
    pharmCtrl = PharmacyController(repo)
    assert pharmCtrl.find_by_name("Aspirin") == Product(2, "Aspirin", 3)
    assert pharmCtrl.find_by_name("VitaminC") == Product(3, "VitaminC", 3)
    try:
        pharmCtrl.find_by_name("AAA")
        assert False
    except ValueError:
        assert True


def __test_find_by_name():
    repo = ProductRepository()
    repo.add(Product(2, "Aspirin", 3))
    repo.add(Product(3, "VitaminC", 3))
    repo.add(Product(4, "VitaminD", 3))
    pharmCtrl = PharmacyController(repo)
    fr = pharmCtrl.find_by_pattern("Asp")
    assert len(fr) == 1
    assert Product(2, "Aspirin", 3) in fr
    fr = pharmCtrl.find_by_pattern("Vit")
    assert len(fr) == 2
    assert Product(3, "VitaminC", 3) in fr
    assert Product(4, "VitaminD", 3) in fr


def __test_add_to_cart():
    repo = ProductRepository()
    repo.add(Product(2, "Aspirin", 3))
    repo.add(Product(3, "VitaminC", 3))
    repo.add(Product(4, "VitaminD", 3))
    pharmCtrl = PharmacyController(repo)
    pharmCtrl.add_to_cart("Aspirin", 3)
    assert pharmCtrl.amount_cart() == 3*3
    pharmCtrl.add_to_cart("Aspirin", 3)
    pharmCtrl.add_to_cart("VitaminC", 4)
    assert pharmCtrl.amount_cart() == 3*6 + 4*3


if __name__ == "__main__":
    __test_find_by_pattern()
    __test_find_by_name()
    __test_add_to_cart()
