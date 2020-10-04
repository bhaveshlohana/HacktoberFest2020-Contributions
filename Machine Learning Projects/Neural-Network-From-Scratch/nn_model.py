import numpy as np
def initialize_parameters(layer_dims): #initialize parameters
    parameters = {}
    L = len(layer_dims)
    for i in range(1,L):
        parameters["W"+str(i)] = np.random.randn(layer_dims[i],layer_dims[i-1])*0.01
        parameters["b"+str(i)] = np.zeros((layer_dims[i],1))
    
    return parameters

def sigmoid(Z):
    A = 1/(1+np.exp(-Z))
    return A,Z

def relu(Z):
    A = Z*(Z>0)
    return A,Z

#Forward Propagation

def linear_forward_function(A,W,b): #linear function of forward propagation
    Z = np.dot(W,A) + b
    cache = (A,W,b)
    return Z,cache

def linear_activation_forward(A_prev,W,b,activation): #linear activation function of forward ptopagation
    if activation=="sigmoid":
        Z,linear_cache = linear_forward_function(A_prev,W,b)
        A,activation_cache = sigmoid(Z)
    elif activation=="relu":
        Z,linear_cache = linear_forward_function(A_prev,W,b)
        A,activation_cache = relu(Z)
    cache = (linear_cache,activation_cache)
    return A,cache

def forward_propagation(X,parameters): #combining both functions
    caches = []
    A = X
    L = len(parameters)//2
    for i in range(1,L):
        A_prev = A
        A,cache = linear_activation_forward(A_prev,parameters["W"+str(i)],parameters["b"+str(i)],activation = "relu")
        caches.append(cache)
    A_last,cache = linear_activation_forward(A,parameters["W"+str(L)],parameters["b"+str(L)],activation="sigmoid")
    caches.append(cache)
    return(A_last,caches)

# computing cost

def compute_cost(A_last,Y):
    m = Y.shape[1]
    cost = (-1/m)*np.sum((Y*np.log(A_last))+((1-Y)*np.log(1-A_last)))
    cost = np.squeeze(cost)
    return(cost)

#Backward Propagation

def sigmoid_backward(da,Z):
    dg = (1/(1+np.exp(-Z)))*(1-(1/(1+np.exp(-Z))))
    dz = da*dg
    return dz

def relu_backward(da,Z):
    dg = 1*(Z>=0)
    dz = da*dg
    return dz

def linear_backward_function(dz,cache): #linear function of bakward propagation
    A_prev,W,b = cache
    m = A_prev.shape[1]
    dW = (1/m)*np.dot(dz,A_prev.T)
    db = (1/m)*np.sum(dz,axis = 1, keepdims=True)
    dA_prev = np.dot(W.T,dz)
    return dA_prev,dW,db

def linear_activation_backward(dA,cache,activation): #activation function of backward propagation
    linear_cache,activation_cache = cache
    
    if activation=="relu":
        dZ = relu_backward(dA,activation_cache)
        dA_prev,dW,db = linear_backward_function(dZ,linear_cache)
    if activation=="sigmoid":
        dZ = sigmoid_backward(dA,activation_cache)
        dA_prev,dW,db = linear_backward_function(dZ,linear_cache)
    return dA_prev,dW,db

def backward_propagation(AL,Y,caches): #combinig both functions
    grads = {}
    L = len(caches)
    m = AL.shape[1]
    Y = Y.reshape(AL.shape)
    dAL = -((Y/AL)-((1-Y)/(1-AL)))
    current_cache = caches[L-1]
    grads["dA"+str(L-1)],grads["dW"+str(L)],grads["db"+str(L)] = linear_activation_backward(dAL,current_cache,activation = "sigmoid")
    for l in reversed(range(L-1)):
        current_cache = caches[l]
        dA_prev,dW,db = linear_activation_backward(grads["dA"+str(l+1)],current_cache,activation = "relu")
        grads["dA"+str(l)] = dA_prev
        grads["dW"+str(l+1)] = dW
        grads["db"+str(l+1)] = db
        
    return grads

#parameters updation for gradient decent
def update_parameters(parameters,grads,learning_rate):
    L = len(parameters)//2
    for l in range(L):
        parameters["W"+str(l+1)] = parameters["W"+str(l+1)]-(learning_rate*grads["dW"+str(l+1)])
        parameters["b"+str(l+1)] = parameters["b"+str(l+1)]-(learning_rate*grads["db"+str(l+1)])
    
    return parameters

#complete model
def deep_nn_model(X,Y,layer_dims,learning_rate = 0.0075,num_iterations = 100):
    costs = []
    parameters = initialize_parameters(layer_dims)
    for i in range(num_iterations):
        AL,caches = forward_propagation(X,parameters)
        
        cost = compute_cost(AL,Y)
        grads = backward_propagation(AL,Y,caches)
        parameters = update_parameters(parameters,grads,learning_rate)
        if i%100==0:
            print("cost after "+str(i)+" iterations is "+str(cost))
            costs.append(cost)
    return parameters,costs 

#prediction function
def predict(X,parameters):
    AL,caches = forward_propagation(X,parameters)
    return AL
