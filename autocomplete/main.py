import sys
from pyautogui import press, typewrite, hotkey
import time
import keyboard

with open(sys.argv[1], "r") as file:
    data = file.read()
    
time.sleep(5)

for elem in data:

    if elem != "\r":

            if elem == "\n":
                
                keyboard.press_and_release('enter')

            else:
                keyboard.write(elem)
                time.sleep(1)