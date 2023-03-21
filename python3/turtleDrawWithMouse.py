from turtle import (Turtle, Screen, listen, onscreenclick)

def drag(x,y):
    t.ondrag(None)
    t.setheading(t.towards(x,y))
    t.goto(x,y)
    t.ondrag(drag)

def clearScreen(x,y):
    t.clear()

def movePen(x,y):
    t.penup()
    t.goto(x,y)
    t.pendown()
    t.ondrag(drag)

if __name__ == "__main__":
    screen = Screen()
    t = Turtle()
    t.shape("turtle")
    t.pensize(5)
    t.speed(-1)

    listen()
    t.ondrag(drag)
    onscreenclick(clearScreen,3)
    onscreenclick(movePen, 1)
    screen.mainloop()


