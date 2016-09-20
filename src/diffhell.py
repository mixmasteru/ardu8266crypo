#!/usr/bin/python
import random
from sys import stdin

MIN_RAND = 1000
MAX_RAND = 10000

p = pow(2,1279)-1
g = pow(2,111)

a = random.randint(MIN_RAND,MAX_RAND)
A = pow(g,a)%p

print 'a: '+str(a)
print 'g: '+str(g)
print 'p: '+str(p)
print 'A: '+str(A)

print 'B:'
B = int(stdin.readline())
K = pow(B,a)%p
print 'K: '+str(K)
