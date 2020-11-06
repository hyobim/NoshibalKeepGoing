import math
def solution(w,h):
    answer = w*h
    sum=0
    for i in range(0,w//2): 
        sum+=math.ceil(h*(w-i)/w)-math.floor(h*(w-(i+1))/w)
    answer-=sum*2
    return answer
