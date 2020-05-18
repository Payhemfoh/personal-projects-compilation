import requests
from bs4 import BeautifulSoup

def get_html(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        print("Ops! Error occur when extract html content!")

#return the category name
def get_name(li,num):
    print(li[num])
    return li[num].text.strip()

def get_content(url):
    html = get_html(url)
    url_list = []
    soup = BeautifulSoup(html,'lxml')
    categories = soup.find_all('div',class_="item")
    categories_2 = soup.find_all('div',class_="item ml")
    for category in categories:
        #get category name and write into csv file as title
        name = get_name(category.find('h2'),-1)
        with open("novelList.csv","a+") as f:
            f.write("Category:{}\n\n".format(name))
        general_list = category.find_all('li')
        
        #get the list of book and save to file with link extracted and save in a list
        for book in general_list:
            link = book.find('a')['href'].replace('book','dir')
            title = book.find('a').text.strip()
            url_list.append(link)
            with open("novelList.csv","a+") as f:
                f.write("name:{}\tlink:{}\n\n".format(title,link))

    for category in categories_2:
        #get category name and write into csv file as title
        name = get_name(category.find('h2'),-1)
        with open("novelList.csv","a+") as f:
            f.write("Category:{}\n\n".format(name))
        general_list = category.find_all('li')
        
        #get the list of book and save to file with link extracted and save in a list
        for book in general_list:
            link = book.find('a')['href'].replace('book','dir')
            title = book.find('a').text.strip()
            url_list.append(link)
            with open("novelList.csv","a+") as f:
                f.write("name:{}\tlink:{}\n\n".format(title,link))
    
    return url_list

#get link for all the chapters of the book
def get_txt_url(url): 
    url_list = []
    html = get_html(url)
    soup = BeautifulSoup(html,'lxml')
    block_title =soup.find('div',class_='dh') 
    title = get_name(block_title.find_all('a'),2)
    chapter_block = soup.find('div',class_="chapter")
    chapters = chapter_block.find_all('li')
    with open("{}.txt".format(title),"a+") as f:
        f.write("Title:{}".format("title"))
    for chp in chapters:
        url_list.append("http://mm.hengyan.com"+chp.a['href'])
    return url_list,title

#get text from all chapters of the book
def get_one_txt(url,txt_name):
    html = get_html(url)
    soup = BeautifulSoup(html)
    try:
        txt = soup.find('div',class_="content").replace('chaptererror()','')
        title = soup.find('div',class_="ch").text.strip()

        with open("{}.txt".format(txt_name),"a+") as f:
            f.write(title+"\n\n")
            f.write(txt)
            print("novel:{} chapter:{} completed!".format(txt_name,title))
    except:
        print("Ops!Something went wrong when extracting chapter!")

#main function
if __name__ == "__main__":
    base_url = "http://top.hengyan.com"
    contents = get_content(base_url)
    contents = list(set(contents))
    for book in contents:
        links=get_txt_url(book)
        for li in links[0]:
            get_one_txt(li,links[1])
    print("Completed!!")

