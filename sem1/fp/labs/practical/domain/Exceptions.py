class TrainException(Exception):

    def __init__(self, message = "Train Exception!"):
        self.message = message

    def __str__(self):
        return self.message