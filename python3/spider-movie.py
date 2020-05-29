import requests
from bs4 import BeautifulSoup as bs

def get_html(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = "gbk"
        print("Html contents extract complete!!")
        return r.text
    except:
        print("Oops!Error occur when extracting html contents")

def get_content(url):
    html = get_html(url)
    soup = bs(html,'lxml')
    ulTag = soup.find('ul',class_="picList clearfix")
    liTags = ulTag.find_all('li')
    contents=[]
    print("Start extract webpage data!")
    for li in liTags:
        content = {}
        content['title']=li.find('span',class_="sTit").text.strip()
        try:
            content['time']=li.find('span',class_="sIntro").text.strip()
        except:
            content["time"]="unknown"
        act_field=li.find('p',class_="pActor")
        actors = act_field.find_all('a')
        content["actor"]=""
        for actor in actors:
            content["actor"]+=actor.text.strip()+" "
        content['desc']=li.find('p',class_="pTxt pIntroShow").text.strip()
        content['pic']="http:"+li.find('img')['src']
        contents.append(content)
        print("title:{} completed!".format(content['title']))
    return contents

def output(dic):
    print("Start writing data into file")
    with open("movie.txt","a+") as f:
        f.write("Movie List:\n\n")
        for item in dic:
            f.write("title:{}\tactors:{}\ttime:{}\ndescription:{}\n\n".format(item['title'],item['actor'],item['time'],item['desc']))
            with open("C:/Users/Payhemfoh/source/repos/img/"+item['title']+".png",'wb+') as f:
                f.write(requests.get(item['pic']).content)
    print("File saved completed!!")
if __name__ == "__main__":
    url = "http://dianying.2345.com/top/"
    content = get_content(url)
    output(content)
    print("Program completed and runs successfully")
