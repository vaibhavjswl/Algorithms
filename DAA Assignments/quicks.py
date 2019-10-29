#Quick sort time complexity analysis
from random import randint
from timeit import default_timer as time
from matplotlib import pyplot as plt
import csv

def QuickS(A,start,end):
    if start < end:
        p = partition(A,start,end)

        QuickS(A,start,p-1)
        QuickS(A,p+1,end)

def partition(A,start,end):

    pivot=randint(start,end)
    A[pivot] , A[end] = A[end] , A[pivot]

    i=start-1

    for indx in range(start,end+1):
        if A[indx] < A[end]:
            i+=1
            A[i] , A[indx] = A[indx] , A[i]

    
    A[i+1] , A[end] = A[end] , A[i+1]

    return i+1

#Execution time lists for 3 different methods of sorting array
#sorting array in descending order
execTimeDesc=[]
#sorting array in ascending order
execTimeAsc=[]
#sorting array in Random order
execTimeRandom=[]

ArraySizes=[]

#vary array size
for siz in range(100,2001,100):
    
    #initialize list
    A1 = [x for x in range(siz-1,-1,-1)]
    
    start=time()
    QuickS(A1,0,len(A1)-1)
    end=time()
    #store exec time
    execTimeDesc.append((end-start)*1000)
    
    #initialize list
    A2 = [x for x in range(0,siz)]
    start=time()
    QuickS(A2,0,len(A2)-1)
    end=time()
    #store exec time
    execTimeAsc.append((end-start)*1000)
    
    #initialize list
    A3 = [randint(0,siz-1) for x in range(0,siz)]
    start=time()
    QuickS(A3,0,len(A3)-1)
    end=time()
    #store exec time
    execTimeRandom.append((end-start)*1000)
    
    #store respective array size
    ArraySizes.append(siz)
    
#combine the lists
pairs=list(zip(ArraySizes,execTimeAsc,execTimeDesc , execTimeRandom))
fields=["Size of Array" , "Execution Time Ascending Order " , "Execution Time Descending Order","Execution Time Random array "]

#store lists into csv for analysis
with open("QuickS.csv", 'w', newline='\n') as myfile:
    wr = csv.writer(myfile, quoting=csv.QUOTE_ALL)
    wr.writerow(fields)
    wr.writerows(pairs)
    
#PLOT the Results using matplotlib    
plt.plot(ArraySizes , execTimeAsc , label="Execution Time for Ascending Sorted Array")
plt.plot(ArraySizes , execTimeDesc , label="Execution Time for Descending Sorted Array")
plt.plot(ArraySizes , execTimeRandom , label="Execution Time for Random Array")
plt.xlabel("Size of Array")
plt.ylabel("Execution TIme in Milliseconds")
plt.legend()
plt.autoscale()
plt.show()

    
    
    
    