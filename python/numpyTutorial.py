import numpy as np

#numpy is more effective array compare to list

#create an array
#default data type is int32(4-byte integer)
a = np.array([1,2,3,4,5],dtype="int16")

#display the dimention of array
print(a.ndim)

#display the shape of array
print(a.shape)

#display the data type of the elements in array
print(a.dtype)

#display size of each element
print(a.itemsize)

#display length of the array
print(a.size)

#display total size
print(a.size*a.itemsize) #a.nbytes

#access or change value
a = np.array([1,2,3,4,5,6],[7,8,9,10,11,12])
print(a.shape)  #(2,6)

#get an element in array,can use []
#work outside in (count from outmost array)
#can use -num to count from back
print(a[1,2])  #9

#get a row directly
print(a[0,:]) #array([1,2,3,4,5,6])

#get a column directly
print(a[:,4]) #array([5,11])

#get element with loops [start:end:step]
print(a[0,1:5:2] #array([2,4,6])

#change an element
a[1,4] = 31
print(a)    #[[1,2,3,4,5,6],[7,8,9,10,31,12]]

#change a row
a[:,2]=3
print(a)

#initialize array
#all zero
np.zeros(5) #array([0,0,0,0,0])
np.zeros((2,3)) #array([0,0,0],[0,0,0]])

#all one
np.ones(5,dtype="int8") #array([1,1,1,1,1])

#with other value
#first param:shape
#second param:value
np.full((2,4),3) #array([[3,3,3,3],[3,3,3,3]])

#full initialize with others array's shape
np.full_like(a,1)
np.full(a.shape,1)    #array([1,1,1,1,1,1])

#initialize with random number
np.random.rand(4,2) #[[x,x],[x,x],[x,x],[x,x]]
np.random.random_sample(a.shape)

#random integer value
#start,end,size=
np.random.randint(4,8,size=(3,3)) #create array with range 4-7 in map 3*3

#identity matrix [1,0],[0,1]
np.identity(5)

arr = np.array([[1,2]])
#axis means layer, if same layer will repeat inside the array
r1 = np.repeat(arr,3,axis=0)
print(r1)

#create matrix [1,1,1,1,1],[1,0,0,0,1],[1,0,9,0,1],[1,0,0,0,1],[1,1,1,1,1]]
output = np.ones((5,5))
z = np.zeros((3,3))
z[1,1]=9
output[1:4,1:4] = z
print(z)

#referencing
a = np.array([1,2,3])
b = a
b[0] = 100 # a= [100,2,3]
#use copy to prevent this scnario

a[0] = 1
b = a.copy()
b[0] = 100 # a=[1,2,3] b=[100,2,3]


#mathematics
a = np.array([1,2,3,4])

a+2 #[3,4,5,6]
a+=2 #a=[3,4,5,6]
#works for +-*/ **(exponent)

b=([1,0,1,0])
a+b #[4,4,6,6]

np.sin(a)   #get sin of all value
#works for sin cos tan 




#linear algebra
a = np.full((2,3),1)
b = np.full((3,2),2)

#matrix multiply
np.matmul(a,b)

#find determinant
c = np.identity(3)
np.linalg.det(c) #1.0

#other functions
"""
determinant
trace
singular vector decomposition
eigenvalues
matrix norm
inverse
"""


#statistics
a = array([3,2,4,21,53],[2,32,421,52,50])
np.min(a) #2
np.max(a,axis=1) #[53,421]
np.sum(a)   #get sum of all elements


#reorganizing arrays
before = np.array([[1,2,3,4],[5,6,7,8]])
print(before)

after = before.reshape((8,1))
print(after)

#vertically stacking vectors
v1 = np.array([1,2,3,4])
v2 = np.array([5,6,7,8])

np.vstack([v1,v1,v2,v2])

#horizontal stack
#both parenthesis and bracket works
np.hstack((v1,v2))


#miscellaneous
#load data from file
#eg data.txt
#delimiter is separator
filedata = np.genfromtxt('data.txt',delimiter=',')
#return array with same format but different format
filedata = filedata.astype('int32')


#boolean masking and advanced indexing
#check all data in filedata and return array of result
filedata > 50
#only get data >50
filedata[filedata>50]



#can index with a list in numpy
a = np.array([1,2,3,4,5,6,7,8,0])
a[[1,2,8]]  #array([2,3,9])

#check which column has data >50
np.any(filedata>50,axis=0)
(~((filedata > 50) & (filedata <100)))