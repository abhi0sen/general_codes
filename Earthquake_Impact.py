# Measuring the imapct of Earthquake

import math
Intensity = int(input("Enter the intensity of  earthquake "))
if Intensity <= 0:
    print("Please provide a valid intensity of earthquake")
else:
    Magnitude = math.log(Intensity)
    print ("The magnitde of earthquake is ", Magnitude)