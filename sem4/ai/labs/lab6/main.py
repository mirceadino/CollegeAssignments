import sys
from network import Network
from statistics import mean, stdev
from random import shuffle


def read_data(filename):
    input_data = []
    output_data = []
    f = open(filename)
    raw_values = []
    for line in f:
        raw_values.append(list(map(float, line.split())))
    #shuffle(raw_values)
    for values in raw_values:
        input_data.append(values[:-1])
        output_data.append(values[-1])
    output_data = list(map(int, output_data))
    return input_data, output_data


def normalize_data(data):
    if len(data) < 1:
        return
    num_features = len(data[0])
    for feature_index in range(num_features):
        miu = mean([entry[feature_index] for entry in data])
        sigma = stdev([entry[feature_index] for entry in data])
        maxx = max([entry[feature_index] for entry in data])
        minn = min([entry[feature_index] for entry in data])
        for i in range(len(data)):
            if maxx != minn:
                data[i][feature_index] = (data[i][feature_index] - minn)/(maxx - minn)* 2 - 1
            else:
                data[i][feature_index] = 0


def main():
    if len(sys.argv) < 2:
        print("usage: {0} <filename>".format(sys.argv[0]))
        return

    filename = sys.argv[1]
    input_data, output_data = read_data(filename)
    input_train_data = input_data[:2000]
    output_train_data = output_data[:2000]
    input_test_data = input_data[2000:]
    output_test_data = output_data[2000:]

    normalize_data(input_train_data)
    normalize_data(input_test_data)

    num_features = len(input_data[0])
    num_labels = max(output_data) + 1

    network = Network(num_features, num_labels, 2, 10)
    network.set_params(learning_rate=0.2, epoch_limit=1000, success_rate=0.95)
    network.learn(input_train_data, output_train_data)
    success = network.test(input_test_data, output_test_data)
    print("success on test data: {0}".format(success))


if __name__ == "__main__":
    main()
