def cálculos(a, b, c):

    if a == '/':

        if c == 0:

            print("-> Não é possível fazer divisão por 0")
            return

        div = b / c

        print(f"\n-> A divisão entre os números {b} e {c} é igual a: {div}")
        return

    soma = b + c
    sub = b - c
    mult = b * c

    if a == '+':

        print(f"\n-> A adição entre os números {b} e {c} é igual a: {soma}")

    elif a == '-':

        print(f"\n-> A subtração entre os números {b} e {c} é igual a: {sub}")

    elif a == '*':

        print(f"\n-> A multiplicação entre os números {b} e {c} é igual a: {mult}")
        
    else:

        print("-> Operação inválida!")
    

print("     ---- Calculadora do Balacubaco ----     \n\n")

print("* Existem 4 operações possíveis, são elas: \n")

print("     |Para Adição, digite: +       \n")
print("     |Para Subtração, digite: -    \n")
print("     |Para Multiplicação, digite: *\n")
print("     |Para Divisão, digite: /      \n")

operação = str(input(" \n|Escolha a operação que deseja fazer: "))

print("\nEscolha dois números para elaborar os cálculos: \n")

numero_um = float(input("     |Digite o primeiro número: "))
numero_dois = float(input("     |Digite o segundo número: "))

cálculos(operação, numero_um, numero_dois)