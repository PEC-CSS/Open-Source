from turtle import Turtle
ALIGN="center"
FONT=("Verdana",15,"italic")
class ScoreBoard(Turtle):
    def __init__(self):
        super().__init__()
        self.score=-1
        self.hideturtle()
        self.pencolor("white")
        self.penup()
        self.goto(x=0,y=278)


    def score_count(self):
        self.score+=1
        return self.score
    def game_over(self):
        self.goto(0,0)
        self.write("GAME OVER",align=ALIGN,font=FONT)
    def score_write(self):
        self.clear()    
        self.write(f"Score ={self.score_count()}",align=ALIGN,font=FONT)
              
