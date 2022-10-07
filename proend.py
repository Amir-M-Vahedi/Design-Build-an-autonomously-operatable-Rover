# -*- coding: utf-8 -*-
"""
Created on Tue Feb 18 20:31:38 2020

@author: Amir
"""

# -*- coding: utf-8 -*-
"""
Created on Sun Feb 16 22:44:28 2020

@author: Amir
"""

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Feb 13 18:12:54 2020

@author: appleland_kiarash
"""
from tkinter import *
import tkinter as tk
import numpy as np
import matplotlib.pyplot as plt
import serial
import time
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
    my_port.write('b'.encode())
def control_robot2() :
    a=3
    print(a)
    my_port.write('r'.encode())
def control_robot3() :
    a=4
    print(a)
    my_port.write('l'.encode())
def control_robot5() :
    a=5
    k=3
    print(a)
    my_port.write('a'.encode())
def signin():
    global name2
    global out1
    global out2
    name2=name1.get()
    Label(window,text="submited",font=("tahoma",20),bg="black",fg="white").pack(padx=200,pady=10)
    out1=check_btn1.get()
    out2=check_btn2.get()

def close_window():
    window.destroy()
counter = 0
data=[]
j=10
def counter_label(d1,d2):
    
    global j
    if (out1==1):
        global ss
        ss=' centimeters'
        def count():
            global data
            my_data=(my_port.readline())
            data.append(float(my_data.decode()))
            global counter
            global b
            global c
            global d
            global e
            global d2
            global d1
      #      global d3
       #     global d4
            counter = counter + 1
            if (counter==2):
                counter=0
                print(data)
                b=(data[0])
                c=data[1]
#                d=data[2]
#                e=data[3]
                d1.config(text=(str(b)+' cm'))
                d2.config(text=str(c)+' cm')
           #     d3.config(text=str(d)+' cm')
            #    d4.config(text= str (e)+' cm')
                data=[]
            d1.after(100,count)
        count()
    if (out2==1):
        ss=' feets'
        def count():
            global data
            my_data=(my_port.readline())
            data.append(float(my_data.decode()))
            global counter
            global b
            global c
            global d
            global e
            global d2
            global d1
        #    global d3
         #   global d4
            counter = counter + 1
            if (counter==2):
                counter=0
                print(data)
                b=(data[0])
                c=data[1]
#                d=data[2]
           #     e=data[3]
                d1.config(text=(str(b/30.48)+' ft'))
                d2.config(text=str(c/30.48)+' ft')
           #     d3.config(text=str(d)+' ft')
            #    d4.config(text= str (e)+' ft')
                data=[]
            d1.after(100,count)
        count()
        
      
      
      
        
    

 
window=Tk()
window.minsize(600,300)
window.resizable(width=False,height=False)
window.title("first values")
Label(window,text="your robot name :",font=("tahoma",20),bg="blue",fg="white").pack(side=TOP, expand=YES)
name1=Entry(window)
name1.pack()
Label(window,text="distance unit :",font=("tahoma",20),bg="red",fg="white").pack(side=TOP, expand=YES)
check_btn1=IntVar()
Checkbutton(window,text='in centimeters',variable=check_btn1).pack()
check_btn2=IntVar()
Checkbutton(window,text='in feet ',variable=check_btn2).pack()
Button(window,text='submit',font=("tahoma",20),bg="green",fg="red",command=signin).pack(side=TOP, expand=YES)
Button(window,text='go to controller',font=("tahoma",20),bg="green",fg="red",command=close_window).pack(side=TOP, expand=YES)
window.mainloop()



    

window=Tk()
window.title(name2+"'s control panel")        
window.minsize(600,300)       

window.resizable(width=False,height=False)      
Button(window,text='forward',font=("tahoma",20),bg="green",fg="red",padx=40,pady=10,command= control_robot1).pack(side=TOP)
 
Button(window,text=' left ',font=("tahoma",20),bg="green",fg="blue",padx=40,pady=10,command= control_robot2).pack(side = tk.LEFT)
      
Button(window,text=' right ',font=("tahoma",20),bg="green",fg="blue",padx=40,pady=10,command= control_robot3).pack(side = tk.RIGHT)
Button(window,text='backward',font=("tahoma",20),bg="green",fg="red",padx=40,pady=10,command= control_robot4).pack(side = tk.BOTTOM)
d1=Label(window,font=("tahoma",20),bg="yellow",fg="black")
d1.pack(side=TOP)
d2=Label(window,font=("tahoma",20),bg="yellow",fg="black")
d2.pack(side = tk.BOTTOM)
#d3=Label(window,font=("tahoma",20),bg="yellow",fg="black")
#d3.pack(side = tk.RIGHT)
#d4=Label(window,font=("tahoma",20),bg="yellow",fg="black")
#d4.pack(side = tk.BOTTOM)
Button(window,text='stop',font=("tahoma",20),bg="yellow",fg="red",padx=40,pady=10,command= control_robot5).pack(padx=100,pady=50)
  
counter_label(d1,d2)
window.mainloop()
      