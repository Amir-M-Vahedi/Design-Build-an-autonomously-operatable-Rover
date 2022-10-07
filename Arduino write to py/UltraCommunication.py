# -*- coding: utf-8 -*-
"""
Created on Thu Sep 12 11:46:06 2019

@author: Amir
"""

import serial
import matplotlib.pyplot as plt
import numpy as np
my_port=serial.Serial('COM16',9600)
def led_on():
    my_port.write('s'.encode())
def led_off():
    my_port.write('0'.encode())
data=[]
i=1
while True:
    
    my_data=(my_port.readline())
    data.append(float(my_data.decode()))
    led_on()
    i=i+1
    if (i==5):
        print(data)
        i=1
        data=[]
    
#    if len(data)==50:
#        break

#plt.plot(data)
#plt.show()
