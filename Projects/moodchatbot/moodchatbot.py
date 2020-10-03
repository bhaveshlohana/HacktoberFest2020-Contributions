#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 23 15:06:52 2020

@author: sougata
"""

from textblob import TextBlob
import random
pos=['its very nice of you..we should be friend','i am always feel happy talking to you..continue please','wow..continue in that']
neg=['its very rude of you','i dont like to talk to you','i am hurted by you']
nutral=['oo i see','what happend next','continue..i am listening']

text='as'
print('hey,i am a moody chatbot created by sougata....lets talk something..tell me anythonh you want but donot ask me any question <<quit>> to exit')
while(text!='quit'):
    text=input()
    analysis=TextBlob(text)
    mind='nutral'
    if analysis.sentiment.polarity>0:
        mind='positive'
    elif analysis.sentiment.polarity<0:
        mind='negetive'
    else:
        mind='nutral'
    
    index=random.randrange(3)
    if(mind=='positive'):
        print(pos[index])
    elif(mind=='negetive'):
        print(neg[index])
    else:
        print(nutral[index])

