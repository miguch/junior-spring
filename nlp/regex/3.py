import re

key = r'sysu@hotmail.edu.cn'
p = r'@.{,7}\.'
pattern = re.compile(p)
match = re.findall(pattern, key)
print(match)