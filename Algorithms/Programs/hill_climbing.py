import random

def copy_state(first_state, second_state):
    for i in range(int(len(first_state))):
        first_state[i] = second_state[i]

# Function to generate random positions on
# board, according to given state
def generate_board(board, state):
    boardSize = int(len(board))
    board = [[0 for j in range(boardSize)] for i in range(boardSize)]
    for i in range(boardSize):
        board[state[i]][i] = 1
    return board

# Function to calculate total Attacks
# (i.e. queen count that can attack each other)
def calculate_objective(board, state):
    
    attacking = 0
    row = 0
    col = 0
    boardSize = int(len(board))
    
    for i in range(boardSize):
        row = state[i]
        col = i - 1
       
        while col >= 0 and board[row][col] != 1:
            col -= 1
        if col >= 0 and board[row][col] == 1:
            attacking += 1
        row = state[i]
        col = i + 1
        
        while col < boardSize and board[row][col] != 1:
            col += 1
        if col < boardSize and board[row][col] == 1:
            attacking += 1
        row = state[i] - 1
        col = i - 1
        
        while col >= 0 and row >= 0 and board[row][col] != 1:
            col -= 1
            row -= 1
        if col >= 0 and row >= 0 and board[row][col] == 1:
            attacking += 1
        row = state[i] + 1
        col = i + 1
       
        while col < boardSize and row < boardSize and board[row][col] != 1:
            col += 1
            row += 1
        if col < boardSize and row < boardSize and board[row][col] == 1:
            attacking += 1
        row = state[i] + 1
        col = i - 1
       
        while col >= 0 and row < boardSize and board[row][col] != 1:
            col -= 1
            row += 1
        if col >= 0 and row < boardSize and board[row][col] == 1:
            attacking += 1
        row = state[i] - 1
        col = i + 1
        
        while col < boardSize and row >= 0 and board[row][col] != 1:
            col += 1
            row -= 1
        if col < boardSize and row >= 0 and board[row][col] == 1:
            attacking += 1
   
    return attacking // 2
    
    
# Function to print the board as final solution
def print_board(board):
    boardSize = int(len(board))
    for i in range(boardSize):
        for j in range(boardSize):
            print(board[i][j], end=" ")
        print()


# Function to get optimal neighbour
# of given state, objective value wise (least on priority).
def get_neighbour(board, state):
    boardSize = int(len(board))

    
    optimal_board = [[0 for j in range(boardSize)] for i in range(boardSize)]
    optimal_state = [0 for i in range(boardSize)]

   
    copy_state(optimal_state, state)
    optimal_board = generate_board(optimal_board, optimal_state)

    
    optimalObjective = calculate_objective(optimal_board, optimal_state)

    neighbourBoard = [[0 for j in range(boardSize)] for i in range(boardSize)]
    neighbourState = [0 for i in range(boardSize)]

    copy_state(neighbourState, state)
    neighbourBoard = generate_board(neighbourBoard, neighbourState)

    
    for i in range(boardSize):
        for j in range(boardSize):
         
            if j != state[i]:
                neighbourState[i] = j
                neighbourBoard[neighbourState[i]][i] = 1
                neighbourBoard[state[i]][i] = 0

               
                temp = calculate_objective(neighbourBoard, neighbourState)
                # Comparing both, newly obtained and previous optimal objective
                if temp <= optimalObjective:
                   
                    optimalObjective = temp
                    copy_state(optimal_state, neighbourState)
                    optimal_board = generate_board(
                        optimal_board, optimal_state)
                # Setting values to handle next iteration
                neighbourBoard[neighbourState[i]][i] = 0
                neighbourState[i] = state[i]
                neighbourBoard[state[i]][i] = 1

   
    copy_state(state, optimal_state)
    board = [[0 for j in range(boardSize)] for i in range(boardSize)]
    board = generate_board(board, state)

# compare the current and neighbour states
def compare_states(first_state, second_state):
    for i in range(int(len(first_state))):
        if first_state[i] != second_state[i]:
            return False
    return True



def solve_hill_climbing(board, state):
    boardSize = int(len(board))
    
    neighbourBoard = [[0 for j in range(boardSize)] for i in range(boardSize)]
    neighbourState = [0 for i in range(boardSize)]

   
    copy_state(neighbourState, state)
    neighbourBoard = generate_board(neighbourBoard, neighbourState)

    # loop until you get optimal solution
    while True:
        
        copy_state(state, neighbourState)
        board = generate_board(board, state)

        
        get_neighbour(neighbourBoard, neighbourState)

       
        if compare_states(state, neighbourState):
            print_board(board)
            break
      
        elif calculate_objective(board, state) == calculate_objective(neighbourBoard, neighbourState):
            neighbourState[random.randint(
                0, boardSize - 1)] = random.randint(0, boardSize - 1)
            neighbourBoard = generate_board(neighbourBoard, neighbourState)


if __name__ == "__main__":
    size = 4
    try:
        size = int(input("Enter board size "))
        size = size if size > 0 else 4
    except:
        pass
    if size == 2 or size == 3:
        print("Not Possible")
    else:
       
        state = [0 for i in range(size)]
        board = [[0 for j in range(size)] for i in range(size)]

        boardSize = int(len(board))
        for i in range(boardSize):
            state[i] = random.randint(0, boardSize - 1)
            board[state[i]][i] = 1
       
        solve_hill_climbing(board, state)
