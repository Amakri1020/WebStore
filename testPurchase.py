#!/usr/bin/python

import csv
online_users = []
inventory = []
quantity = []
price = []
f = open('LoggedIn.csv')
csv_f = csv.reader(f)

for row in csv_f:
    online_users.append(row[1])
    
f.close()

f = open('Inventory.csv',"rb")
csv_f = csv.reader(f)

for row in csv_f:
    inventory.append(row[0])
    quantity.append(row[1])
    price.append(row[2])
f.close()

q = raw_input("Enter quantity you wish to purchase: ")
q = int(q)
total = 0

for i in range(len(inventory)):
    price[i] = int(price[i])
    print "Item: %s | Quantity: %s | Price: %s" % (inventory[i],q,price[i]*q)
    total += price[i]*q
    #quantity[i] = quantity[i] - q

    
print "\nTotal Price: $%s" %(total)
    
    
    
