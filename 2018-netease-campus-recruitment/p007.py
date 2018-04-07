# python 3.5
def main():
    n = int(input())
    a = [int(_) for _ in input().split()]
    cost = [abs(_1 - _2) for (_1, _2) in zip([a[0]] + a[:-1], a)]
    dp = [[0] * n for _ in range(n)]
    for i in range(2, n):
        dp[i][0] = dp[i - 1][0] + cost[i]
        dp[i][i - 1] = dp[i - 1][i - 2] + cost[i - 1]
    for i in range(2, n):
        for j in range(i - 1):
            dp[i][j] = dp[i - 1][j] + cost[i]
            dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + abs(a[i] - a[j]))
    print(min([2 ** 60] + dp[n - 1][:-1]))


if __name__ == '__main__':
    main()
