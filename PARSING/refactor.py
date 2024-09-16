file = open('data.txt', 'r', encoding='UTF8')

data = [i.rstrip() for i in file.readlines()]

file_refactor = open("data_refact.txt", 'a', encoding='UTF8')

new_length = 0
for i in data:
    text = i.split()
    if len(text) > 1 and 'УРОВЕНЬ' not in text:
        new_text = ' '.join(text[1:])
        file_refactor.write(new_text + '\n')
        new_length += 1

print(new_length)
file_refactor.close()
file.close()
