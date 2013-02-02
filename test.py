'''
Created on Jan 29, 2013

@author: lzjun
'''
import time

def timeit(func):
    def wrapper():
        start = time.clock()
        func()
        end = time.clock()
        return start-end
    return wrapper
        
        

@timeit
def foo():
    print "helloworld"
    


if __name__ == '__main__':
    
    print foo()
    
    
    #[x%3*4::]
   # for x in range(101):
       
      #  print"fizz" [:]
      #  print"fizz"[x%3*4::]+"buzz"[x%5*4::]or x