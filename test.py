import urllib2
import sys
url="http://www.douban.com/"
content = urllib2.urlopen(url).read()
print content

