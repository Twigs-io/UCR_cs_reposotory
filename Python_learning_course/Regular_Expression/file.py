import re

pattern = re.compile(r"[^A-Za-z0-9$#@]{7,}[0-9]")
string = 'asdass9'

a = pattern.fullmatch(string)
print(a)