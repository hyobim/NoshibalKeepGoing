# 해시문제, 조합 사용, K개의 옷 종류, 각 종류에서 n개의 옷 중 1개 선택 -> nC1 , 각 종류마다 적용해서 곱하기, 아무것도 안 입는 경우 -1

def solution(clothes):
    answer = 1
    category=[]
    names=[]

    for i in clothes:
        if i[1] not in category:
            category.append(i[1])
            names.append([])

    for i in clothes:
        if i[1] in category:
            names[category.index(i[1])].append(i[0])

    for i in names:
        answer*=(len(i)+1)

    return answer-1
    
# 다른 사람 코드

def solution(clothes):
    from collections import Counter
    from functools import reduce
    cnt = Counter([kind for name, kind in clothes])
    answer = reduce(lambda x, y: x*(y+1), cnt.values(), 1) - 1
    
    return answer
