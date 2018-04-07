# python 3.5
def main():
    s = input()
    chips, tmp = [], 1
    for i in range(len(s)):
        if i == 0: continue
        if s[i] == s[i - 1]:
            tmp += 1
        else:
            chips.append(tmp)
            tmp = 1
    chips.append(tmp)
    print("%.2f" % (sum(chips) / len(chips)))


if __name__ == '__main__':
    main()
