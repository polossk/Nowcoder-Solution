#  python 3.5

def vaild(_):
    cnt = 0
    for elem in _:
        cnt += 1 if elem == '(' else -1
        if cnt < 0: return False
    return cnt == 0


def main():
    s = input()
    test = set()
    for i in range(len(s)):
        p = s[:i] + s[i + 1:]
        for j in range(len(p)):
            test.add(p[:j] + s[i] + p[j:])
    vaild_elems = set(filter(vaild, test))
    print(len(vaild_elems) - 1)


if __name__ == '__main__':
    main()
