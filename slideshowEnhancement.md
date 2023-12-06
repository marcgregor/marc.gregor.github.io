# Artifact One - Software Design and Engineering: Slideshow
[Link to the original and enhanced artifact](https://github.com/marcgregor/marcgregor.github.io/tree/main/Artifact%20One%20-%20Slideshow)

## Briefly Describe the Artifact. What is it? When was it Created?
Originally, it was a slideshow created in Java for CS250 back in 23EW3. Using the JFrame framework, the task was to create a slideshow revolving around 5 different destinations to travel. Each of the 5 slides had an image of the destination, as well as a blurb of information. 
## Justify the Inclusion of the Artifact in your ePortfolio. Why did you Select this Item? What Specific Components of the Artifact Showcase your Skills and Abilities in Software Development? How was the Artifact Improved?
My main justification in including this artifact is that I thought porting a slideshow into a different language would be a great way to showcase my talents – after all, it involves different libraries and frameworks instead of just a simple translation. Overall, my ability to take an existing piece of software and fully translate it into another language showcases the skill needed to port an entire program without error. This included correctly using libraries, such as Pillow, which adds image processing capabilities, and tkinter, which allows usage of the Tk GUI. In this initial instance, on top of creating it in Python, I also improved the color scheme to make it more appealing to look at, as well as adding hyperlinks to every slide that will bring the user to the destination’s website.
## Did you Meet the Course Objectives you Planned to Meet with the Enchancement in Module One? Do you have any Updates to your Outcome-Coverage Plans?
The following course objectives have been met:

### Outcome 1 - Employ strategies for building collaborative environments that enable diverse audiences to support organizational decision making in the field of computer science: 
I provided simple but concise in-line comments that provided not only the reasoning behind writing the code, but also the purpose of each main code block. I also used comments to split up the coding into different sections, such as initial setup and functions for user readability. I took the requirements given, gathered any additional information needed, and built the software around the requirements, while writing a narrative explaining the whys and hows of the enhancement. Finally, I wrote a reflective piece at the end of each enhancement to discuss my overall experience with the enhancement.
### Outcome 2 - Design, develop, and deliver professional-quality oral, written, and visual communications that are coherent, technically sound, and appropriately adapted to specific audiences and contexts:
These comments also provide a line of communication between the reader and developer, and this narrative allows the reader to understand what the artifact was, why I chose it, and also understand the improvements of the artifact. On top of that, the reflection describes my experience and explains what I considered to be the best overall practice to accomplishing the enhancement.
### Outcome 4 - Demonstrate an ability to use well-founded and innovative techniques, skills, and tools in computing practices for the purpose of implementing computer solutions that deliver value and accomplish industry-specific goals:
I was able to use my innovated skills and techniques to implement the solution of porting to a different language. I was able to prevent errors, such as out of scope values in lists, and I was able to follow the SDLC in order to produce this slideshow in a realistic schedule. I followed all standard conventions for Python (including naming conventions such as naming variables lowercase_underscore_lowercase). I declared string variables ahead of time, so I could reuse them in multiple situations, preventing the constant problem of reusing code, and I kept all related code blocks together. I used iterative testing by gradually making small changes to the program based on feedback (from both the enhancement plan and the initial enhancement), such as adding in additional comments about the purpose of the project and cleaning up the slideshow – I fixed any typos I found, as well as changing the hyperlink to make it more in-line with the rest of the slideshow.
## Reflect on the Process of Enhancing and/or Modifying the Artifact. What did you Learn as you were Creating it and Improving it? What Challenges did you Face?
Overall, it was an enjoyable experience. I’ve worked with multiple languages at once, but I’ve never directly ported a program from one language to another, so it was interesting to see close up how even though the syntax may change, overall, languages follow the same underlying concept. My biggest challenge was implementing the slide show. In Java, I used the JFrame frameworks to create the slideshow UI, so I had to do some research on the best route to go in order to implement a slideshow in Python.

# Original Artifact
<img width="590" alt="javaslideshow" src="https://github.com/marcgregor/marcgregor.github.io/assets/120348789/7730ef26-bb8a-4457-8890-ec40055edb51">

The original slideshow created in Java. It was a rough slideshow, with text that was difficult to see with the background color, the images were stretched and pixelated, and the overall presentation was lacking.

# Pseudocode for tkinter and Pillow Implmentation
```python
# Import both tkinter and Pillow modules
Import tkinter as tk
From tkinter import *
From PIL import Image
From PIL import ImageTk

# Adjusts the window screen and size
Root = tk.Tk()
Root.geometry(“800x800)

# Loads the images used for the slideshow
placeholder = ImageTk.PhotoImage(Image.open(“placeholder.png”))
placeholderTwo = ImageTk.PhotoImage(Image.open(“placeholder2.png”))
placeholderThree = ImageTk.PhotoImage(Image.open(“placeholder3.png”))
placeholderFour = ImageTk.PhotoImage(Image.open(“placeholder4.png”))
placeholderFive = ImageTk.PhotoImage(Image.open(“placeholder5.png”))

```
# Enhanced Artifact
<img width="601" alt="pythonslideshow" src="https://github.com/marcgregor/marcgregor.github.io/assets/120348789/88f463e0-d1e7-4713-968d-961fad8772d9">

The enhanced slideshow created in Python. Presentation is much neater, with much easier to read text. The pic is now centered, with a white border, and there is now a link to the destination included.

```python

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

```
Here, this code set up the initialization of the tkinter window, such as the title and size. Then, 5 images were loaded in and set to their corresponding variables, and finally added to an image list.
```python

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

```
This function is called when the Previous button is clicked on, which keeps track of the slide its currently on by a counter. Every click will decrease the value of the counter by one, and if it attempts to go below zero, it resets back to the highest counter value possible (the 5th slide in the show). Otherwise, an if statement will execute based on the counter value, which will then set the correct image and description.
