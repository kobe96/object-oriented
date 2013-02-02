# -*- coding: UTF-8 -*-
'''
Created on Feb 2, 2013
自动处理每月文章统计发送至指定邮箱xxx@gmail.com
这个需要结合linux 的cron使用   运行： python manage.py mail
@author: lzjun
'''
from django.core.mail import EmailMultiAlternatives
from django.shortcuts import  render_to_response
from articleStat.models import Author, Article
import datetime
import time
import calendar

from django.core.management.base import BaseCommand

class Command(BaseCommand):
    args = '<poll_id poll_id ...>'
    help = 'Closes the specified poll for voting'


    def handle(self,*args,**options):
        
        year = time.localtime()[0]
        month = time.localtime()[1]
        
        articleStat=[]
        authors = Author.objects.all().order_by("-isPayAuthor")
        
        startDate=datetime.date(year,month,1)
        days=calendar.monthrange(year, month)[1] #当前月份的天数
        endDate=datetime.date(year,month,days)
    
        for author in authors:
            articles = Article.objects.filter(Author=author,addTime__range=(startDate,endDate))
            if len(articles)>0:
                articleStat.append((author,articles))
        
        params = {   'articleStat':articleStat, 
                     'year':year,
                     'month':month,}
        
        html_content = render_to_response("mail_template.html",params)
        
        subject=str(year)+'年'+str(month)+'月 importnew 译文统计'
        from_email,to='lzjun567@gmail.com','importnew.com@gmail.com'
        text_content = 'this is an important message'
        html_content = str(html_content).replace("Content-Type: text/html; charset=utf-8","")
       
        html_content += "<br>此邮件由系统自动发送"
        msg = EmailMultiAlternatives(subject,text_content,from_email,[to])
        msg.attach_alternative(html_content, 'text/html')
        msg.send()

