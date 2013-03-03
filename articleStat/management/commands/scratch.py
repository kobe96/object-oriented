# -*- coding:UTF-8 -*-
'''
Created on 2013-3-3
抓取importnew.com的文章信息，保存数据库
结合linux cron 运行  python manage.py scratch，每周抓取一次，每个月底抓取一次
@author: liuzhijun
'''

from articleStat.models import Author,Article
from django.core.management.base import BaseCommand

import urllib2
from bs4 import BeautifulSoup
import time
from time import mktime
from datetime import datetime

class Command(BaseCommand):
    
    def handle(self,*args,**options):
        authors = Author.objects.all()
        for author in authors:
            print author
            scratch_save(author,author.link)
        
'''根据链接返回Article列表对象'''
def scratch_save(author,link):
    page=urllib2.urlopen(link).read()
    try:
        main_tag=BeautifulSoup(page).html.body.find(id="main")
        article_tags=main_tag.section.find_all('article')
        
        links_maps = Article.objects.filter(Author=author).values('link')
       
        #数据库中对应作者的所有文章的在importnew的链接地址
        db_links  = []
        
        for link_map in links_maps:
            db_links.append(link_map['link'])
            
        '''
                    从article_tag中查出db_links中没有的链接，保存数据库
        '''
        for article_tag in article_tags:
            #获取importnew当前作者页面的所有文章link
            link = article_tag.section.h1.a['href']
            
            #如果在数据库中没有对应的链接，则加入数据库
            if link not in db_links:
                #标题
                title_ = article_tag.section.h1.a['title']
                date_tag = (article_tag.find_all('ul')[1]).find_all('li')[2].string.replace(" ","")
                struct = time.strptime(date_tag,u"%Y年%m月%d日")
                #添加日期
                addtime_ = datetime.fromtimestamp(mktime(struct))
                
                article = Article(title=title_,addTime=addtime_,Author=author,link=link)
                print article
                article.save()
    except AttributeError, e:
        print "找不到相应的链接"
        print e

