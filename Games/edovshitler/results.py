# -*- coding: utf-8 -*-
"""
Created on Thu Apr 18 11:07:47 2019

@author: edoardottt
"""

import sqlite3
from datetime import datetime
    

def save(missili,bombe,nemici):

    conn = sqlite3.connect('result.db')
    timenow = datetime.now()
    
    c = conn.cursor()
    c.execute("INSERT INTO  match VALUES(?,?,?,?)",(timenow,missili,bombe,nemici))
    conn.commit()
    
    c.execute("SELECT missili,bombe,nemici FROM match WHERE date=?",(str(timenow),))
    
    c.execute("SELECT MAX(missili) FROM match")
    bold = str(c.fetchone())
    bold = bold.replace("(", "")
    bold = bold.replace(")", "")
    b = bold.replace(",","")
    
    c.execute("SELECT MAX(bombe) FROM match")
    aold = str(c.fetchone())
    aold = aold.replace("(", "")
    aold = aold.replace(")", "")
    a = aold.replace(",","")
    
    c.execute("SELECT MAX(nemici) FROM match")
    dold = str(c.fetchone())
    dold = dold.replace("(", "")
    dold = dold.replace(")", "")
    d = dold.replace(",","")
    conn.commit()
    
    conn.close()
    return [a,b,d]
