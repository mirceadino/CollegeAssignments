from domain.Product import Product


class CartRepository:
    '''
    Class used for handling a cart containing products and quantities for those products.
    '''

    def __init__(self):
        '''
        Constructor for the class CartRepository.
        '''
        self.__dict = {}


    def __iter__(self):
        '''
        Returns iterator for the repository.
        :return: iterator for the repository
        '''
        return iter(self.__dict)


    def get_all(self):
        '''
        Gets a list of all the products and quantities in the cart.
        :return: list of tuples - list of tuples of form (name, quantity)
        '''
        products = []

        for name in self.__dict:
            products.append((name, self.__dict[name]))

        return products


    def add(self, product, quantity):
        '''
        Adds a product with a certain quantity to the cart.
        :param product: Product - product to add to the cart
        :param quantity: integer - quantity of the product
        :return: product and quantity are added in the cart
        '''
        if product.get_name() in self.__dict:
            self.__dict[product.get_name()] += quantity
        else:
            self.__dict[product.get_name()] = quantity


def __test_add():
    repo = CartRepository()
    repo.add(Product(2, "Aspirin", 3), 3)
    assert ("Aspirin", 3) in repo.get_all()
    repo.add(Product(2, "Aspirin", 3), 2)
    assert ("Aspirin", 5) in repo.get_all()

    repo.add(Product(4, "Vitamin", 3), 4)
    assert ("Aspirin", 5) in repo.get_all()
    assert ("Vitamin", 4) in repo.get_all()


if __name__ == "__main__":
    __test_add()