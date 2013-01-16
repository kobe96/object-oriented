# -*- coding: UTF-8 -*-
from django.db import models

# Create your models here.

class Author(models.Model):
    name=models.CharField(max_length=15)
    link=models.CharField(max_length=100,null=True)
    email=models.EmailField(max_length=30)
    weibo=models.CharField(max_length=50)
    qq=models.CharField(max_length=20,null=True,blank=True)
    addTime=models.DateTimeField(null=True)
    descr=models.CharField(max_length=500,blank=True)
    #是否为支付作者
    isPayAuthor=models.BooleanField(default=True)
    isDelete=models.BooleanField()
    
    def __unicode__(self):
        return self.name
    
class Article(models.Model):
    title=models.CharField(max_length=100)
    link=models.CharField(max_length=200)
    originalLink=models.CharField(max_length=200 ,null=True)
    duration=models.IntegerField(default=1)
    addTime=models.DateTimeField()
    isDelete=models.BooleanField()
    Author=models.ForeignKey(Author)
    
    def __unicode__(self):
        return self.title
    
    
from django import forms
class AuthorModelForm(forms.ModelForm):
    descr = forms.CharField(widget=forms.Textarea)
    class Meta:
        model=Author


    
