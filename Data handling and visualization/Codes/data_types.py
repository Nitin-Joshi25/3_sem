import pandas as pd 

data  = {
    "name" : ["Nitin","Dholu","Jaggu"],
    "age": [21,23,22],
    "salary": [450000.0,50000.0,45000.0],
    "city": ["Haridwar","Pune","Mumbai"],
    "is_active": [True, False, True]
}

df = pd.DataFrame(data)
print(df)
print("\nData Types:")
print(df.types)
