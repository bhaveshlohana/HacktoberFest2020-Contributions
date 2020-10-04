from io import BytesIO
from PIL import Image
from django.core.files import File


def compress(image):
    im = Image.open(image)
    # create a BytesIO object
    im_io = BytesIO() 
    if im.mode in ("RGBA", "P"):
        im = im.convert("RGB")
    im = im.convert("RGB")
    # save image to BytesIO object
    im.save(im_io, 'webp', quality=100) 
    # create a django-friendly Files object
    new_image = File(im_io,name="Image.webp")
    return new_image
