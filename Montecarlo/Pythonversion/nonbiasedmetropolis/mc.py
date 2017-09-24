import random as rnd
import numpy as np
import math
from random import randint

f=open("dumpold","r")
lines = f.readlines()
ind=[];type=[];x=[];y=[];z=[];ene=[]
ntot=np.int(lines[3])
#print ntot
for i in range(ntot+18,2*ntot+18):
	ind.append(np.int(lines[i].split()[0]))
	type.append(np.int(lines[i].split()[1]))
	x.append(np.float(lines[i].split()[2]))
	y.append(np.float(lines[i].split()[3]))
	z.append(np.float(lines[i].split()[4]))
	ene.append(np.float(lines[i].split()[5]))
sum=0
for i in range(ntot):
	sum=sum+ene[i]
#print sum
fnew=open("dump","r")
line=fnew.readlines()
indnew=[];typenew=[];xnew=[];ynew=[];znew=[];ennew=[]
for i in range(ntot+18,2*ntot+18):
	indnew.append(np.int(line[i].split()[0]))
	typenew.append(np.int(line[i].split()[1]))
	xnew.append(np.float(line[i].split()[2]))
	ynew.append(np.float(line[i].split()[3]))
	znew.append(np.float(line[i].split()[4]))
	ennew.append(np.float(line[i].split()[5]))
sumnew=0
for i in range(ntot):
	sumnew=sumnew+ennew[i]
#print sumnew
dE=sumnew-sum
rannum=rnd.uniform(0,1)
#print rannum
kbt=0.0603213121
fw=open("dump","w+")
if(dE<0.0):
	for i in range(len(line)):
		fw.write(line[i])
else:
	transprob=np.exp(-dE/kbt)
	if(transprob>rannum):
		for i in range(len(line)):
			fw.write(line[i])
	else:
		for i in range(len(lines)):
			fw.write(lines[i])

f.close()
fnew.close()
fw.close()
