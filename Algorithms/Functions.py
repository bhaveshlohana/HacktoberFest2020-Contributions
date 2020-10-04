import math
def distance(p1,p2):
    x1=p1[0]
    x2=p2[0]
    y1=p1[1]
    y2=p2[1]
    d=math.sqrt((x1-x2)**2+(y1-y2)**2)
    return d
print(distance((0,0),(1,1)))

def in_circle(x, origin=[0,0]):
    if(distance(x,origin)<=1):
        return True
    else:
        return False
in_circle((1,1))
