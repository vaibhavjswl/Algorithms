# Python program for Optimal Merge Pattern

def MinComputations(filesizes):
    #create temp list of filesizes
    temp=list()
    
    #copy filesizes list into temp
    temp=filesizes.copy()
    
    #initialize sum i.e. merging cost to 0
    sum=0
    #sort temp to simulate a priority queue
    temp = sorted(temp)
    
    while(len(temp)>1):
        #pop the first 2 elements i.e. 2 lowest elements from list into temp1
        temp1=temp.pop(0) + temp.pop(0)
        
        #Add the value to merging cost
        sum+=temp1
        
        # append sum of elements into temp list
        temp.append(temp1)
        
        #sort temp
        sorted(temp)
    
    #after calculation return final computation cost
    return sum


#List of File sizes
filesizes = [2,3,4,5,6,7]

print(f"\nMerging Cost of The Files with sizes {filesizes} is : " + str( MinComputations(filesizes)))

#List of File sizes
filesizes = [5,3,2,7,9,13]
print(f"\n\nMerging Cost of The Files with sizes {filesizes} is : " +str( MinComputations(filesizes)) + "\n\n")
        