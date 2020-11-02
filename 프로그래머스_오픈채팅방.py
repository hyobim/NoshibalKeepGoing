def solution(record):
    answer = {}
    li=[]

    for i in record:
        if "Enter" in i:
            answer[i.split()[1]]=i.split()[2]
        elif "Change" in i:
            answer[i.split()[1]]=i.split()[2]

    for i in record:
        if "Enter" in i:
            li.append(str(answer[i.split()[1]]+"님이 들어왔습니다."))
        elif "Leave" in i:
            li.append(str(answer[i.split()[1]]+"님이 나갔습니다."))

    return li
