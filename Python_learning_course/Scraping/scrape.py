from bs4 import BeautifulSoup # Beautiful Soup
import requests # To get the source code of the website

res = requests.get('https://news.ycombinator.com/')
soup = BeautifulSoup(res.text, 'html.parser')
links = soup.select('.titleline')
subtext = soup.select('.subtext')

def create_coustome_hn(links, subtext):
    hn = []
    for idx, item in enumerate(links):
        title = item.getText()
        href = item[idx].get('href', None)
        votes = subtext[idx].select('.score')
        if len(votes):
            points = int(votes[idx].getText().replace(' points', ''))
            hn.append({'title': title, 'link': href, 'votes': points})
    return hn


print(create_coustome_hn(links, subtext))