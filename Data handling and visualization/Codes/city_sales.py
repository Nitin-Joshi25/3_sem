sales = pd.DataFrame({
    "city": ["New York", "Los Angeles", "Chicago", "Houston", "Phoenix"],
    "sales": [1000, 1500, 800, 1200, 900]
})

city_sales = sales.groupby("city")["sales"].sum()

print(city_sales)