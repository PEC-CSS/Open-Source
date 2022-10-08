# Python Program to draw a Broken Heart using Turtle Library of Python

# import everything from turtle module
import turtle as h

# Setting the pen size, color and speed
h.pensize(20)
h.pencolor("red")
h.speed(10)

# set the background color to black
h.bgcolor("black")


def curve():
    """Creating a Function to Draw a Curve."""
    for i in range (200):
        h.right(1)
        h.forward(1)

def heart():
    """Creating a Function to Draw a Heart."""
    h.fillcolor("red")
    h.begin_fill()
    h.left(140)
    h.forward(113)
    curve()
    h.left(120)
    curve()
    h.forward(112)
    h.end_fill()

# Calling the heart() function to Draw a Heart.
heart()

# Drawing a Broken Heart

# Setting the pen color to black
h.pencolor("black")


h.penup()
h.goto(0,170)
h.pendown()


for u in range (3):
     h.left(75)
     h.forward(40)
     h.right(65)
     h.forward(40)
h.ht


h.done()