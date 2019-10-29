# Python  program to solve N Queen using backtracking 

#change N in increase Number of Queens as well as size of board in NxN patttern
global N 
N =50

def printSolution(board): 
	for i in range(N): 
		for j in range(N): 
			print (board[i][j], end = " ") 
		print() 

# A  function to check if a queen can be placed on board. 

def Safe(board, row, col): 

	# Check row on left side 
	for i in range(col): 
		if board[row][i] == 1: 
			return False

	# Check upper diagonal on left side 
	for i, j in zip(range(row, -1, -1), 
					range(col, -1, -1)): 
		if board[i][j] == 1: 
			return False

	# Check lower diagonal on left side 
	for i, j in zip(range(row, N, 1), 
					range(col, -1, -1)): 
		if board[i][j] == 1: 
			return False

	return True

def SolveNQueen(board, col): 
	
	# base case: If all queens are placed  
	if col >= N: 
		return True

	# Consider this column and try placing this queen in all rows one by one 
	for i in range(N): 

		if Safe(board, i, col): 
			
			# Place this queen in board
			board[i][col] = 1

			# recursively place all next queens
			if SolveNQueen(board, col + 1) == True: 
				return True

			# remove queen if there are no valid solutions
			board[i][col] = 0

	# if queens cannot be placed 
	return False



# Initialize the board 
board = [ [0 for x in range(N)] for y in range(N)] 

#Call Solving Function
if SolveNQueen(board, 0) == False: 
	print ("Solution does not exist")

else:
    print("\n\n Solution :\n")
    printSolution(board) 
    print("\n\n")




