#!/usr/bin/python

import os
import cgi,cgitb
import csv

form = cgi.FieldStorage()
bill_total = 0
online_users = []
logged_in = 1

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
    print "Bill of Sales:<br>"
    for i in range(len(inventory)):
        price[i] = int(price[i])
        if (form.getvalue('checkbox'+str(i)) and form.getvalue('input_quantity'+str(i))!=None):
            q = form.getvalue('input_quantity'+str(i))
            q=int(q)
            if(q > int(quantity[i])):
                print "Unfortunately, we only have %s of %s left in stock. We apologize for any inconvenience.<br>"%(quantity[i],inventory[i])
            else:
                print "Item: %s     Quantity: %s     Price: %s<br>" %(inventory[i],q,price[i]*q)
                bill_total += price[i]*q
    if bill_total == 0:
        print "No items selected!"
    else:
        print "Total price:  $ %s" % (bill_total)
#    print "<li class="menu-item"><a class="menu-url" href="index.html">Back to Homepage</a></li>"
#    print "<li class="menu-item"><a class="menu-url" href="catalogue.html">Back to Catalogue</a></li>"
    print "</body>"
    print "</html>"
    
    data = ["Trottier,%s,7500000"%quantity[0],
"McConnell,%s,2000000"%quantity[1],
"MacDonald,%s,1000000"%quantity[2],
"Leacock,%s,250000"%quantity[3],
"McIntyre,%s,45000"%quantity[4],
"Arts,%s,20"%quantity[5]]
    
    with open("Inventory.csv","wb") as csv_file:
        writer = csv.writer(csv_file)
        for line in data:
            writer.writerow(line.split(","))
    
else:
    print "Content-type:text/html\r\n\r\n"
    print "<html>"
    print "<head>"
    print "<title>Error Page</title>"
    print "</head>"
    print "<body>"
    print "You must log in to purchase items!"
#    print "<li class="menu-item"><a class="menu-url" href="catalogue.html">Back to Catalogue</a></li>"
    print "</body>"
    print "</html>"
    
