def around(ns, index, n):
    return ns[max(0, index-n):min(len(ns), index+n+1)]

def move_down(ns, n = 1):
    return [ max( around(ns, k, n) ) for k in range(len(ns)) ]

ncases = int(input())
for index in range(1, ncases + 1):
    width, length, nflags = [ int(x) for x in input().split(' ') ]
    flags = {}
    for _ in range(nflags):
        x, y, w = map(int, input().split(' '))
        flags.setdefault(y, []).append((x, w))
    scores = [ 0 ] * width
    ys = sorted(flags.keys())
    jumps = list(zip([0, *ys], ys))
    for (y1, y2) in jumps:
        scores = move_down(scores, y2 - y1)
        for (x, w) in flags.get(y2, []):
            scores[x] += w
    solution = max(scores)
    print(f'{index} {solution}', flush=True)
