import os

class Pessoa:

    def __init__(self, nome, idade):

        self.nome = nome
        self.idade = idade

class Aluno(Pessoa):

    def __init__(self, nome, idade, ra):

        super().__init__(nome, idade)
        self.ra = ra

    def apresentar(self):

        print(f"-> [STATUS: ALUNO]\n")
        print(f"-> [NOME: {self.nome}]")
        print(f"-> [IDADE: {self.idade}]")
        print(f"-> [RA: {self.ra}]")

class Professor(Pessoa):

    def __init__(self, nome, idade, materia):

        super().__init__(nome, idade)
        self.materia = materia

    def apresentar(self):

        print(f"-> [STATUS: PROFESSOR]\n")
        print(f"-> [NOME: {self.nome}]")
        print(f"-> [IDADE: {self.idade}]")
        print(f"-> [MATERIA: {self.materia}]")

if __name__ == "__main__":

    nome = str(input("|Digite o nome do usuário: "))
    idade = int(input(f"\n|Digite a idade do(a) {nome}: "))

    pessoa = Pessoa(nome, idade)

    os.system("cls")

    print("> O usuário é:\n")
    print("[1] - ALUNO")
    print("[2] - PROFESSOR")
    op = int(input("|: "))

    os.system("cls")

    if op == 1:

        ra = int(input(f"> Digite o RA do aluno {pessoa.nome}: "))
        pessoAluno = Aluno(pessoa.nome, pessoa.idade, ra)
        os.system("cls")

        pessoAluno.apresentar()

    elif op == 2:

        materia = str(input(f"> Digite a matéria que o(a) professor(a) {pessoa.nome} ministra: "))
        pessoaProfessor = Professor(pessoa.nome, pessoa.idade, materia)
        os.system("cls")

        pessoaProfessor.apresentar()

    else: print("> Digite um número válido")