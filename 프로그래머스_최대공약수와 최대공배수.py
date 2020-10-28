def solution(n, m):
    nDiv=set()
    mDiv=set()

    for i in range(1,(n//2)+1):
        if n%i==0 and i not in nDiv:
            nDiv.add(i)
            nDiv.add(n//i)

    for i in range(1,(m//2)+1):
        if m%i==0 and i not in mDiv:
            mDiv.add(i)
            mDiv.add(m//i)

    comDiv=max(list(nDiv & mDiv))

    if comDiv==1:
        comMul=n*m
    elif comDiv==min(n,m):
        comMul=max(n,m)
    else:
        i=1
        while True:
            if (comDiv*i)%n==0 and (comDiv*i)%m==0:
                comMul=(comDiv*i)
                break;
            i+=1

    return [comDiv,comMul]
    
    # 숏코딩, 유클리드 호제법 
    # n = a % b, n = 0일 때, b가 최대공약수 
    # 최소공배수 = a*b/최대공약수
    
def gcdlcm(a, b):
    c, d = max(a, b), min(a, b)
    t = 1
    while t > 0:
        t = c % d
        c, d = d, t
    answer = [c, int(a*b/c)]

    return answer
    
    # 다른 방법
def gcdlcm(a, b):
    for i in range(a):
        if a%(a-i)+b%(a-i) == 0:
            return [a-i, a*b/(a-i)]
   
   # lamda, 재귀호출 사용
def solution(n, m):
    gcd = lambda a,b : b if not a%b else gcd(b, a%b)
    lcm = lambda a,b : a*b//gcd(a,b)
    return [gcd(n, m), lcm(n, m)]
