import sys
from ui import UI
from controller import Controller
from problem import Problem


def main():
    controller = Controller()
    ui = UI(controller)
    ui.run()


if __name__ == "__main__":
    main()
