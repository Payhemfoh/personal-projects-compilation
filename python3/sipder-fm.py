import requests
import bs4 as BeaufifulSoup

def get_html(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        print("Oops!Error occur when extract html content!!")
