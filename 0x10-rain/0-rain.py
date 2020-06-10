#!/usr/bin/python3

""" Module for rainwater algorithm
"""


def rain(walls):
    """ Calculate how much water will be retained after it rains """

    prev_wall = walls[0]
    prev_index = max_retained = temp = 0

    for i in range(1, len(walls)):
        if walls[i] >= prev_wall:
            prev_wall = walls[i]
            prev_index = i
            temp = 0
        else:
            max_retained += prev_wall - walls[i]
            temp += prev_wall - walls[i]

    if prev_index < len(walls):
        max_retained -= temp
        prev_wall = walls[len(walls)-1]

        for i in range(len(walls) - 1, prev_index - 1, -1):
            if walls[i] >= prev_wall:
                prev_wall = walls[i]
            else:
                max_retained += prev_wall - walls[i]

    return max_retained
