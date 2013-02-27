# -*- coding: UTF-8 -*-
'''
Created on Dec 14, 2012

@author: lzjun
'''

from django.shortcuts import  render_to_response
from articleStat.models import Author, Article
from django.shortcuts import  HttpResponse
import datetime
import calendar
from django.views.decorators.csrf import csrf_exempt
from django.utils import simplejson

from django.core import serializers


#select author.name,count(article.id) from 
#articleStat_author as author,articleStat_article as article where author.id=article.Author_id and article.addTime between 20130101 and 20130228 group by author.name order by  count(article.id) desc;
#统计指定月份的作者的文章
def stat(request,year,month,template='stat.html'):
    year=int(year)
    month=int(month)
    
    articleStat=[]
    authors = Author.objects.all().order_by("-isPayAuthor")
    
    startDate=datetime.date(year,month,1)
    days=calendar.monthrange(year, month)[1] #当前月份的天数
    endDate=datetime.date(year,month,days)

    for author in authors:
        articles = Article.objects.filter(Author=author,addTime__range=(startDate,endDate))
        if len(articles)>0:
            articleStat.append((author,articles))
    
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
   
    
    return render_to_response(template,params)


def stat_current_month(request):
    
    ccurrent_day=datetime.date.today()
    year=ccurrent_day.timetuple()[0]
    month=ccurrent_day.timetuple()[1]
    return stat(request, year, month)
    

'''
    作者详细信息
'''
@csrf_exempt 
def authorprofile(request,author):
    
    if request.method=="POST":
        dict = {}
        dict['message']="helloworld"
        print dict['message']
        print author
        authorId=int(author)
        author = Author.objects.get(id=authorId)
        articles=Article.objects.filter(Author=author)
        
        dict['descirption']=author.descr
        
        
        data = serializers.serialize('json',articles)
        
        print type(data)
        
        dict['articles']=data
        
        json=simplejson.dumps(dict)
        return HttpResponse(json, mimetype="application/json")
        #return HttpResponse(simplejson.dumps({'result':'success'}),mimetype='application/javascript')
    
    
    authorId=int(author)
    author = Author.objects.get(id=authorId)
    articles=Article.objects.filter(Author=author)
    
    return render_to_response("profile.html",{"author":author,"articles":articles})



'''
    作者列表
'''
def authorlist(request):
    authors = Author.objects.all().order_by("-isPayAuthor")
        
    return render_to_response("authorlist.html",{"authors":authors})


  

def thanks(reqest): 
    return HttpResponse("thanks")   

