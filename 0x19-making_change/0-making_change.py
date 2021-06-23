#!/usr/bin/python3
""" Making change"""

def makeChange(coins, total):
    """Given a pile of coins of different values,
        determine the fewest number of coins needed
        to meet a given amount total."""
    min_coins = 0
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    while (total > 0 and coins):
        n = int(total / coins[0])
        total = total - (coins[0] * n)
        min_coins = min_coins + n
        coins.remove(coins[0])
    if total != 0:
        return -1
    return min_coins
