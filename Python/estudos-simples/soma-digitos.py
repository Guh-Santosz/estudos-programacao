soma = int(0)

palavra = str(input("|Digite um número: "))
saida = palavra

tamanho = len(palavra)

for i in range(tamanho):

	soma += int(palavra[i])

print(f"\n > A soma das unidades do número {saida} é de: {soma}")
