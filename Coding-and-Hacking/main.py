from html.parser import HTMLParser
import sys

class Node(object):
    def __init__(self):
        self.tagname=None
        self.childlist=list()
        self.parent=None
        self.content=None
        self.classname=None
        self.childcount=dict()
        self.maxval=0

class MyHTMLParser(HTMLParser):
    def __init__(self):
        super(MyHTMLParser,self).__init__()
        self.root=Node()
        self.root.tagname="root"
        self.currentptr=self.root
    def handle_starttag(self, tag, attrs):
        node=Node()
        node.tagname=tag
        node.classname=attrs

        node.parent=self.currentptr
        self.currentptr.childlist.append(node)
        if tag in self.currentptr.childcount:
            self.currentptr.childcount[tag]+=1
        else:
            self.currentptr.childcount[tag]=1
        self.currentptr=node

    def handle_endtag(self, tag):
        self.currentptr=self.currentptr.parent

    def handle_data(self, data):
        self.currentptr.content=data

parser = MyHTMLParser()
import requests
from bs4 import BeautifulSoup

url=sys.argv[1]
r=requests.get(url)
soup = BeautifulSoup(r.content, 'html.parser')
parser.feed(str(soup).replace('\n',''))
# print(soup)
sortlist=list()
def dfs(node):
    if 'input' in node.childcount:
        del node.childcount['input']
    childrenvalues=list(node.childcount.values())
    if len(childrenvalues)!=0:
        node.maxval=max(childrenvalues)
        sortlist.append(node)
    for t in node.childlist:
        dfs(t)

dfs(parser.root)
sortlist = sorted(sortlist, key=lambda x: x.maxval)
sortlist=reversed(sortlist)

column_list=list()
kvpair=dict()
def getkeyval(t,parstr):
    for t1 in t.childlist:
        getkeyval(t1,parstr+t.tagname)
    if t.content!=None:
        temp=parstr+t.tagname
        while temp in kvpair:
            temp=temp+'1'
        kvpair[temp]=t.content



import numpy as np
final_table = list()

for node in sortlist:
    if(node.tagname=='meta' or node.tagname=='head'):
        continue
    for t in node.childlist:
        getkeyval(t,'')
        for t1 in kvpair.keys():
            if not t1 in column_list:
                column_list.append(t1)
        templist=list()
        for t1 in column_list:
            templist.append(kvpair.get(t1,'-'))
        final_table.append(templist)
        kvpair=dict()
    break
for i in range(len(final_table)):
    final_table[i]=final_table[i]+['-']*(len(column_list)-len(final_table[i]))
import pandas as pd
column_list1=list()
for i in range(len(column_list)):
    column_list1.append('column'+str(i))
df = pd.DataFrame(np.array(final_table),columns=column_list1)

print(df.to_json(orient='records'))