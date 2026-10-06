import pandas as pd
from sklearn.preprocessing import MinMaxScaler 
df= pd.DataFrame({
    "age":[20,30,40,50],
    "salary":[20000,30000,40000,50000]
})

'''df["age_normalized"] = (df["age"] - df["age"].min()) / (df["age"].max() - df["age"].min())

df["salary_normalized"] = (df["salary"] - df["salary"].min()) / (df["salary"].max() - df["salary"].min())

print(df)'''

scaler = MinMaxScaler()

df[["age", "salary"]] = scaler.fit_transform(df[["age", "salary"]])

print(df)