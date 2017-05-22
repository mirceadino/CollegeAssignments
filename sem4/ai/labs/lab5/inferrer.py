from fuzzifier import Fuzzifier
from utils import print_fuzz


class Inferrer:

    def __init__(self, fuzzifier):
        self._fuzzifier = fuzzifier

        """
        Rule goes like that:
        rules[A][B] = N <=> if A and B, then N
        rules[C][D] = N <=> if C and D, then N
        Thus: if (A and B) or (C and D), then N
        """
        rules = {}
        rules["very cold"] = {"wet": "short", "normal": "short", "dry": "medium"}
        rules["cold"] = {"wet": "short", "normal": "medium", "dry": "long"}
        rules["normal"] = {"wet": "short", "normal": "medium", "dry": "long"}
        rules["warm"] = {"wet": "short", "normal": "medium", "dry": "long"}
        rules["hot"] = {"wet": "medium", "normal": "long", "dry": "long"}
        self._rules = rules


    def time(self, state):
        return self._time[state]


    def infer(self):
        """
        Inference is done by applying Mandani model with clipped fuzzy sets
        """
        fuzzifier = self._fuzzifier
        rules = self._rules

        fuzz = {"short": 0, "medium": 0, "long": 0}
        for temp in ["very cold", "cold", "normal", "warm", "hot"]:
            for hum in ["dry", "normal", "wet"]:
                state = rules[temp][hum]
                time = min(fuzzifier.temperature(temp), fuzzifier.humidity(hum))
                fuzz[state] = max(fuzz[state], time)

        self._time = fuzz

        print_fuzz("Inferred time is: ", self._time)
