# python 3.5
def main():
    n = int(input())
    x = [int(_) for _ in input().split()]
    y = [int(_) for _ in input().split()]
    def dot(i, j, k):
        return (x[k] - x[i]) * (x[j] - x[i]) + (y[k] - y[i]) * (y[j] - y[i])
    def para(i, j, k):
        return (x[k] - x[i]) * (y[j] - y[i]) == (y[k] - y[i]) * (x[j] - x[i])
    res = min(n, 3)
    for i in range(n):
        for j in range(i + 1, n):
            ans, pool = 0, {0:0}
            for k in range(n):
                if para(i, j, k):
                    ans += 1
                else:
                    d = dot(i, j, k)
                    if d in pool:
                        pool[d] += 1
                    else:
                        pool[d] = 1
            ans += max(pool.values())
            res = max(ans, res)
    print(res)


if __name__ == '__main__':
    main()
