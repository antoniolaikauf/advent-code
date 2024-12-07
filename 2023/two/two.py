with open('small.txt', mode='r') as f:
    count=0
    file = f.readlines()
    max_cube =[]
    potenza = []
    for i,t in enumerate(file):
        multiplo=0
        r_max,b_max,g_max = 0,0,0
        mainD = t[t.find(':') + 1:].rstrip().split(';')
        game_round=list(map(lambda x: x.split(','),mainD))
        flag_exist=True
        for y in game_round:
            print(y)
            r,g,b=0,0,0
            for u in y:
                if 'green' in u : 
                    g+= int(u[:len(u) - len('green')])
                    if g > g_max:
                        g_max = g
                if 'red' in u: 
                    r += int(u[:len(u) - len('red')])
                    if r > r_max:
                        r_max = r
                if 'blue' in u: 
                    b += int(u[:len(u) - len('blue')])
                    if b > b_max:
                        b_max = b
            # if g > 13  or r > 12 or b > 14:
            #     flag_exist= False
            #     break
        max_cube.append({'red':r_max,'blue':b_max,'green':g_max})
        mul = r_max * b_max * g_max
        potenza.append(mul)
        if flag_exist:
            count+=(i+1)
    print(max_cube)
    print(count) 
    print(sum(potenza)) 