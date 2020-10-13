def solution(s):
    idx=0
    li=[]
    for i in s:
        if i==' ':
            idx=-1
            
        if idx%2==0:
            li.append(i.upper())
        else:
            li.append(i.lower())
        
        idx+=1
    
    return ''.join(li)  
