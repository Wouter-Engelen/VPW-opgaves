from sys import stdin


def subsums(n, xs):
    if n == 0:
        return { 0 }
    elif n > len(xs):
        return set()
    else:
        return { xs[0] + subsum for subsum in subsums(n - 1, xs[1:]) }.union( subsums(n, xs[1:]) )


def sum_reachable(nss, goal):
    if goal < 0:
        return False
    elif nss:
        return any( sum_reachable(nss[1:], goal - s) for s in nss[0] )
    else:
        return goal == 0


def solve(bill, diamonds):
    max_diamonds = min( len(d) for d in diamonds )
    for n in range(1, max_diamonds + 1):
        if sum_reachable([ subsums(n, d) for d in diamonds ], bill):
            return n
    return -1


for index in range(1, int(stdin.readline()) + 1):
    bill = int(stdin.readline())
    ndwarves = int(stdin.readline())
    diamonds = []
    for _ in range(ndwarves):
        stdin.readline()
        diamonds.append([ int(x) for x in stdin.readline().split(' ') ])
    solution = solve(bill, diamonds)
    if solution == -1:
        solution = 'ONMOGELIJK'
    print(f'{index} {solution}')