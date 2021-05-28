storage = 0
while True:
    try:
        age_group = int(input("enter the age "))
    except:
        break
    if age_group<5:
        storage = storage+0
    elif age_group>=5 and age_grou=<15:
        storage = storage+20
    elif age_group>60:
        storage = storage+40
    else:
        storage = storage+60
Total_cost = round(storage,2)       #rounding up the cost till two digits
print("Total amount to be paid by the group of guest is",Total_cost)
print("!!Enjoy the Exhibition!!")