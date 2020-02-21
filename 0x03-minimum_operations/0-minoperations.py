#!/usr/bin/python3
""" there is a single character H. Your text editor can execute only two
    operations in this file: Copy All and Paste.
    Given a number n, write a method that calculates the fewest number of
    operations needed to result in exactly n H characters in the file.

    Returns an integer
    If n is impossible to achieve, return 0
"""


def minOperations(n):
    """ Start the depth-first search after checking for valid input
        Args:
            n(int): target value to achieve
    """
    if n <= 1:
        return 0
    if n == 2:
        return 2
    return len(dfs(2, 1, n, ['c', 'p']))


def dfs(curr, prev, n, ops):
    """ Depth-first search to achieve minimum amount of operations to reach 'n'
        Args:
            curr(int): current value of characters in the file
            prev(int): previous value of characters in the file, used to
                       perform operations
               n(int): target value to satisfy
            ops(list): list of operations enacted to achieve target value
    """
    if curr == n:
        """ Base case """
        return ops
    if curr > n:
        """ Invalid amount of operations """
        return None
    """ Start / continue recursive tree, saving amount of operations done """
    return dfs(curr * 2, curr, n, ops + ['c', 'p']) or\
        dfs(curr + prev, prev, n, ops + ['p'])
