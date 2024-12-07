# # with open('input.txt', mode='r') as f:
# #     t = f.readlines()
# #     file = map(lambda s: s.strip(), t)
# #     count = 0
# #     for x,v in enumerate(file) :
# #         count_card = 0
# #         number_win = v[v.find(':') + 1:v.find('|')].split()
# #         number_have = v[v.find('|') + 1:].split()
# #         for y in number_win:
# #             if y in number_have and count_card == 0 :count_card += 1
# #             elif y in number_have: count_card += count_card
# #         print(number_have)
# #         print(number_win)
# #         count += count_card
# #     print(count)
        
def somma(array_carte):
    memo={}
    def card(index):
        # se carta gia dentro 
        if index in memo: return memo[index]
        total_count = 1
        c = 0
        # Conta le coincidenze dei numeri
        for x in array_carte[index]['win']:
            if x in array_carte[index]['have']:
                c += 1

        for i in range(1, c + 1):
            next_index = index + i
            # blocco che indice non superi lunghezza array
            if next_index < len(array_carte):
                # somma
                total_count += card(next_index)
                
        memo[index] = total_count
        return total_count
    
    totale = 0
    for x in  range(len(array_carte)):
        totale += card(x)
    print(totale)
    return memo

# Lettura del file e creazione della lista di carte
with open('input.txt', mode='r') as f:
    t = f.readlines()
    file = map(lambda s: s.strip(), t)
    cards = []
    for v in file:
        card = {}
        card['win'] = v[v.find(':') + 1:v.find('|')].split()
        card['have'] = v[v.find('|') + 1:].split()
        cards.append(card)

# Esegui la funzione partendo dalla prima carta
print(somma(cards))