
"""
import requests

try:
    file = open("google.txt","w+")
    r = requests.get("http://www.google.com",timeout=30)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    file.write(r.text)
    file.close()
    file = open("Program.java","r")
    print(file.read())
    file.close()
except:
    print("Something went wrong");
finally:
    x = input();
    """

"""
from bs4 import BeautifulSoup as b

try:
    file = open("google.txt","r")
    text=file.read();
    soup = b(text,'lxml')
    print(soup.prettify())
except:
    print("Something went wrong")
finally:
    x = input()

"""

import requests
from bs4 import BeautifulSoup as b

def get_html(url):
    try:
        r = requests.get(url,timeout=30)
        r.raise_for_status()
        
        r.encoding=r.apparent_encoding
        return r.text
    except:
        return " ERROR "

#url:
#https://tieba.baidu.com/f?kw=%E7%AB%A5%E8%AF%9D%E8%BE%B9%E5%A2%83&ie=utf-8&pn=50
def get_content(url):
    comments=[]
    html = get_html(url)
    soup = b(html,'lxml')
    liTags = soup.find_all('li',attrs={'class':'j_thread_list clearfix'})
    
    for li in liTags:
        comment={}
        try:
            comment['title'] = li.find(
                'a',attrs={'class':'j_th_tit'}).text.strip()
            comment['link'] = li.find(
                'a',attrs={'class':'j_th_tit'})['href']
            comment['name'] = li.find(
                'span',{'class':'tb_icon_author'})['title']
            comment['time'] = li.find(
                'span',{'class':"pull-right is_show_create_time"}).text.strip()
            comment['replyNum'] = li.find(
                'span',{'class':"threadlist_rep_num center_text"}).text.strip()
            comments.append(comment)
            print('complete '+comment["link"])
        except:
            print("Error")
    return comments

def Output(dict):
    with open('spider.txt','a+') as f:
        for comment in dict:
            f.write("title:{} \t link:{} \t {} \t time:{} \t replyNum:{}\n".format(
                comment['title'],comment['link'],comment['name'],comment['time'],comment['replyNum']))
        print("complete")
    
def main(base_url, deep):
    url_list=[]
    
    for i in range(0,deep):
        url_list.append(base_url+'&pn='+str(50*i))
    print('starting search')
    
    for url in url_list:
        content = get_content(url)
        Output(content)
    print("Data Saved completed")
    
base_url = "https://tieba.baidu.com/f?kw=%E7%AB%A5%E8%AF%9D%E8%BE%B9%E5%A2%83&ie=utf-8"
deep = 3

if __name__ == '__main__':
    main(base_url,deep)
    input()