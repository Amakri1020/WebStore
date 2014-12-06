#!/usr/bin/python

import os
import cgi,cgitb
import csv

form = cgi.FieldStorage()
bill_total = 0
online_users = []
logged_in = 0

##Load registered members into users
f = open('Members.csv')
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

##Check the catalogue's hidden HTML field,
##if it matches a user they are logged in
for user in online_users:
    if form.getvalue('username') == user:
        logged_in = 1
        

##If user is logged in generate bill of sales html
if logged_in == 1:
    print "Content-type:text/html\r\n\r\n"
    print "<html>"
    print "<head>"
    print "<title>Purchase Summary and Bill</title>"
    print "</head>"
    print "<body>"
    print "Bill of Sales:<br>"
    
    ##For each inventory item, take some verification steps
    ##and if everything is ok add total to their bill
    for i in range(len(inventory)):
        price[i] = int(price[i])
        if (form.getvalue('checkbox'+str(i)) and form.getvalue('input_quantity'+str(i))!=None):
            q = form.getvalue('input_quantity'+str(i))
            q=int(q)
            ##Make sure they haven't exceeded quantity
            if(q > int(quantity[i])):
                print "Unfortunately, we only have %s of %s left in stock. We apologize for any inconvenience.<br>"%(quantity[i],inventory[i])
            else:
                print "Item: %s,     Quantity: %s,     Price: $%s CAD<br>" %(inventory[i],q,price[i]*q)
                bill_total += price[i]*q
                quantity[i] = str(int(quantity[i])-q)
    ##If no items selected but they're logged in show this msg
    ##Otherwise print their total price
    if bill_total == 0:
        print "No items selected!"
    else:
        print "Total price:  $%s<br> CAD" % (bill_total)
    print "<a href='index.html'>Back to Homepage</a>"
    print "<a href='catalogue.html'>Back to Catalogue</a>"
    print "</body>"
    print "</html>"
    
    ##generate data with new inventory amounts
    data = ["Trottier,%s,7500000"%quantity[0],
"McConnell,%s,2000000"%quantity[1],
"MacDonald,%s,1000000"%quantity[2],
"Leacock,%s,250000"%quantity[3],
"McIntyre,%s,45000"%quantity[4]]
    
    ##write new data to inventory.csv
    with open("Inventory.csv","wb") as csv_file:
        writer = csv.writer(csv_file)
        for line in data:
            writer.writerow(line.split(","))

#if they aren't logged in show this error page
else:
    print "Content-type:text/html\r\n\r\n"
    print "<html>"
    print "<head>"
    print "<title>Error Page</title>"
    print "</head>"
    print "<body>"
    print "You must log in to purchase items!<br>"
    print "<a href='index.html'>Back to Homepage</a>"
    print "<a href='catalogue.html'>Back to Catalogue</a>"
    print "</body>"
    print "</html>"
    
