import spacy
nlp = spacy.load('en')

# Add neural coref to SpaCy's pipe
import neuralcoref
neuralcoref.add_to_pipe(nlp)

sentences = [
    'My sister has a dog. She loves him.',
    'Some like to play football, others are fond of basketball.',
    'The more a man knows, the more he feels his ignorance.'
]

for sentence in sentences:
    doc = nlp(sentence)
    print(sentence)
    print('has coref: %s'%doc._.has_coref)
    if doc._.has_coref:
        print(doc._.coref_clusters)
    print()
