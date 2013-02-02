# -*- coding: UTF-8 -*-
'''
Created on Dec 14, 2012

@author: lzjun
'''

from django.shortcuts import  render_to_response
from articleStat.models import Author, Article
import datetime
import calendar
from  django.core.mail import send_mail
from django.shortcuts import  HttpResponseRedirect
from django.shortcuts import  HttpResponse

from django.core.mail import BadHeaderError
from django.views.decorators.csrf import csrf_exempt
from django.core.mail import EmailMultiAlternatives

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
def authorprofile(request,author):
    
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



'''

'''
@csrf_exempt
def auto_send_mail(request):
    
    if request.method=='GET':
        return render_to_response('mail.html',{})
    
    subject = request.POST.get('subject','')
    message = request.POST.get('message','')
    to_email =request.POST.get('to_email','')
    
    if subject and message and to_email:
        try:
            print subject,message,to_email
            send_mail(subject,message,'lzjun567@gmail.com',['lzjun567@qq.com'])
        except BadHeaderError:
            return HttpResponse('Invalid header found')
        return HttpResponseRedirect('/importnewstat/thanks/')
    else:
        return HttpResponse('make sure all filed are entered and valid')
            

def cron_send_mail(request):
    subject=''
    from_email,to='lzjun567@gmail.com','lzjun567@qq.com'
    
    text_content = 'this is an important message'
    html_content = stat(request,2013,1,"mail_template.html")
    html_content = str(html_content).replace("Content-Type: text/html; charset=utf-8","")
    print html_content
    msg = EmailMultiAlternatives(subject,text_content,from_email,[to])
    msg.attach_alternative(html_content, 'text/html')
    msg.send()
    return HttpResponseRedirect('/importnewstat/thanks/')
    
  

def thanks(reqest): 
    return HttpResponse("thanks")   

