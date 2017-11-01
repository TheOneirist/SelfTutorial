#change

def prob4():

    allPalins = []

    for i in range(0,1000):
        for k in range(0,1000):
            if isPalin(i*k):
                allPalins += [i*k]

    return max(allPalins)



def isPalin(n):
    
    strn = str(n)
    reverse = strn[::-1]

    if strn == reverse:
        return 1
    else:
        return 0

    
