#!/usr/bin/env python
# coding: utf-8

# In[1]:


import nltk


# In[2]:


SENTENCE = 'the lawyer questioned the witness about the revolver'


# In[3]:


def getGrammar(tags):
    DTs = '|'.join(['"%s"'%e[0] for e in tags if e[1] == 'DT'])
    NNs = '|'.join(['"%s"'%e[0] for e in tags if e[1] == 'NN'])
    VBDs = '|'.join(['"%s"'%e[0] for e in tags if e[1] == 'VBD'])
    INs = '|'.join(['"%s"'%e[0] for e in tags if e[1] == 'IN'])
    grammar = nltk.CFG.fromstring('''
    S -> NP VP 
    VP -> VBD NP | VBD NP PP 
    PP -> IN NP 
    NP -> DT NN 
    DT -> %s
    NN -> %s
    VBD -> %s
    IN -> %s
    ''' % (DTs, NNs, VBDs, INs))
    return grammar


# In[4]:


def topDown(sentence):
    words = nltk.word_tokenize(sentence)
    tags = nltk.pos_tag(words)
    tags = set(tags)
    grammar = getGrammar(tags)
    rd_parser = nltk.RecursiveDescentParser(grammar)
    for tree in rd_parser.parse(words):
        print(tree)


# In[5]:


topDown(SENTENCE)


# In[6]:


def bottomUp(sentence):
    words = nltk.word_tokenize(sentence)
    tags = nltk.pos_tag(words)
    tags = set(tags)
    grammar = getGrammar(tags)
    parser = nltk.ShiftReduceParser(grammar, trace=2)
    for tree in parser.parse(words):
        print(tree)


# In[7]:


# failed to find a parse because there is no backtracking
bottomUp(SENTENCE)


# In[ ]:




