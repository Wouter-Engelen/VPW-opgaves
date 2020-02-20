# Binary search + 2-pointer technique
# ~ O(n^2 * log(n)^2)

# wedstrijd.invoer in 2.27s
# test case with n = 42K in >300s

for nr in range(1, int(input()) + 1):
    n, k = [int(x) for x in input().split()]

    huizen = [[int(x) for x in input().split()] for _ in range(n)]
    huizen.sort(key=lambda a: a[0] + a[1])

    def possible(max_dist):
        # 2-pointer technique: find range of huizen with dist(x+y) <= max_dist
        i, j = 0, 0
        while j < n:
            while j < n and huizen[j][0] + huizen[j][1] <= huizen[i][0] + huizen[i][1] + max_dist:
                j += 1

            potential = list(sorted(huizen[x][0] - huizen[x][1] for x in range(i, j)))

            # 2-pointer technique: find range of huizen with dist(x-y) <= max_dist
            p, q = 0, 0
            while q < len(potential):
                while q < len(potential) and potential[q] <= potential[p] + max_dist:
                    q += 1
                
                if q - p >= k:  # if range contains enough huizen => max_dist is possible
                    return True
            
                p += 1

            i += 1

    dist = 0
    jump = max(max(x[0], x[1]) for x in huizen) - min(min(x[0], x[1]) for x in huizen)

    # Binary search
    while jump > 0:
        while not possible(dist + jump):
            dist += jump
        jump //= 2
    
    print("{0} {1}".format(nr, dist + 1))
