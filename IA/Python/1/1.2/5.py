mass=int(input())
height=float(input())
bmi=mass/(height*height)
if bmi<18.5:
    print("High risk: the weight is too low")
elif bmi>=18.5 and bmi<=24.9:
    print("Minimum/Low risk")
elif bmi>=25 and bmi<=29.9:
    print("Low/Medium risk")
elif bmi>=30 and bmi<=34.9:
    print("Medium/High risk")
else:
    print("High risk: the weight it too high")
