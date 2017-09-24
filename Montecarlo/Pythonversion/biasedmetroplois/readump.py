import numpy as np
import math
import random as rnd
from random import randint

fr=open("dump","r")
line=fr.readlines()
ntot=np.int(line[3])


ind=[];type=[];x=[];y=[];z=[];en=[]


for i in range(ntot+18,2*ntot+18):
	ind.append(np.int(line[i].split()[0]))
	type.append(np.int(line[i].split()[1]))
	x.append(np.float(line[i].split()[2]))
	y.append(np.float(line[i].split()[3]))
	z.append(np.float(line[i].split()[4]))
	en.append(np.float(line[i].split()[5]))


fileswap=open("testdata","a+")
fileswap.write("created by alam@mpie.de\n")
fileswap.write("%i atoms\n" %ntot)
fileswap.write("\n")
fileswap.write("2 atom types\n")
fileswap.write("%f %f xlo xhi\n" %(np.float(line[5].split()[0]),np.float(line[5].split()[1])))
fileswap.write("%f %f ylo yhi\n" %(np.float(line[6].split()[0]),np.float(line[6].split()[1])))
fileswap.write("%f %f zlo zhi\n" %(np.float(line[7].split()[0]),np.float(line[7].split()[1])))
fileswap.write("\n")
fileswap.write("Atoms\n")
fileswap.write("\n")
for i in range(ntot):
	fileswap.write("%i %i %f %f %f %f \n" %(ind[i],type[i],x[i],y[i],z[i],en[i]))

fr.close()
fileswap.close()
