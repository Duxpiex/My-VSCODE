# 윤년 구하기, 윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때다.

Year = int(input())

if((Year%4==0) and (Year%100!=0) or (Year%400==0) ):
    print('1')

else:
    print('0')