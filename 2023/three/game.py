def controllo_up_down(row1,row2,row3,array): # funzione per riga sora e sotto
    # se carattere speciale è dentro alle row allora true 
    value = False
    for x in array:
          if (x in row1) or (x in row2) or (x in row3): 
            value = True
    return value

def two_row(row1,row2,array): # funzione solo quando si è sopra riga 0 o in fondo 
    value = False
    # se carattere speciale è dentro alle row allora true 
    for x in array:
          if (x in row1) or (x in row2) : 
            value = True
    return value

with open('input.txt',mode='r') as f:
  risultato = []
  t = f.readlines()
  file = list(map(lambda s: s.strip(), t))
  array_number = ['0','1','2','3','4','5','6','7','8','9']
  array_caratteri = ['*','#','+','$','@','/','=','-','%','&']
  array_caratteri_all = ['*','#','+','$','@','/','=','-','%','.','&']
  check = False
  index = 0
  numbers=[]
  array_len= len(file)-1
  for v,x in enumerate(file):
    number =''
    y=0
    start = 0
    end= 0
    #mettere dentro tutti i numeri che is incontrano
    while y < len(x):
        if x[y] in array_number:
            if number == '': start = y
            number+= x[y]
            end = y
        if number !='' and (x[y] in array_caratteri_all or (y == len(x) - 1 and x[y] in array_number)) :
            numbers.append({'s':start,'e':end,'num':number})
            number = ''
        y+= 1
    # ciclo sui numeri  e vedere le loro posizioni  
    while (index < len(numbers)):
        s = numbers[index]['s']
        e = numbers[index]['e']
        if v==0: # prima row controllo solo di qulla sotto ed essa
            if s == 0: # inizio da 0
                if two_row(file[v + 1][s:e + 2],file[v][s:e + 2],array_caratteri):check = True
            elif e == len(x): # si arriva alla fine 
                if two_row(file[v + 1][s - 1:e + 1],file[v][s - 1:e + 1],array_caratteri):check = True
            else: # vlori tutti in messo
                if two_row(file[v + 1][s -1 :e + 2],file[v][s -1 :e + 2],array_caratteri):check = True
        elif v == array_len: # ultima row si controlla la precedente ed essa
            if s == 0: # inizio row
                if two_row(file[v - 1][s:e +2],file[v][s:e + 2],array_caratteri):check = True
            elif e == len(x): # fine row
                if two_row(file[v - 1][s - 1:e + 1],file[v][s - 1:e + 1 ],array_caratteri):check = True
            else: #valori in mezzo
                if two_row(file[v - 1][s -1 :e + 2],file[v][s -1 :e + 2],array_caratteri):check = True
        else: # tutti i valori in messo
            if s == 0:
                if controllo_up_down(file[v + 1][s:e + 2],file[v][s:e + 2],file[v - 1][s:e + 2],array_caratteri):check = True
            elif e == len(x):
                if  controllo_up_down(file[v + 1][s - 1:e  + 1], file[v][s - 1: e + 1],file[v - 1][s - 1: e + 1],array_caratteri):check = True
            else: 
                if  controllo_up_down(file[v + 1][s - 1 :e + 2],file[v][s - 1 :e + 2],file[v - 1][s - 1:e + 2],array_caratteri):check = True
        if check:
            risultato.append(int(numbers[index]['num']))
            check = False
        index += 1
  print(numbers)
  print(risultato)
  print(sum(risultato))
