import pandas as pd 
data = {
"Customer_id" : [1,2,3,4,5,6],

"Name": ["Suhail","Prince","Nitin","Vansh","Lakshaya","Maviya"],
"age": [23,24,21,22,26,27],
"salary": [45000,50000,80000,60000,55000,40000],
"city": ["Delhi","Haridwar","Mohali","Pune","Mumbai","Hedrabad"]


}

df = pd.DataFrame(data)
#print(df)
#print(df.shape)
'''print(df.describe())
print(df.isna().sum())
print(df.duplicated())'''
print(df["city"].unique())
print(df["city"].value_counts())