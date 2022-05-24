import math 
import random
def getarea(r):
    return r * r * math.pi
radius = random.random() * 10
raduis = round(radius, 2)
print('원의 반지름: %.2f' % raduis)
print('원주율 pi: %.4f' % math.pi)
print('반지름 %.2f인 원의 면적은 %.2f' % (radius, getarea(radius)))
