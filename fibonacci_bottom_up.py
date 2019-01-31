def fib(n):
    if n==1:
        return 1
    elif n==2:
        return 2
    else:
        arr=[0 for i in range(0,n)]
        arr[0]=1
        arr[1]=1
        for i in range(2,n):
            arr[i]=arr[i-1]+arr[i-2]
        return arr[n-1]

print fib(12)