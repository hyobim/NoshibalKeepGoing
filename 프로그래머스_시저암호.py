def solution(s, n):
    answer = ''
    li=[]
    for i in s:                                           # 대문자 65~90, 소문자: 97~122 
        if 65<=ord(i)<=90:                                # li.append(chr((ord(i)-ord('A')+ n)%26+ord('A')))
            if ord(i)+n>90:
                li.append(chr(ord(i)+n-26))
            else:
                li.append(chr(ord(i)+n))

        elif 97<=ord(i)<=122:                             # li.append(chr((ord(i)-ord('a')+ n)%26+ord('a')))
            if ord(i)+n>122:
                li.append(chr(ord(i)+n-26))
            else:
                li.append(chr(ord(i)+n))

        else:
            li.append(i)

    return ''.join(li)
