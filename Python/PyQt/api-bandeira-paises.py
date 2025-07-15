import sys
import requests
from PyQt5.QtWidgets import *
from PyQt5.QtCore import Qt
from PyQt5.QtGui import *

validation = False
open_windows = []

def usingAPI():
    global validation, open_windows

    countryName = entry.text()
    url = f"https://restcountries.com/v3.1/name/{countryName}"
    response = requests.get(url)

    if response.status_code == 200:
        data = response.json()
        info = data[0]

        flag_url = info['flags']['png']
        flag_response = requests.get(flag_url)

        if not validation:
            validation = True
            new_window = QWidget()
            new_window.setWindowTitle("Country Info")
            new_window.resize(350, 400)

            def on_close(event):
                global validation
                validation = False
                event.accept()

            new_window.closeEvent = on_close

            header = QFrame()
            header.setContentsMargins(0,0,0,0)
            header.setStyleSheet("background-color: purple")
            header.setFixedHeight(36)

            header_layout = QHBoxLayout()
            title = QLabel(f"{info['name']['common']} Info")
            title.setStyleSheet("font-size: 12pt; color: white; font-family: Comic Sans")
            header_layout.addWidget(title, alignment=Qt.AlignCenter)
            header.setLayout(header_layout)

            body = QFrame()
            body.setStyleSheet("background-color: lightgray; border-radius: 13px")
            body.setFixedSize(280, 300)
            body_layout = QVBoxLayout()

            if flag_response.status_code == 200:
                pixmap = QPixmap()
                pixmap.loadFromData(flag_response.content)
                pixmap = pixmap.scaledToWidth(200, Qt.SmoothTransformation)

                flag_label = QLabel()
                flag_label.setPixmap(pixmap)
                flag_label.setAlignment(Qt.AlignCenter)

                body_layout.addWidget(flag_label)

            name_label = QLabel(f"Nome Oficial: {info['name']['official']}")
            name_label.setAlignment(Qt.AlignCenter)
            body_layout.addWidget(name_label)

            body.setLayout(body_layout)

            main = QVBoxLayout()
            main.setContentsMargins(0,0,0,0)
            main.addWidget(header)
            main.addWidget(body, alignment=Qt.AlignCenter)

            new_window.setLayout(main)
            new_window.show()
            open_windows.append(new_window)

app = QApplication(sys.argv)
app.setStyle("Fusion")

window = QWidget()
window.resize(350, 350)
window.setStyleSheet("background-color: white")
window.setContentsMargins(0,0,0,0)
window.setWindowTitle("Consumindo API")

body = QFrame()
body.setFixedSize(215, 200)
body.setContentsMargins(0,0,0,0)
body.setStyleSheet("background-color: lightgray; border-radius: 15px")

body_layout = QVBoxLayout()
entry = QLineEdit()
entry.setPlaceholderText("Enter the name of a country: ")
entry.setFixedSize(150, 35)
entry.setStyleSheet("background-color: white; border-radius: 5px")
entry.setAlignment(Qt.AlignCenter)

button = QPushButton("Submit")
button.setFixedWidth(150)
button.setStyleSheet("background-color: purple; color: white; font-size: 12pt; padding: 13px; border-radius: 5px")
button.clicked.connect(usingAPI)

body_layout.addWidget(entry, alignment=Qt.AlignCenter)
body_layout.addWidget(button, alignment=Qt.AlignCenter)
body.setLayout(body_layout)

main = QVBoxLayout()
main.addWidget(body, alignment=Qt.AlignCenter)

window.setLayout(main)
window.show()
sys.exit(app.exec_())
