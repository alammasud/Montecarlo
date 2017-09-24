import math
import numpy as np
import random as rnd

f=open("testdata","r")
lines=f.readlines()
nchild=6
totline=np.int(lines[1].split()[0])*nchild+10*nchild

ind=[];type=[];x=[];y=[];z=[];en=[]

ntot=np.int(lines[1].split()[0])

t=10
for j in range(nchild):
	for i in range(0,ntot):
		ind.append(np.int(lines[j*ntot+i+t].split()[0]))
		type.append(np.int(lines[j*ntot+i+t].split()[1]))
		x.append(np.float(lines[j*ntot+i+t].split()[2]))
		y.append(np.float(lines[j*ntot+i+t].split()[3]))
		z.append(np.float(lines[j*ntot+i+t].split()[4]))
		en.append(np.float(lines[j*ntot+i+t].split()[5]))
	t=t+10

toten=[]

for i in range(nchild):
	toten.append(0.0)
	for j in range(ntot):
		toten[i]=toten[i]+en[i*ntot+j]



rw=[]
kbt=0.06

for i in range(nchild):
	rw.append(np.exp(-(toten[i]-toten[0])/kbt))

sumw=0
sumwi=[]
for i in range(nchild):
	sumw=sumw+rw[i]
sum=0
for i in range(nchild):
	if(i==0):
		sumwi.append(sum+rw[i])
	else:
		sumwi.append(sum+sumwi[i-1]+rw[i])

ra=rnd.uniform(0,1)

diff=[]

for i in range(nchild):
	diff.append(sumwi[i]-ra*sumwi[nchild-1])

for i in range(nchild):
	for j in range(nchild-i-1):
		if(diff[j]>diff[j+1]):
			temp=diff[j]
			diff[j]=diff[j+1]
			diff[j+1]=temp

for i in range(nchild):
	if(diff[i]>0.0):
		te=i
		break

fw=open("datanew","w+");
fw.write("file created by alam@mpie.de\n")
fw.write("%i Atoms\n"%ntot)
fw.write("\n")
fw.write("2 atom types\n")
fw.write("%f %f xlo xhi\n" %(np.float(lines[4].split()[0]),np.float(lines[4].split()[1])))
fw.write("%f %f xlo xhi\n" %(np.float(lines[5].split()[0]),np.float(lines[5].split()[1])))
fw.write("%f %f xlo xhi\n" %(np.float(lines[6].split()[0]),np.float(lines[6].split()[1])))
fw.write("\n")
fw.write("Atoms\n")
fw.write("\n")

for i in range(ntot):
	fw.write("%i %i %f %f %f\n" %(ind[te*ntot+i],type[te*ntot+i],x[te*ntot+i],y[te*ntot+i],z[te*ntot+i]));
