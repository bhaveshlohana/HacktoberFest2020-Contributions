import tweepy
from Tkinter import *
#variable intilizing
consumer_key = 'consumer key'
consumer_secret = 'consumer secrets'
access_token = 'access token'
access_token_secret = 'access token secret'

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)
#calling the api
user = api.me()
print(user.name)
print(user.location)
 # for accesing followers
for follower in tweepy.Cursor(api.followers).items():
    follower.follow()

print("Followed everyone that is following " + user.name)
  #intializing the tkinnter 
root = Tk()
# calling the label function with root and Tex parameters
label1 = Label( root, text="Search")
E1 = Entry(root, bd =5)
# calling the label function for root and number of twwet
label2 = Label( root, text="Number of Tweets")
E2 = Entry(root, bd =5) #entry function
# label function for response
label3 = Label( root, text="Response")
E3 = Entry(root, bd =5)
# label function for reply
label4 = Label( root, text="Reply?")
E4 = Entry(root, bd =5)
# label function for retweet
label5 = Label( root, text="Retweet?")
E5 = Entry(root, bd =5)
# label function for favorite
label6 = Label( root, text="Favorite?")
E6 = Entry(root, bd =5)
# label function for follow option
label7 = Label( root, text="Follow?")
E7 = Entry(root, bd =5)
# define  functions for get request of e
def getE1():
    return E1.get()

def getE2():
    return E2.get()

def getE3():
    return E3.get()


def getE4():
    return E4.get()

def getE5():
    return E5.get()

def getE6():
    return E6.get()

def getE7():
    return E7.get()


def mainFunction():
    getE1()
    search = getE1()
    
    getE2()
    numberOfTweets = getE2()
    numberOfTweets = int(numberOfTweets)
    
    getE3()
    phrase = getE3()
    
    getE4()
    reply = getE4()
    
    getE5()
    retweet = getE5()
    
    getE6()
    favorite = getE6()

    getE7()
    follow = getE7()

    if reply == "yes":
        for tweet in tweepy.Cursor(api.search, search).items(numberOfTweets):
            try:
                #Reply
                print('\nTweet by: @' + tweet.user.screen_name)
                print('ID: @' + str(tweet.user.id))
                tweetId = tweet.user.id
                username = tweet.user.screen_name
                api.update_status("@" + username + " " + phrase, in_reply_to_status_id = tweetId)
                print ("Replied with " + phrase)
                
            except tweepy.TweepError as e:
                print(e.reason)

            except StopIteration:
                break


    if retweet == "yes": 
        for tweet in tweepy.Cursor(api.search, search).items(numberOfTweets):
            try:
                #Retweet
                tweet.retweet()
                print('Retweeted the tweet')   

            except tweepy.TweepError as e:
                print(e.reason)

            except StopIteration:
                break

    if favorite == "yes": 
        for tweet in tweepy.Cursor(api.search, search).items(numberOfTweets):
            try:
                #Favorite
                tweet.favorite()
                print('Favorited the tweet')   

            except tweepy.TweepError as e:
                print(e.reason)

            except StopIteration:
                break

    if follow == "yes": 
        for tweet in tweepy.Cursor(api.search, search).items(numberOfTweets):
            try:
                #Follow
                tweet.user.follow()
                print('Followed the user')
                
            except tweepy.TweepError as e:
                print(e.reason)

            except StopIteration:
                break       
            
submit = Button(root, text ="Submit", command = mainFunction)

label1.pack()
E1.pack()
label2.pack()
E2.pack()
label3.pack()
E3.pack()
label4.pack()
E4.pack()
label5.pack()
E5.pack()
label6.pack()
E6.pack()
label7.pack()
E7.pack()
submit.pack(side =BOTTOM)

root.mainloop()
