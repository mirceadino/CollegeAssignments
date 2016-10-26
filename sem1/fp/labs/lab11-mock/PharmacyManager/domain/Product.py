class Product:
    '''
    Class used to handle a Product.
    '''

    def __init__(self, id, name, price):
        '''
        Constructor for the class Product.
        :param id: integer - ID of the product
        :param name: string - name of the product
        :param price: integer - price of the product
        '''
        self.__id = id
        self.__name = name
        self.__price = price


    def get_id(self):
        '''
        Getter for the ID.
        :return: integer - ID of the product
        '''
        return self.__id


    def get_name(self):
        '''
        Getter for the name.
        :return: string - name of the product
        '''
        return self.__name


    def get_price(self):
        '''
        Getter for the price.
        :return: integer - price of the product
        '''
        return self.__price


    def __eq__(self, other):
        '''
        Overrides the equality method.
        :param other: Product - other product to test equality with
        :return: True if products are equal; False otherwise
        '''
        return str(self) == str(other)


    def __str__(self):
        '''
        Returns string representation of the product.
        :return: string - representation of the product
        '''
        prod = ""
        prod += str(self.__id) + " - "
        prod += self.__name + " - "
        prod += str(self.__price)
        return prod


def __test_getters():
    c = Product(1, "VitaminC", 3)

    assert c.get_id() == 1
    assert c.get_name() == "VitaminC"
    assert c.get_price() == 3


def __test_eq():
    c = Product(1, "VitaminC", 3)
    cp = Product(1, "VitaminC", 3)
    d = Product(2, "VitaminD", 3)

    assert c == cp
    assert c != d
    assert cp != d


if __name__ == "__main__":
    __test_getters()
    __test_eq()