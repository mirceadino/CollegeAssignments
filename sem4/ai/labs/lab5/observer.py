
class Observer:

    def __init__(self):
        pass


    def temperature(self):
        return self._temperature


    def humidity(self):
        return self._humidity


    def observe(self):
        self._temperature = float(input("Temperature [-30, 35]: "))
        self._humidity = float(input("Humidity [0, 100]: "))
