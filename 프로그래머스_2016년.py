def solution(a, b):
    day=['FRI','SAT','SUN','MON','TUE','WED','THU']
    mon=[31,29,31,30,31,30,31,31,30,31,30,31]

    for i in range(a-1):
        b+=mon[i]

    return day[b%7-1] # return day[(b+sum(mon[:a-1]))%7-1]
