################################################
#### Author: Kamran Sarear                   ###
#### Email:  malik.kamrran.sarwar@gmail.com  ###
################################################


from PyQt5 import QtWidgets, uic
import sys
import requests
import json

class Ui(QtWidgets.QDialog):
    def __init__(self):
        super(Ui, self).__init__()
        uic.loadUi('CurrencyConverterGUI.ui', self)
        
        self.button = self.findChild(QtWidgets.QPushButton, 'pb_convert_currency') 
        self.button.clicked.connect(self.convertCurrency) 
        
        self.callToAPI()
        self.fillCurrencyCombo()

       
        
        self.show()
    def callToAPI(self):
        try:
            response = requests.get() #Provide Currecny Exchange API link here.
            #print(response.json())
            self.data = response.json()
            print(self.data['rates']['AED'])
        except:
            print()
    
    def fillCurrencyCombo(self):
        self.from_currency_combo = self.findChild(QtWidgets.QComboBox, 'cb_from_currency')
        self.from_currency_combo.addItems(self.data['rates'].keys())

        self.to_currency_combo = self.findChild(QtWidgets.QComboBox, 'cb_to_currency')
        self.to_currency_combo.addItems(self.data['rates'].keys())
        
    def convertCurrency(self):
        # This is executed when the button is pressed

        self.currencyText = self.findChild(QtWidgets.QLineEdit, 'le_from_currency')
        
        from_amount = float(self.currencyText.text())
        print(from_amount)
        from_currency = str(self.from_currency_combo.currentText())
        print(from_currency, self.data['rates'][from_currency])
        to_currency = str(self.to_currency_combo.currentText())
        print(to_currency, self.data['rates'][to_currency])

        fraction = float(self.data['rates'][to_currency] / self.data['rates'][from_currency])

        to_amount = fraction * from_amount

        print(str(from_amount) + " " + from_currency + " are approximatly equals to " + str(to_amount) + " " + to_currency)
        finalText = str(from_amount) + " " + from_currency + " = " + str(round(to_amount, 2)) + " " + to_currency
        self.label = self.findChild(QtWidgets.QLabel, 'lbl_converted_currency')
        self.label.setText(finalText)
        self.label.adjustSize()
        print('printButtonPressed')

app = QtWidgets.QApplication(sys.argv)
window = Ui()
app.exec_()
