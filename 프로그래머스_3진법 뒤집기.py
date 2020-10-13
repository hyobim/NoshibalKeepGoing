def solution(n):
    answer = 0
    num=[]
    
    while True:
        if n<3:
            num.append(n)
            break
        num.append(n%3)
        n=int(n/3)           # n=n//3
        

    l=len(num)-1
    
    for i in num:
        answer+=i*3**(l)
        l-=1
        
    return answer
