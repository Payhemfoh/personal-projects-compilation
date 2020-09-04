import random
import turtle

def up():
    pen.setheading(90)
    pen.forward(100)

def down():
    pen.setheading(270)
    pen.forward(100)

def left():
    pen.setheading(180)
    pen.forward(100)

def right():
    pen.setheading(0)
    pen.forward(100)

def clickLeft(x,y):
    pen.color(random.choice(colors))

def clickRight(x,y):
    pen.stamp()

if __name__ == "__main__":
    pen = turtle.Turtle()
    pen.speed(0)
    pen.width(5)

    colors = ['red', 'blue', 'green', 'purple', 'yellow', 'orange', 'black']

    turtle.listen()

    turtle.onkey(up,'Up')
    turtle.onkey(down,"Down")
    turtle.onkey(left,"Left")
    turtle.onkey(right,"Right")
    turtle.onscreenclick(clickLeft,1)
    turtle.onscreenclick(clickRight,3)

    turtle.mainloop()