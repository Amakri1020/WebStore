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
    quantity[i] = str(int(quantity[i]) - q)
    
print "\nTotal Price: $%s" %(total)

data = ["Trottier,%s,7500000"%quantity[0],
"McConnell,%s,2000000"%quantity[1],
"MacDonald,%s,1000000"%quantity[2],
"Leacock,%s,250000"%quantity[3],
"McIntyre,%s,45000"%quantity[4],
"Arts,%s,20"%quantity[5]]
print data

with open("Inventory.csv","wb") as csv_file:
    writer = csv.writer(csv_file)
    for line in data:
        writer.writerow(line.split(","))
    
    
    
