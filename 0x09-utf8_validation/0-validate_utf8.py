#!/usr/bin/python3
"""UTF8"""


def validUTF8(data):
    """Validation utf8"""
    n_bytes = 0

    for i in data:
        bin_repre = format(i, '#010b')[-8:]

        if n_bytes == 0:
            for j in bin_repre:
                if j == '0':
                    break
                n_bytes += 1
            if n_bytes == 0:
                continue

            if n_bytes == 1 or n_bytes > 4:
                return False

        else:
            if not (bin_repre[0] == '1' and bin_repre[1] == '0'):
                return False

        n_bytes -= 1
    return n_bytes == 0
