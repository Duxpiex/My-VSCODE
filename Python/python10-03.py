import turtle as t            
colors = ['yellow', 'red', 'blue']
t.setup(500, 500) #초기 원도의 크기 조정
t.bgcolor('black')
rep = 200
t.speed(0) #최고 속도로 지정
for i in range(rep):
    t.color(colors[i % len(colors)])
    t.width(i/rep + 1)
    t.forward(i * 2)
    t.left(119)
