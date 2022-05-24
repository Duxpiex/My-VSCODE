from math import factorial as fact
from statistics import median, mean, variance, stdev

if __name__ == '__main__':
    for i in range(1, 21, 5):
        print('{:2d}! = {}'.format(i, fact(i)))
        
    lst = [80, 99, 77, 65, 92, 74, 82]
    print(); print(lst)
    print('중앙 값: %.2f' % median(lst)) #중앙값
    print('평균: %.2f' % mean(lst)) #평균
    print('분산: %.2f' % variance(lst)) #분산
    print('표준편차: %.2f' % stdev(lst)) #표준편차
