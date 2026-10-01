def age_group(age):
    if age < 18:
        return"Minor"
    elif age <30:
        return "Young Adult"
    elif age < 60:
        return "Adult"
    else:
        return "Senior"

    df[age_group] = df['age'].apply(age_group)

    print(df)