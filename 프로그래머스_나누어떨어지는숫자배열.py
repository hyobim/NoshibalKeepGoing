def solution(arr, divisor):
    answer = []
    
    for i in arr:
        if i%divisor==0:
            answer.append(i)
            
    if not answer:
        answer.append(-1)
    
    return sorted(answer)   # return sorted([i for i in arr if i%divisor == 0]) or [-1] 
                            # or 앞이 참일 경우 해당 값까지만 , 거짓일 경우 뒤에 것까지 호출
