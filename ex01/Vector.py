class Vector:
    values = []

    def __init__(self, values):
        self.values = values

    def add(self, v2):
        self.values = [self.values[i] + v2.values[i]
                       for i in range(len(self.values))]
        return Vector(self.values)

    def sub(self, v2):
        self.values = [self.values[i] - v2.values[i]
                       for i in range(len(self.values))]
        return Vector(self.values)

    def scl(self, scaler):
        self.values = [self.values[i] *
                       scaler for i in range(len(self.values))]
        return Vector(self.values)

    def __str__(self):
        return str(self.values)
