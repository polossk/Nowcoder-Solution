# python 3.5
def main():
    n, l = map(int, input().split())
    fa = [int(_) for _ in input().split()]
    depth = [0] * n
    for i in range(n - 2):
        depth[i + 1] = depth[fa[i]] + 1
    max_depth = max(depth)
    max_ans = l + 1 if l <= max_depth else 1 + max_depth + (l - max_depth) // 2
    print(min(n, max_ans))


if __name__ == '__main__':
    main()
