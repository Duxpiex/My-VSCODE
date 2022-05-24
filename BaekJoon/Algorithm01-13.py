A = int(input()) # 첫번째 입력받은 문자 : 숫자로 변환
B = input() # 두번째 입력받은 문자 : 문자열로 놔둠

# 문자열의 인덱스를 이용해서 두번째 입력받은 문자를 하나씩 숫자로 반환하고 A와 곱한다
AxB2 = A * int(B[2]) # A와 B의 1의자리 숫자
AxB1 = A * int(B[1]) # A와 B의 10의 자리 숫자
AxB0 = A * int(B[0]) # A와 B의 100의 자리 숫자
AxB = A * int(B) # A와 B 그대로 곱함

print(AxB2, AxB1, AxB0, AxB, sep='\n')
