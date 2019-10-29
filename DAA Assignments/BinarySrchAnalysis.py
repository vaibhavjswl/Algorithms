#Time complexity analysis of Recursive and non recursive binary search
#Both implementation are evaluated on 2 cases - Element found and element not found

from timeit import default_timer as time 
import matplotlib.pyplot as plt
import random


def binarysrch(arr , ﬁrst , last , element):
    if ﬁrst < last :
        mid = int((ﬁrst+last)/2)
        if arr[mid] == element:
            return True
        elif arr[mid] >= element:
            return binarysrch(arr , ﬁrst , mid , element)
        elif arr[mid] < element:
            return binarysrch(arr , mid+1 , last , element)
    else:
        return False
    
    
def nonRecBinarySrch(arr,ﬁrst,last,element):
    while ﬁrst < last :
        mid = int((ﬁrst+last)/2)
        if arr[mid] == element:
            return True
        elif arr[mid] >= element:
            last=mid-1
        else:
            ﬁrst=mid+1
    return False


ExecTimeRecursiveFound=list()
ExecTimeRecursiveNOTFOUND=list()
ExecTimeNonRecursiveFOUND=list()
ExecTimeNonRecursiveNotFound=list()
ArraySize=list()

#Vary Array Size
for siz in range(250 , 8000 , 250):
    #initialize the list
    arr=[x for x in range(0,siz)]
    
    #Calcualted the Execution time and Add them into respective lists
    
    start = time()
    found = binarysrch(arr , 0 , len(arr) ,arr[-1])
    end = time()
    
    ExecTimeRecursiveFound.append((end-start)*1000)
    
    start=time()   
    found = binarysrch(arr , 0 , len(arr) ,siz+10)
    end=time()
    ExecTimeRecursiveNOTFOUND.append((end-start)*1000)
    
    start=time()   
    found = nonRecBinarySrch(arr , 0 , len(arr) ,arr[-1])
    end=time()
    
    ExecTimeNonRecursiveFOUND.append((end-start)*1000)
    
    start=time() 
    found = nonRecBinarySrch(arr , 0 , len(arr) ,siz+10)
    end=time()
    ExecTimeNonRecursiveNotFound.append((end-start)*1000)
    
    #Store the respective array size
    ArraySize.append(siz)
    
    
#Plot hte results 
plt.plot(ArraySize , ExecTimeRecursiveFound , label="Recursive Binary Search with Element Found")
plt.plot(ArraySize , ExecTimeRecursiveNOTFOUND , label="Recursive Binary Search with Element Not Found")
plt.plot(ArraySize , ExecTimeNonRecursiveFOUND , label="Non Recursive Binary Search with Element FOund")
plt.plot(ArraySize , ExecTimeNonRecursiveNotFound , label="Non Recursive Binary Search with Element Not Found")
plt.legend()
plt.xlabel("Size of Array")
plt.ylabel("Execution time In Milliseconds")
plt.show()