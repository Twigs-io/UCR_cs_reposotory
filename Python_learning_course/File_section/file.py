from translate import Translator

transltor = Translator(to_lang="ja")

with open('files/text.txt', mode = 'r') as test:
    text = test.read()
    transltor = transltor.translate(text)
    with open('files/translated.txt', mode = 'w') as tests:
        tests.write(transltor)
