teste = bool(False)

numero_secreto = int(45)

tentativas = int(1)

pontos = 100

print("     ---- Advinhe o número secreto ----  \n")
print("* Advinhe o número entre 0 a 100: \n")

palpite = int(input("   |Digite seu palpite: "))

if palpite > numero_secreto:
    
    print("\n     -> O número secreto é menor\n")
    
elif palpite < numero_secreto:
    
    print("\n     -> O número secreto é maior\n")

elif palpite == numero_secreto:
    
    print("\n **Parabéns você encontro o número secreto!\n")
    teste = True

if teste == False:
    
    while palpite != numero_secreto:
        
        palpite = int(input("   |Digite seu palpite: "))
        
        if palpite > numero_secreto:
            
            print("\n     -> O número secreto é menor\n")
            
        elif palpite < numero_secreto:
            
            print("\n     -> O número secreto é maior\n")
        
        tentativas = tentativas + 1
        
        pontos = pontos - 10

    print("\n **Parabéns você encontro o número secreto!\n")
    print(f"Você usou {tentativas} tentativas")
    print(f"Sua pontuação foi de {pontos} pontos")

