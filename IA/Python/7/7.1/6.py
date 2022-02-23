def write_unique_words(in_file, out_file):
    wordsdict = {}
    [([open(out_file,'w').writelines([w[0]+"\n" for w in [(word, wordsdict.__setitem__(word, 1)) for word in [word.lower() for word in open(in_file, 'r').read().split('\n')] if wordsdict.keys().__contains__(word) == False]]) for x in range(1)]) for x in range(1)]
