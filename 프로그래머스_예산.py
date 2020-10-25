def solution(d, budget):
    answer = 0
    d.sort()
    
    li=[]

    if sum(d) <= budget:
        answer=len(d)
        
    else:
        for i in d: 
            li.append(i)            # sum 반복되면 시간복잡도 증가, num += i
            
            if sum(li) > budget:
                break
                
            answer+=1
        
    return answer
