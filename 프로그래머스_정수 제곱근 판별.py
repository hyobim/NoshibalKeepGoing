def solution(n):

    return ((n**0.5)+1)**2 if n%(n**0.5)==0 else -1         # return ((n**0.5)+1)**2 if (n**0.5)**2==n else -1 이거는 안됨 
