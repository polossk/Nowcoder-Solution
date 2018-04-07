# python 3.5
def main():
    t = int(input())
    while t > 0:
        n = int(input())
        xs = [int(_) for _ in input().split()]
        xs_2 = sum([_ % 2 == 0 and _ % 4 != 0 for _ in xs])
        xs_4 = sum([_ % 4 == 0 for _ in xs])
        print("Yes" if xs_4 >= (n - xs_2 + 1) // 2 else "No")
        t -= 1


if __name__ == '__main__':
    main()
