import time
start = time.time()  # 시작 시간 저장

cnt=0
tmp=0
s1={1} # 집합
s89={89}

for i in range(1,1000):
  num=i

  if num in s89:
    cnt+=1
  
  elif num in s1:
    continue

  else:
    s = set() # 빈 집합 생성
    while num:
      tmp=0
      s.add(num)

      for i in str(num):
        tmp+=int(i)**2

      if tmp in s1:
        s1 = s1.union(s) # 합집합
        break

      elif tmp in s89:
        s89=s89.union(s)
        cnt+=1
        break

      num=tmp
  

print('1~1000 중 89에 도달하는 수:',cnt) # 857
print("time :", time.time() - start) # 0.005816
