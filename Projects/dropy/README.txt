# dropy

Scaled down version of Microsoft's AirSim (drone only). Ideal for developers looking to control the drone via keyboard. 'dropy' is a utility package to control the simulator (developed in Unity) by writing minimal code, essentially useful for training of NNs and ideally suited for RL agents.

[![dropy](https://img.shields.io/badge/dropy-GitHub-red.svg)](https://github.com/gittygupta/dropy)
[![Simulator](https://img.shields.io/badge/Simulator-drive-yellow.svg)](https://drive.google.com/drive/folders/1aKszPhx8NSxfkh6jYMFV7Cr-rY0P3CeX?usp=sharing)
[![PyPI](https://img.shields.io/badge/PyPI-v0.1.0-blue.svg)](https://pypi.org/project/dropy/)
[![python](https://img.shields.io/badge/python-3.6+-blue.svg)](https://www.python.org)
[![Maintained?](https://img.shields.io/badge/Maintained%3F-YES-green.svg)](https://github.com/gittygupta/dropy)
[![v0.0.x?](https://img.shields.io/badge/v0.0.x-README-indigo.svg)](https://github.com/gittygupta/dropy/blob/master/README_v0.0.x.md)


## New to dropy 0.1.0

* Added multiplayer support to work with more than 1 flight object
* Improved Camera Stability

# Installation

#### For the package to work, please download folder containing the simulator from the the drive link provided in the badge above. 

```
pip install dropy
```

Requires Python 3.6+

Currently supported only on Win32 (MS Windows) environment


# Usage

#### Before using any functionalities of the package, make sure that the simulator (one or multiple instances) is (are) running. Key bindings for the multiplayer simulator is provided in the link itself.

```python
from dropy import Flight

flight = Flight(location='simulator')

flight.turn_left(180)

print('Current Global Coordinates : ', flight.coords_xyz())
print('Current Global Angles : ', flight.angles_xyz())
```

![dropy](https://github.com/gittygupta/dropy/blob/master/readme_gif.gif)

The 'location' parameter specifies the directory of the simulator. In the above, it's in the folder 'simulator' under the same working directory.

`
turn_left(n)
`
 -> 'n' specifies the number of degrees to turn


# Multiplayer

```python
from dropy import Flight

flight1 = Flight(location='multiplayer_drone_simulator')    # regarded as the host flight object
flight2 = Flight(location='multiplayer_drone_simulator')    # new flight-2 spawned
flight3 = Flight(location='multiplayer_drone_simulator')    # new flight-3 spawned
flight4 = Flight(location='multiplayer_drone_simulator')    # new flight=4 spawned

flight1.turn_left(7)                                        # host turns 7 * 5 degrees to the left
flight2.turn_right(7)                                       # flight-2 turns 7 * 5 degrees to the right
flight3.forward(7)                                          # flight-3 goes forward by 7 distance units
flight4.up(7)                                               # flight-4 thrusts up by 7 distance units

print(flight1.angles_xyz())                                 # returns euler angles of the host
print(flight2.angles_xyz())                                 # returns euler angles of flight-2
print(flight3.angles_xyz())                                 # returns euler angles of flight-3
print(flight4.angles_xyz())                                 # returns euler angles of flight-4

flight1.tpp_shot().save('test1.jpg')                        # saves screenshot of tpp-mode of the host
flight2.tpp_shot().save('test2.jpg')                        # saves screenshot of tpp-mode of flight-2
flight3.tpp_shot().save('test3.jpg')                        # saves screenshot of tpp-mode of flight-3
flight4.tpp_shot().save('test4.jpg')                        # saves screenshot of tpp-mode of flight-4

flight2.kill()                                              # flight-2 terminated from simulator and closed
flight3.kill()                                              # flight-3 terminated from simulator and closed
flight4.kill()                                              # flight-4 terminated from simulator and closed
flight1.kill()                                              # Host terminated from simulator and closed
```

#### Host must not be killed at first, or should never be killed. Killing of the host causes all the other flight objects to be terminated. You might as well choose to never control the host object, but it does take up some resources. 
#### HACK : Resize the host window to very small. Doesn't take up much resources then.
####

# Examples

## Controls

```python
from dropy import Flight

flight = Flight(location='simulator')  # location defines the directory where the simulator is, in the workstation

flight.turn_left(7)                    # turns 7 * 5 degrees to the left
flight.turn_right(7)                   # turns 7 * 5 degrees to the right
flight.up(10)                          # thrusts up by 10 distance units
flight.down(10)                        # drops down by 10 distance units
flight.forward(10)                     # moves forward by 10 distance units
flight.backward(10)                    # moves backward by 10 distance units
flight.swerve_left(10)                 # swerves 10 units to the left
flight.swerve_right(10)                # swerves 10 units to the right
```

## Utilities

```python
from dropy import Flight

flight = Flight(location='simulator')  # location defines the directory where the simulator is, in the workstation

coords = flight.coords_xyz()           # returns current global position of the agent
angles = flight.angles_xyz()           # returns current global euler angles of the agent
flight.top_view()                      # activates the top-down view of the simulator
flight.fpp_view()                      # activates the FPP view of the simulator
flight.tpp_view()                      # activates the TPP view of the simulator
fpp_view = flight.fpp_shot()           # returns ImageGrab of FPP camera of the simulator
top_view = flight.top_shot()           # returns ImageGrab of top-down view of the simulator
tpp_view = flight.tpp_shot()           # returns ImageGrab of TPP camera (Main Camera) of the simulator
flight.goto(500, 500)                  # flight travels from current global position to given global coordinates(500, 500)
flight.kill()                          # terminates flight object from the simulator, and closes that instance
```

# Contributions

Every contribution will be welcome.

Please feel free to raise issues on GitHub or pull requests for ideas, features and add-ons.

The vision is to create better environments in a Pythonic way, for small scale development projects.
