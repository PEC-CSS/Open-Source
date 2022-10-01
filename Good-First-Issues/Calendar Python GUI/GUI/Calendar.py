# Program to create a GUI-based Calendar application

# Importing the required modules.
import os
import sys
from PIL import Image
from tkinter import *
from tkinter import messagebox
from tkinter.tix import *


# creating a path for the icon of the window.
def resource_path(relative_path):
    """Get absolute path to resource, works for dev and for PyInstaller."""

    base_path = getattr(sys, '_MEIPASS', os.path.dirname(os.path.abspath(__file__)))
    return os.path.join(base_path, relative_path)

path = resource_path("./Icon//Icon.ico")

import calendar


def calendar_():
    """Defining a function to Create a separate window to display the calendar."""

    global year                                                                                                         # Defining a global variable.

    try:
        int(en1.get())

    except Exception as e:
        if len(en1.get()) == 0:
            messagebox.showerror("Error", "Error! : No value has been entered for year.")
        else:
            messagebox.showerror("Error", "Error! : " + str(e))

    # Prompting Error if user enters no input.
    if int(en1.get()) <= 0:
        messagebox.showerror("Error", "Error! :  Year cannot be -ve or 0.")

    else:
        # Creating an exception if invalid integer is entered by the user.
        try:
            year = int(en1.get())                                                                                       # Getting value from entry box 1.

        except Exception as e:
            messagebox.showerror("Error", str(e))

        # Using calendar library to print the Calendar.
        cal = calendar.calendar(year)

        # Creating a different window to print Calendar
        top1 = Toplevel(root2)

        # Title and icon.
        top1.title(f"{year} Calendar")
        
        try:
            top1.iconbitmap(path)
        except Exception as e:
            messagebox.showerror("Error", "icon - \"PEC logo.ico\" not found.")

        # Geometry.
        top1.geometry('640x620')
        top1.minsize(640, 630)
        top1.maxsize(640, 630)

        # Content.
        txt1 = Text(top1, relief=RIDGE, borderwidth=2, width=100, height=100)                                           # Text box 1.
        txt1.pack(padx=20, pady=10)

        txt1.insert('end', cal)                                                                                         # Inserting calendar string in Text box 1.

        top1.mainloop()


root2 = Tk()

# Title and icon.
root2.title("Question 2")

try:
    root2.iconbitmap(path)
except Exception as e:
    messagebox.showerror("Error", "icon - \"PEC logo.ico\" not found.")

# Geometry
root2.geometry('400x300')
root2.minsize(350, 270)
root2.maxsize(500, 400)

# Background Color.
root2['bg'] = 'grey'

# Heading
Heading = Label(root2, text="Calendar Application", bd=5, font='Aerial 22 underline', bg='black', fg='white',
                relief=RAISED)
Heading.pack(pady=10, ipadx=10)

# Creating a frame.
f1 = Frame(root2, bd=20)
f1.pack(ipady=7, ipadx=30)

# Content
lb1 = Label(f1, text="Enter year :", font="Arial 14")                                                                   # Label 1.
lb1.pack(pady=5)

tip1 = Balloon()                                                                                                        # tip1 for suggestion message.
tip1['bg'] = 'white'

en1 = Entry(f1, font="Arial 14", width=18)                                                                              # Entry box 1.
en1.pack(pady=5)

tip1.bind_widget(en1, balloonmsg="Enter the year (Integer)")

tip2 = Balloon()                                                                                                        # tip2 for suggestion message.
tip2['bg'] = 'white'

bt1 = Button(f1, text="Show Calendar", command=calendar_, cursor='hand2', font="Arial 13")                              # Button 1.
bt1.pack(pady=10, ipadx=20)

tip2.bind_widget(bt1, balloonmsg="Click to show Calendar.")

root2.mainloop()