import nltk
from nltk.tokenize import sent_tokenize 

text_en = open(u'./data/text_en.txt',encoding='utf-8',errors='ignore').read()

print(sent_tokenize(text_en))

