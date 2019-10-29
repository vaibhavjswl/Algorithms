from timeit import default_timer as time 
import matplotlib.pyplot as plt

from itertools import chain
   
import csv

def mergesort(arr):
    if len(arr) >1 :
        mid = int(len(arr)/2)

        L=arr[:mid]
        R=arr[mid:]

        mergesort(L)
        mergesort(R)

        i=j=k=0
        while i < len(L) and j < len(R) :
            if L[i] <= R[j] :
                arr[k] = L[i]
                i+=1
            else :
                arr[k] = R[j]
                j+=1
            k+=1
        
        while i < len(L):
            arr[k] = L[i]
            i+=1
            k+=1

        while j < len(R):
            arr[k] = R[j]
            j+=1
            k+=1
            
            

def insertionSort(arr): 
  
    for i in range(1, len(arr)): 
  
        key = arr[i] 
        j = i-1
        while j >=0 and key < arr[j] : 
                arr[j+1] = arr[j] 
                j -= 1
        arr[j+1] = key 



exectimeMergesort=[]
exectimeinsertionsort=[]
NumEle=[]        

for siz in range(500 , 10000 , 500):
        
    testarr=[x for x in range(siz , 0 , -1)] 
    
    start=time()
    mergesort(testarr)
    end = time()
    
    exectimeMergesort.append((end-start)*1000)
    
    
    testarr=[x for x in range(siz , 0 , -1)] 
    
    start=time()
    insertionSort(testarr)
    end = time()
    
    exectimeinsertionsort.append((end-start)*1000)
    NumEle.append(siz)
  
  
c = list(zip(NumEle,exectimeMergesort,exectimeinsertionsort))
field=["Num of Elements","Exec Time Merge (Milliseconds)","Exec Time Insert (Milliseconds)"]

with open("combined.csv", 'w', newline='\n') as myfile:
    wr = csv.writer(myfile, quoting=csv.QUOTE_ALL)
    wr.writerow(field)
    wr.writerows(c)