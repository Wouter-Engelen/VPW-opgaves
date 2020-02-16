ncases = int(input())

for index in range(1, ncases+1):
    room_size = int(input())
    nlemmings = int(input())
    lemmings = []
    solution = 0
    for _ in range(nlemmings):
        line = input()
        position = int(line[0:-1])
        direction = line[-1]
        if direction == 'L':
            solution = max(solution, position)
        else:
            solution = max(solution, 2 * room_size - position)
    print(f'{index} {solution}')
