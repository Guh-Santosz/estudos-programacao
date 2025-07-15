print("Digite suas notas: ")

i = int(0)

teste = [0,0,0]

soma = int(0)

media_ponderada = float(0)

media = float(0)

while i < 3:
    
    teste[i] = int(input(f"Digita a nota {i + 1}: "))

    soma += teste[i] 
    
    i += 1
    
media_ponderada = teste[0] * 0.4 + teste[1] * 0.4 + teste[2] * 0.2
media = soma / 3 

print(f"Sua média ponderada foi de: {media_ponderada}")
print(f"Sua média aritmética foi de: {media: .1f}")