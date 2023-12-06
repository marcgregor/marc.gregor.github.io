import tkinter as tk
from tkinter import *
import tkinter.font as font
import webbrowser
from PIL import Image
from PIL import ImageTk

# ============================================================================
# Name        : main.py
# Description : Enhancement One: Software Engineering and Design
#               Previously: Basic slideshow built using Java and JFrame
# Author      : Marc Gregor
# Contact     : marc.gregor@snhu.edu
# Date        : 5 December 2023
# Version     : 3.0 - Final Enhanced Edition

# Purpose     : My intent in this enhancement was to showcase my various
#               skills and abilities in software engineering and design to
#               implement solutions and ideas that helped boost an existing
#               piece of software. As a result, I decided to port this
#               slideshow, previously written in Java, into Python. I felt
#               this showed my ability to create a well-designed piece of
#               software in an entirely different language.

# Function    : A fully functional slideshow built using the tkinter interface
#               module to build the framework of the slideshow as well as the
#               Pillow library to add image processing capability.
# ============================================================================

####################################################################################
# INITIAL SETUP OF TKINTER FRAMEWORK, PILLOW PROCESSING OF IMAGES, AND STRINGS FOR #
# DESTINATION INFORMATION AND HYPERLINKS                                           #
####################################################################################

# Adjusts the slideshow's window
slideshow = tk.Tk()
slideshow.title("The Top Destinations for Wellness and to Detox")
slideshow.geometry("800x600")
# Locks window size
slideshow.resizable(False, False)

# Loads each of the 5 destination images and resizes them to equal size
koh_image = ImageTk.PhotoImage(Image.open("KohSamui.jpg").resize((640, 427)))
new_zealand_image = ImageTk.PhotoImage(Image.open("Glenorchy.jpg").resize((640, 427)))
portugal_image = ImageTk.PhotoImage(Image.open("DouroValley.jpg").resize((640, 427)))
indonesia_image = ImageTk.PhotoImage(Image.open("Bali.jpg").resize((640, 427)))
phuket_image = ImageTk.PhotoImage(Image.open("Phuket.jpg").resize((640, 427)))

# Adds the images into a list
image_list = [koh_image, new_zealand_image, portugal_image, indonesia_image, phuket_image]
# Creates a counter to keep track of the slide number
counter = 0

# Destination text quips
koh = "#1 Kamalaya, Koh Samui, Thailand.\n" \
      "Built into a hillside, the property \n" \
      "overlooks the ocean and is renown for \n" \
      "holistic treatment."
new_zealand = "#2 Aro Ha, Glenorchy, New Zealand. \n" \
        "Nestled in NZ's Southern Aps, this \n" \
        "retreat overlooks Lake Wakatip and \n" \
        "is completely powered by solar and water."
portugal = "#3 Six Senses Douro Valley, Portugal. \n" \
           "Tucked away in the vineyards of Douro Valley, \n" \
           "the restored 19th century manor is the ultimate \n" \
           "escape for yoga and cleansing."
indonesia = "#4 Fivelements, Bali, Indonesia. \n" \
            "Found in the lush jungles of Bali, this retreat \n" \
            "comes with spa treatments, meditation, \n" \
            "and a plant-based cuisine."
phuket = "#5 Amanpuri, Phuket, Thailand. \n" \
         "Overlooking the ocean, Amanpuri houses a \n" \
         "two-story spa that sits atop a hill. \n" \
         "It truly is a piece of paradise."

# Hyperlinks
koh_link = "https://kamalaya.com/"
new_zealand_link = "https://aro-ha.com/"
portugal_link = "https://www.sixsenses.com/en/resorts/douro-valley"
indonesia_link = "https://fivelementsbali.com/"
phuket_link = "https://www.aman.com/resorts/amanpuri"

####################################################################################
# DEFINITIONS OF METHODS FOR FUNCTIONALITY OF SLIDESHOW                            #
####################################################################################


# Defines a function to open the hyperlink for each slide
def callback(url):
    # Calls open_new_tab which will open up link in browser
    webbrowser.open_new_tab(url)


