# input from user height and weight
weight = int(input("Enter your weight: "))
height = int(input("Enter your height: "))

# calculating BMI
# bmi = (weight/(height*height))*10000
bmi = (weight/(height*height))*10000
formatted_bmi = "{:.2f}".format(bmi)

# bmi <= 18.5 , Underweight
if bmi <= 18.5:
    print("BMI = "+ str(formatted_bmi) + ", Underweight")
# bmi between 18.5 and 24.9 , Normal weight
elif bmi > 18.5 and bmi <= 24.9:
    print("BMI = " + str(formatted_bmi) + ", Normal Weight")
# bmi between 25 and 29.9 , Overweight
elif bmi >= 25 and bmi <= 29.9:
    print("BMI = " + str(formatted_bmi) + ", Overweight")
# bmi 30 or more , Obesity
else:
    print("BMI = " + str(formatted_bmi) + ", Obesity")
