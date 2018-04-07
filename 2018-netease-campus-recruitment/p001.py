# python 3.5
def main():
    x = int(input())
    ops = []
    while x != 0:
        op = '1' if x % 2 == 1 else '2'
        ops.append(op)
        x = (x + 1) // 2 - 1
    ops = ''.join(ops)
    print(ops[::-1])


if __name__ == '__main__':
    main()
