#!/usr/bin/python3

import sys

if (len(sys.argv) != 2):
    print('Usage: nqueens N')
    exit(1)
else:
    try:
        N = int(sys.argv[1])
        if (N < 4):
            print('N must be at least 4')
            exit(1)
    except ValueError:
        print('N must be a number')
        exit(1)

board = [[0] * N for x in range(N)]


def attack_fun(i, j):
    for k in range(0, N):
        if board[i][k] == 1 or board[k][j] == 1:
            return True

    for k in range(0, N):
        for l in range(0, N):
            if (k + l == i + j) or (k - l == i - j):
                if board[k][l] == 1:
                    return True
    return False


def N_queen(n):
    if n == 0:
        return True
    for i in range(0, N):
        for j in range(0, N):
            if (not(attack_fun(i, j))) and (board[i][j] != 1):
                board[i][j] = 1
                if (N_queen(n - 1) is True):
                    return True
                board[i][j] = 0

    return False

N_queen(N)
for i in board:
    print(i)
