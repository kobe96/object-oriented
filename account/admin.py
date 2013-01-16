'''
Created on Jan 4, 2013

@author: lzjun
'''
from django.contrib import admin

from account.models import Bill


class BillAdmin(admin.ModelAdmin):
    list_display=('amount','description','addTime',)
    search_fields=('addTime',)

admin.site.register(Bill,BillAdmin)
