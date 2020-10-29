#!/bin/env python
import numpy as np
def label_it(D,w):
""" return the most likely class """
X,y = D
cls = np.unique(y)
cl_w = [sum(w[y==cl]) for cl in cls]
#v,c = np.unique(y,return_counts=True)
ind = np.argmax(cl_w)
return cls[ind]
def to_freq(y,w,debug=False):
"""convert to frequencies for each class"""
p =np.array([len(y[y==cl])/len(y) for cl in np.unique(y)])
weight = np.array([sum(w[y==cl]) for cl in np.unique(y)])
if debug:
print('from function to_freq',p)
return p,weight
def split_data(D,split):
"""split the data set"""
X,y = D
idx, threshold = split
idx=int(idx)
idx_l = X[:,idx] <= threshold;
idx_r = X[:,idx] > threshold;
Xl=X[X[:,idx] <= threshold,:]
yl=y[X[:,idx] <= threshold]
Xr=X[X[:,idx] > threshold,:]
yr=y[X[:,idx] > threshold]
Dl = (Xl,yl)
Dr = (Xr,yr)
return (Dl,Dr,idx_l,idx_r)
def get_thresholds_from_vec(x):
""" thresholds are the middle points of consecutive unique points """
return 0.5*np.diff(np.unique(x)) + np.unique(x)[:-1]
def get_threshold_from_mat(X):
""" call get_thresholds from vec, and zip all the results """
ns,nf = X.shape
tmp=[get_thresholds_from_vec(X[:,i]) for i in range(nf)]
ids = np.concatenate([(i*np.ones(len(item))) for i, item in zip(np.arange(nf),tmp)])
return [(idx,t) for idx, t in zip(ids,np.concatenate(tmp))]
def get_imp(p,w,metric='entropy'):
""" Calculate the impurity index
  p: is the probability vector, the sum of which equal to 1 """
return {
'entropy': (-p*np.log2(p)).dot(w),
'error' : (1-np.max(p))*w[np.argmax(p)],
'gini': (p*(1-p)).dot(w)
      }.get(metric)
def info_gain(D,split,w,metric='entropy'):
""" the information gain of a given split
  split: (idx_feature, threshold) is a tuple """
Dl,Dr,idx_l,idx_r = split_data(D,split)
Nl = sum(w[idx_l])#len(Dl[1])
Nr = sum(w[idx_r])#len(Dr[1])
Np = sum(w)#len(D[1])
#print(Dl[1])
#print(w[idx_l]) 
pl,weight_l =  to_freq(Dl[1],w[idx_l])
pr,weight_r = to_freq(Dr[1],w[idx_r])
p,weight = to_freq(D[1],w)
Il = get_imp(pl,weight_l,metric=metric)
Ir = get_imp(pr,weight_r,metric=metric)
Ip = get_imp(p,weight,metric=metric)
return Np*(Ip - Nl/Np * Il - Nr/Np*Ir)
###################################################
# class definition 
class BT_node(object):
""" a simple binary tree node base class"""
def __init__(self,Data=None,weight=None,parent=None,metric='entropy',max_depth=1):
self.Data = Data
self.w = weight
self.parent = parent
self.metric = metric
self.max_depth=max_depth
def update(self):
X,y = self.Data
if self.w is None:
self.w= np.ones(y)/len(y)
self.level = self.parent.level+1 if self.parent is not None  else 0
self.label = label_it(self.Data,self.w)
sps = get_threshold_from_mat(X)
# number of samples are 1 or zero || uniform class || max level reached || some features are identical, but labels are different
if len(y) <= 1 or self.level>=self.max_depth or len(sps)==0:
self.lchild = None
self.rchild = None
self.split = None
else:
#print(self.Data[0])
split,Dl,Dr,wl,wr = self.get_child(sps)
#print(split)
self.lchild = BT_node(Data=Dl,weight=wl,parent=self,max_depth=self.max_depth)
self.lchild.update()
self.rchild = BT_node(Data=Dr,weight=wr,parent=self,max_depth=self.max_depth)
self.rchild.update()
self.split = split
self.updated = True
return self
def get_child(self,sps):
""" train the decision tree """
X,y = self.Data
IGs = np.array([info_gain((X,y),sp,self.w,self.metric) for sp in sps])
# return the first maximum information gain
cond = IGs==np.max(IGs)
self.IG_max = IGs[cond]
tmp = np.array(sps)[cond]
split = (int(tmp[0,0]),tmp[0,1])
# calculate the class label 
Dl,Dr,idx_l,idx_r = split_data((X,y),split)
return (split,Dl,Dr,self.w[idx_l],self.w[idx_r])
def info(self):
""" print out informations """
print('split is: ',self.split)
print('childrens are: ',self.lchild,self.rchild)
print('node depth is: ',self.level)
print('parent is: ',self.parent)
class Decision_Tree(object):
""" Decision Tree, by Wensheng Sun"""
def __init__(self,max_depth=3,random_state=1,impurity_fun='entropy',debug=False):
self.random_state=random_state
self.impurity_fun = impurity_fun
self.max_depth = max_depth
self.debug = debug
def fit(self,X,y,w):
""" growing the Binary Tree """
self.root = BT_node((X,y),w,metric=self.impurity_fun,max_depth=self.max_depth)
self.root.update()
self.root.info()
def find_leaf(self,x):
node = self.root
while True:
if node.split is None:
break
else:
if x[node.split[0]] <= node.split[1]:
# print('the %d feature is less than threshold %.2f' %node.split)
node = node.lchild
else:
node = node.rchild
return node.label
def predict(self,X):
""" predict the results"""
if len(X.shape)==1:
X = [X]
return np.array([self.find_leaf(x) for x in X])
def main():
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from Perceptron import plot_decision_regions
# import data
from sklearn import datasets
iris = datasets.load_iris()
X = iris.data[:,[2,3]]
y = iris.target
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=0.3,random_state=1,stratify=y)
#  test = BT_node((X,y),metric='entropy')
#  test.update()
#  test.info()
#
#  test.lchild.update()
#  test.lchild.info()
# instantiate the Decision Tree classifier
dc = Decision_Tree(impurity_fun='entropy',max_depth=3)
dc.fit(X_train,y_train,np.ones(y_train.shape)/len(y_train))
# plot the decision regions
plt.figure()
plot_decision_regions(X,y,classifier=dc)
plt.title('Decision Tree')
plt.xlabel('sepal length [standardized]')
plt.ylabel('petal length [standardized]')
plt.show()
if __name__=='__main__':
main()
