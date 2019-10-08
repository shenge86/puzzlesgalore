# -*- coding: utf-8 -*-
"""
Created on Sun Oct  6 00:11:23 2019

@author: sheng
Simple Pong in Python3 for Beginners

"""
import turtle
import time
# import os   # only for linux or mac
import winsound 

# Screen
wn = turtle.Screen()
wn.title("Pong")
wn.bgcolor("black")
wn.setup(width=800,height=600)
wn.tracer(0)

# Score
score_a = 0
score_b = 0

# Paddle A
paddle_a = turtle.Turtle() # create object of class Turtle which is in the turtle library
paddle_a.speed(0) # speed of animation set to the maximum
paddle_a.shape("square")
paddle_a.color("white")
paddle_a.shapesize(stretch_wid=5,stretch_len=1)
paddle_a.penup()
paddle_a.goto(-350,0)

# Paddle B
paddle_b = turtle.Turtle() # create object of class Turtle which is in the turtle library
paddle_b.speed(0) # speed of animation set to the maximum
paddle_b.shape("square")
paddle_b.color("white")
paddle_b.shapesize(stretch_wid=5,stretch_len=1)
paddle_b.penup()
paddle_b.goto(350,0)

# Ball
ball = turtle.Turtle() # create object of class Turtle which is in the turtle library
ball.speed(0) # speed of animation set to the maximum
ball.shape("circle")
ball.color("white")
ball.penup()
ball.goto(0,0)
ball.dx = 0.2
ball.dy = 0.2

# Pen
pen = turtle.Turtle()
pen.speed(0)
pen.color("white")
pen.penup()
pen.hideturtle() # don't want to see the pen object
pen.goto(0, 260)
pen.write("Player A: 0 Player B: 0", align="center", font=("Courier",24,"normal"))


## Functions ##
def paddle_a_up():
    y = paddle_a.ycor()
    y += 20
    paddle_a.sety(y)

def paddle_a_down():
    y = paddle_a.ycor()
    y -= 20
    paddle_a.sety(y)

def paddle_b_up():
    y = paddle_b.ycor()
    y += 20
    paddle_b.sety(y)

def paddle_b_down():
    y = paddle_b.ycor()
    y -= 20
    paddle_b.sety(y)

## Keyboard binding ##
wn.listen()
wn.onkeypress(paddle_a_up,"w")
wn.onkeypress(paddle_a_down,"s")
wn.onkeypress(paddle_b_up,"i")
wn.onkeypress(paddle_b_down,"k")


## Main game loop ##
while True:
    wn.update()
    
    # Move the ball
    ball.setx(ball.xcor()+ball.dx)
    ball.sety(ball.ycor()+ball.dy)
    
    # border checking
    if ball.ycor() > 290:
        ball.sety(290)
        ball.dy *= -1
        # os.system("aplay Beep2.wav&) # for Linux or Mac
        winsound.PlaySound("Beep2.wav",winsound.SND_ASYNC) # for Windows only
        
    if ball.ycor() < -290:
        ball.sety(-290)
        ball.dy *= -1
        # os.system("aplay Beep2.wav&) # for Linux or Mac
        winsound.PlaySound("Beep2.wav",winsound.SND_ASYNC) # for Windows only
        
    if ball.xcor() > 390:
        # ball.setx(390)
        # reset ball to middle of screen and reset speed
        ball.goto(0,0)
        ball.dx = -0.2
        score_a += 1
        pen.clear()
        pen.write("Player A: {} Player B: {}".format(score_a,score_b), align="center", font=("Courier",24,"normal"))
    
    if ball.xcor() < -390:
        # ball.setx(-390)
        ball.goto(0,0)
        ball.dx = 0.2
        score_b += 1
        pen.clear()
        pen.write("Player A: {} Player B: {}".format(score_a,score_b), align="center", font=("Courier",24,"normal"))
        
    # paddle and ball collisions
    if (ball.xcor() > 340 and ball.xcor() < 350) and (ball.ycor() < paddle_b.ycor()+50 and ball.ycor() > paddle_b.ycor()-50):
        ball.setx(340)        
        ball.dx *= -2 # reverse direction and increase speed
        # os.system("aplay Beep2.wav&) # for Linux or Mac
        winsound.PlaySound("Beep2.wav",winsound.SND_ASYNC) # for Windows only
        
    if (ball.xcor() < -340 and ball.xcor() > -350) and (ball.ycor() < paddle_a.ycor()+50 and ball.ycor() > paddle_a.ycor()-50):
        ball.setx(-340)        
        ball.dx *= -2 # reverse direction and increase speed
        # os.system("aplay Beep2.wav&) # for Linux or Mac
        winsound.PlaySound("Beep2.wav",winsound.SND_ASYNC) # for Windows only
        
    if score_a > 0:
        pen.clear()
        pen.goto(0,0)
        pen.write("Player A WINS!", align="center", font=("Courier",36,"normal"))
        break
        
    if score_b > 0:
        pen.clear()
        pen.goto(0,0)
        pen.write("Player B WINS!", align="center", font=("Courier",36,"normal"))
        break
    
time.sleep(15)
turtle.bye()