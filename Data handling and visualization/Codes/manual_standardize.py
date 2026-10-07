import pandas as pd 
from sklearn.preprocessing import StandardScaler    
df = pd.DataFrame({
    "salary": [1000, 2000, 3000, 4000],
    "age": [25, 30, 35, 40]
})


mean = df["salary"].mean()
std  = df["salary"].std()

df["salary"] = (df["salary"] - mean) / std
scaler = StandardScaler()
df[["age", "salary"]] = scaler.fit_transform(df[["age", "salary"]])
print(df)