with open ('input.txt' , mode='r') as f:

    t = f.readlines()
    file = list(map(lambda s:s.strip(), t))
    combination = [x.split() for x in file]

    somma = 0
    def extrapolated(array,value):
        array_new_value = value
        array_new_value.append(int(array[-1]))
        history=[]
        for x in range(len(array) - 1):
            value = int(array[x + 1]) - int(array[x])
            history.append(value)
        if all(x == 0 for x in history): 
            # print(sum(array_new_value))
            return sum(array_new_value)
        else: extrapolated(history, array_new_value)

        return sum(array_new_value)
    for x in combination:
         somma += extrapolated(x,[])
    print(somma)
           