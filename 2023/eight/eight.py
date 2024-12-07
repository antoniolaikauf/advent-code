with open('input.txt', mode = 'r') as f:
    t = f.readlines()
    file = list(map(lambda s :s.strip(),t))
    path = [{'start': x[:3], 'L':x[7:10], 'R':x[12:15]} for x in file ]
    start = 'AAA'
    end = 'ZZZ'
    p  = 'LRLRRRLRRLRLLRRRLRRLLRRRLLRLRRLLRRRLRLRRRLRRLRRLRRLLLLRRRLRRLRRRLRRRLRRRLRLRRRLRLLRRRLLRLRRRLRRRLRLRRLLRLLRRLRLLRRRLLRRLRLLLRLRLRLLRRRLRLRLRRLRRRLRRLRLRRRLRRRLRRRLLLLRLLRRLLRRRLRRLRRLLRRLRRRLLRRLLLRRRLRLRLLRRLRRRLRRLRRRLLRLRRRLRLLRLLRRRLRRLLRLRRRLRRLRRRLRRLRRLRRRLRRLRRRR'
    array=[x for x in p]

    count =0 
    while start != end:
         for x in array: # percorso
            for node in path:
                if node['start'] == start:
                   count += 1 
                   start = node[x] # start doventa il nodo che c'è nel percorso 
                   break
    print(start)
    print(count)
    