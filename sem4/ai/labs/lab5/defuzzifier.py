from inferrer import Inferrer
from utils import triangular


class Defuzzifier:

    def __init__(self, inferrer):
        self._inferrer = inferrer


    def crisp_time(self):
        return self._crisp_time


    def defuzzify(self):
        inferrer = self._inferrer
    
        sample = {}
        for x in range(0, 100+1):
            y = {}
            y["short"] = min(inferrer.time("short"), triangular(x, -1000, 0, 50))
            y["medium"] = min(inferrer.time("medium"), triangular(x, 0, 50, 100))
            y["long"] = min(inferrer.time("long"), triangular(x, 50, 100, 1000))
            y = max(y.values())
            sample[y] = x * y

        self._crisp_time = sum(sample.values()) / sum(sample.keys())

