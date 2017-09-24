import numpy as np
import math
import random as rnd
from random import randint

fr=open("datanew","r")
line=fr.readlines()
ntot=np.int(line[1].split()[0])


ind=[];type=[];x=[];y=[];z=[];

for i in range(10,ntot+10):
	ind.append(np.int(line[i].split()[0]))
	type.append(np.int(line[i].split()[1]))
	x.append(np.float(line[i].split()[2]))
	y.append(np.float(line[i].split()[3]))
	z.append(np.float(line[i].split()[4]))
sumc=0;sumsi=0
insi=[];inc=[]

for i in range(ntot):
	if (type[i]==1 and z[i]>172.9413243097 and z[i]<278.864006072):
		insi.append(i)
		sumsi=sumsi+1
	elif(type[i]==2):
		inc.append(i)
		sumc=sumc+1

ras=rnd.choice(insi)
rac=rnd.choice(inc)

type[ras]=2
type[rac]=1


fileswap=open("datafileswap","w")
fileswap.write("created by alam@mpie.de\n")
fileswap.write("%i atoms\n" %ntot)
fileswap.write("\n")
fileswap.write("2 atom types\n")
fileswap.write("%f %f xlo xhi\n" %(np.float(line[4].split()[0]),np.float(line[4].split()[1])))
fileswap.write("%f %f ylo yhi\n" %(np.float(line[5].split()[0]),np.float(line[5].split()[1])))
fileswap.write("%f %f zlo zhi\n" %(np.float(line[6].split()[0]),np.float(line[6].split()[1])))
fileswap.write("\n")
fileswap.write("Atoms\n")
fileswap.write("\n")
for i in range(ntot):
	fileswap.write("%i %i %f %f %f \n" %(ind[i],type[i],x[i],y[i],z[i]))
fr.close()
fileswap.close()
