#!/usr/bin/python3
""" You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and each box may contain
    keys to the other boxes.
    Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """ canUnlockAll - return true if all boxes can be opened, false if not
        attrs:
            boxes (List of lists): boxes with list indicies that 'open' other
                                   boxes
    """
    new = [False for i in range(len(boxes))]
    return checkBoxes(boxes, new, 0) is True


def checkBoxes(boxes, new, index):
    """ checkBoxes - recursively check path of key
        attrs:
            boxes (List of lists): boxes with list indicies that 'open' other
                                   boxes
                       new (list): list of booleans to 'mark' each box at a
                                    specific index
                       index(int): index to a box to check through 'keys'
    """
    if new[index] is True:
        # print("nope! go back...")
        return False
    new[index] = True
    # print(new)
    for i in range(len(boxes[index])):
        if False not in new:
            # print("done!")
            return True
        # print(i, boxes[index], boxes[index][i])
        checkBoxes(boxes, new, boxes[index][i])
    return False
