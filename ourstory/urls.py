'''
Created on Jan 22, 2013

@author: lzjun

'''

from django.conf.urls.defaults import *

from ourstory.views import story

urlpatterns = patterns('',
                       
                       url(r'^$',story),
                       
                       )


