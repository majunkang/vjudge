import sys, itertools

def combinationCount(m, n):
    if n == 0:
        return 1

    if m == n:
        return 1

    y = 1
    x = 1
    z = 1
    for i in range(m, 0, -1):
        y = y * i

    for i in range(n, 0, -1):
        x = x * i

    for i in range(m-n, 0, -1):
        z = z * i

    return y/(x*z)

def getCounht(number):
    if number == 1 or number == 0:
        return 1

    count = 0
    for i in range(0, number):
        a = combinationCount(number-1, i)
        b = getCounht(number-i-1)
        count += a*b

    return count

for line in sys.stdin:
    n = int(line)
    count = getCounht(n)
    print(count)