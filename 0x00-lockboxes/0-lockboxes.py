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
    if not boxes or not isinstance(boxes, list):
        return False
    if not len(boxes):
        return True
    stack = [0]
    verify = [False] * len(boxes)
    verify[0] = True
    while stack:
        node = stack.pop()
        for el in boxes[node]:
            try:
                if isinstance(el, int) and el >= 0 and el < len(boxes)\
                 and not verify[el]:
                    verify[el] = True
                    stack.append(el)
            except Exception:
                pass
    return all(verify)

# def canUnlockAll(boxes):
#     """ canUnlockAll - Return true if all boxes can be opened, false if not.
#         attrs:
#             boxes (List of lists): Boxes with list indicies that 'open' other
#                                    boxes.
#     """
#     new = [False for i in range(len(boxes))]
#     try:
#         return checkBoxes(boxes, new, 0) is True
#     except:
#         return False

# def checkBoxes(boxes, new, index, debug=True):
#     """ checkBoxes - Recursively check the path of keys unlocking boxes.
#         attrs:
#             boxes (List of lists): Boxes with list indicies that 'open' other
#                                    boxes.
#                        new (list): List of booleans to 'mark' each box at a
#                                    specific index.
#                        index(int): Index to a box to check through keys.
#     """
#     debug and print("calling...")
#     debug and print(new)
#     if new[index] is True:
#         debug and print("nope! go back...", boxes[index])
#         return False
#     new[index] = True
#     for i in range(len(boxes[index])):
#         debug and print(i, boxes[index], boxes[index][i])
#         checkBoxes(boxes, new, boxes[index][i])
#     if False not in new:
#         debug and print("done!", new, index)
#         return True
#     return False
