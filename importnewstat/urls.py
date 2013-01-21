from django.conf.urls import patterns, include, url
from importnewstat.views import *
from django.conf import settings
from django.contrib import admin
admin.autodiscover()

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'importnewstat.views.home', name='home'),
    # url(r'^importnewstat/', include('importnewstat.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    # url(r'^admin/', include(admin.site.urls)),
    
    #^(0?[1-9]|1[0-2])$
    url(r"stat/date/(\d{4})([1-9]|1[0-2])$", stat),
    url(r'^importnewstat/stat/$',stat_ccurrent_month),
    url(r'importnewstat/author/(\d)',authorprofile),
    
    url(r'^importnewstat/admin/', include(admin.site.urls)),
    url(r'^site_media/(?P<path>.*)$','django.views.static.serve',{'document_root':settings.STATIC_PATH}),
    
    url(r'^story/',include('ourstory.urls'))
    
)
