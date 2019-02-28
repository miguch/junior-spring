import re

key = r'sysu@hotmail.edu.cn'
p = r'@.+?\.'
pattern = re.compile(p)
match = re.findall(pattern, key)
print(match)

