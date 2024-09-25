from Vector import Vector
from linear_combination import linear_combination


def main():
    e1 = Vector([1., 0., 0.])
    e2 = Vector([0., 1., 0.])
    e3 = Vector([0., 0., 1.])

    v1 = Vector([1., 2., 3.])
    v2 = Vector([0., 10., -100.])

    res = linear_combination([e1, e2, e3],  [10., -2., 0.5])
    print(res)
    res2 = linear_combination([v1, v2], [10., -2.])
    print(res2)


if __name__ == "__main__":
    main()
