def solution(prices):
    answer = []
    cnt=0
    for i in range(len(prices)):
        for j in range(i+1,len(prices)):
            if prices[i]<=prices[j]:
                cnt+=1
            else:
                cnt+=1
                break
        answer.append(cnt)
        cnt=0
        
    return answer
