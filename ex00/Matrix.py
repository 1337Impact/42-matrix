class Matrix:
    values = []

    def __init__(self, values):
        self.values = values

    def add(self, m2):
        for i in range(len(self.values)):
            self.values[i] = [self.values[i][j] + m2.values[i][j]
                              for j in range(len(self.values[i]))]
        return self.values

    def sub(self, m2):
        for i in range(len(self.values)):
            self.values[i] = [self.values[i][j] - m2.values[i][j]
                              for j in range(len(self.values[i]))]
        return self.values

    def scl(self, n):
        for i in range(len(self.values)):
            self.values[i] = [self.values[i][j] * n
                              for j in range(len(self.values[i]))]
        return self.values

    def __str__(self):
        return str(self.values)
