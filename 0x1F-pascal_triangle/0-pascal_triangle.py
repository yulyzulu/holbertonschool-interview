#!/usr/bin/python3
""" Pascal triangle method"""


def pascal_triangle(n):
    """Function that returns a list of lists of integers
        representing the Pascal's triangle of n"""
    list1 = []
    if (n <= 0):
        return list1
    for i in range(1, (n + 1)):
        list2 = []
        for j in range(i):
            list2.append(1)
        list1.append(list2)
    for i in range(len(list1)):
        for j in range(i):
            if j != 0:
                list1[i][j] = list1[i - 1][j] + list1[i - 1][j - 1]
    return list1
