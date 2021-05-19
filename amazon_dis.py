def amazon (prime , shop_amount):
    if prime=='yes':
        discount = int((15 * shop_amount/100) +(8 * shop_amount/100))
        result = shop_amount-discount
        print("payable amount by the prime member is")
    else:
        discount = int(8 * shop_amount/100)
        result = shop_amount -discount
        print("payable amount by the normal customer is")
    return result
prime_member = input("Is the customer a prime member?\n Yes \n No \n")
while True:
    try:
        shop_amount = int(input("Enter the payable amount by the customer "))
        break
    except:
        print("please enter the shopping amount")
if prime_member=="yes":
    print(amazon('yes' , shop_amount))
else:
    print(amazon('no' , shop_amount))