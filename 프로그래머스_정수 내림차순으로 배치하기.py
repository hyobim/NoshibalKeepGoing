def solution(n):
    return int(''.join(sorted(list(str(n)), reverse=True)))  # list 안해도 sorted하면 list로 반환
