# -*- coding: UTF-8 -*-
from django.db import models

# Create your models here.

class Author(models.Model):
    name=models.CharField(max_length=15)
    link=models.CharField(max_length=100,null=True)
    email=models.EmailField(max_length=30)
    weibo=models.CharField(max_length=50)
    addTime=models.DateTimeField(null=True)
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
    
