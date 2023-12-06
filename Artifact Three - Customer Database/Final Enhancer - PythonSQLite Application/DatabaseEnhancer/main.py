import tkinter
from tkinter import *
from tkinter import messagebox, ttk

from db import Database

# ============================================================================
# Name        : main.py; db.py
# Description : Enhancement Three: Database
#               Previously: SQL database that held customer information
# Author      : Marc Gregor
# Contact     : marc.gregor@snhu.edu
# Date        : 5 December 2023
# Version     : 3.0 - Final Enhanced Edition
#
# Purpose     : My intent in this enhancement was to showcase my various
#               skills and abilities in database manipulation and creativity.
#               Since, the original project was just a simple SQL database
#               with no UI or user-friendliness, this enhancement was going
#               to be as close as possible to creating something entirely
#               from the ground up, showcasing my ability to take a single
#               screenshot of some SQL queries and turning it into an
#               entire program.
#
# Function    : Python integration with SQLite; creates a SQLite database to
#               hold customer data. Uses Python for tkinter GUI for user
#               friendliness. Components give user ability to manipulate data
#               for their own needs, such as adding/removing a customer.
# ============================================================================

####################################################################################
# INITIAL SETUP OF TKINTER FRAMEWORK, OBTAINING THE DATABASE, AND CONFIGURING      #
# WINDOW                                                                           #
####################################################################################

db = Database('customers.db')

# Create window object
app = Tk()
app.title('Customer Manager')
app.configure(background='light blue')
app.geometry('800x500')
# Prevents window from being resized
app.resizable(False, False)

####################################################################################
# DEFINING FUNCTIONS THAT PROVIDE VIEW OF DATA, AS WELL AS THE FUNCTIONALITY FOR   #
# USER MANIPULATED ACTIONS, SUCH AS ADDING OR REMOVING CUSTOMER                    #
####################################################################################


# Function that populates the tableview with customer data
def table_view():
    # Clears initial data when customer gets updated
    for item in customer_tree.get_children():
        customer_tree.delete(item)

    # Adds the customer data from the database into the treeview
    for row in db.fetch():
        customer_tree.insert("", 'end', text='', values=row)


# Function that adds customer to database
def add_customer():
    # Returns an error message if any of the input fields are empty
    if first_name.get() == '' or last_name.get() == '' or address.get() == '' or city.get() == ''\
            or state.get() == '' or zipcode.get() == '':
        messagebox.showerror('Required Fields', 'Please include all fields')
        return
    # Calls insert function from database class to insert the customer into the database by entering each field
    db.insert(first_name.get(), last_name.get(), address.get(), city.get(), state.get(), zipcode.get())
    clear_data_fields()
    table_view()


# Function that selects a customer's data when clicked on to populate the entry fields
def populate_customer_entry(event):
    try:
        global values
        # Removes any entries already filled in
        first_name_entry.delete(0, END)
        last_name_entry.delete(0, END)
        address_entry.delete(0, END)
        city_entry.delete(0, END)
        state_entry.delete(0, END)
        zipcode_entry.delete(0, END)

        # Gets customer
        selected = customer_tree.focus()
        # Gets values
        values = customer_tree.item(selected, 'values')

        # Inserts the customer's data into the data fields
        first_name_entry.insert(0, values[1])
        last_name_entry.insert(0, values[2])
        address_entry.insert(0, values[3])
        city_entry.insert(0, values[4])
        state_entry.insert(0, values[5])
        zipcode_entry.insert(0, values[6])
    except IndexError:
        pass


# Function that will delete the customer from the database
def remove_customer():
    # Calls the remove function from database class with the values parameter to delete the customer record
    db.remove(values[0])
    clear_data_fields()
    table_view()


# Function that updates the customer data
def update_customer():
    # Calls update function from database class with the updated field data
    db.update(values[0], first_name.get(), last_name.get(),
              address.get(), city.get(), state.get(), zipcode.get())
    table_view()


# Function that removes the data fields when button is pressed
def clear_data_fields():
    # Deletes each entry field input
    first_name_entry.delete(0, END)
    last_name_entry.delete(0, END)
    address_entry.delete(0, END)
    city_entry.delete(0, END)
    state_entry.delete(0, END)
    zipcode_entry.delete(0, END)


# Function that outputs message letting user know the program is a prototype along with current and expected features
def help_message():
    tkinter.messagebox.showinfo("Welcome to Customerio - the Customer Database",
                                "Hello! Customerio is still in prototype, but feel free to try our product. \n\n"
                                "Add Customer: Adds entered data into customer data base. Please make sure"
                                "all parameters are entered. \n\n"
                                "Remove Customer: Removes selected customer from database \n\n"
                                "Update Customer: Updates selected customer from database \n\n"
                                "Clear Input: clears the entry fields from text \n\n"
                                "Clicking on a customer in the table will bring up their data on the entry fields,"
                                "making it possible to update their information. \n\n"
                                "Clicking on column heading will sort based on column in as/descinding order")

####################################################################################
# CREATES LABELS AND ENTRY COMPONENTS FOR EACH FIELD AND SETS TO SPOT IN GRID      #
####################################################################################


