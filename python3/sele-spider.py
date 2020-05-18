from selenium import webdriver

#class for the item get by the spider
class Item:
    ip = None
    port = None
    anonymous = None
    type = None
    local = None
    speed = None

#class of functions
class GetProxy(object):
    #initialize the object
    def __init__(self):
        self.base_url="https://www.kuaidaili.com/free/"
        self.urls = self.get_url()
        self.proxylist = self.get_proxy_list(self.urls)
        self.filename = 'proxyList.txt'
        self.saveFile(self.filename,self.proxylist)
    
    #get the list of url from website
    def get_url(self):
        urls=[]
        for i in range(3):
            url = self.base_url+'inha/'+str(i+1)+'/'
            urls.append(url)
        return urls

    #get contents from the website
    def get_proxy_list(self,urls):
        browser = webdriver.Chrome()
        proxy_list =[]
        print("Start to extract information from website")
        for url in urls:
            browser.get(url)
            browser.implicitly_wait(3)
            elements = browser.find_elements_by_xpath('//tbody/tr')
            for element in elements:
                item = Item()
                item.ip=element.find_element_by_xpath('./td[1]').text
                item.port=element.find_element_by_xpath('./td[2]').text
                item.anonymous=element.find_element_by_xpath('./td[3]').text
                item.local=element.find_element_by_xpath('./td[4]').text
                item.speed=element.find_element_by_xpath('./td[5]').text
                print(item.ip+' extract complete!')
                proxy_list.append(item)
        
        browser.quit()
        return proxy_list
    
    def saveFile(self,name,li):
        print("Write the data into file...")
        with open(name,'w') as f:
            for item in li:
                f.write("IP:"+item.ip+'\t')
                f.write("Port:"+item.port+'\t')
                f.write("Anonymous:"+item.anonymous+'\t')
                f.write("Local:"+item.local+'\t')
                f.write("Speed:"+item.speed+'\n\n')


if __name__ == '__main__':
    get = GetProxy()
    print("Completed!")
    x = input("Press any key to continue")
