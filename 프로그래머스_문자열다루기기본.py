def solution(s):

    return True and s.isdecimal() if len(s)==4 or len(s)== 6 else False  # return s.isdigit() and len(s) in (4, 6)
    # isdecimal() - 일반적인 숫자, isdigit() - ‘숫자처럼 생긴’ 모든 글자 ex) 특수문자
