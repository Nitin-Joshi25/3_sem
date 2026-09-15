import pandas as pd 
import json 

structured_data = { 
    "id" : [1,2,3,4],
    "name": ["Maviya","Nitin","prince","Suhail"],
    "age" : [23,24,34,22]
}

df = pd.DataFrame(structured_data)

print("Stuctured Data:")

print(df)

json_data = {
    "customers" :[
        {"id" : 1, "name": "Rahul", "age": 23},
        {"id": 2, "name": "Nitin", "age" :21},
        {"id": 3, "name": "Rohit","age": 24}
    ]
}

with open("customers.json","w") as file:
    json.dump(json_data,file,indent =4 )

    print("\nJSON file created")