# Moves slideshow forward by clicking on "next" button
def move_forward():
    global counter
    # Every time move_forward is called, counter goes up by one
    if counter < len(image_list) - 1:
        counter += 1
    else:
        counter = 0
    image_label.config(image=image_list[counter])
    # Counter keeps track of what slide the show is on, and sets the text and link label based on the correct slide
    if counter == 0:
        info_label.config(text=koh)
        link_label.config(text=koh_link)
        link_label.bind("<Button-1>", lambda e: callback(koh_link))
    if counter == 1:
        info_label.config(text=new_zealand)
        link_label.config(text=new_zealand_link)
        link_label.bind("<Button-1>", lambda e: callback(new_zealand_link))
    if counter == 2:
        info_label.config(text=portugal)
        link_label.config(text=portugal_link)
        link_label.bind("<Button-1>", lambda e: callback(portugal_link))
    if counter == 3:
        info_label.config(text=indonesia)
        link_label.config(text=indonesia_link)
        link_label.bind("<Button-1>", lambda e: callback(indonesia_link))
    if counter == 4:
        info_label.config(text=phuket)
        link_label.config(text=phuket_link)
        link_label.bind("<Button-1>", lambda e: callback(phuket_link))


# Moves slideshow backward by clicking on "previous" button
def move_backward():
    global counter
    # Everytime move_backward is called, counter decreases by one
    if counter < len(image_list):
        counter -= 1
        # If counter attempts to go below zero, it resets to the highest counter/slide. Also prevents out of scope
        # issues
        if counter < 0:
            counter = 4
    else:
        counter = 0
    # Counter keeps track of what slide the show is on, and sets the text, image and link label
    # based on the correct slide
    if counter == 0:
        info_label.config(text=koh)
        image_label.config(image=image_list[counter])
        link_label.config(text=koh_link)
        link_label.bind("<Button-1>", lambda e: callback(koh_link))
    if counter == 1:
        info_label.config(text=new_zealand)
        image_label.config(image=image_list[counter])
        link_label.config(text=new_zealand_link)
        link_label.bind("<Button-1>", lambda e: callback(new_zealand_link))
    if counter == 2:
        info_label.config(text=portugal)
        image_label.config(image=image_list[counter])
        link_label.config(text=portugal_link)
        link_label.bind("<Button-1>", lambda e: callback(portugal_link))
    if counter == 3:
        info_label.config(text=indonesia)
        image_label.config(image=image_list[counter])
        link_label.config(text=indonesia_link)
        link_label.bind("<Button-1>", lambda e: callback(indonesia_link))
    if counter == 4:
        info_label.config(text=phuket)
        image_label.config(image=image_list[counter])
        link_label.config(text=phuket_link)
        link_label.bind("<Button-1>", lambda e: callback(phuket_link))

####################################################################################
# SETUP OF COMPONENTS, BUTTONS, AND CREATES PACK TO DISPLAY THE COMPONENTS         #
####################################################################################


# Defines the font for the buttons
button_font = font.Font(family='Castle', size=15, weight='bold')
# Defines the font for the information quip
info_font = font.Font(family='Courier', size=15, weight='bold')

# Sets up the components of the slideshow, as well as their initial points
slideshow.configure(background='black')
image_label = Label(slideshow, image=koh_image)
info_label = Label(slideshow, text=koh, font=info_font, bg="black", fg="white")
link_label = Label(slideshow, text=koh_link, fg="light blue", bg="black", cursor="hand2")
button = Button(slideshow, text="Next", font=button_font, width=10, height=1, bg="green", activebackground="grey",
                fg="white", activeforeground="black", command=move_forward)
button2 = Button(slideshow, text="Previous", font=button_font, width=10, height=1, bg="green", activebackground="grey",
                 fg="white", activeforeground="black", command=move_backward)

# Calls pack to display each component
image_label.pack()
info_label.pack()
link_label.pack(side="bottom", pady=3)
# calling bind will bind the hyperlink to a button; otherwise, the link would automatically execute
link_label.bind("<Button-1>", lambda e: callback(koh_link))
button.pack(side="right", pady=3, padx=30)
button2.pack(side="left", pady=3, padx=30)

# run the main loop
slideshow.mainloop()
