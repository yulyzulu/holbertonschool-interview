#!/usr/bin/python3

import signal
import sys


def signal_fun(size, status_list):
    print('File size: {}'.format(size))
    for k, v in sorted(status_list.items()):
        if v != 0:
            print('{}: {}'.format(k, v))

status_list = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
               "405": 0, "500": 0}
size = 0
count = 1

try:
    for line in sys.stdin:
        tok = line.split()

        if len(tok) > 2:
            file_status = tok[-1]
            status_c = tok[-2]
            size = size + int(file_status)

            if status_c in status_list:
                status_list[status_c] = status_list[status_c] + 1

        if count % 10 == 0:
            print('File size: {}'.format(size))
            for k, v in sorted(status_list.items()):
                if v != 0:
                    print('{}: {}'.format(k, v))
        count = count + 1

except KeyboardInterrupt:
    pass

finally:
    signal_fun(size, status_list)