# First Name data label and entry field. Sets it to grid for placement, and sets the variable to the declared string
first_name = StringVar()
first_name_label = Label(app, text='First Name', font=('bold', 14), bg="light blue")
first_name_label.grid(row=0, column=0, sticky=E)
first_name_entry = Entry(app, textvariable=first_name)
first_name_entry.grid(row=0, column=1)
# Last Name data label and entry field. Sets it to grid for placement, and sets the variable to the declared string
last_name = StringVar()
last_name_label = Label(app, text='Last Name', font=('bold', 14), bg="light blue")
last_name_label.grid(row=1, column=0, sticky=E)
last_name_entry = Entry(app, textvariable=last_name)
last_name_entry.grid(row=1, column=1)
# Address data label and entry field. Sets it to grid for placement, and sets the variable to the declared string
address = StringVar()
address_label = Label(app, text='Address', font=('bold', 14), bg="light blue")
address_label.grid(row=2, column=0, sticky=E)
address_entry = Entry(app, textvariable=address)
address_entry.grid(row=2, column=1)
# City data label and entry field. Sets it to grid for placement, and sets the variable to the declared string
city = StringVar()
city_label = Label(app, text='City', font=('bold', 14), bg="light blue")
city_label.grid(row=3, column=0, sticky=E)
city_entry = Entry(app, textvariable=city)
city_entry.grid(row=3, column=1)
# State data label and entry field. Sets it to grid for placement, and sets the variable to the declared string
state = StringVar()
state_label = Label(app, text='State', font=('bold', 14), bg="light blue")
state_label.grid(row=4, column=0, sticky=E)
state_entry = Entry(app, textvariable=state)
state_entry.grid(row=4, column=1)
# Zipcode data label and entry field. Sets it to grid for placement, and sets the variable to the declared string
zipcode = StringVar()
zipcode_label = Label(app, text='Zipcode', font=('bold', 14), bg="light blue")
zipcode_label.grid(row=5, column=0, sticky=E)
zipcode_entry = Entry(app, textvariable=zipcode)
zipcode_entry.grid(row=5, column=1)
# Company label
logo_label = Label(app, text='CustoData Limited', font=('Comic Sans MS', 20, 'bold italic'), bg="blue", fg="grey")
logo_label.grid(row=0, column=2, rowspan=2, columnspan=2)

####################################################################################
# SETTING UP AND CREATING TREEVIEW FOR DATA VIEWING                                #
####################################################################################

# Setting up the style for the treeview
style = ttk.Style(app)
style.theme_use("clam")
style.configure("Treeview", background="white", fieldbackground="white", foreground="black")
# Sets up the heading
style.configure("Treeview.Heading", background="blue", foreground="white")

# The treeview is created with a select mode of browse, which allows for single row clicking
customer_tree = ttk.Treeview(app, selectmode='browse')
customer_tree.grid(row=18, column=0, columnspan=5, padx=15, pady=15, sticky='nsew')


# Function to sort the Treeview by column
def sort_treeview(tree, col, descending):
    data = [(tree.set(item, col), item) for item in tree.get_children('')]
    data.sort(reverse=descending)
    for index, (val, item) in enumerate(data):
        tree.move(item, '', index)
    tree.heading(col, command=lambda: sort_treeview(tree, col, not descending))


# Sets up the columns and where each column gets the data from
customer_tree['columns'] = ('id', 'first_name', 'last_name', 'address', 'city', 'state', 'zipcode')
customer_tree.column('#0', width=0)
customer_tree.column('id', width=20)
customer_tree.column('first_name', width=100)
customer_tree.column('last_name', width=100)
customer_tree.column('address', width=200)
customer_tree.column('city', width=100)
customer_tree.column('state', width=100)
customer_tree.column('zipcode', width=100)

# Sets up the heading names
customer_tree.heading('id', text='ID')
customer_tree.heading('first_name', text='First Name')
customer_tree.heading('last_name', text='Last Name')
customer_tree.heading('address', text='Address')
customer_tree.heading('city', text='City')
customer_tree.heading('state', text='State')
customer_tree.heading('zipcode', text='Zip Code')

# Sets up the columns to be allowed to be sorted via clicking on heading
for col in customer_tree['columns']:
    customer_tree.heading(col, text=col, command=lambda c=col: sort_treeview(customer_tree, c, False))
    customer_tree.column(col, width=100)

####################################################################################
# CREATES BUTTONS                                                                  #
####################################################################################

# Add customer button. Calls add_customer when clicked
add_btn = Button(app, text='Add Customer', width=14, command=add_customer)
add_btn.grid(row=2, column=2, padx=5, pady=5)

# Remove customer button. Calls remove_customer when clicked
remove_btn = Button(app, text='Remove Customer', width=14, command=remove_customer)
remove_btn.grid(row=3, column=2, pady=5)

# Update customer button. Calls update_customer when clicked
update_btn = Button(app, text='Update Customer', width=14, command=update_customer)
update_btn.grid(row=4, column=2, pady=5)

# Clear fields button. Calls clear_data_fields when clicked
clear_btn = Button(app, text='Clear Input', width=14, command=clear_data_fields)
clear_btn.grid(row=2, column=3, pady=5)

# Help button. Calls help_message when clicked
help_btn = Button(app, text='Help/Info', width=14, command=help_message)
help_btn.grid(row=4, column=3, pady=5)

# Bind the treeview to releasing left mouse button
customer_tree.bind('<ButtonRelease-1>', populate_customer_entry)

# Populate data into treeview
table_view()

# Start program
app.mainloop()
