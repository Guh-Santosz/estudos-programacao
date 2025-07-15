import sys
from PyQt5.QtWidgets import *
from PyQt5.QtCore import Qt 

def clicked():
    name = entry.text()
    result.setText(f"Olá {name}, seja bem vindo(a)")

app = QApplication(sys.argv)

result = QLabel("")

window = QWidget()
window.setWindowTitle('Receba')
window.resize(600,600)

container = QVBoxLayout()
container.setContentsMargins(30, 30, 30, 30)

layout = QVBoxLayout()
layout.setSpacing(10)

entry = QLineEdit()
entry.setPlaceholderText("Digite seu nome")
entry.setFixedSize(150,25)
button = QPushButton("Clique aqui")
button.setFixedSize(150, 25)

button.clicked.connect(clicked)

container.addWidget(result)
container.addWidget(entry)
container.addWidget(button)

layout.addLayout(container, stretch=0)
layout.setAlignment(Qt.AlignCenter)

window.setLayout(layout)

window.show()
sys.exit(app.exec_())
