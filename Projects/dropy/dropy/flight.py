import os
import math
import time
import ctypes
import pyautogui
import win32gui
import win32ui
import win32con
import pywinauto
from pywinauto import application
from ctypes import windll
from PIL import Image, ImageGrab
from ctypes import wintypes

class CameraControlError(Exception):
    '''
    When Camera control goes into an infinite loop of trials and errors
    '''
    def __init__(self, message):
        self.message = message
        super().__init__(self.message)


class Flight(object):
    # start all instances of the multiplayer, then run the script
    count = 0
    handles = pywinauto.findwindows.find_windows(title='drone_simulator')
    def __init__(self, location):
        # window
        self.location = location
        self.fpp_key = 0
        self.top_key = 0
        self.title = 'drone_simulator'

        time.sleep(1)   # control buffer
        self.app = application.Application(backend='win32')

        self.app.connect(handle=Flight.handles[Flight.count])      # 'start' does not load LOG file, so connect
        self.win = self.app.window(title_re=self.title)
        self.hwnd = Flight.handles[Flight.count]
        ctypes.windll.user32.SetProcessDPIAware()

        self.__start()

        self.coords = (0, 0, 0)
        self.angles = (0, 0, 0)

        self.logfile = ''
        Flight.count += 1
        logfile = self.location + '/LOG' + str(Flight.count) + '.txt'
        
        if not os.path.exists(logfile):     # control buffer
            time.sleep(1)

        self.logfile = logfile

            


    def __start(self):      # private
        self.win.send_keystrokes('{o}')
        if Flight.count == 1:
            self.win.send_keystrokes('{h}')
        else:
            self.win.send_keystrokes('{c}')


    def __screenshot(self): # private
        dimensions = win32gui.GetWindowRect(self.hwnd)    

        # this gets the window size, comparing it to `dimensions` will show a difference
        winsize = win32gui.GetClientRect(self.hwnd)

        # this sets window to front if it is not already
        win32gui.SetWindowPos(self.hwnd, win32con.HWND_NOTOPMOST,0,0,0,0, win32con.SWP_NOMOVE | win32con.SWP_NOSIZE)
        win32gui.SetWindowPos(self.hwnd, win32con.HWND_TOPMOST,0,0,0,0, win32con.SWP_NOMOVE | win32con.SWP_NOSIZE)
        win32gui.SetWindowPos(self.hwnd, win32con.HWND_NOTOPMOST,0,0,0,0, win32con.SWP_SHOWWINDOW | win32con.SWP_NOMOVE | win32con.SWP_NOSIZE)

        # grab screen region set in `dimensions`
        image = ImageGrab.grab(dimensions)
        #image.show()

        # we're going to use this to get window attributes
        f=ctypes.windll.dwmapi.DwmGetWindowAttribute

        # `rect` is for the window coordinates
        rect = ctypes.wintypes.RECT()
        DWMWA_EXTENDED_FRAME_BOUNDS = 9

        # and then the coordinates of the window go into `rect`
        f(ctypes.wintypes.HWND(self.hwnd),
        ctypes.wintypes.DWORD(DWMWA_EXTENDED_FRAME_BOUNDS),
        ctypes.byref(rect),
        ctypes.sizeof(rect)
        )

        # if we want to work out the window size, for comparison this should be the same as `winsize`
        size = (rect.right - rect.left, rect.bottom - rect.top)        

        # put the window coordinates in a tuple like that returned earlier by GetWindowRect()
        dimensions = (rect.left, rect.top, rect.right, rect.bottom)

        # grab screen region set in the revised `dimensions`
        image = ImageGrab.grab(dimensions)
        return image


    def fpp_shot(self):
        # add changes to unity to denote which camera is currently open
        # Also save LOG file to its own directory 
        if self.fpp_key % 2 == 0:
            self.fpp_view()
        shot = self.__screenshot()
        self.fpp_view()
        return shot


    def top_shot(self):
        # add changes to unity to denote which camera is currently open
        # Also save LOG file to its own directory 
        if self.top_key % 2 == 0:
            self.top_view()
        shot = self.__screenshot()
        self.top_view()
        return shot


    def tpp_shot(self):
        # add changes to unity to denote which camera is currently open
        # Also save LOG file to its own directory 
        self.tpp_view()
            #raise CameraControlError('''Might have viewed FPP and then suddenly Top View (vice versa), before exiting into TPP View, i.e, pressed "1 and then 2" or "2 and then 1 again".
            #                            Had to press "1, then again 1 to exit, and then, press 2''')
        return self.__screenshot()


    def turn_left(self, n=1):
        #win.send_keystrokes('{w}')
        #win.send_keystrokes('{a}')
        #win.send_keystrokes('{s}')
        #win.send_keystrokes('{d}')
        #win.send_keystrokes('{i}')
        for _ in range(n):
            self.win.send_keystrokes('{j}')
        #win.send_keystrokes('{j}')
        #win.send_keystrokes('{k}')
        #win.send_keystrokes('{l}')
        #print('Turn Left')


    def turn_right(self, n=1):
        #win.send_keystrokes('{w}')
        #win.send_keystrokes('{a}')
        #win.send_keystrokes('{s}')
        #win.send_keystrokes('{d}')
        #win.send_keystrokes('{i}')
        #win.send_keystrokes('{j}')
        #win.send_keystrokes('{k}')
        #win.send_keystrokes('{l}')
        for _ in range(n):
            self.win.send_keystrokes('{l}')
        #print('Turn Right')


    def up(self, n=1):
        #win.send_keystrokes('{w}')
        #win.send_keystrokes('{a}')
        #win.send_keystrokes('{s}')
        #win.send_keystrokes('{d}')
        for _ in range(n):
            self.win.send_keystrokes('{i}')
        ##
        #win.send_keystrokes('{j}')
        #win.send_keystrokes('{k}')
        #win.send_keystrokes('{l}')
        #print('Move up')


    def down(self, n=1):
        #win.send_keystrokes('{w}')
        #win.send_keystrokes('{a}')
        #win.send_keystrokes('{s}')
        #win.send_keystrokes('{d}')
        #win.send_keystrokes('{i}')
        #win.send_keystrokes('{j}')
        for _ in range(n):
            self.win.send_keystrokes('{k}')
        ##
        #win.send_keystrokes('{l}')
        #print('Move down')


    def forward(self, n=1):
        for _ in range(n):    
            self.win.send_keystrokes('{w}')
        ##
        #win.send_keystrokes('{a}')
        #win.send_keystrokes('{s}')
        #win.send_keystrokes('{d}')
        #win.send_keystrokes('{i}')
        #win.send_keystrokes('{j}')
        #win.send_keystrokes('{k}')
        #win.send_keystrokes('{l}')
        #print('Go Forward')


    def backward(self, n=1):
        #win.send_keystrokes('{w}')
        #win.send_keystrokes('{a}')
        for _ in range(n):
            self.win.send_keystrokes('{s}')
        #
        #win.send_keystrokes('{d}')
        #win.send_keystrokes('{i}')
        #win.send_keystrokes('{j}')
        #win.send_keystrokes('{k}')
        #win.send_keystrokes('{l}')
        #print('Go Backward')


    def swerve_left(self, n=1):
        #win.send_keystrokes('{w}')
        for _ in range(n):
            self.win.send_keystrokes('{a}')
        ##
        #win.send_keystrokes('{s}')
        #win.send_keystrokes('{d}')
        #win.send_keystrokes('{i}')
        #win.send_keystrokes('{j}')
        #win.send_keystrokes('{k}')
        #win.send_keystrokes('{l}')
        #print('swerve Left')


    def swerve_right(self, n=1):
        #win.send_keystrokes('{w}') 
        #win.send_keystrokes('{a}')
        #win.send_keystrokes('{s}')
        for _ in range(n):
            self.win.send_keystrokes('{d}')
        ##
        #win.send_keystrokes('{i}')
        #win.send_keystrokes('{j}')
        #win.send_keystrokes('{k}')
        #win.send_keystrokes('{l}')
        #print('swerve Right')


    def top_view(self):
        #win.send_keystrokes('{1}')
        self.win.send_keystrokes('{1}')
        self.top_key += 1
        #print('Top View')


    def fpp_view(self):
        #win.send_keystrokes('{2}')
        self.win.send_keystrokes('{2}')
        self.fpp_key += 1
        #print('FPP View')


    def tpp_view(self):
        if self.fpp_key % 2 == 0 and self.top_key % 2 == 0:
            # alreaady in tpp
            pass
        elif self.fpp_key % 2 == 0 and self.top_key % 2 != 0:
            # in top view
            self.top_view()
        elif self.fpp_key % 2 != 0 and self.top_key % 2 == 0:
            # in fpp view
            self.fpp_view()
        else:
            # mixed up
            self.fpp_view()
            self.top_view()
        #print('TPP View')


    def coords_xyz(self):
        try:
            f = open(self.logfile, 'r')
            f.seek(0)
            self.coords, _ = f.read().split('\n')
            self.coords = tuple(map(float, self.coords.split()))
            return self.coords
        except:
            return self.coords


    def angles_xyz(self):
        try:
            f = open(self.logfile, 'r')
            f.seek(0)
            _, self.angles = f.read().split('\n')
            self.angles = tuple(map(float, self.angles.split()))
            return self.angles
        except:
            return self.angles


    def goto(self, x2, z2):
        ## if at the start x1 > x2, doesn't work
        # Main Loop
        while(True):
            try:
                coordinates = self.coords_xyz()
                angles = self.angles_xyz()

                #print('Coordinates : ', coordinates)

                x1 = coordinates[0]
                y1 = coordinates[1]
                z1 = coordinates[2]
                m_line = float((z2 - z1)/(x2 - x1))
                slope_angle = 90 - math.degrees(math.atan(m_line))
                #print('Slope Angle : ', slope_angle)

                drone_angle = angles[1]
                drone_angle_relative = drone_angle
                if drone_angle > 180:
                    drone_angle_relative -= 360

                turn_angle = drone_angle_relative - slope_angle

                if x1 > x2:     # to add a vector kinda thingie
                    turn_angle += 180

                #print('Drone Angle : ', drone_angle_relative)
                #print('Turn Angle : ', turn_angle)

                if turn_angle < -10:     # 10 for thresholding
                    self.turn_right(1)
                elif turn_angle > 10:
                    self.turn_left(1)
                else:
                    self.forward(1)
                f.close()

                if x1 > x2 - 10 and x1 < x2 + 10 and z1 > z2 - 10 and z1 < z2 + 10:
                    print('Reached!')
                    break        

            except:
                pass


    def kill(self):
        self.tpp_view()
        time.sleep(1)   # buffer
        self.win.close()
        os.remove(self.logfile)
