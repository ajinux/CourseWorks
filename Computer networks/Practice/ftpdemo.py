from ftplib import FTP 

ftp = FTP('www.ajithkumarsekark.me')

ftp.login(user="username", passwd="password")

ftp.cwd("/dir/")

