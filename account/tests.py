"""
This file demonstrates writing tests using the unittest module. These will pass
when you run "manage.py test".

Replace this with more appropriate tests for your application.
"""

from django.test import TestCase


class SimpleTest(TestCase):
    def test_basic_addition(self):
        """
        Tests that 1 + 1 always equals 2.
        """
        self.assertEqual(1 + 1, 2)
        
if __name__=="__main__":
    print "hello"
    
    s='python'
    print s[0]
    print s[-1]
    
    a =  list(s)
    a.append("world")
    print a
    
    a.sort()
    a.reverse()
    print a
    print sorted(a)
    
    data = [x+1 for x in range(10) if x%2==0]
    print data
    
    data2 = (x+1 for x in range(10) if x%2==0)
    print data2
    
    for line in open("tests.py"):
        if "world" in line:
            print line
