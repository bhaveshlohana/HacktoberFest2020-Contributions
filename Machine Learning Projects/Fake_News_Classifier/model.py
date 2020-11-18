# Necessary Libraries
import pandas as pd
import numpy as np
import pickle
import matplotlib.pyplot as plt
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.pipeline import Pipeline
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import MultinomialNB
from sklearn.feature_extraction.text import TfidfVectorizer
import nltk

nltk.download('punkt')

# In[2]:


# Importing the dataset
df = pd.read_csv('/Users/sumitkumarkundu/PycharmProjects/Fake_News_Classifier/venv/Model/train.csv')


# In[3]:
print(df.head())


df.isnull().sum()


# In[4]:


df.sample()


# In[5]:


# df.info()


# In[6]:


# input column is text and output column is label and in text there are 39 missing data
# df['text'].shape


# In[7]:


# but you see total 20800 text rows are there so we can drop these 28 rows , it will do no effect
df['text'] = df['text'].fillna(method='ffill')


# In[8]:
# df['text'].shape
# In[9]:


X = df['text']
y = df['label']


# In[10]:


# let's split the data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25)


# In[11]:


# now let's create a pipeline for removing stopwords and create bag of words
# applying multinomialNB as it gives us better results
pipe=Pipeline([('tfidf', TfidfVectorizer(stop_words='english')), ('nbmodel', MultinomialNB())])


# In[13]:


# fit the model
pipe.fit(X_train, y_train)


# In[15]:


prediction=pipe.predict(X_test)


# In[16]:


print(classification_report(y_test, prediction))


# In[17]:


print(confusion_matrix(y_test, prediction))


# In[18]:
# see true positive and true negative value are so much high
# In[19]:

# make the pickle file
with open('model.pickle', 'wb') as target:
    pickle.dump(pipe, target, protocol=pickle.HIGHEST_PROTOCOL)

