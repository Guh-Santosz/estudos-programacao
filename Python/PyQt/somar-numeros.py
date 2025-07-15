import sys
from PyQt5.QtWidgets import *
from PyQt5.QtCore import Qt
from PyQt5.QtGui import *

def sum():
    
    if(entry1.text() == "" or entry2.text() == ""):
        title.setText("Soma inválida")
    else:
        num1 = int(entry1.text())
        num2 = int(entry2.text())

        title.setText(f"O resulrado da soma é {num1 + num2}")

app = QApplication(sys.argv)
app.setStyle("Fusion")

window = QWidget()
window.setWindowTitle("Somador")
window.resize(600,600)

header = QFrame()

title = QLabel("SOMADOR")
title_font = QFont("Comic Sans", 15)
title.setFont(title_font)
title.setStyleSheet("color: white")

header.setStyleSheet("background-color: #000")
header.setFixedHeight(50)

header_layout = QHBoxLayout()
header_layout.addWidget(title, alignment=Qt.AlignCenter)
header.setLayout(header_layout)

body = QFrame()
body.setFixedSize(450,450)
body.setStyleSheet("background-color: lightgray; border-radius: 15px")

actions_fonts = QFont("Sans Serif", 12)

number1 = QLabel("Digite o primeiro numero")
number1.setFont(actions_fonts)

entry1 = QLineEdit()
entry1.setPlaceholderText("Digite um numero")
entry1.setFixedSize(350,45)
entry1.setStyleSheet("outline: none; border: 1px solid #ccc; border-radius: 12px; background-color: #fff; padding: 0px; margin: 0px")

number2 = QLabel("Digite o segundo numero")
number2.setFont(actions_fonts)

entry2 = QLineEdit()
entry2.setPlaceholderText("Digite um numero")
entry2.setFixedSize(350,45)
entry2.setStyleSheet("outline: none; border: 1px solid #ccc; border-radius: 15px; background-color: #fff; padding: 0px; margin: 0px")

button = QPushButton("Clique aqui para somar")
button.setStyleSheet("background-color: #000; color: white; border: 1px, solid, #ccc; border-radius: 15px; font-size: 13px")
button.setFixedSize(200, 35)
button.clicked.connect(sum)

entry1.setAlignment(Qt.AlignCenter)
entry2.setAlignment(Qt.AlignCenter)
entry1.setValidator(QIntValidator())  # só aceita números inteiros
entry2.setValidator(QIntValidator())

action = QVBoxLayout()
action.setSpacing(45)
action.setContentsMargins(0,0,0,0)
action.addWidget(number1, alignment=Qt.AlignCenter)
action.addWidget(entry1, alignment=Qt.AlignCenter)
action.addWidget(number2, alignment=Qt.AlignCenter)
action.addWidget(entry2, alignment=Qt.AlignCenter)
action.addWidget(button, alignment=Qt.AlignCenter)

container = QWidget()
container.setLayout(action)

body_layout = QVBoxLayout()
body_layout.addWidget(container, alignment=Qt.AlignCenter)
body.setLayout(body_layout)

main = QVBoxLayout()
main.addWidget(header)
main.addWidget(body, alignment=Qt.AlignCenter)

window.setLayout(main)
window.show()
sys.exit(app.exec_())