from asyncore import write
import shutil

DICT = "dict.txt"

flag = False
with open("ascii_dict.txt", "w+") as output:
    with open(DICT) as f:
        for line in f:
            if flag == True:
                flag = False
                continue
            flag = False
            for c in line:
                if ord(c) > 127:
                    flag = True
            if flag == True:
                continue
            output.write(line)