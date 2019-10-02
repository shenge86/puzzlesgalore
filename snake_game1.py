import turtle
import time
import random

delay0 = 0.2
delay = delay0
px = 20
maxx = 500
maxy = 500

# Score
score = 0
high_score = 0

# setup the screen
wn = turtle.Screen()
wn.title("Snake Game")
wn.bgcolor("green")
wn.setup(width=maxx, height=maxy)
wn.tracer(0) # turns off animation on screen

# Snake head
head = turtle.Turtle()
head.speed(0)
head.shape("square")
head.color("red")
head.penup() # does not draw lines
head.goto(0,0) # default location set
head.direction = "up"

# Snake body
segments = []

# Snake food
food = turtle.Turtle()
food.speed(0)
food.shape("turtle")
food.color("white")
food.penup() # does not draw lines
food.goto(0,100) # default location set

# Pen
pen = turtle.Turtle()
pen.speed(0)
pen.shape("square")
pen.color("black")
pen.penup()
pen.hideturtle()
pen.goto(0,maxy/2-30)
pen.write("Score: 0 High Score: 0", align="center", font=("Courier", 24, "normal"))


# Functions
def go_up():
	if head.direction != "down":
		head.direction = "up"

def go_down():
	if head.direction != "up":
		head.direction = "down"
	
def go_left():
	if head.direction != "right":
		head.direction = "left"
	
def go_right():
	if head.direction != "left":
		head.direction = "right"

def move():
	if head.direction == "up":
		y = head.ycor()
		head.sety(y + px)
	
	if head.direction == "down":
		y = head.ycor()
		head.sety(y - px)
		
	if head.direction == "left":
		x = head.xcor()
		head.setx(x - px)
		
	if head.direction == "right":
		x = head.xcor()
		head.setx(x + px)

def clear_score():
	score = 0
	pen.clear()	
	pen.write("Score: {} High Score: {}".format(score, high_score), align="center", font=("Courier", 24, "normal"))

# Keyboard bindings
wn.listen()
wn.onkeypress(go_up, "w")
wn.onkeypress(go_down, "s")
wn.onkeypress(go_left, "a")
wn.onkeypress(go_right, "d")

# Main game loop
while True:
	wn.update()
	
	# Check for collision with border
	if head.xcor()>maxx/2-10 or head.xcor()<-maxx/2+10 or head.ycor()>maxy/2-10 or head.ycor()<-maxy/2+10:
		print("Collided with edge!")
		time.sleep(1)
		head.goto(0,0)
		head.direction = "stop"
		
		# Hide the segments (doing this since don't know how to actually delete it)
		for segment in segments:
			segment.goto(2*maxx,2*maxy)
			
		# Clear segments list
		segments.clear()
		
		# Reset score
		clear_score()
		
		# Reset delay
		delay = delay0
	
	
	# Check for collision with food
	if head.distance(food) < px:
		# move food to a random spot on screen
		print("Collided with food!")
		x = random.randint(-maxx/2+10,maxx/2-10)
		y = random.randint(-maxy/2+10,maxy/2-10)
		food.goto(x,y)
		
		# add a segment
		new_segment = turtle.Turtle();
		new_segment.speed(0)
		new_segment.shape("circle")
		new_segment.color("grey")
		new_segment.penup()
		segments.append(new_segment)
		
		# lower delay
		delay -= 0.01
		
		# add score
		score += 10
		if score > high_score:
			high_score = score
		
		pen.clear()	
		pen.write("Score: {} High Score: {}".format(score, high_score), align="center", font=("Courier", 24, "normal"))

	# Move end segments first in reverse order
	for index in range(len(segments)-1,0,-1):
		x = segments[index-1].xcor()
		y = segments[index-1].ycor()
		segments[index].goto(x,y)

	# Move segment 0 to where the head is
	if len(segments) > 0:
		x = head.xcor()
		y = head.ycor()
		segments[0].goto(x,y)

	move()
	
	# Check for head collision with the body segments
	for segment in segments:
		if segment.distance(head) < px:
			time.sleep(1)
			head.goto(0,0)
			head.direction = "stop"
			
			# Hide segments
			for segment in segments:
				segment.goto(maxx*2,maxy*2)
				
			# Clear segments list
			segments.clear()
			
			# Reset score
			clear_score()
			
			# Reset delay
			delay = delay0
	
	time.sleep(delay)


wn.mainloop() # keeps window open
