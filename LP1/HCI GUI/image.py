from tkinter import *
from PIL import ImageTk, Image

i = 1

root = Tk()
root.title("Image Viewer")
root.config(bg="black")
root.iconbitmap('D:/tkinter/Image Viewer/211677_image_icon.ico')

Label(root, text="Python Image Viewer", font='arial 15 bold', bg='#000000', fg="#ffffff").grid(row=0, column=0, columnspan=3)

my_image1 = ImageTk.PhotoImage(Image.open("D:/tkinter/Image Viewer/mountain.jpg"))
my_image2 = ImageTk.PhotoImage(Image.open("D:/tkinter/Image Viewer/parrot.jpg"))
my_image3 = ImageTk.PhotoImage(Image.open("D:/tkinter/Image Viewer/hogwart.jpg"))
my_image4 = ImageTk.PhotoImage(Image.open("D:/tkinter/Image Viewer/robert.jpg"))
my_image5 = ImageTk.PhotoImage(Image.open("D:/tkinter/Image Viewer/groot.jpg"))
my_img = [my_image1, my_image2, my_image3, my_image4, my_image5]

status = Label(root, text="Image 1 of " + str(len(my_img)), bd=1, relief=SUNKEN, anchor=E, bg='#000000', fg="#ffffff")

def next(n):
    global mylabel, next_button, back_button
    mylabel.grid_forget()
    mylabel = Label(image=my_img[n - 1])
    mylabel.grid(row=1, column=0, columnspan=3)
    next_button = Button(root, text=">>", command=lambda: next(n + 1))
    back_button = Button(root, text="<<", command=lambda: back(n - 1))
    button_quit = Button(root, text="Toggle Theme", command=toggle)
    
    if n == len(my_img):
        next_button = Button(root, text=">>", command=lambda: next(n + 1), state=DISABLED)
    
    back_button.grid(row=2, column=0)
    button_quit.grid(row=2, column=1)
    next_button.grid(row=2, column=2, pady=10)
    
    # Update status
    status.config(text="Image " + str(n) + " of " + str(len(my_img)))
    status.grid(row=3, column=0, columnspan=3, sticky=W + E)

def toggle():
    global i
    if i % 2 != 0:
        root.config(bg="white")
        Label(root, text="Python Image Viewer", font='arial 15 bold', bg='#ffffff', fg="#000000").grid(row=0, column=0, columnspan=3)

    else:
        root.config(bg="black")
        Label(root, text="Python Image Viewer", font='arial 15 bold', bg='#000000', fg="#ffffff").grid(row=0, column=0, columnspan=3)

    i += 1

def back(n):
    global mylabel, next_button, back_button
    mylabel.grid_forget()
    mylabel = Label(image=my_img[n - 1])
    mylabel.grid(row=1, column=0, columnspan=3)
    next_button = Button(root, text=">>", command=lambda: next(n + 1))
    back_button = Button(root, text="<<", command=lambda: back(n - 1))
    button_quit = Button(root, text="Toggle Theme", command=toggle)

    if n == 1:
        back_button = Button(root, text="<<", command=lambda: back(n - 1), state=DISABLED)

    back_button.grid(row=2, column=0)
    button_quit.grid(row=2, column=1)
    next_button.grid(row=2, column=2, pady=10)

    # Update status
    status.config(text="Image " + str(n) + " of " + str(len(my_img)))
    status.grid(row=3, column=0, columnspan=3, sticky=W + E)

mylabel = Label(image=my_img[0])
mylabel.grid(row=1, column=0, columnspan=3)

next_button = Button(root, text=">>", command=lambda: next(2))
back_button = Button(root, text="<<", state="disabled")

button_quit = Button(root, text="Toggle Theme", command=toggle)

back_button.grid(row=2, column=0)
button_quit.grid(row=2, column=1)
next_button.grid(row=2, column=2, pady=10)

status.grid(row=3, column=0, columnspan=3, sticky=W + E)

root.mainloop()
