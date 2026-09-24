import pandas as pd 
data = {
"name": ["Rahul","Priya","Amit","Sohan"],
"age": [23,34,23,None],
"salary": [40000,50000,None,60000],
"city":["Delhi","Haridwar",None,"Bombay"]
}

df = pd.DataFrame(data)

print("Original:")
print(df)

#Numerical missing values
df["age"] = df["age"].fillna(df["age"].median())
df["salary"]= df["salary"].fillna(df["salary"].median())

#Categorical missing values
df["city"] = df["city"].fillna(df["city"].mode( )[0])


print("\nAfter handling missing values:")

print(df)