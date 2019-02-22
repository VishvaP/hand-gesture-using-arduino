import serial
import pyautogui

Arduino_Serial = serial.Serial('com3',9600)

while 1:
    incoming_data = str (Arduino_Serial.readline())
    print incoming_data
    if 'Play' in incoming_data:
        pyautogui.press('space')
        
    if 'Down' in incoming_data:
        pyautogui.press('down')
        #pyautogui.scroll(-100)
    
    if 'Up' in incoming_data:
        pyautogui.press('up')
        #pyautogui.scroll(100)        
    
    if 'Change' in incoming_data:
        pyautogui.keyDown('alt')
        pyautogui.press('tab')
        pyautogui.keyUp('alt')
        
    if 'Close' in incoming_data:
        pyautogui.keyDown('alt')
        pyautogui.press('f4')
        pyautogui.keyUp('alt')
        
    incoming_data = "";
