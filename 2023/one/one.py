'''
first part
'''

# def check(n):
#     num_row=[]
#     if n.isdigit(): num_row.append(n)
#     return num_row

# with open('small.txt',  mode='r')  as file:
#     f=file.readlines()
#     filtered_lst=[]
#     for r in f:
#         filtered_lst += [list(filter(check,r))]

# count=0
# for n in filtered_lst:
#     count+= int( n[0] + n[-1])

# # print(count)

'''
second part
'''
# number_letter = ['one', 'two',  'three', 'four',  'five',  'six',  'seven',  'eight',  'nine']
number_letter = [
    {'d': 1, 'n': 'one'},
    {'d': 2, 'n': 'two'},
    {'d': 3, 'n': 'three'},
    {'d': 4, 'n': 'four'},
    {'d': 5, 'n': 'five'},
    {'d': 6, 'n': 'six'},
    {'d': 7, 'n': 'seven'},
    {'d': 8, 'n': 'eight'},
    {'d': 9, 'n': 'nine'}
]

with open('input.txt',  mode='r')  as file:
    f=file.readlines()
    filtered_list=[]
    count=0
    for x in f:
        row_list=[]
        for y in range(len(x)):
            for value in number_letter:
               letter=value['n'] 
               number=str(value['d'])
               if x[y:].startswith(letter):  row_list.append(number) #guarda se riga inizia con componenti in number_letter
               if x[y:].startswith(number):  row_list.append(number) #guarda se riga inizia con componenti in number_letter
        filtered_list.append(int((row_list[0] + row_list[-1]))) # prende primo e ultimo 
    print(sum(filtered_list))

# r=5

# def check_foward(num_let,chunk):
#     for x in range(len(chunk)):
#         for y in num_let:
#             letter=y['n']
#             number=str(y['d'])
#             if chunk[x:].startswith(letter): return number
#             if chunk[x:].startswith(number): return number

# def check_back(num_let,chunk):
#     for x in range(len(chunk)):
#         for y in num_let:
#             letter=y['n']
#             number=str(y['d'])
#             if chunk[x:].startswith(letter): return number
#             if chunk[x:].startswith(number): return number

    # count+=int(row_list[0] + row_list[-1])
    # print(count)

        # chunk=[x[y:y + r] for y in range((len(x) - r) + 1)]
        # index=0
        # index_back=len(chunk) - 1
        # for x in chunk:
        #     if check_foward(number_letter,x) not in row_list: row_list.append(check_foward(number_letter,x))

        # while len(row_list) != 2 :
        #     if len(row_list) < 1:
        #        if check_foward(number_letter,chunk[index]) != None: row_list.append(check_foward(number_letter,chunk[index]))
        #        index+=1
        #     else:
        #        if check_back(number_letter, chunk[index_back]) != None: row_list.append(check_back(number_letter, chunk[index_back]))
        #        index_back-=1
        # if None in row_list: row_list.remove(None)
        # print(row_list)
        # count+= int(row_list[0] + row_list[-1])
        # print([row_list[0] + row_list[-1]])
# print(count)