#!/usr/bin/python3


def rain(walls):
    wall_len = len(walls)
    if wall_len == 0:
        return 0
    count = 0
    for i in range(1, wall_len - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for j in range(i + 1, wall_len):
           right = max(right, walls[j])
        count = count + (min(left, right) - walls[i])
    return count
