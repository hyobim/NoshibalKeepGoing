def solution(s):
    s=s.lower()
    val=0
    
    for i in s:
        if i=='p':
            val+=1
        elif i=='y':
            val-=1
            
    if val==0:
        return True
    else:
        return False      # return s.lower().count('p') == s.lower().count('y')
