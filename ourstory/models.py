from django.db import models
from django.contrib import admin

# Create your models here.

class OurStory(models.Model):
    
    firstTime=models.DateField()
    action=models.TextField(null=True)
    
    class Meta:
        ordering=('firstTime',)

class OurStoryAdmin(admin.ModelAdmin):
    list_display=('firstTime','action',)
    
admin.site.register(OurStory, OurStoryAdmin)
