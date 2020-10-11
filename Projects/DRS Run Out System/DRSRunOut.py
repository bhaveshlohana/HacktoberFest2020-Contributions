import tkinter                      # for gui
import cv2                          # pip install opencv-python
import PIL.Image, PIL.ImageTk       # pip install pillow
import imutils                      # for image resizing     # pip install imutils
from functools import partial       # Adds argument in the function while calling function in button
import threading
import time

stream = cv2.VideoCapture("clip.mp4")
flag = True     # To show blinking text

def play(speed):
    global flag

    # To play video
    frame1 = stream.get(cv2.CAP_PROP_POS_FRAMES)    # To get frames of video
    stream.set(cv2.CAP_PROP_POS_FRAMES, frame1 + speed)   # To increase r decrease speed

    grabbed, frame = stream.read()      # To read current frame
    if not grabbed:
        exit()
    frame = imutils.resize(frame, width=SET_WIDTH, height=SET_HEIGHT)
    frame = PIL.ImageTk.PhotoImage(image = PIL.Image.fromarray(frame))
    canvas.image = frame
    canvas.create_image(0,0, image=frame, anchor=tkinter.NW)
    if flag:
        canvas.create_text(134, 26, fill="red", font="Times 26 bold", text="Decision Pending")
    flag = not flag

def pending(decision):
    # 1. Display decision pending image
    frame = cv2.cvtColor(cv2.imread("pending.png"), cv2.COLOR_BGR2RGB)
    frame = imutils.resize(frame, width=SET_WIDTH, height=SET_HEIGHT)
    frame = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(frame))
    canvas.image = frame
    canvas.create_image(0,0, image=frame, anchor=tkinter.NW)

    # 2. Wait for 1 second
    time.sleep(2)

    # 3. Display sponsor image
    frame = cv2.cvtColor(cv2.imread("sponsor.png"), cv2.COLOR_BGR2RGB)
    frame = imutils.resize(frame, width=SET_WIDTH, height=SET_HEIGHT)
    frame = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(frame))
    canvas.image = frame
    canvas.create_image(0,0, image=frame, anchor=tkinter.NW)

    # 4. Wait for 1.5 second
    time.sleep(3)

    # 5. Display out/notout image
    if decision == "Out":
        decisionImg = "out.png"
    else:
        decisionImg = "not_out.png"
    frame = cv2.cvtColor(cv2.imread(decisionImg), cv2.COLOR_BGR2RGB)
    frame = imutils.resize(frame, width=SET_WIDTH, height=SET_HEIGHT)
    frame = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(frame))
    canvas.image = frame
    canvas.create_image(0,0, image=frame, anchor=tkinter.NW)

def out():
    thread = threading.Thread(target=pending,args=("Out",))
    thread.daemon=1
    thread.start()

def not_out():
    thread = threading.Thread(target=pending,args=("Not Out",))
    thread.daemon=1
    thread.start()

SET_WIDTH = 650
SET_HEIGHT = 368

# tkinter gui starts here
window = tkinter.Tk()
window.title("DRS Run-Out System")

cv_img = cv2.cvtColor(cv2.imread("front.jpg"), cv2.COLOR_BGR2RGB)
cv_img = imutils.resize(cv_img,width=SET_WIDTH,height=SET_HEIGHT)
canvas = tkinter.Canvas(window, width = SET_WIDTH, height = SET_HEIGHT)
photo = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(cv_img))
image_on_canvas = canvas.create_image(0,0,ancho=tkinter.NW,image=photo)
canvas.pack()

# Now buttonds for playback
btn = tkinter.Button(window, text="Next (fast) >>", width=50, command=partial(play,25))
btn.pack()

btn = tkinter.Button(window, text="Next (slow) >>",width=50, command=partial(play,2))
btn.pack()

btn = tkinter.Button(window, text="<< Previous (fast)",width=50, command=partial(play,-25))
btn.pack()

btn = tkinter.Button(window, text="<< Previous (slow)",width=50, command=partial(play,-2))
btn.pack()

btn = tkinter.Button(window, text="Give Out",width=50, command=out)
btn.pack()

btn = tkinter.Button(window, text="Give Not Out",width=50,command=not_out)
btn.pack()

window.mainloop()