import sys
import math
from itertools import *

def dist(a, b):
    return math.sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)

def main():
    cord = list(map(int, input().split()))
    x, y = cord[::2], cord[1::2]
    f = [[dist((x[i], y[i]), (x[j], y[j])) for i in range(5)] for j in range(5)]
    g = [dist((0, 0), (x[i], y[i])) for i in range(5)]
    res = 99999999999999999999999999999999999
    for sol in permutations(list(range(5))):
        tmp = g[sol[0]] + g[sol[-1]]
        for i, j in zip(sol[:4], sol[1:]):
            tmp += f[i][j]
        res = min(res, tmp)
    print(math.floor(res))


if __name__ == '__main__':
    main()


"""
200 0 200 10 200 50 200 30 200 25
456
"""
