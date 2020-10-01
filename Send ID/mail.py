import smtplib

mail=smtplib.SMTP('smtp.gmail.com',587)

mail.ehlo()

mail.starttls()

mail.login('Email','Password')

mail_list = ["Fill the list with mail ids to which you want to send the mails."]

for i in range(len(mail_list)):
    msg = f"""\
Message
"""
    mail.sendmail('From Mail',mail_list[i],'Subject: Type Subject.\n\n'+msg)

mail.quit()
