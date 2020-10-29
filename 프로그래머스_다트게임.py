def solution(dartResult):
    answer = []
    num=""

    for i in dartResult:
        if i=='S':
            answer.append(int(num))
            num=""
        elif i=='D':
            answer.append(int(num)**2)
            num=""
        elif i=='T':
            answer.append(int(num)**3)
            num=""
        elif i=='*':
            answer[-1]*=2
            if len(answer)>1:
                answer[-2]*=2
        elif i=='#':
            answer[-1]*=(-1)
        else:
            num+=i

    return sum(answer)
    
    # 다른 사람 풀이, 정규표현식 사용
    
import re

def solution(dartResult):
    bonus = {'S' : 1, 'D' : 2, 'T' : 3}
    option = {'' : 1, '*' : 2, '#' : -1}
    p = re.compile('(\d+)([SDT])([*#]?)')
    dart = p.findall(dartResult)
    for i in range(len(dart)):
        if dart[i][2] == '*' and i > 0:
            dart[i-1] *= 2
        dart[i] = int(dart[i][0]) ** bonus[dart[i][1]] * option[dart[i][2]]

    answer = sum(dart)
    return answer
