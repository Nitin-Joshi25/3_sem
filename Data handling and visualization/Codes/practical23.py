import pandas as pd
from sklearn.preprocessing import MinMaxScaler 
from sklearn.preprocessing import StandardScaler     
data ={
    "customer_id": [101, 102, 103,104,105,105,106],
    "name":["Alice", "Bob", "Charlie", "David", "Eve", "Eve", "Frank"],
    "age":[25, 30, 35, None, 28, 28, 33],
    "city":["Delhi", "mumbai", "Bangalore", "delhi", "Kolkata", "Kolkata", "Hyderabad"],
    "salary":[50000, 60000, None, 80000, None, 55000, 65000],
    "orders":[5, 10, 15, 20, 8, 8, 12]

}

df = pd.DataFrame(data)
'''print(df.head())
print(df.shape)
print(df.info())
print(df.describe())
print(df.isna().sum())#no null values.
print(df.duplicated().sum())#1 duplicate value.'''
#df = df.drop_duplicates("customer_id")#drop duplicate values.

#df["city"] = df["city"].str.title()
#df["age"]= df["age"].fillna(df["age"].median()) 

#df["salary"]= df["salary"].fillna(df["salary"].median())

df["estimated_revenue"] = df["orders"]*1500
#scaler = MinMaxScaler()
#df["salary_normalized"] = scaler.fit_transform(df[["salary"]]) 

#scaler = StandardScaler()
#features = ["age", "salary", "orders","estimated_revenue"]
#df[features]= scaler.fit_transform(df[features])      
print(df)
