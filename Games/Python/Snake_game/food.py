from turtle import Turtle
import random

class Food(Turtle) :
    def __init__(self):
        super().__init__()
        self.shape("circle")
        self.penup()
        self.shapesize(stretch_len=0.5,stretch_wid=0.5)
        self.color("white")
        self.speed(0)
        self.refresh()

    def refresh(self):
        x_cor=random.randint(-270,270)
        y_cor=random.randint(-270,270)
        self.goto(x_cor,y_cor)

        