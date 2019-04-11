from nltk.corpus import wordnet as wn
def get_syn_definitions_examples(word):
    syns = wn.synsets(word)
    print('%s:'%word)
    for syn in syns:
        if syn.name().split('.')[0] == word:
            continue
        print('  %s:'%syn.name().split('.')[0])
        print(syn.definition())
        for example in syn.examples():
             print(example)
    print() 

words = ['dog', 'apple', 'fly']
for word in words:
    get_syn_definitions_examples(word)


def get_similarity(word_pair):
    syns_1 = wn.synsets(word_pair[0])
    syns_2 = wn.synsets(word_pair[1])
    for syn_1 in syns_1:
        for syn_2 in syns_2:
            if str(syn_1.name()).split('.')[1] != str(syn_2.name()).split('.')[1] or str(syn_1.name()).split('.')[0] != word_pair[0] or str(syn_2.name()).split('.')[0] != word_pair[1]:
                continue
            similarity = syn_1.path_similarity(syn_2)
            if similarity:
                print('%s, %s: %s'%(str(syn_1.name()), str(syn_2.name()), similarity))
word_pairs = [('good', 'beautiful'), ('good', 'bad'), ('dog', 'cat')]
for pair in word_pairs:
    get_similarity(pair)

words = ['walk', 'supply', 'hot']
def get_entailment_antonym(word):
    syns = wn.synsets(word)
    print('%s:'%word)
    entailments = []
    antonyms = []
    for syn in syns:
        if syn.name().split('.')[0] != word:
            continue
        entailments.extend(syn.entailments())
        antonyms.extend(syn.lemmas()[0].antonyms())
    print('entailments: %s'%entailments)
    print('antonyms: %s' % antonyms)
    print() 
for word in words:
    get_entailment_antonym(word)

