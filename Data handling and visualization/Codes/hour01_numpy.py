import numpy as np 

#Step 1:Record daiy orders.
orders=np.array([120,150,180,140,120])

#Step 2: Calculate statistics
total_orders = np.sum(orders)
average_orders = np.mean(orders)    
highest_orders = np.max(orders) 
lowest_orders = np.min(orders) 

#Step 3: Print the results  
print("Daily orders:",orders)
print("Total orders:", total_orders)
print("Average orders:", average_orders)
print("Highest orders:", highest_orders)
print("Lowest orders:", lowest_orders)