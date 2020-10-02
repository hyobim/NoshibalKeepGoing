cnt=0
tmp=0

for i in range(1,1000):
  tmp=i
  while tmp:
    if len(str(tmp))>2: # 세자리수
      tmp = int(tmp/100)**2 + int(int(tmp/10)%10)**2 + int(tmp%10)**2
    elif len(str(tmp))>1: # 두자리수
      tmp = int(tmp/10)**2 + int(tmp%10)**2
    else: # 한자리수
      tmp = tmp**2
    
    if tmp==1 or tmp==89:
      break
  
  if tmp==89:
    cnt+=1

print('1~1000 중 89에 도달하는 수:',cnt) # 857
