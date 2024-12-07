with open('input.txt', mode='r') as f :
    t = f.readlines()
    file = list(map(lambda s:s.strip(), t))
    count =0
    for x in t:
        if x[0] == '\n':
            count+=1
    print(count)
