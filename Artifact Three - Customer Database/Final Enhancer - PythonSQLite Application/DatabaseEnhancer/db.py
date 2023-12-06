import sqlite3


class Database:
    # Initializes and creates table 'customers' if it does not already exist with the fields id (primary key),
    # first_name, last_name, address, city, state, and zipcode
    def __init__(self, db):
        self.conn = sqlite3.connect(db)
        self.cur = self.conn.cursor()
        self.cur.execute(
            "CREATE TABLE IF NOT EXISTS customers (id INTEGER PRIMARY KEY, first_name text, last_name text, "
            "address text, city text, state text, zipcode text)")
        self.conn.commit()

    # Function that runs a SELECT query; this will populate the treeview for the user to see
    def fetch(self):
        self.cur.execute("SELECT * FROM customers")
        rows = self.cur.fetchall()
        return rows

    # Function that runs an INSERT INTO query; this will be called when the user wants to add the customer
    # into the database
    def insert(self, first_name, last_name, address, city, state, zipcode):
        # Parameterized query to help prevent sql injections
        self.cur.execute("INSERT INTO customers VALUES (NULL, ?, ?, ?, ?, ?, ?)",
                         (first_name, last_name, address, city, state, zipcode))
        self.conn.commit()

    # Function that runs a DELETE FROM query; this is called when the user wants to delete a customer from
    # the database and uses the id of the customer as the parameter
    def remove(self, id):
        self.cur.execute("DELETE FROM customers WHERE id= " + str(id))
        self.conn.commit()

    # Function that runs an UPDATE query; this will be called when the user wants to update an existing customer's
    # data
    def update(self, id, first_name, last_name, address, city, state, zipcode):
        self.cur.execute("UPDATE customers SET first_name = ?, last_name = ?, address = ?, city = ?,"
                         "state = ?, zipcode = ? WHERE id = ?",
                         (first_name, last_name, address, city, state, zipcode, id))
        self.conn.commit()

    def __del__(self):
        self.conn.close()
