# -*- coding: UTF-8 -*-
'''
Created on Dec 14, 2012

@author: lzjun
'''

from django.shortcuts import  render_to_response
from articleStat.models import Author, Article
import datetime
import calendar
import articleStat

#统计指定月份的作者的文章
def stat(request,year,month):
    year=int(year)
    month=int(month)
    
    articleStat=[]
    authors = Author.objects.all().order_by("-isPayAuthor")

    print authors
    
    
    
    startDate=datetime.date(year,month,1)
    days=calendar.monthrange(year, month)[1] #当前月份的天数
    endDate=datetime.date(year,month,days)

    for author in authors:
        articles = Article.objects.filter(Author=author,addTime__range=(startDate,endDate))
        
        articleStat.append((author,articles))
    
    print articleStat
    
    next_month=""
    pre_month=""
    today=datetime.date.today()
    
    if(month==12):
        next_month=str((year+1))+"1"
    else:
        next_month=str((year))+str((month+1))
    if(month==1):
        pre_month=str((year-1))+"12"
    else:
        pre_month=str((year))+str((month-1))
   
     
    params = {   'articleStat':articleStat,
                 'year':year,
                 'month':month,
                 'pre_month':pre_month,
                 "next_month":next_month,
                 "current_month":str(today.timetuple()[0])+str(today.timetuple()[1])
             }
   
    for obj in articleStat:
        print obj[0].qq,obj[1]
    
    return render_to_response("stat.html",params)


def stat_ccurrent_month(request):
    
    ccurrent_day=datetime.date.today()
    year=ccurrent_day.timetuple()[0]
    month=ccurrent_day.timetuple()[1]
    return stat(request, year, month)
    

'''
    作者信息
'''
def authorprofile(request,author):
    
    authorId=int(author)
    author = Author.objects.get(id=authorId)
    
    articles=Article.objects.filter(Author=author)
    
    return render_to_response("profile.html",{"author":author,"articles":articles})




