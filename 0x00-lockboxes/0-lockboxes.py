#!/usr/bin/python3

def canUnlockAll(boxes):
    new = [False for i in range(len(boxes))]
    return checkBoxes(boxes, new, 0) == True

def checkBoxes(boxes, new, index):
    if new[index] == True:
        return False
    new[index] = True
    for i in range(len(boxes[index])):
        checkBoxes(boxes, new, boxes[index][i])
    if False not in new:
        return True
    return False