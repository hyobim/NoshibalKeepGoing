import operator
def solution(progresses, speeds):
    answer = []
    cnt=0
    while progresses:
        if progresses[0]>=100:
            progresses.pop(0)
            speeds.pop(0)
            cnt+=1
        else:
            if cnt>0:
                answer.append(cnt)
                cnt=0
            progresses=list(map(operator.add, progresses, speeds))
    answer.append(cnt)

    return answer
    
# 다른 사람 풀이
def solution(progresses, speeds):
    Q=[]
    for p, s in zip(progresses, speeds):
        if len(Q)==0 or Q[-1][0]<-((p-100)//s):
            Q.append([-((p-100)//s),1])
        else:
            Q[-1][1]+=1
    return [q[1] for q in Q]
