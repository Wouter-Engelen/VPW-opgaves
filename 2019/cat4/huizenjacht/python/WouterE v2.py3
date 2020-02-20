# Binary search + 2-pointer technique + Segment tree
# ~ O(n * log(n)^2)

# wedstrijd.invoer in 13.76s
# test case with n = 42K in 63s

class Struct:
    def __init__(self, **entries):
        self.__dict__.update(entries)

def smallest_power_of_two_bigger_than(x):
    x -= 1
    x |= x >> 1
    x |= x >> 2
    x |= x >> 4
    x |= x >> 8
    x |= x >> 16
    return x + 1

for nr in range(1, int(input()) + 1):
    n, k = [int(x) for x in input().split()]
    segment_tree_size = smallest_power_of_two_bigger_than(n) * 2

    huizen = [[int(x) for x in input().split()] for _ in range(n)]
    huizen = [Struct(nr = x, x = huizen[x][0], y = huizen[x][1], xpy = huizen[x][0] + huizen[x][1], xmy = huizen[x][0] - huizen[x][1]) for x in range(n)]

    # list of huizen sorted by x + y and x - y
    xpy = list(sorted(huizen, key=lambda huis: huis.xpy))
    xmy = list(sorted(huizen, key=lambda huis: huis.xmy))

    # Segment tree: update range of values with 'change' in log(n)
    def range_update(segment_tree, update_range, change, node = 1, node_min = 0, node_max = n - 1):
        if segment_tree[node].lazy:
            segment_tree[node].max += segment_tree[node].lazy
            
            if node_min != node_max:
                segment_tree[node * 2].lazy += segment_tree[node].lazy
                segment_tree[node * 2 + 1].lazy += segment_tree[node].lazy
            
            segment_tree[node].lazy = 0

        if update_range.max < node_min or node_max < update_range.min:
            return
        if update_range.min <= node_min and node_max <= update_range.max:
            segment_tree[node].max += change

            if node_min != node_max:
                segment_tree[node * 2].lazy += change
                segment_tree[node * 2 + 1].lazy += change
        else:
            d = (node_min + node_max) // 2

            range_update(segment_tree, update_range, change, node * 2, node_min, d)
            range_update(segment_tree, update_range, change, node * 2 + 1, d + 1, node_max)
            segment_tree[node].max = max(segment_tree[node * 2].max, segment_tree[node * 2 + 1].max)

    # Segment tree: return max of all values
    def range_max(segment_tree):
        return segment_tree[1].max

    # Are there k houses within max_dist from eachother?
    def possible(max_dist):
        ranges = [Struct(min = 0, max = 0) for _ in range(n)]
        
        # 2-pointer technique: for every house y find the largest interval f_y = [x, y] so that abs(huis[x].xpy - huis[y].xpy) <= max_dist
        left, right = 0, 0
        while left < n:
            while right < n and abs(xpy[left].xpy - xpy[right].xpy) <= max_dist:
                ranges[xpy[right].nr].min = left
                right += 1

            ranges[xpy[left].nr].max = left
            left += 1
        
        frequencies = [Struct(max = 0, lazy = 0) for _ in range(segment_tree_size)]

        # 2-pointer technique:  for every house y find the largest interval [x, y] so that abs(huis[x].xmy - huis[y].xmy) <= max_dist
        #                       for every a in [x, y]: for every b in f_y(a): frequencies[a]++
        #                       if max(frequencies) >= k   <=>   there is a house within k intervals   <=>   there is a interval with k houses   <=>   'max_dist' is possible
        left, right = 0, 0
        while right < n:
            while right < n and abs(xmy[left].xmy - xmy[right].xmy) <= max_dist:
                range_update(frequencies, ranges[xmy[right].nr], 1)
                right += 1
            
            if range_max(frequencies) >= k:
                return True
            
            range_update(frequencies, ranges[xmy[left].nr], -1)
            left += 1
        
        return False

    dist = -1
    jump = max(max(huis.x, huis.y) for huis in huizen) - min(min(huis.x, huis.y) for huis in huizen)

    # Binary search
    while jump > 0:
        while not possible(dist + jump):
            dist += jump
        jump //= 2
    
    print("{0} {1}".format(nr, dist + 1))
