delux_room = 7500
non_AC_room = 4500
room_type = str(input("which type of room is booked by the family"))
days_spent = int(input("How many days did they spent in the hotel"))
food_amount = int(input("How much amount is spent on food"))
print("for spending", days_spent, "days in hotel\n you are supposed to pay for the below expenditure")
print("facility\t-\tamount")

try:
    if room_type == 'delux':
        print('delux room\t-\t',delux_room)
        food_spent = int(0.18*food_amount + food_amount)
    elif room_type == 'non ac':
        print('Non-AC Room\t-\t', non_AC_room)
        food_spent = int(0.05*food_amount + food_amount)
except:
    print("Please enter a valid option ")
CGST = 0.09*food_amount
SGST = 0.09*food_amount
GST = CGST+SGST
tip = food_amount*0.1
total = days_spent*(food_spent+GST+delux_room)
grand_total = total + tip
print("Food spent\t-\t", food_spent)
print("CGST 9% on food\t-\t", CGST)
print("SGST 9% on food\t-\t", SGST)
print("---------------------------------")
print("Total GST\t-\t", GST)
print("---------------------------------")
print("Grand Total\t-\t", total)
print("Tip added\t-\t", tip)
print("---------------------------------")
print("Grand Total\t-\t", grand_total)