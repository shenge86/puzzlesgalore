'''
Animate trajectory of an object in projectile motion
'''
from matplotlib import pyplot as plt
from matplotlib import animation
import math

g = 9.8

def get_intervals(u, theta):
    t_flight = 2*u*math.sin(theta)/g
    intervals = []
    start, interval = 0, 0.005
    while start < t_flight:
        intervals.append(start)
        start += interval
    return intervals

def update_position(i, circle, intervals, u, theta):
    t = intervals[i]
    x = u*math.cos(theta)*t
    y = u*math.sin(theta)*t - 0.5*g*t**2
    circle.center = x, y
    return circle

def create_animation(u, theta):
    intervals = get_intervals(u, theta)
    xmin = 0
    xmax = u*math.cos(theta)*intervals[-1]
    ymin = 0
    t_max = u*math.sin(theta)/g # equal to half of t_flight if start at 0
    ymax = u*math.sin(theta)*t_max - 0.5*g*t_max**2

    fig = plt.gcf()
    maxscale = max(xmax,ymax)
    ax  = plt.axes(xlim=(xmin,maxscale), ylim=(ymin,maxscale))
    
    circle = plt.Circle((xmin, ymin), radius=math.sqrt(u))
    ax.add_patch(circle)

    anim = animation.FuncAnimation(fig, update_position, fargs=(circle,
        intervals, u, theta), frames=len(intervals), interval=1, repeat=True)

    plt.title('Projectile Motion')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.show()

    return intervals

if __name__ == '__main__':
    try:
        u = float(input('Enter initial velocity (m/s): '))
        theta = float(input('Enter angle (deg): '))
    except ValueError:
        print('Invalid input.')
    else:
        theta = math.radians(theta)
        create_animation(u, theta)
