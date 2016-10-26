from domain.Product import Product
from repository.ProductRepository import ProductRepository
from controller.PharmacyController import PharmacyController
from ui.Console import Console


def main():
    prodRepo = ProductRepository("products.txt")
    pharmCtrl = PharmacyController(prodRepo)
    ui = Console(pharmCtrl)

    ui.run()


if __name__ == "__main__":
    main()