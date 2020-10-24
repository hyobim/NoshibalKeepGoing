#2775번
'''
T = int(input()) #테스트케이스 갯수
count=0

while True:
    k=int(input())
    n=int(input())
    ans=0
    add=[]
    for j in range (1,n+1):
        ans=ans+j
        add.append(ans)
    if(k==1):
        print(ans)
        count=count+1
        if(count==T):
            break
    else:
        for h in range(1,k):
            ans=0
            for i in range (0,n):
                ans=add[i]+ans
                add[i]=ans

        print(ans)
        count=count+1
        if(count==T):
            break

'''
for _ in range(10):
    print("hyobin")
n=[]

a=int(input())
r=sum ([int (i) for i in str(a)])
print(r)
n.append(sum([int(j)for j in str(a)]))
print(n)

'''
다른사람 코드
1. python은 펙토리얼 함수가 내장되어있다 (이용할수있으면 줄일수있음)
2.

t = int(input())

for _ in range(t):
  k = int(input())
  n = int(input())
  a = [i for i in range(1, n+1)] ##이부분기억할것 
  for _ in range(k):
    for j in range(1, n):
      a[j] += a[j-1]
  print(a[-1])

  길이도 짧고 보기좋은 코드 
'''
