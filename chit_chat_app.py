def chit_chat_charater(message):
    print("The outcome of this part is of about 200 characters in a message")       # only for the tester not for the end user
    if len(message)<200:    # spliting the message into words and counting the words
        print("Your message is sent!, \n\n")
        return message
    else:
        print("your first 200 char which is sent as message is \n", message[:200])

def chit_chat_words(words):
    print("The outcome of this part is of about 30 words in a message")     # only for the tester not for the end user
    if len(words.split())<30:
        print("the message is", words)
        print("your message is sent!!")
    else:
        splitter = words.split()[:30]
        print("the first 30 words that are sent as a message", " ".join(splitter))     #.join() operators is referred from python doc or pythonbasics.org
    return words
user_message = input("enter your message in less than 200 char or 30 words!!")
print("the message of user is ", user_message)  # only for the tester not for the end user

chit_chat_charater(user_message)

chit_chat_words(user_message)