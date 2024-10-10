from turtle import Turtle, Screen
from paddle import Paddle
from ball import Ball
from scoreboard import Scoreboard
import time

my_screen = Screen()

my_screen.bgcolor("black")
my_screen.setup(height=600,width=800)
my_screen.title("PONG")
my_screen.tracer(0)

lines = Turtle()

lines.color("white")
lines.penup()
lines.goto(x=0,y=300)
lines.setheading(270)


for _ in range(100):
    lines.pendown()
    lines.forward(10)
    lines.penup()
    lines.forward(10)



r_paddle = Paddle((370,0))
l_paddle = Paddle((-370,0))
ball = Ball()
scoreboard = Scoreboard()
    
my_screen.listen()
my_screen.onkey(r_paddle.move_up, "Up")
my_screen.onkey(r_paddle.move_down, "Down")
my_screen.onkey(l_paddle.move_up, "w")
my_screen.onkey(l_paddle.move_down, "s")


game_is_on = True
while game_is_on:
    time.sleep(ball.move_speed)
    my_screen.update()
    ball.move()
    if ball.ycor() > 280 or ball.ycor() < -280:
        ball.bounce_y()

    if ball.distance(r_paddle) < 50 and ball.xcor() > 340 or  ball.distance(l_paddle) < 50 and ball.xcor() < -340:
        ball.bounce_x()

    if ball.xcor() > 380 :
        ball.r_reset()
        scoreboard.right_point()

    if  ball.xcor() < -380:
        ball.r_reset()
        scoreboard.left_point()

    if scoreboard.r_score == 5:
        game_is_on = False
        print("Right Player WON!!")
    elif scoreboard.l_score == 5:
        game_is_on = False
        print("Left Player WON!!")

    my_screen.update()












my_screen.exitonclick()