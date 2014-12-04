#!/usr/bin/python

import os
import cgi,cgitb
import csv

print "Content-type:text/html\n\n"
form = cgi.FieldStorage()
bill_total = 0
online_users = []
logged_in = 0

##Load all users currently logged in into online_users##
f = open('LoggedIn.csv')
csv_f = csv.reader(f)
for row in csv_f:
    online_users.append(row[1])

inventory = []
quantity = []
price = []
              
##Load building names into inventory,
##quantity available into quantity,
##individual building price into price
f = open('Inventory.csv')
csv_f = csv.reader(f)

for row in csv_f:
    inventory.append(row[0])
    quantity.append(row[1])
    price.append(row[2])
f.close()

for user in online_users:
    if form.getvalue('username') == user:
        logged_in = 1
        

if logged_in == 1:
    print "Content-type:text/html\r\n\r\n"
    print "<html>"
    print "<head>"
    print "<title>Purchase Summary and Bill</title>"
    print "</head>"
    print "<body>"
    for i in range(len(inventory)):
        price[i] = int(price[i])
        if form.getvalue('checkbox{i}'):
            q = form.getvalue('input_quantity{i}')
            print "Item: %s     Quantity: %s     Price: %s" %(inventory[i],q,price[i]*q)
            bill_total += price[i]*q
    print "Total price:  $ %s" % (bill_total)
    print "<li class="menu-item"><a class="menu-url" href="index.html">Back to Homepage</a></li>"
    print "<li class="menu-item"><a class="menu-url" href="catalogue.html">Back to Catalogue</a></li>"
    print "</body>"
    print "</html>"
    
else:
    print "Content-type:text/html\r\n\r\n"
    print "<html>"
    print "<head>"
    print "<title>Error Page</title>"
    print "</head>"
    print "<body>"
    print "You must log in to purchase items!"
    print "<li class="menu-item"><a class="menu-url" href="catalogue.html">Back to Catalogue</a></li>"
    print "</body>"
    print "</html>"
    
