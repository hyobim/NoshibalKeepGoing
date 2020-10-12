def solution(strings, n):
    
    return sorted(sorted(strings), key=lambda x: x[n])  # return sorted(sorted(strings), key=itemgetter(n)) sorted key 지정 가능
