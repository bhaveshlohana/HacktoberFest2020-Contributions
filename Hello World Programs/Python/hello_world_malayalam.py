#!/usr/bin/python
# -*- coding: utf-8 -*-
import numpy as np
from PIL import ImageFont, ImageDraw, Image

fontpath="/usr/share/fonts/truetype/samyak-fonts/Samyak-Malayalam.ttf"
font = ImageFont.truetype(fontpath, 32)
x, y, w, h = 300, 100, 300, 300
blackboard = np.zeros((480, 640, 3),dtype=np.uint8)
img = Image.fromarray(blackboard)
draw = ImageDraw.Draw(img_)
draw.text((50, 30),"ഹലോ വേൾഡ്", font = font,fill = (b, g, r, a))
img.show()
