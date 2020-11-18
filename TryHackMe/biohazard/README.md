MACHINE IP: 10.10.72.144

NMAP SCAM RESULTS: 

21/tcp   open     ftp            vsftpd 3.0.3

22/tcp   open      ssh            OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)

80/tcp   open     http           Apache httpd 2.4.29 ((Ubuntu))



TASK 1 "THE MANSION":

   Chris is missing
   Jill try to open the door but stopped by Weasker
   a gunshot can be heard in the nearby room
   Weaker order Jill to make an investigate on the gunshot. 
   Check source code its the /diningRoom
 
 DINING ROOM:
 
  Jill and Barry started their investigation
  Blood stein can be found near the fireplace
  Jill can't find any empty shell
  There is a link embedded which will give you emblem flag
  
   emblem{fec832623ea498e20bf4fe1821d58727}

  ALSO THERE IS A HINT ON THE EMBLEM PAGE

     Look like you can put something on the emblem slot, refresh / diningRoom/

   In The Source code of Dining room there is a hash. 
                 
    SG93IGFib3V0IHRoZSAvdGVhUm9vbS8=     
   It is a base64 after decoding it gives
        "How about the /teaRoom/"
 
 TEA ROOM:
    Barry give Jill a Lockpick.
    HERE'S OUR LOCKPICK FLAG
    
    lock_pick{037b35e2ff90916a9abf99129c8e1837}

    Barry also suggested that Jill should visit the /artRoom/
 
 ART ROOM:
    THERE'S A LINK TO OTHER PAGE WHICH LEADS US TO:
     http://10.10.97.121/artRoom/MansionMap.html

 MANSION MAP:
      Location:
      
      /diningRoom/
      /teaRoom/
      /artRoom/
      /barRoom/
      /diningRoom2F/
      /tigerStatusRoom/
      /galleryRoom/
      /studyRoom/
      /armorRoom/
      /attic/
 BAR ROOM:
     
  There is a link which will give you a base 32 encoded string
     NV2XG2LDL5ZWQZLFOR5TGNRSMQ3TEZDFMFTDMNLGGVRGIYZWGNSGCZLDMU3GCMLGGY3TMZL5 

     After decoding it you get music sheet flag!
     music_sheet{362d72deaf65f5bdc63daece6a1f676e} 
     
 Entering the music sheet Flag in the bar room given space you will be taken to a "SECRET BAR ROOM"

     
     There you will find a gold emblem flag
     gold_emblem{58a8c41a9d08b8a4e38d02a4d7ff4843}
     
     REFRESH THE PAGE
     and enter the emblem flag and after submitting it you get "rebecca"

SINCE THERE IS A EMBLEM SLOT IN DINING ROOM ONE 
WE TRIED ENTRING THE OLD EMBLEM IT DIDINT WORKED
LET'S ENTER THE GOLD EMBLEM THERE

Now you get a cipher text!
klfvg ks r wimgnd biz mpuiui ulg fiemok tqod. Xii jvmc tbkg ks tempgf tyi_hvgct_jljinf_kvc
 
 Decoding it gives you;
 "there is a shield key inside the dining room. The html page is called the_great_shield_key"

    shield_key{48a7a9227cd7eb89f0a062590798cbac}


 DINING ROOM 2F:
      VIEW THE SOURCE CODE.
      Theres a ROT 13 encoded text
      After decoding you get:
      "You get the blue gem by pushing the status to the lower floor. The gem is on the diningRoom first floor. Visit sapphire.html" 
      add sapphire.html in diningRoom url
             
             blue_jewel{e1d457e96cac640f863ec7bc475d48aa} 
 
 TIGER STATUS ROOM;
     Enter the blue jewel flag and then :
     crest 1:
 S0pXRkVVS0pKQkxIVVdTWUpFM0VTUlk9
 Hint 1: Crest 1 has been encoded twice 
 Hint 2: Crest 1 contanis 14 letters
 Note: You need to collect all 4 crests, combine and decode to reavel another path
 The combination should be crest 1 + crest 2 + crest 3 + crest 4. Also, the combination is a type of encoded base and you need to decode it 
  
  The above hash is base64 after decoding we get
  KJWFEUKJJBLHUWSYJE3ESRY=  

  The above hash is base 32 and after decoding it we get a base 64 hash: RlRQIHVzZXI6I

  
 
 GALLERY ROOM:
    crest 2:
      GVFWK5KHK5WTGTCILE4DKY3DNN4GQQRTM5AVCTKE
      Hint 1: Crest 2 has been encoded twice
      Hint 2: Crest 2 contanis 18 letters
      Note: You need to collect all 4 crests, combine and decode to reavel another path
      The combination should be crest 1 + crest 2 + crest 3 + crest 4. Also, the        combination is a type of encoded base and you need to decode it.
       
       decode using base 32 an then base64 you get:
       h1bnRlciwgRlRQIHBh
  
 ARMOR ROOM: 
     crest 3:
