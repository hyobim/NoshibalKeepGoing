def solution(s):
    li=list(map(int,s.split()))
    
    return str(min(li))+" "+str(max(li))
