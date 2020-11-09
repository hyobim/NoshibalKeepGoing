def solution(brown, yellow):
    a = 1
    b = -(brown//2+2)
    c = brown+yellow

    return sorted([int((-b + (b ** 2 - 4 * a * c) ** 0.5) // (2 * a)),
                  int((-b - (b ** 2 - 4 * a * c) ** 0.5) // (2 * a))],reverse=True)
