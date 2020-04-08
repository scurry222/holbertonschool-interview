#!/usr/bin/python3


def validUTF8(data):
    """ Determine if data set represents a valid UTF-8 encoding  """
    bytes = 0
    for bit in data:
        mask = 1 << 7
        if bytes == 0:
            while mask & bit:
                bytes += 1
                mask >>= 1
            if bytes == 0:
                continue
            if bytes == 1 or bytes > 4:
                return False
        else:
            if bit >> 6 != 2:
                return False
        bytes -= 1
    return bytes == 0
