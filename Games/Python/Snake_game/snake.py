from turtle import Turtle, down
STARTING_POSITON=[(0,0),(-20,0),(-40,0)]
MOVE_DISTANCE=10
UP=90
DOWN=270
RIGHT=0
LEFT=180

class Snake :
    def __init__(self):
        self.all_segments=[]
        self.creat_snake()
        self.head=self.all_segments[0]
        self.head.color("purple")
        
        
    def creat_snake(self):
        for position in STARTING_POSITON:
            self.add_segment(position)
#  add segment to the snake body 
    def add_segment(self,position):
            new_segment=Turtle(shape="square")
            new_segment.color("white")
            new_segment.penup()
            new_segment.goto(position)
            self.all_segments.append(new_segment)
#  increase the lenght of snake 
    def increase_lenght(self):
        self.add_segment(self.all_segments[-1].position())    
#   move the snake 
    def move(self):
        for seg_num in range(len(self.all_segments)-1,0,-1):
            x_cor=self.all_segments[seg_num-1].xcor()
            y_cor=self.all_segments[seg_num-1].ycor()
            self.all_segments[seg_num].goto(x_cor,y_cor)
        self.head.forward(MOVE_DISTANCE)    
    
    def up(self):
        if self.head.heading() != DOWN:
            self.head.seth(90)
    
    def down(self):
        if self.head.heading() != UP:
            self.head.seth(270)
    
    def left(self):
        if self.head.heading() != RIGHT:
            self.head.seth(180)

    def right(self):
        if self.head.heading() != LEFT:
            self.head.seth(0)


