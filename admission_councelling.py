names = []      # assigning empty list for names
for i in range(10):
        student_name = input("Enter the name of student\n")
        names.append(student_name)      #adding students' name to 'name' list
    
admission_id = []       # assigning empty list for admission ID
for i in range(len(names)):
    enroll = input("Enter the application id of students\n")
    admission_id.append(enroll)     # adding application ID for the students

cap_rank = []       # assigning empty list for CAP rank
for i in range(len(names)):
    try:
        rank = int(input("Enter the CAP rank of student "))
        cap_rank.append(rank)       # showing CAP rank for the students
    except:
        print("please, Enter the valid entries")

    print(f'''Hi {names[i]}\n\n Congratulations...!  
    \n\t You got selected for next round of recruitment process 
    \n\t submit your academic credential including primary and secondary certificates. 
    \n\t Your admission ID is {admission_id[i]} and you will be eligible for the next round of interview with a CAP rank of {cap_rank[i]} 
    \n \tIf you submit all the documents on time and process university might offer you a scholarship. \n\n''')