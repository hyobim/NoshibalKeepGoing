import time
start = time.time()  # 시작 시간 저장

cnt=0
tmp=0

for i in range(1,1000):
  num=i
  while num:
    tmp=0
    for i in str(num):
      tmp+=int(i)**2
  
    if tmp==1 or tmp==89:
      break

    num=tmp
  
  if tmp==89:
    cnt+=1

print('1~1000 중 89에 도달하는 수:',cnt) # 857
print("time :", time.time() - start)
