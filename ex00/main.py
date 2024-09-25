from Matrix import Matrix
from Vector import Vector


u = Matrix([
    [1., 2.],
    [3., 4.]
])

v = Matrix([
    [7., 4.],
    [-2., 2.]
])

u.sub(v)

print(u)

v1 = Vector([2., 3.])
v2 = Vector([5., 7.])

v1.sub(v2)
print(v1)
