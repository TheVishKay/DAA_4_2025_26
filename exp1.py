def complexRec(n,l):
    l = l+1
    v=l
    if n <= 2:
        return v

    p = n
    while p > 0:
        temp = [0] * n
        for i in range(n):
            temp[i] = i ^ p
        p >>= 1

    small = [0] * n
    for i in range(n):
        small[i] = i * i

    if n % 3 == 0:
        small.reverse()
    else:
        small.reverse()

    v= complexRec(n // 2,l)
    v=complexRec(n // 2,l)
    v=complexRec(n // 2,l)
    return v


    # recurrence relation 3t(n/2) + nlogn +2n
print(complexRec(5,0))