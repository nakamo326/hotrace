import random
import shutil

DICT = "dict.txt"
WORD_NUM = 102401
TEST_NUM = 5

random_val = random.sample(range(1, WORD_NUM + 1), k=TEST_NUM)

key_index = list(map(lambda x:x*2 - 1, random_val))

key_list = []
for kc in range(TEST_NUM):
    i = 1
    with open(DICT) as f:
        for line in f:
            if i == key_index[kc] :
                key_list.append(line.replace('\n', ''))
                break
            i = i + 1

print("key: ", key_list)
print("val: ", random_val)

shutil.copy(DICT, "test.htr")
with open("test.htr", mode='a') as f:
    for key in key_list:
        f.write('\n')
        f.write(key)
