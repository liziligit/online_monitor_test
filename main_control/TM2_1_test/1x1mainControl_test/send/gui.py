import os
import time

from Tkinter import *
root = Tk()
root.title("Beam Monitor Control Panel")
root.geometry('1500x150')

var=StringVar()
e=Entry(root,textvariable=var,width=80)
var.set("")
e.pack()
print var.get()


def init():
    print os.system("./initi4Tm2-.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./initi4Tm2-.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def debug():
    print os.system("./debug4Tm2-.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./debug4Tm2-.sh "+ var.get()+"\n")
    f.close()
    var.set("")


def compileRealTime():
    print os.system("./compile4RealTime.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./compile4RealTime.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def pede():
    print os.system("./pede4.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./pede4.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def pedeCheck():
    print os.system("./pedeCheck4.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./pedeCheck4.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def onlinePd1():
    print os.system("./onlinePd14.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./onlinePd14.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def takeData():
    print os.system("./runData4.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./runData4.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def Pd1Draw2D():
    print os.system("./pd1Draw2D4.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./pd1Draw2D4.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def pixelPd1Draw():
    print os.system("./pd1DrawPixel4.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./pd1DrawPixel4.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def pixelCalibration():
    print os.system("./tau4.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./tau4.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def pd1Topd3():
    print os.system("./pd1Topd34.sh  "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./pd1Topd34.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def Pd3Draw2D():
    print os.system("./pd3Draw2D4.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./pd3Draw2D4.sh "+ var.get()+"\n")
    f.close()
    var.set("")

def pixelPd3Draw():
    print os.system("./pd3DrawPixel4.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./pd3DrawPixel4.sh "+ var.get()+"\n")
    f.close()



def editScript():
    print os.system("./editScript.sh "+ var.get())
    f = open('wuWei.log', 'a')
    f.write(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))+ "\t" + "./editScript.sh "+ var.get()+"\n")
    f.close()
    var.set("")


w=10
l=3

Button(root, text="Initialize", command = init, width=w, height=l).pack(side=LEFT)
Button(root, text="Start&Debug", command = debug, width=w, height=l).pack(side=LEFT)
Button(root, text="ComplieRealTime", command = compileRealTime, width=w, height=l).pack(side=LEFT)
Button(root, text="Pedestal", command = pede, width=w, height=l).pack(side=LEFT)
Button(root, text="Online Pd1", command = onlinePd1, width=w, height=l).pack(side=LEFT)
Button(root, text="Take Data", command = takeData,  width=w, height=l).pack(side=LEFT)
Button(root, text="Display 2D Pd1", command = Pd1Draw2D, width=w, height=l).pack(side=LEFT)
Button(root, text="Pixel Pd1 Draw", command = pixelPd1Draw, width=w, height=l).pack(side=LEFT)
Button(root, text="Pixel Calibration", command = pixelCalibration, width=w, height=l).pack(side=LEFT)
Button(root, text="Pd1 To Pd3", command = pd1Topd3, width=w, height=l).pack(side=LEFT)
Button(root, text="Display 2D Pd3", command = Pd3Draw2D, width=w, height=l).pack(side=LEFT)
Button(root, text="Pixel Pd3 Draw", command = pixelPd3Draw, width=w, height=l).pack(side=LEFT)
Button(root, text="Pedestal Check", command = pedeCheck, width=w, height=l).pack(side=LEFT)
Button(root, text="Edit Script", command = editScript, width=w, height=l).pack(side=LEFT)

root.mainloop()
