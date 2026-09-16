'''import pandas as pd 
df =  pd.read_csv("customers.csv")

print(df)

import pandas as pd

df = pd.read_excel("customers.xlsx")

print(df)'''


import json 
import pandas as pd
with open("customers.json","r") as file:
    data = json.load(file)

df = pd.json_normalize(data["customers"])

print(df)


df.to_parquet("customers.paequet")

new_df = pd.read("customers.parquet")

print(new_df)