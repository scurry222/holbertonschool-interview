#!/usr/bin/python3

"""
    print coordinates of queens that arent attacking each other
    Args:
        n: passed in number, > 4, that will be the size of the chessboard
        board: row and column grid
        row: x axis
        col: y axis
"""


def isSafe(board, row, col):
    """check if queens placed are attacking"""
    for c in range(col):
        if board[c] is row or abs(board[c] - row) is abs(c - col):
            return False
    return True


def checkBoard(board, col):
    """recursively place queens on board until end of board"""
    n = len(board)
    if col is n:
        print(str([[c, board[c]] for c in range(n)]))
        return
    for row in range(n):
        if isSafe(board, row, col):
            board[col] = row
            checkBoard(board, col + 1)

if __name__ == "__main__":
    """read from stdin"""
    import sys
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    n = 0
    """display errors"""
    try:
        n = int(sys.argv[1])
    except:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    """set up board"""
    board = [0 for x in range(n)]
    checkBoard(board, 0)
