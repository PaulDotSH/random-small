nota_lab = (int(input()) + int(input())) / 2
nota_examen = int(input())
if (nota_lab<5 or nota_examen<5):
    print("failed")
else:
    print(round(0.7*nota_lab+0.3*nota_examen,2))
