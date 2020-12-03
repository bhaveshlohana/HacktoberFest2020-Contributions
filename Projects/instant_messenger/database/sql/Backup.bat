@echo off
cd/
cd c:
cd Program Files\MySQL\MySQL Server 5.1\bin
mysqldump -u root -pkvuc pro > "C:/pro.sql"
echo Done******
pause
