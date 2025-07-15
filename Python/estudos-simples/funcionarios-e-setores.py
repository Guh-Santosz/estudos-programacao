i = int(0)
l = int(0)
maior_salario = float(0)
menor_salario = float(2000)
tempo = 0
setor_maior_salario = 0
setor_menor_salario = 0
maior_tempo = int(0)
funcionario_com_maior_tempo = int(0)
setor_funcionario_com_maior_tempo = int(0)
funcionario_maior_salario = int(0)
funcionario_menor_salario = int(0)

print("_________________________________________________________________________")

for i in range(3):
    
    funcionarios = int(input(f"\n-> Digite a quantidade de funcionarios no setor {i + 1}: "))
    total_salario = float(0)
    
    print("_________________________________________________________________________")
    
    for l in range(funcionarios):
        
        salario = float(input(f"\n  |Digite o salario do funcionario {l + 1}: R$ "))
        tempo = int(input(f"\n  |Digite o tempo de casa do funcionario {l + 1}(em meses): "))
        print("_________________________________________________________________________")
        
        if maior_salario < salario:
            
            maior_salario = salario
            setor_maior_salario = i
            funcionario_maior_salario = l
        
        if salario < menor_salario:
            
            menor_salario = salario
            setor_menor_salario = i
            funcionario_menor_salario = l
            
        if tempo > maior_tempo:
            
            maior_tempo = tempo
            funcionario_com_maior_tempo = l
            setor_funcionario_com_maior_tempo = i
        
        
        total_salario += salario
        
    print(f"\n      |-> O salario total dos funcionarios no setor { i + 1} foi de: R$ {total_salario:.2f}")
    print("_________________________________________________________________________")
    
print("_________________________________________________________________________") 

print(f"\n      |-> O funcionario com maior tempo de empresa é o colaborador {funcionario_com_maior_tempo + 1} do setor {setor_funcionario_com_maior_tempo + 1}")
print(f"\n      |-> O maior salario pertence ao funcionario {funcionario_maior_salario + 1} do setor {setor_maior_salario + 1}")    
print(f"\n      |-> O menor salario pertence ao funcionario {funcionario_menor_salario + 1} do setor {setor_menor_salario + 1}")  