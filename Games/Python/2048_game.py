import random
import os

def initialize_board():
    board = [[0] * 4 for _ in range(4)]
    add_random_tile(board)
    add_random_tile(board)
    return board

def add_random_tile(board):
    empty_cells = [(i, j) for i in range(4) for j in range(4) if board[i][j] == 0]
    if empty_cells:
        i, j = random.choice(empty_cells)
        board[i][j] = random.choice([2, 4])

def print_board(board):
    os.system('cls' if os.name == 'nt' else 'clear')
    for row in board:
        print(' '.join(str(cell) if cell != 0 else '.' for cell in row))
    print()

def move(board, direction):
    rotated_board = rotate_board(board, direction)
    merged_board = merge_tiles(rotated_board)
    new_board = rotate_board(merged_board, 4 - direction)
    if board != new_board:
        add_random_tile(new_board)
    return new_board

def rotate_board(board, times):
    return [list(row) for row in zip(*board[::-1])] if times % 4 != 0 else board

def merge_tiles(board):
    for row in board:
        for i in range(3):
            if row[i] == row[i + 1] and row[i] != 0:
                row[i] *= 2
                row[i + 1] = 0
    return board

if __name__ == '__main__':
    board = initialize_board()

    while True:
        print_board(board)
        move_direction = input("Enter move (W/A/S/D): ").upper()

        if move_direction == 'W':
            board = move(board, 1)
        elif move_direction == 'A':
            board = move(board, 2)
        elif move_direction == 'S':
            board = move(board, 3)
        elif move_direction == 'D':
            board = move(board, 0)
        else:
            print("Invalid move. Use W/A/S/D.")

        # Check for game over condition
        if all(cell != 0 for row in board for cell in row):
            print("Game Over! No more moves left.")
            break
