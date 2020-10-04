# -*- coding: utf-8 -*-
"""
Created on Thu Apr 18 12:38:48 2019

@author: edoardott
"""

import sqlite3


conn = sqlite3.connect('result.db')
    
c = conn.cursor()

c.execute("SELECT nemici FROM match")
print(c.fetchall())
c.execute("SELECT MAX(missili) FROM match")
print("RECORD MISSILI: "+str(c.fetchone()))
    
c.execute("SELECT MAX(nemici) FROM match")
print("RECORD NEMICI: "+str(c.fetchone()))
    
conn.close()
