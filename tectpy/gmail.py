# Python code to illustrate Sending mail 
# to multiple users 
# from your Gmail account 
import smtplib

# list of email_id to send the mail
li = ["swamyshivaji@gmail.com", "kmbasavaraja@gmail.com"]

for i in range(len(li)):
	s = smtplib.SMTP('smtp.gmail.com', 587)
	s.starttls()
	s.login("kmvs.027@gmail.com", "Veena123456")
	message = "Message_you_need_to_send"
	s.sendmail("sender_email_id", li[i], message)
	s.quit()

