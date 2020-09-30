def solution(numbers):
    answer = []
    
    for i in range(len(numbers)):
        for j in range(len(numbers)-i-1):
            answer.append(numbers[i]+numbers[i+j+1])
    
    answer=set(answer)     # return sorted(list(set(answer))) 가능
    answer=list(answer)
    answer.sort()
    
    return answer
