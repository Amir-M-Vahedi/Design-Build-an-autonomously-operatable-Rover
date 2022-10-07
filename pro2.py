#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Feb 13 18:12:54 2020

@author: appleland
"""
from tkinter import *
import tkinter as tk
import numpy as np
import matplotlib.pyplot as plt
import serial
my_port=serial.Serial('COM16',9600)
b=0
c=0
d=0
e=0
def control_robot1() :
    a=1
    print(a)
    my_port.write('1'.encode())
def control_robot4() :
    a=2
    print(a)
    my_port.write('2'.encode())
def control_robot2() :
    a=3
    print(a)
    my_port.write('3'.encode())
def control_robot3() :
    a=4
    print(a)
    my_port.write('4'.encode())
def control_robot5() :
    a=5
    k=3
    print(a)
    my_port.write('5'.encode())
def signin():
    global name2
    name2=name1.get()
    Label(window,text="submited",font=("tahoma",20),bg="black",fg="white").pack(padx=200,pady=10)
    out1=check_btn1.get()
    out2=check_btn2.get()
    if (out1==1):
        global ss
        ss=' meters'
    elif (out2==1):
        ss=' feets'
def close_window():
    window.destroy()
data=[]
i=1   
window=Tk()
window.minsize(600,300)
window.resizable(width=False,height=False)
window.title("first values")
Label(window,text="your robot name :",font=("tahoma",20),bg="blue",fg="white").pack(side=TOP, expand=YES)
name1=Entry(window)
name1.pack()
Label(window,text="distance unit :",font=("tahoma",20),bg="red",fg="white").pack(side=TOP, expand=YES)
check_btn1=IntVar()
Checkbutton(window,text='in meter',variable=check_btn1).pack()
check_btn2=IntVar()
Checkbutton(window,text='in feet ',variable=check_btn2).pack()
Button(window,text='submit',font=("tahoma",20),bg="green",fg="red",command=signin).pack(side=TOP, expand=YES)
Button(window,text='go to controller',font=("tahoma",20),bg="green",fg="red",command=close_window).pack(side=TOP, expand=YES)
window.mainloop()



window=Tk()
window.title(name2)
window.minsize(400,400)
window.resizable(width=False,height=False)
Button(window,text='forward',font=("tahoma",20),bg="green",fg="red",padx=40,pady=10,command= control_robot1).pack(side=TOP)
Button(window,text=' left ',font=("tahoma",20),bg="green",fg="blue",padx=40,pady=10,command= control_robot2).pack(side = tk.LEFT)
Button(window,text=' right ',font=("tahoma",20),bg="green",fg="blue",padx=40,pady=10,command= control_robot3).pack(side = tk.RIGHT)
Button(window,text='backward',font=("tahoma",20),bg="green",fg="red",padx=40,pady=10,command= control_robot4).pack(side = tk.BOTTOM)
#while True:
my_data=(my_port.readline())
data.append(float(my_data.decode()))
i=i+1
if (i==5):
    i=1
    print(data)
    b=data[0]
    c=data[1]
    d=data[2]
    e=data[3]
    data=[]
Label(window,text='distance : '+str(b)+ss,font=("tahoma",20),bg="yellow",fg="black").pack(side=TOP)
#Label(window,text='distance : '+str(e)+ss,font=("tahoma",20),bg="yellow",fg="black").pack(side = tk.LEFT)
Label(window,text='distance : '+str(c)+ss,font=("tahoma",20),bg="yellow",fg="black").pack(side = tk.RIGHT)
Label(window,text='distance : '+str(d)+ss,font=("tahoma",20),bg="yellow",fg="black").pack(side = tk.BOTTOM)
Button(window,text='stop',font=("tahoma",20),bg="yellow",fg="red",padx=40,pady=10,command= control_robot5).pack(padx=100,pady=100)
window.mainloop()
Label(window,text='distance : '+str(e)+ss,font=("tahoma",20),bg="yellow",fg="black").pack(side = tk.LEFT)
