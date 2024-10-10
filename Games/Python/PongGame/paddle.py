from turtle import Turtle

class Paddle(Turtle):
    
    def __init__(self, position):
        super().__init__()
       
        self.color("white")
        self.shape("square")
        self.penup()
        self.shapesize(stretch_len=1.5, stretch_wid=5)
        self.goto(position)

    def move_up(self):
        new_y = self.ycor() + 20
        self.goto(self.xcor(), new_y)
    
    def move_down(self):
        new_y = self.ycor() - 20
        self.goto(self.xcor(), new_y)
