from random import random
from math import exp


class Neuron:

    def __init__(self, num_inputs=0):
        self.num_inputs = num_inputs
        self.weights = [(random() * 2 - 1) for k in range(self.num_inputs)]
        self.output = 0
        self.error = 0


    def activate(self, values):
        net = sum([values[i] * self.weights[i] for i in range(self.num_inputs)])
        self.output = 1 / (1 + exp(-net))


    def set_error(self, error):
        self.error = error * self.output * (1 - self.output)


class Layer:

    def __init__(self, num_neurons=0, num_inputs_per_neuron=0):
        self.num_neurons = num_neurons
        self.neurons = [Neuron(num_inputs_per_neuron) for k in range(self.num_neurons)]


    def outputs(self):
        return [neuron.output for neuron in self.neurons]


    def __iter__(self):
        return iter(self.neurons)


class Network:

    def __init__(self, num_inputs, num_outputs, num_hidden_layers, num_neurons_per_hidden_layer):
        self.num_inputs = num_inputs
        self.num_outputs = num_outputs
        self.num_hidden_layers = num_hidden_layers
        self.num_neurons_per_hidden_layer = num_neurons_per_hidden_layer
        self.layers = []
        self.layers += [Layer(self.num_inputs, 0)]
        self.layers += [Layer(self.num_neurons_per_hidden_layer, self.num_inputs)]
        self.layers += [Layer(self.num_neurons_per_hidden_layer, self.num_neurons_per_hidden_layer) for k in range(self.num_hidden_layers - 1)]
        self.layers += [Layer(self.num_outputs, self.num_neurons_per_hidden_layer)]
        print("{0} neurons on the input layer".format(self.num_inputs))
        print("{0} neurons on the output layer".format(self.num_outputs))
        print("{0} hidden layers with {1} neurons on each hidden layer".format(self.num_hidden_layers, self.num_neurons_per_hidden_layer))


    def set_params(self, learning_rate, epoch_limit, success_rate):
        self.kLearnRate= learning_rate
        self.kEpochLimit = epoch_limit
        self.kSuccessRate = success_rate
        print("learning rate: {0}".format(self.kLearnRate))
        print("epoch limit: {0}".format(self.kEpochLimit))
        print("goal for success rate: {0}".format(self.kSuccessRate))


    def activate(self, inputs):
        # Set the values on the input layer
        neuron_index = 0
        for neuron in self.layers[0]:
            neuron.output = inputs[neuron_index]
            neuron_index += 1

        # Activate all the neurons on the hidden layers and the output layer
        layer_index = 1
        for layer in self.layers[1:]:
            for neuron in layer:
                prev_layer = self.layers[layer_index-1]
                neuron.activate(prev_layer.outputs())
            layer_index += 1


    def backpropagate(self, errors):
        # Set errors on the output layer
        neuron_index = 0
        for neuron in self.layers[-1]:
            neuron.set_error(errors[neuron_index])
            neuron_index += 1

        # Set errors on the hidden layers and the input layer
        layer_index = len(self.layers) - 2
        for layer in self.layers[::-1][1:]:
            next_layer = self.layers[layer_index+1]
            neuron_index = 0
            for neuron in layer:
                sum_errors = sum([neuron.weights[neuron_index] * neuron.error for neuron in next_layer])
                neuron.set_error(sum_errors)
                neuron_index += 1
            layer_index -= 1

        # Update weights
        layer_index = 1
        for layer in self.layers[1:]:
            prev_layer = self.layers[layer_index-1]
            for neuron in layer:
                for i in range(neuron.num_inputs):
                    delta = self.kLearnRate * neuron.error * prev_layer.neurons[i].output
                    neuron.weights[i] += delta
            layer_index += 1


    def compute_transformed_outputs(self):
        # Use softmax to transform the outputs into probabilities
        sum_exp = sum(exp(neuron.output) for neuron in self.layers[-1])
        return [exp(neuron.output)/sum_exp for neuron in self.layers[-1]]


    def compute_prediction(self):
        num_labels = self.layers[-1].num_neurons
        transformed_outputs = self.compute_transformed_outputs()

        # Compute label as the one with the highest probability
        computed_label = 0
        max_prob = transformed_outputs[0]
        for i in range(num_labels):
            if transformed_outputs[i] > max_prob:
                computed_label = i
                max_prob = transformed_outputs[i]
        return computed_label


    def compute_errors(self, target):
        num_labels = self.layers[-1].num_neurons
        transformed_outputs = self.compute_transformed_outputs()

        # Compute errors
        errors = [-e for e in transformed_outputs]
        errors[target] += 1

        # Compute global error
        computed_label = self.compute_prediction()
        is_correct = (1 if computed_label == target else 0)
        return is_correct, errors


    def compute_success(self, is_corrects):
        if len(is_corrects) < 1:
            return None
        total_corrects = sum(is_corrects)
        success = total_corrects/len(is_corrects)
        return success


    def learn(self, input_data, output_data):
        num_data = len(input_data)
        stop_condition = False
        epoch = 0
        print("starting to learn...")
        while not stop_condition and epoch < self.kEpochLimit:
            is_corrects = []
            for data_index in range(num_data):
                self.activate(input_data[data_index])
                is_correct, errors = self.compute_errors(output_data[data_index])
                self.backpropagate(errors)
                is_corrects.append(is_correct)
            success = self.compute_success(is_corrects)
            stop_condition = success > self.kSuccessRate
            print("epoch #{0}, success on training data: {1}".format(epoch, success))
            epoch += 1
        print("enough learning!")


    def test(self, input_data, output_data):
        num_data = len(input_data)
        is_corrects = []
        for data_index in range(num_data):
            self.activate(input_data[data_index])
            is_correct, errors = self.compute_errors(output_data[data_index], )
            is_corrects.append(is_correct)
        return self.compute_success(is_corrects)
