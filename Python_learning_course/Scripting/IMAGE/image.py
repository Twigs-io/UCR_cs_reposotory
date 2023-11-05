from PIL import Image
import sys
import os

arg1 = sys.argv[1]
arg2 = sys.argv[2]
check = False

if os.path.exists(arg2) != True:
    os.mkdir(arg2)

for files in os.listdir(arg1):
    f=os.path.join(arg1, files)
    img = Image.open(f)
    f = f.split('.')
    f = f[1].split('/')
    img.save(f'{arg2}/{f[2]}.png', 'png')
