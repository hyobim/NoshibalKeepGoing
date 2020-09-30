def solution(board, moves):
    answer = 0
    stack=[0]
    
    for i in moves:
        for j in range(len(board)):
            if board[j][i-1]!=0:
                if board[j][i-1]==stack[-1]:
                    stack.pop()
                    board[j][i-1]=0
                    answer+=2
                    break
                    
                else:
                    stack.append(board[j][i-1])
                    board[j][i-1]=0
                    break
    
    return answer
