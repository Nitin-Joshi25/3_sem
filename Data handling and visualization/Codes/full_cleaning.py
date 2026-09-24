import pandas as pd 
data = {
    "customer_id": [1,2,3,4,4],
    "name":["lakshaya","Nitin","Prince","Suhail","Suhail"],
    "age": [21,24,None,33,21],
    "salary": [45000,80000,50000,40000,45000],
    "city":["Roorke","Haridwar","Uttar.P","Delhi","Delhi"]
}

df = pd.DataFrame(data)

#Remove duplicates
df = df.drop_duplicates()

#Clean names
df["name"] = df["name"].str.strip().str.title()

#Clean city names
df["city"] = df["city"].str.strip().str.title()

#Clean city values
df["city"] = df["city"].str.strip().str.title()

#Convert numerical fields

df["age"] = pd.to_numeric(df["age"],errors = "coerce")
df["salary"] = pd.to_numeric(df["salary"], errors = "coerce")

print(df)
