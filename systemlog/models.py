# -*- coding:UTF-8 -*-
from django.db import models

from django.contrib import admin

# Create your models here.
'''
系统日志，记录平台功能更新日志记录
'''
class Systemlog(models.Model):
    title = models.CharField(max_length=100)
    content = models.TextField()
    update_date = models.DateField()
    class Meta:
        ordering=['-update_date']
    
    def __unicode__(self):
        return self.content
    
    
class SystemlogAdmin(admin.ModelAdmin):
    
    list_display=('title','update_date',)
    
admin.site.register(Systemlog, SystemlogAdmin)
        
