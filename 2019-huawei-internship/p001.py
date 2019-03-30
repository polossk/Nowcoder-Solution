import sys

def cut(s, k):
    return (s, None) if len(s) < k else (s[:k], s[k:])


def cut9(s): return cut(s, 9)


def main():
    n = int(input())
    s = input()
    ans = []
    while n:
        a, s = cut9(s)
        ans.append(a[1:][::-1] if a[0] == '0' else a[1:])
        n -= 1
    print(' '.join(ans))


if __name__ == '__main__':
    main()


"""
2
1asdfzxcv0vcxzfdsa
"""
