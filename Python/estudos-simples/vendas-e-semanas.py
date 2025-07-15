import os

quantidade_vendedores = int(2)
vendedores = [" "] * quantidade_vendedores
semanas = int(2)
vendas = [[0.00 for _ in range(semanas)] for _ in range(quantidade_vendedores)]
total_vendedor = [0.00] * quantidade_vendedores
total_semanas = [0.00] * semanas
total = float(0.00)

os.system("color 0f")

for i in range(quantidade_vendedores):

	vendedores[i] = str(input(f"|Digite o nome do vendedor {i + 1}: "))

	os.system('cls')

	for j in range(semanas):

		vendas[i][j] = float(input(f"|Digite quanto o(a) {vendedores[i]} vendeu na semana {j + 1}: R$ ")) 
		total += vendas[i][j]
		total_vendedor[i] += vendas[i][j]
		total_semanas[j] += vendas[i][j]

		os.system('cls')

for i in range(quantidade_vendedores):

	print(f"> Sobre o vendedor {vendedores[i]}:\n\n")

	for j in range(semanas):

		print(f"\tSemana {j + 1} ->  |Vendas: R$ {vendas[i][j]}0|")

	print(f"\n\t|Total: R$ {total_vendedor[i]}0|\n")

for i in range(semanas):

	print(f"|Total da semana {i + 1}: R$ {total_semanas[i]}0")

print(f"\n|O total de vendas do mês foi de: R$ {total}0")