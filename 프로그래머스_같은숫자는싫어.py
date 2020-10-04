def solution(arr):
    answer = []
    pre=-1
    
    for i in arr:
        if pre!=i:
            answer.append(i)
        pre=i
        
    return answer
