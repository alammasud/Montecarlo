#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int main(){
	srand((unsigned)time(NULL));
	int i;
	double* x;double* y;double* z;
	double xhi,xlow,yhi,ylow,zhi,zlow;
	int *index;int *type;
	char item[60];char item11[60]; 
	int step;
	char item21[60]; char item22[60]; char item23[60]; char item24[60];
	int ntot;
	char item31[60]; char item32[60]; char item33[60]; char item34[60]; char item35[60]; char item36[60];
	 char item41[60]; char item42[60]; char item43[60]; char item44[60]; char item45[60]; char item46[60];char item47[60];char item48[60];char item49[60];char item410[60];
	char item51[60]; char item52[60]; char item53[60];
	 double* fx;double* fy;double* fz;
	 double *ptotold;
	FILE* fp;
	fp =fopen("dump","r");
	int tt=0;
	while(tt<2){
	fscanf(fp," %s %s",item,item11);
	fscanf(fp," %i",&step);
	fscanf(fp," %s %s %s %s",item21,item22,item23,item24);
	fscanf(fp," %i",&ntot);
	fscanf(fp," %s %s %s %s %s %s",item31,item32,item33,item34,item35,item36);
	fscanf(fp,"%lf %lf",&xlow,&xhi);
	fscanf(fp,"%lf %lf",&ylow,&yhi);
	fscanf(fp,"%lf %lf",&zlow,&zhi);
	x=(double*)malloc(ntot*sizeof(double));
	y=(double*)malloc(ntot*sizeof(double));
	z=(double*)malloc(ntot*sizeof(double));
	fx=(double*)malloc(ntot*sizeof(double));
        fy=(double*)malloc(ntot*sizeof(double));
	fz=(double*)malloc(ntot*sizeof(double));
	index=(int*)malloc(ntot*sizeof(double));
	type=(int*)malloc(ntot*sizeof(double));
	ptotold=(double*)malloc(ntot*sizeof(double));
	fscanf(fp," %s %s %s %s %s %s %s %s",item41,item42,item43,item44,item45,item46,item47,item48);
	for(i=0;i<ntot;i++){
		fscanf(fp,"%i %i %lf %lf %lf %lf ",&index[i],&type[i],&x[i],&y[i],&z[i],&ptotold[i]);
	}
	tt++;
	}
	fclose(fp);

	FILE* fp2;
	fp2=fopen("datafile","w+");

	fprintf(fp2, " \n");
	fprintf(fp2, " %i atoms \n",ntot);
	fprintf(fp2, " \n");
	fprintf(fp2, " 2 atom types\n");
	fprintf(fp2, " %20.20f %20.20f xlo xhi\n",xlow,xhi);
	fprintf(fp2, " %20.20f %20.20f ylo yhi\n",ylow,yhi);
	fprintf(fp2, " %20.20f %20.20f zlo zhi\n",zlow,zhi);
	fprintf(fp2, " \n");
	fprintf(fp2, " Atoms \n");
	fprintf(fp2, " \n");

	for(i= 0;i<ntot;i++){
		fprintf(fp2,"%i\t%i\t%20.20lf\t%20.20lf\t%20.20lf %lf\n",index[i],type[i],x[i],y[i],z[i],ptotold[i]);
	}
	fclose(fp2);
	FILE* haire;
	haire=fopen("datafileswap","w+");
	int cab,sil;
	int *cpos,*spos;
	int car,sar;
	int kc,ks;
	cab=0;
	sil=0;
	for(i=0;i<ntot;i++){
		if(type[i]==2){
			cab++;
		}
		else{
			sil++;
		}
	}
	cpos=(int*)malloc(cab*sizeof(int));
	spos=(int*)malloc(sil*sizeof(int));
	kc=0; ks=0;
	for(i=0;i<ntot;i++){
		if(type[i]==2){
			cpos[kc]=i;
			 kc++;
		}
		else if(type[i]==1&&z[i]>172.9413243097 &&z[i]<278.864006072){
			spos[ks]=i;
			ks++;
		}
	}
	int randomIndex = rand() % kc;
	car=cpos[randomIndex];
	int indd=rand() % ks;
	sar=spos[indd];
	type[car]=1;type[sar]=2;
        //printf("%i %i\n",car,sar);	
	fprintf(haire, " \n");
	fprintf(haire, " %i atoms \n",ntot);
	fprintf(haire, " \n");
	fprintf(haire, " 2 atom types\n");
	fprintf(haire, " %20.20f %20.20f xlo xhi\n",xlow,xhi);
	fprintf(haire, " %20.20f %20.20f ylo yhi\n",ylow,yhi);
	fprintf(haire, " %20.20f %20.20f zlo zhi\n",zlow,zhi);
	fprintf(haire, " \n");
	fprintf(haire, " Atoms \n");
	fprintf(haire, " \n");
	for(i= 0;i<ntot;i++){
		fprintf(haire,"\t%d\t%i\t%20.20f\t%20.20f\t%20.20f\n",index[i],type[i],x[i],y[i],z[i]);
	}
	fclose(haire);



	return 0;
}
