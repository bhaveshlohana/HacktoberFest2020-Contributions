import smtplib

import gspread

from oauth2client.service_account import ServiceAccountCredentials

scope = ['https://spreadsheets.google.com/feeds','https://www.googleapis.com/auth/drive']

creds = ServiceAccountCredentials.from_json_keyfile_name('client_secret.json',scope)

client = gspread.authorize(creds)

sheet = client.open('Google Sheet Name').sheet1

mail_list = sheet.col_values(2)

mail_list = mail_list[1:]

print(mail_list)


mail=smtplib.SMTP('smtp.gmail.com',587)

mail.ehlo()

mail.starttls()

mail.login('Email','Password')

for i in range(len(mail_list)):
    msg = f"""\
Message
"""
    mail.sendmail('From Mail',mail_list[i],'Subject: Type Subject\n\n'+msg)

mail.quit()
