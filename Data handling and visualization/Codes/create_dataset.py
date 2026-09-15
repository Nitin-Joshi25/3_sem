import pandas as pd 
customers =  [ 
    {
        "customer_id" : 1,
        "name":"Rahul",
        "age":23,
        "city":"Delhi"
    },

{
    "customer_id" :2, 
    "name":"Raju",
    "age":25,
    "city":"Dholakpur"
},

{
    "customer_id" : 3,
    "name":"Bheem",
    "age":21,
    "city":"Haridwar"
}

]

df = pd.DataFrame(customers)

print(df)

df.to_csv("customers.csv", index =False)

print("Data saved successfully.")