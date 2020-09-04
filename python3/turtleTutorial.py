import turtle

if __name__ == "__main__":
    #create new object
    t = turtle.Turtle()
    #initialize the object
    t.color('red')
    t.pensize(10)
    t.shape("circle")

    #move the object in the screen
    t.forward(100)
    t.backward(0)
    t.left(90)
    t.penup()
    t.forward(100)
    t.right(90)
    t.pendown()
    t.color("green")
    t.forward(100)

    pen = turtle.Turtle()
    colors = ['red','blue','green','purple','yellow','orange','black']

    #set color for turtle
    pen.color('red','blue')

    pen.width(5)

    #fill in shape with color
    pen.begin_fill()
    pen.circle(50)
    pen.end_fill()

    pen.penup()
    pen.forward(150)
    pen.pendown()

    pen.color('yellow','black')
    pen.begin_fill()

    for x in range(4):
        pen.forward(100)
        pen.right(90)

    pen.end_fill()

    for x in range(5):
        randColor = random.randint(0,len(colors)-1)
        randFillColor = random.randint(0,len(colors)-1)
        rand1 = random.randint(-300,300)
        rand2 = random.randint(-300,300)
        pen.penup()
        pen.color(colors[randColor],colors[randFillColor])
        pen.setpos(rand1,rand2)
        pen.pendown()
        pen.begin_fill()
        pen.circle(random.randint(0,80))
        pen.end_fill()