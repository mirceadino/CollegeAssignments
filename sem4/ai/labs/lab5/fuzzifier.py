from observer import Observer
from utils import trapezoidal, triangular, print_fuzz


class Fuzzifier:

    def __init__(self, observer):
        self._observer = observer


    def temperature(self, state):
        return self._temperature[state]


    def humidity(self, state):
        return self._humidity[state]


    def fuzzify(self):
        self._fuzzify_temperature()
        self._fuzzify_humidity()


    def _fuzzify_temperature(self):
        temperature = self._observer.temperature()

        fuzz = {}
        fuzz["very cold"] = trapezoidal(temperature, -1000, -30, -20, 5)
        fuzz["cold"] = triangular(temperature, -5, 0, 10)
        fuzz["normal"] = trapezoidal(temperature, 5, 10, 15, 20)
        fuzz["warm"] = triangular(temperature, 15, 20, 25)
        fuzz["hot"] = trapezoidal(temperature, 25, 30, 35, 1000)

        self._temperature = fuzz

        print_fuzz("Temperature is: ", self._temperature)


    def _fuzzify_humidity(self):
        humidity = self._observer.humidity()

        fuzz = {}
        fuzz["dry"] = triangular(humidity, -1000, 0, 50)
        fuzz["normal"] = triangular(humidity, 0, 50, 100)
        fuzz["wet"] = triangular(humidity, 50, 100, 1000)

        self._humidity = fuzz

        print_fuzz("Humidity is: ", self._humidity)

