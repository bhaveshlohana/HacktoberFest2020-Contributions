import random
import string

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont

img = Image.new('RGB', (200, 100))
d = ImageDraw.Draw(img)

len = random.randint(0, 10)
captcha = ""
for i in range(len):
    r2 = random.randint(0, 10)
    if(r2 < 6):
        r3 = random.randint(0, 10)
    else:
        r3 = random.choice(string.ascii_letters)
    captcha = captcha + str(r3)

print("Captcha of length", len, "is", captcha)
d.text((20, 20), captcha, fill=(255, 0, 0))
img.save('Cryptography/s.png')

print("Captcha: ", captcha)
user_inp = input("Enter captcha: ")
if(user_inp == captcha):
    print("Validated")
else:
    print("Unvalid entry")
