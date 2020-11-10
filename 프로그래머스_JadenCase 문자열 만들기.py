def solution(s):
    answer = ""
    s=s.lower().split(' ')
    
    for i in s:
        i= i.capitalize()
        answer+= i+" "
        
    return answer[:-1]
