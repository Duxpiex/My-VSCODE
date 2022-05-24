import turtle as t            
t.setup(500, 400) #초기 원도의 크기 조정

rep = 60
t.speed(0) #최고 속도로 지정

for i in range(rep):
    for i in range(5):
        t.forward(100)
        t.left(360/5)
    t.left(360/rep)
