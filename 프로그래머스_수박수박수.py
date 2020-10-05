def solution(n):
    s='수박'
    return s*(n//2) if n%2==0 else s*(n//2) + s[0]
