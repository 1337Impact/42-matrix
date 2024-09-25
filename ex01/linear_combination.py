from typing import List
from Vector import Vector


def linear_combination(arr: List[Vector], scalers: List[float]) -> Vector:
    try:
        tmp = arr[0].scl(scalers[0])
        for i in range(1, len(arr)):
            tmp.add(arr[i].scl(scalers[i]))
        return tmp
    except Exception:
        return None
