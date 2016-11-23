from domain.Product import Product


class ProductRepository:
    '''
    Class used for handling a repository of product read from a file.
    '''

    def __init__(self, filename=""):
        '''
        Constructor for the class ProductRepository.
        :param filename: string - filename where the products are stored
        :return: products are loaded from the file
        '''
        self.__list = []
        self.__filename = filename
        self.__load_from_file()


    def __len__(self):
        '''
        Length of the repository.
        :return: integer - length of the repository
        '''
        return len(self.__list)


    def __iter__(self):
        '''
        Returns iterator for the repository.
        :return: iterator for the repository
        '''
        return iter(self.__list)


    def add(self, product):
        '''
        Adds a product to the repository.
        :param product: Product - product to be added
        :return: product is added to the repository
        '''
        self.__list.append(product)


    def find_by_pattern(self, pattern):
        '''
        Finds all the products whose names begin with a pattern.
        :param pattern: string - pattern to search upon
        :return: list - all the products whose names begin with the pattern
        '''
        foundProducts = []

        for product in self:
            name = product.get_name()

            if name.find(pattern) == 0:
                foundProducts.append(product)

        return foundProducts


    def __load_from_file(self):
        '''
        Loads products from a file.
        :return: products are loaded from the file
        '''
        try:
            f = open(self.__filename, "r")
        except IOError:
            return

        for line in f:
            line = line.strip()
            attributes = line.split(";")

            if len(attributes) != 3:
                continue

            attributes[0] = int(attributes[0])
            attributes[2] = int(attributes[2])

            product = Product(attributes[0], attributes[1], attributes[2])
            self.add(product)


def __test_add():
    repo = ProductRepository()
    assert len(repo) == 0
    repo.add(Product(2, "Aspirin", 3))
    assert len(repo) == 1
    assert Product(2, "Aspirin", 3) in repo
    repo.add(Product(3, "Vitamin", 3))
    assert len(repo) == 2
    assert Product(3, "Vitamin", 3) in repo


def __test_find_by_pattern():
    repo = ProductRepository()
    repo.add(Product(2, "Aspirin", 3))
    repo.add(Product(3, "VitaminC", 3))
    repo.add(Product(4, "VitaminD", 3))
    fr = repo.find_by_pattern("Aspirin")
    assert len(fr) == 1
    assert Product(2, "Aspirin", 3) in fr
    fr = repo.find_by_pattern("Vit")
    assert len(fr) == 2
    assert Product(3, "VitaminC", 3) in fr
    assert Product(4, "VitaminD", 3) in fr


if __name__ == "__main__":
    __test_add()
    __test_find_by_pattern()