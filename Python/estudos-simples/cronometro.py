import time
import os

segundos = 0
minutos = 0
horas = 0
infinito = True

while infinito:

	time.sleep(1)
	segundos += 1
	os.system('cls')
	print(f"{horas}:{minutos}:{segundos}")

	if segundos == 60:

		segundos = 0
		minutos += 1

	if minutos == 60:

		minutos = 0
		horas += 1	

	if horas == 24:

		segundos = 0
		minutos = 0
		horas = 0

		break

print("Um dia foi completado")