MDAxMTAxMTAgMDAxMTAwMTEgMDAxMDAwMDAgMDAxMTAwMTEgMDAxMTAwMTEgMDAxMDAwMDAgMDAxMTAxMDAgMDExMDAxMDAgMDAxMDAwMDAgMDAxMTAwMTEgMDAxMTAxMTAgMDAxMDAwMDAgMDAxMTAxMDAgMDAxMTEwMDEgMDAxMDAwMDAgMDAxMTAxMDAgMDAxMTEwMDAgMDAxMDAwMDAgMDAxMTAxMTAgMDExMDAwMTEgMDAxMDAwMDAgMDAxMTAxMTEgMDAxMTAxMTAgMDAxMDAwMDAgMDAxMTAxMTAgMDAxMTAxMDAgMDAxMDAwMDAgMDAxMTAxMDEgMDAxMTAxMTAgMDAxMDAwMDAgMDAxMTAwMTEgMDAxMTEwMDEgMDAxMDAwMDAgMDAxMTAxMTAgMDExMDAwMDEgMDAxMDAwMDAgMDAxMTAxMDEgMDAxMTEwMDEgMDAxMDAwMDAgMDAxMTAxMDEgMDAxMTAxMTEgMDAxMDAwMDAgMDAxMTAwMTEgMDAxMTAxMDEgMDAxMDAwMDAgMDAxMTAwMTEgMDAxMTAwMDAgMDAxMDAwMDAgMDAxMTAxMDEgMDAxMTEwMDAgMDAxMDAwMDAgMDAxMTAwMTEgMDAxMTAwMTAgMDAxMDAwMDAgMDAxMTAxMTAgMDAxMTEwMDA=
Hint 1: Crest 3 has been encoded three times
Hint 2: Crest 3 contanis 19 letters
Note: You need to collect all 4 crests, combine and decode to reavel another path
The combination should be crest 1 + crest 2 + crest 3 + crest 4. Also, the combination is a type of encoded base and you need to decode it.

  Decoding base 64:
   00110110 00110011 00100000 00110011 00110011 00100000 00110100 01100100 00100000 00110011 00110110 00100000 00110100 00111001 00100000 00110100 00111000 00100000 00110110 01100011 00100000 00110111 00110110 00100000 00110110 00110100 00100000 00110101 00110110 00100000 00110011 00111001 00100000 00110110 01100001 00100000 00110101 00111001 00100000 00110101 00110111 00100000 00110011 00110101 00100000 00110011 00110000 00100000 00110101 00111000 00100000 00110011 00110010 00100000 00110110 00111000
 
 Convert to ASCII:
      63 33 4d 36 49 48 6c 76 64 56 39 6a 59 57 35 30 58 32 68

 Convert HEX to ASCII:
      c3M6IHlvdV9jYW50X2h


  ATTIC ROOM:
       crest 4:
       gSUERauVpvKzRpyPpuYz66JDmRTbJubaoArM6CAQsnVwte6zF9J4GGYyun3k5qM9ma4s
       Hint 1: Crest 2 has been encoded twice
       Hint 2: Crest 2 contanis 17 characters
       Note: You need to collect all 4 crests, combine and decode to reavel another path
       The combination should be crest 1 + crest 2 + crest 3 + crest 4. Also, the combination is a type of encoded base and you need to decode it
       
   That's a base58 hash
   after decoding you get hex
       70 5a 47 56 66 5a 6d 39 79 5a 58 5a 6c 63 67 3d 3d
       hex to ASCII gives us:
         
         pZGVfZm9yZXZlcg==

 Combining all 4 crests:

      RlRQIHVzZXI6IGh1bnRlciwgRlRQIHBhc3M6IHlvdV9jYW50X2hpZGVfZm9yZXZlcg==
 
 Decoding above base64:
     FTP user: hunter, FTP pass: you_cant_hide_forever
  
 CONNECT VIA FTP CREDENTIALS:
      cat important.txt
      Jill,

       I think the helmet key is inside the text file, but I have no clue on decrypting stuff. Also, I come across a /hidden_closet/ door but it was locked.

       From,
       Barry
     
  Downloading the key files
      use exiftool 
      key2: 5fYmVfZGVzdHJveV9

      Use steghide in Key 1 image and extract data without any passwd:
      cGxhbnQ0Ml9jYW
  
  And the third picture had a zip file containing a text file
      use binwalk -e 003-key.jpg
       
       key3: 3aXRoX3Zqb2x0
 
 Combining key 1,2 & 3 you get:
      cGxhbnQ0Ml9jYW5fYmVfZGVzdHJveV93aXRoX3Zqb2x0
      Decoding this base64 you get:
      plant42_can_be_destroy_with_vjolt
  
  To extract helmet flag use:  gpg -d helmet_key.txt.gpg 
      enter the above decoded passphrase
      
      helmet_key{458493193501d2b94bbab2e727f8db4b}

   Now go to the study room:
       Enter the helmet flag and then 
       you have to download a file and you will get 
       SSH user: umbrella_guest
  
  HIDDEN CLOSET:
       MO DISK: 

      wpbwbxr wpkzg pltwnhro, txrks_xfqsxrd_bvv_fy_rvmexa_ajk
     
     Wolf medal:
       SSH password: T_virus_rules

  After connecting via SSH go to jailcell dir
  cat chris.txt
         
         Jill: Chris, is that you?
         Chris: Jill, you finally come. I was locked in the Jail cell for a while. It seem that weasker is behind all this.
         Jil, What? Weasker? He is the traitor?
         Chris: Yes, Jill. Unfortunately, he play us like a damn fiddle.
         Jill: Let's get out of here first, I have contact brad for helicopter support.
         Chris: Thanks Jill, here, take this MO Disk 2 with you. It look like the key to decipher something.
         Jill: Alright, I will deal with him later.
         Chris: see ya.
         MO disk 2 :albert
 
 wpbwbxr wpkzg pltwnhro, txrks_xfqsxrd_bvv_fy_rvmexa_ajk
 Decode this vigenre cipher the key is Albert
  
      weasker login password, stars_members_are_my_guinea_pig

  Go to weasker profile 
  and read the note
  Tyrant is the ultimate life form

   Weasker has all the permissions
      run sudo -i

   You are root now!
       
       FLAG!
       3c5794a00dc56c35f2bf096571edf3bf  
    



















