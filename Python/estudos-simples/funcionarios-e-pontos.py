receba = 3

maior_jan = 0
maior_dez = 0
maior_nov = 0
nov = [0] * receba
dez = [0] * receba
jan = [0] * receba
pontuacao_geral = [0] * receba
media = [0] * receba

p = 0
d = 0
j = 0
n = 0
i = 0

for i in range(3):
    
    if i == 0:
        
        print("Pontuação geral dos funcionários no mês de Novembro: \n")
        
        for n in range(receba):
            
            nov[n] = int(input(f"Digite a pontuação do funcionário {n + 1}: "))
            
            if maior_nov < nov[n]:
                
                maior_nov = nov[n]
    
    elif i == 1:
        
        print("\nPontuação geral dos funcionários no mês de Dezembro: \n")
        
        for d in range(receba):
            
            dez[d] = int(input(f"Digite a pontuação do funcionário {d + 1}: "))
            
            if maior_dez < dez[d]:
                
                maior_dez = dez[d]
    
    elif i == 2:
        
        print("\nPontuação geral dos funcionários no mês de Janeiro: \n")
        
        for j in range(receba):
            
            jan[j] = int(input(f"Digite a pontuação do funcionário {j + 1}: "))
            
            if maior_jan < jan[j]:
                
                maior_jan = jan[j]

print("")

for p in range(receba):
    
    pontuacao_geral[p] = nov[p] + dez[p] + jan[p]
    media[p] = (nov[p] + dez[p] + jan[p]) / 3

    print(f"    |A pontuação geral do funcionário {p + 1} foi de: {pontuacao_geral[p]}")
    print(f"    |A média do funcionário {p + 1} foi de: {media[p]}\n")

print("")

if maior_jan > maior_dez and maior_jan > maior_nov:
    
    print(f"    -> A maior pontuação foi de: {maior_jan}")
    
elif maior_dez > maior_jan and maior_jan > maior_nov:
    
    print(f"    -> A maior pontuação foi de: {maior_dez}")
    
elif maior_nov > maior_dez and maior_dez > maior_jan:
    
    print(f"    -> A maior pontuação foi de: {maior_nov}")