#!/usr/bin/python3
""" You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and each box may contain
    keys to the other boxes.
    Write a method that determines if all the boxes can be opened.

    Examples:
        [[1], [2], [3], [4], []] => return True

        [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]] => return True

        [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]] => return False
"""


def canUnlockAll(boxes):
    """ canUnlockAll - Return true if all boxes can be opened, false if not.
        attrs:
            boxes (List of lists): Boxes with list indicies that 'open' other
                                   boxes.
    """
    new = [False for i in range(len(boxes))]
    return checkBoxes(boxes, new, 0) is True


def checkBoxes(boxes, new, index):
    """ checkBoxes - Recursively check the path of keys unlocking boxes.
        attrs:
            boxes (List of lists): Boxes with list indicies that 'open' other
                                   boxes.
                       new (list): List of booleans to 'mark' each box at a
                                   specific index.
                       index(int): Index to a box to check through keys.
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
