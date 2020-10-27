def solution(n, arr1, arr2):
    answer = []
    
    for i,j in zip(arr1,arr2):
        ans=""
        for k in range(n):
            if i%2==0 and j%2==0:
                ans+=" "
            else:
                ans+="#"
            i=i//2
            j=j//2
            
        answer.append(ans[::-1])
        
    return answer
    
# 숏코딩

def solution(n, arr1, arr2):
    answer = []
    for i,j in zip(arr1,arr2):
        a12 = str(bin(i|j)[2:])
        a12=a12.rjust(n,'0')
        a12=a12.replace('1','#')
        a12=a12.replace('0',' ')
        answer.append(a12)
    return answer
