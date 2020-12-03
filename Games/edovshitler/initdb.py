# -*- coding: utf-8 -*-
"""
Created on Thu Apr 18 11:37:00 2019

@author: edoardottt
"""

import sqlite3

conn = sqlite3.connect('result.db')
    
c = conn.cursor()
c.execute('drop table if exists match')
c.execute("""CREATE TABLE match (
            date date,
            missili integer,
            bombe integer,
            nemici integer,
            PRIMARY KEY(date)
            )""")
conn.commit()
conn.close()