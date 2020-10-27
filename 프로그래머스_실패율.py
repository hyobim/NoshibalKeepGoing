from collections import Counter

def solution(N, stages):
    answer = []
    num=0
    
    li=list(Counter(stages).items())
    temp=[i[0] for i in li]
    
    for i in range(1,N+1):
        if i not in temp:
            li.append((i,0))
    
    li=sorted(li, key=lambda kv: kv[0], reverse=True)
    
    for i in range(len(li)):
        num+=(li[i])[1]
        
        if (li[i])[0]>N:
            continue
            
        if (li[i])[1]==0 :
            answer.append((len(li)-i,0))
            
        else:
            answer.append((len(li)-i,(li[i])[1]/num))
    
    answer=sorted(answer,key=lambda x: (x[1],-x[0]), reverse=True)

    return [i[0] for i in answer]
    
    
# 숏코딩
def solution(N, stages):
    result = {}
    denominator = len(stages)
    
    for stage in range(1, N+1):
        if denominator != 0:
            count = stages.count(stage)           # count, 딕셔너리 사용
            result[stage] = count / denominator
            denominator -= count
            
        else:
            result[stage] = 0
            
    return sorted(result, key=lambda x : result[x], reverse=True)
