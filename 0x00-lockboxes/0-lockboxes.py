#!/usr/bin/python3


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""

    lengthBox = len(boxes)
    keys = []
    state = []

    for i in range(lengthBox):
        state.append(0)
    state[0] = 1

    for i in boxes[0]:
        keys.append(i)

    for key in keys:
        if key < lengthBox and state[key] == 0:
            state[key] = 1
        for j in boxes[key]:
            if j not in keys:
                keys.append(j)

    if 0 in state:
        return False
    else:
        return True
