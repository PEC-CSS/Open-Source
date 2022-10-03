# Python Program in Tkinter to create a simple Hello World program.

# import everything from tkinter module
from tkinter import *


def name():
    """This function is used to get the name of the user and print it."""

    x=input("What is your name? :")
    print("hello",x,"I am made in tkinter.")


def close():
    """This function is used to close the program."""
    exit()

# Create a GUI window
root=Tk()


# Geometry
root.geometry('600x600')
root.minsize(500, 500)
root.maxsize(1920, 1080)
root['bg']="Green"

# Creating Labels
lbl=Label(text="HelloWorld",font="Courier 18 bold underline",bg="blue",fg="White").pack(pady=15)

# Adding Buttons
btn= Button(text="HelloWorld", font="Courier 22 bold", height=5, width= 20,bg="Yellow",borderwidth=4,command=name, relief=SUNKEN).pack()
btn2=Button(text="Press Me to ❌",fg="yellow",bg="Black",relief=SUNKEN,command=close).pack(pady=10)

# The mainloop
root.mainloop()