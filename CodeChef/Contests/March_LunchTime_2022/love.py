t=int(input()) 
for i in range(t): 
    n=int(input()) 
    A=list(map(int,input().split(" "))) 
    l=[] 
    c=0 
    for j in range(len(A)): 
        import random 
        random.shuffle(A) 
        l=[] 
        for k in range(0,len(A)-1): 
            l.append(A[k]*A[k+1]) 
        if sum(l)%2!=0: 
            c=c+1 
            break 
    if c==1: 
        print(A) 
    else: 
        print(-1)