# -*- coding: utf-8 -*-
"""
Created on Thu Sep 12 10:57:34 2019

@author: Amir
"""

import serial
my_port=serial.Serial('COM16',9600)
def led_on():
    my_port.write('s'.encode())
def led_off():
    my_port.write('0'.encode())
#for i in range(1000):

    led_on()
    