# -*- coding: UTF-8 -*-
'''
Created on Dec 14, 2012

@author: lzjun
'''
from django.contrib import admin

from articleStat.models import Author,Article,AuthorModelForm


class ArticleAdmin(admin.ModelAdmin):
    list_display=('title','Author','link','originalLink','duration','addTime',)
    search_fields=('title',)

class AuthorAdmin(admin.ModelAdmin):
    list_display=('name','email','weibo','addTime','qq',)
    search_fields=('name',)
    ordering=('addTime',)
    form=AuthorModelForm

    
    


admin.site.register(Author,AuthorAdmin)
admin.site.register(Article,ArticleAdmin)