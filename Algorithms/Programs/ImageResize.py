from io import BytesIO
from PIL import Image
from django.core.files import File
"""
Image Compression useful when needed feature like progessive loading
"""

def resize_image(image_file):
    extension_image = str(image).split('.')[-1]
    image = Image.open(image_file)
    image_file = BytesIO()
    w, h = image.size
    image = image.resize((w//10, h//10), Image.ANTIALIAS)
    image.save(image_file, extension_image, quality=100)
      new_image = File(image_file,name=f"Image.{extension_image}")
    return new_image
