import re

key = r'http://www.poshoaiu.com and https://iusdhbfw.com'
p = r'https*://'
pattern = re.compile(p)
match = re.findall(pattern, key)
print(match)
