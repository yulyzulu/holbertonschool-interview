#!/usr/bin/python3
""" Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """ Rotate 2d Matrix """
    N = len(matrix)

    for i in range(N):
        for j in range(i):
            temp = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = temp
    for i in range(N):
        for j in range(N // 2):
            temp = matrix[i][j]
            matrix[i][j] = matrix[i][N - j - 1]
            matrix[i][N - j - 1] = temp
