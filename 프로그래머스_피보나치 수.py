def solution(n):
    li=[0,1]
    
    for i in range(2,n+1):
        li.append(li[i-1]+li[i-2])
    
    return li[n]%1234567


# 훨씬 효율적인 코드

def solution(n):
    a,b = 0,1
    
    for i in range(n):
        a,b = b,a+b
    
    return a%1234567
