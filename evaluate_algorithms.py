import numpy as np
import matplotlib.pyplot as plt
import os,sys
import tqdm
if(len(sys.argv)==1):
    testcase_num=1e5/5
else:
    testcase_num=sys.argv[1]
yInsertionSort=[]
yMergeSort=[]
yStlSort=[]
x=[]
os.system("build insertion_sort.cpp")
os.system("build merge_sort.cpp")
os.system("build stl_sort.cpp")
#progress bar
pbar = tqdm.tqdm(total=(3*testcase_num)/100)
# generate test case for checking correctness of solution
# open a file named IN and write test case one by one and run checker log as well
def checker():
    f= open("OUT","r")
    data = f.readline().split()
    if(len(data)==1):
        # print("Accepted")
        # update the progress bar
        pbar.update(1)
        return
    i=0
    flag=True
    while(i<len(data)-1):
        if(int(data[i])>int(data[i+1])):
            flag=False
            break
        i+=1
    if(not flag):
        print("Rejected.\nExiting program")
        exit()
    else:
        # print("Accepted")
        # update the progress bar
        pbar.update(1)

numOfElement= 1
while(numOfElement< testcase_num):
    testcase= np.random.randint(1,1e9,size=(numOfElement))
    f= open("IN","w")
    f.write(str(numOfElement)+'\n')
    for i in testcase:
        f.write(str(int(i))+" ")
    f.close()
    os.system("run insertion_sort.cpp>runtime")
    #check correctness of solution
    checker()
    # retrieve running time and append it to yInsertionSort
    with open("runtime","r") as f:
        data =f.read()
        yInsertionSort.append(int(data))

    os.system("run merge_sort.cpp>runtime")
    #check correctness of solution
    checker()
    # same as done earlier
    with open("runtime","r") as f:
        data =f.read()
        yMergeSort.append(int(data))
    os.system("run merge_sort.cpp>runtime")
    #check correctness of solution
    checker()
    # same as done earlier
    with open("runtime","r") as f:
        data =f.read()
        yStlSort.append(int(data))

    #increase number of element
    x.append(numOfElement)
    numOfElement+=100

#if program is successfully lauched please go ahead with mapping
plt.scatter(x,yInsertionSort,label="Insertion sort",color="red")
plt.scatter(x,yMergeSort,label="Merge sort",color="green")
plt.scatter(x,yMergeSort,label="STL sort",color="blue")
plt.plot(x, yInsertionSort, linestyle='-', marker='o', label="Insertion sort (line)",color="red")
plt.plot(x, yMergeSort, linestyle='-', marker='x', label="Merge sort (line)",color="green")
plt.plot(x, yStlSort, linestyle='-', marker='x', label="STL sort (line)",color="blue")
plt.xlabel("Input Size")
plt.ylabel("Running Time")
plt.title("Comparasion of merge sort with insertion sort in term of runnig time")
plt.legend()
plt.show()