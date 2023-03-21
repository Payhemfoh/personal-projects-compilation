import smtplib
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart

if __name__ == "__main__":
    server = smtplib.SMTP("smtp.gmail.com",25)

    server.ehlo()

    #read password from file
    with open("password.bin","r") as f:
        password = f.read()

    #login to the server
    server.login("sample@gmail.com",password)

    #the object to store the information of email
    msg = MIMEMultipart()

    #the header of the email
    msg['From'] = "GG bond"
    msg['To'] = "Everyone"
    msg['Subject'] = "Python Testing"

    #the contain of the email
    message = "Hi This is a message sent from python program"
    msg.attach(MIMEText(message,"plain"))

    pictureName = "picture.jpg"
    attachment = open(pictureName,"rb")

    p = MIMEBase('application','octet-stream')
    p.set_payload(attachment.read())

    encoders.encode_base64(p)
    p.add_header('Content-Disposition',f'attachment; filename={pictureName}')

    msg.attach(p)

    email_text = msg.as_string()
    server.sendmail("sample@gmail.com","sample2@gmail.com",email_text)
    print("Email sent successfully")