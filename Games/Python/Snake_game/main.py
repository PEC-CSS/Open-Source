import time
from turtle import Screen, listen
from snake import Snake
from food import Food
from scoreboard import ScoreBoard


sc=Screen()
sc.setup(width=600,height=600)
sc.bgcolor("black")
sc.title("Snake Game")
sc.tracer(0)
snake=Snake()
food=Food()
score=ScoreBoard()
score.score_write()
sc.listen()


sc.onkey(key='Up',fun=snake.up)
sc.onkey(key='Down',fun=snake.down)
sc.onkey(key='Right',fun=snake.right)
sc.onkey(key='Left',fun=snake.left)
is_game_on=True

while is_game_on:
    sc.update()
    time.sleep(0.1)
    snake.move()
#    Dectect collision with food
    if snake.head.distance(food)<10:
        food.refresh()
        snake.increase_lenght()
        score.score_write()
#   Dectect collision with wall 
    if snake.head.xcor()>290 or snake.head.xcor()<-290 or snake.head.ycor()>290 or snake.head.ycor() < -290:
        is_game_on=False
        score.game_over()
#  Dectect collision with tail
    for segment in snake.all_segments[1:]:
        if snake.head.distance(segment) < 5:
            is_game_on=False
            score.game_over()
        
 
    
        




sc.exitonclick()
