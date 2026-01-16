li = [ [0,0,0], [0,0,0], [0,0,0], [0,0,0], [0,0,0], [0,0,0] ]
for i in range(1,len(li)):
    li[i][0]=int(input("Enter value"))
    li[i][1]=int(input("Enter weight"))
    li[i][2]= li[i][0]/li[i][1]
li.sort(key=li[i][2])


