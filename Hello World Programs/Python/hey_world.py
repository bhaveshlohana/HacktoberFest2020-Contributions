def fancy_hello(text):
    text = text
    for idx, c in enumerate(text):
        print('-'*idx, c, '-'*(len(text)-idx))


fancy_hello('HELLO AWESOME WORLD')

