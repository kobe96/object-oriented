from cgi import maxlen
from django.db import models

# Create your models here.


class Bill(models.Model):
    description=models.CharField(max_length=100)
    addTime=models.DateTimeField()
    amount=models.DecimalField(None, None, 7, 2)
