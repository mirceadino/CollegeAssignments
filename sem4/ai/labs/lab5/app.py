from observer import Observer
from fuzzifier import Fuzzifier
from inferrer import Inferrer
from defuzzifier import Defuzzifier


def main():
    observer = Observer()
    fuzzifier = Fuzzifier(observer)
    inferrer = Inferrer(fuzzifier)
    defuzzifier = Defuzzifier(inferrer)

    observer.observe()
    fuzzifier.fuzzify()
    inferrer.infer()
    defuzzifier.defuzzify()

    print("Time should be {0} minutes".format(defuzzifier.crisp_time()))


if __name__ == "__main__":
    main()
