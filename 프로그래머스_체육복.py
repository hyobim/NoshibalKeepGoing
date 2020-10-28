def solution(n, lost, reserve):
    li=set(lost) & set(reserve)
    lost=list(set(lost)-li)
    reserve=list(set(reserve)-li)
    ridx,lidx=0,0

    for i in range(ridx,len(reserve)):
        for j in range(lidx,len(lost)):
            if abs(reserve[i]-lost[j])<=1:
                ridx+=1
                lidx+=1
                n+=1
                break

    return n-len(lost)

# 다른 사람 풀이
def solution(n, lost, reserve):
    _reserve = [r for r in reserve if r not in lost]
    _lost = [l for l in lost if l not in reserve]
    for r in _reserve:
        f = r - 1
        b = r + 1
        if f in _lost:
            _lost.remove(f)
        elif b in _lost:
            _lost.remove(b)
    return n - len(_lost)
