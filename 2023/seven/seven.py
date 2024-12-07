with open('input.txt',mode='r') as f:
    t = f.readlines()
    file = list(map(lambda s:s.strip(),t))
    pair=[{'hand':x[0:5] , 'bid':x[6:]} for x in file]

    two_double, three, Full_house, two,one, four_of_a_kind, five_of_a_kind = [],[],[],[],[],[],[]

    for card in pair:
        value_count = []
        q =''
        for y , v in enumerate(card['hand']): 
            count = card['hand'].count(v) # occorenza di una carta
            if v not in q : # se non contata allora si inserisce se no mette dei doppioni 32T3K mette due volte 2 invece di una
               q += v
               value_count.append(count) 
        value_count.sort(reverse=True)
        
        # combinazioni 
        if value_count == [5]: five_of_a_kind.append(card['hand'])
        elif value_count == [4,1]: four_of_a_kind.append(card['hand'])
        elif value_count == [3,2]: Full_house.append(card['hand'])
        elif value_count == [3,1,1]: three.append(card['hand'])
        elif value_count == [2,2,1]: two_double.append(card['hand'])
        elif value_count == [2,1,1,1]: two.append(card['hand'])
        else:one.append(card['hand'])

    print(one)
    print(two)
    print(three)
    print(Full_house)
    print(two_double)
    print(four_of_a_kind)
    print(five_of_a_kind)


    def reorder(array):
        # array vuoto
        if len(array) <2:
           return array
        
        scala = ['2','3','4','5','6','7','8','9','T','J','Q','K','A']
        array_cards=[]
        x = 0
        value = None
        while  0 != len(array):
            big = -1
            for y in array:
              # cerca l'importanza di ogni prima carta di ogni mano  
              card2 = scala.index(y[x])
            #   se più grande di precedente allora è più forte 
              if card2 > big and y not in array_cards: 
                big = card2
                value = y
            #    se ci sono due carte che hanno la stessa forza allora si guarda quella successiva 
              elif card2 == big:
                #   ciclo ma dalla carta successiva 
                 for i in range(x + 1, 5):
                    #  carta successiva maggiore 
                    if scala.index(y[i]) > scala.index(value[i]):
                       value = y
                       break
                    elif scala.index(y[i]) < scala.index(value[i]): break
           # aggiunta carta 
            if value:
               x = 0
               array.remove(value)
               array_cards.append(value) 
            
        return array_cards[::-1]

    lista_two_double = reorder(two_double)
    lista_one = reorder(one)
    lista_two = reorder(two)
    lista_three = reorder(three)
    lista_Full_house = reorder(Full_house)
    lista_five_of_a_kind = reorder(five_of_a_kind)
    lista_four_of_a_kind = reorder(four_of_a_kind)
    # unione array 
    def unione (arra1,array2,array3,array4,array5,array6,array7):
        import itertools
        lista = list([arra1+array2+array3 + array4 + array5 + array6 + array7])
        return  list(itertools.chain(*lista))

    lista = unione(lista_one, lista_two, lista_two_double, lista_three, lista_Full_house, lista_four_of_a_kind, lista_five_of_a_kind)
    print(lista)       

    somma = [int(int(x['bid']) * (lista.index(x['hand']) + 1)) for x in pair if x['hand'] in lista]
    
    # for i, value  in enumerate(lista):
    #    for x in pair:
    #       if x['hand'] == value:
    #          somma.append(int(int(x['bid']) * (i + 1)))

    print(len(somma))
    print(sum(somma))
       
    # 246409899