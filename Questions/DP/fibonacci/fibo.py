def fiboBtmUp(n):
    if(n == 0 or n == 1):
        return n
    a = 0
    b = 1
    c = a + b
    for _ in [2, n+3] :
        c = a + b 
        a = b 
        b = c
    
    return c


n = int(input("Enter number: "))
print(fiboBtmUp(n))