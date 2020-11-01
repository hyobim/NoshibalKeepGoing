def solution(n, words):
    answer = [0,0]
    li=[]
    temp=""

    for i in range(len(words)):
        if words[i] in li:
            answer=[i%n+1,i//n+1]
            break
        elif temp!=words[i][0] and i>0:
            answer=[i%n+1,i//n+1]
            break
        li.append(words[i])
        temp=words[i][len(words[i])-1]

    return answer
    
# 다른사람풀이
def solution(n, words):
    for p in range(1, len(words)):
        if words[p][0] != words[p-1][-1] or words[p] in words[:p]: return [(p%n)+1, (p//n)+1]
    else:
        return [0,0]
