@echo off
cd/
cd c:
cd Program Files\MySQL\MySQL Server 5.1\bin
mysql -u root -pkvuc pro < "c:/pro.sql"
echo done*******
pause
