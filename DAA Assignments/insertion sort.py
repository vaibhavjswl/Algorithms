from timeit import default_timer as time 
import matplotlib.pyplot as plt

from itertools import chain
   
import csv

def insertionSort(arr): 
  
    for i in range(1, len(arr)): 
  
        key = arr[i] 
        j = i-1
        while j >=0 and key < arr[j] : 
                arr[j+1] = arr[j] 
                j -= 1
        arr[j+1] = key 



exectime=[]
NumEle=[]        

for siz in range(500 , 10000 , 500):
        
    nlist=[x for x in range(siz , 0 , -1)] 
    
    start=time()
    insertionSort(nlist)
    end = time()
    
    exectime.append((end-start)*1000)
    NumEle.append(siz)
    
c = list(zip(NumEle,exectime))
field=["Num of Elements","Exec Time (Milliseconds)"]

with open("insertion.csv", 'w', newline='\n') as myfile:
    wr = csv.writer(myfile, quoting=csv.QUOTE_ALL)
    wr.writerow(field)
    wr.writerows(c)