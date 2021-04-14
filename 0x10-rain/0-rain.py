#!/usr/bin/python3

def rain(walls):
    if len(walls) == 0:
        return 0
    new_list = []
    for i in range(len(walls)):
        if i > 0 and i < len(walls) - 2:
            new_list.append(walls[i])
    suma = sum(new_list)
    return suma
