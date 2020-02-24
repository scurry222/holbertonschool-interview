#!/usr/bin/python3
""" there is a single character H. Your text editor can execute only two
    operations in this file: Copy All and Paste.
    Given a number n, write a method that calculates the fewest number of
    operations needed to result in exactly n H characters in the file.
    Returns an integer
    If n is impossible to achieve, return 0
"""
import math


def minOperations(n):
    """ Efficient solution by reducing size of n recursively.
        Args:
            n(int): integer to count minimum amount of operations.
                    first n: value to match
                    last n: amount of minimum operations to reach first n
                            value.
    """
    if n <= 1:
        return 0
    for i in range(2, int(math.sqrt(n)) + 1):
        """ Iterate to root of n. If root doesnt exist, return n. """
        if n % i == 0:
            """ A divisor was found! make new n equal to half previous n,
                add iteration.
            """
            return minOperations(int(n / i)) + i
    return n
