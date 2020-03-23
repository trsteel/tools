import sys

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def gcd(a, b):
    return b if a%b==0 else gcd(b, a%b)

def cal(s):
    num, mid = list(), 0
    for i in range(0, len(s)-1):
        if s[i] != s[i+1]: mid = i; break
    num.append(gcd(s[mid], s[mid+1]))
    for i in range(mid+1, len(s)): num.append(s[i]/num[-1])
    for i in range(mid, -1, -1): num.insert(0, s[i]/num[0])
    idx, dt = sorted(list(set(num))), dict()
    for i in range(len(idx)): dt[idx[i]] = alphabet[i]
    return "".join([dt[i] for i in num])

def get_input():
    line = sys.stdin.readline()
    return line.split(' ')

if __name__ == '__main__':
    T = int(get_input()[0])
    for t in range(1, T+1):
        n, l = get_input()
        s = get_input()
        s = map(lambda x: int(x), s)
        print "Case #%d: %s" % (t, cal(s))
