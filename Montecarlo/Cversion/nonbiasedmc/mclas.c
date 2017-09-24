#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){

	srand((unsigned)time(NULL));
        double kbt;
	kbt=0.0603213121;
	int i;
        int ntot;char item[60];
	double *x1,*y1,*z1;
	int *inx;int *typ;
	double xlo,xhi,ylo,yhi,zlo,zhi;
	double *ptotold;
	FILE* fpha;
	fpha=fopen("datafile","r");
	fscanf(fpha, " %i %s",&ntot,item);
	x1=(double*)malloc(ntot*sizeof(double));
	y1=(double*)malloc(ntot*sizeof(double));
	z1=(double*)malloc(ntot*sizeof(double));
	inx=(int*)malloc(ntot*sizeof(int));
	typ=(int*)malloc(ntot*sizeof(int));
	ptotold=(double*)malloc(ntot*sizeof(double));
	fscanf(fpha, " %s %s %s",item,item,item);
	fscanf(fpha, " %lf %lf %s %s",&xlo,&xhi,item,item);
	fscanf(fpha, " %lf %lf %s %s",&ylo,&yhi,item,item);
	fscanf(fpha, " %lf %lf %s %s",&zlo,&zhi,item,item);
	fscanf(fpha, " %s ",item);
        
	for(i= 0;i<ntot;i++){
        	fscanf(fpha,"%d %i %lf %lf %lf %lf",&inx[i],&typ[i],&x1[i],&y1[i],&z1[i],&ptotold[i]);
	}
	fclose(fpha);
        


        //printf("%i\n",ntot);
        double* xnew;double* ynew;double* znew;
	int *index;int *type;
	char item11[60]; 
	int step;
	char item21[60]; char item22[60]; char item23[60]; char item24[60];
	char item31[60]; char item32[60]; char item33[60]; char item34[60]; char item35[60]; char item36[60];
	char item41[60]; char item42[60]; char item43[60]; char item44[60]; char item45[60]; char item46[60];char item47[60];
 
	double *ptotnew;
	FILE* fp2;
	fp2 =fopen("dump","r");
	int tt=0;
	while(tt<2){
	fscanf(fp2," %s %s",item,item11);
	fscanf(fp2," %i",&step);
	fscanf(fp2," %s %s %s %s",item21,item22,item23,item24);
	fscanf(fp2," %i",&ntot);
	fscanf(fp2," %s %s %s %s %s %s",item31,item32,item33,item34,item35,item36);
	fscanf(fp2,"%lf %lf",&xlo,&xhi);
	fscanf(fp2,"%lf %lf",&ylo,&yhi);
	fscanf(fp2,"%lf %lf",&zlo,&zhi);
	xnew=(double*)malloc(ntot*sizeof(double));
	ynew=(double*)malloc(ntot*sizeof(double));
	znew=(double*)malloc(ntot*sizeof(double));
	index=(int*)malloc(ntot*sizeof(int));
	type=(int*)malloc(ntot*sizeof(int));
	ptotnew=(double*)malloc(ntot*sizeof(double));
	fscanf(fp2," %s %s %s %s %s %s %s %s",item41,item42,item43,item44,item45,item46,item47,item47);
	for(i=0;i<ntot;i++){
		fscanf(fp2,"%i %i %lf %lf %lf %lf",&index[i],&type[i],&xnew[i],&ynew[i],&znew[i],&ptotnew[i]);
	}
        tt++;
	}
	fclose(fp2);
         //printf("%i\n",ntot);	
        FILE* haire;
	haire=fopen("dump","w+");
        int cab,sil;
        int *cpos,*spos; 
        int car,sar;
        //int randomIndex,indd;
        int kc,ks;

	double transprob;
	FILE* fpn;
	double totenold=0;
	double totennew=0;
	for(i=0;i<ntot;i++){
		totenold=totenold+ptotold[i];
		totennew=totennew+ptotnew[i];
	}
	double dE=totennew-totenold;
	// printf("%lf %lf\n",totenold,totennew);
        double *den;
        den=(double*)malloc(ntot*sizeof(double));
        

        if(dE<0.0){
                FILE* hug;
                hug=fopen("pl","r");
                FILE* huw;
                huw=fopen("pl2","w+");
		tt=0;
		while(tt<2){
			fprintf(haire,"%s %s\n",item,item11);
			fprintf(haire,"%i\n",step);
			fprintf(haire,"%s %s %s %s\n",item21,item22,item23,item24);
			fprintf(haire,"%i\n",ntot);
			fprintf(haire," %s %s %s %s %s %s\n",item31,item32,item33,item34,item35,item36);
			fprintf(haire,"%lf %lf\n",xlo,xhi);
			fprintf(haire,"%lf %lf\n",ylo,yhi);
			fprintf(haire,"%lf %lf\n",zlo,zhi);
			fprintf(haire," %s %s %s %s %s %s %s %s\n",item41,item42,item43,item44,item45,item46,item47,item47);
			for(i=0;i<ntot;i++){
				fprintf(haire,"%i %i %lf %lf %lf %lf\n ",index[i],type[i],xnew[i],ynew[i],znew[i],ptotnew[i]);
			}
			tt++;
		}
               for(i=0;i<ntot;i++){
                    fscanf(hug,"%lf",&den[i]);
                }
                for(i=0;i<ntot;i++){
                     if(type[i]==2){
                       den[i]++;
                   }
                  else{
                      den[i]=den[i]+0.0;
                    }
              }
             for(i=0;i<ntot;i++){
                    fprintf(huw,"%lf\n",den[i]);
              }
             fclose(hug);
             fclose(huw);
          }
         else{
              transprob=exp(-dE/kbt);
	      double ra=rand()/(double)(RAND_MAX);
              if( transprob>ra){
                 FILE* hug;
                 hug=fopen("pl","r");
                 FILE* huw;
                 huw=fopen("pl2","w+");

		tt=0;
		while(tt<2){
			fprintf(haire,"%s %s\n",item,item11);
			fprintf(haire,"%i\n",step);
			fprintf(haire,"%s %s %s %s\n",item21,item22,item23,item24);
			fprintf(haire,"%i\n",ntot);
			fprintf(haire," %s %s %s %s %s %s\n",item31,item32,item33,item34,item35,item36);
			fprintf(haire,"%lf %lf\n",xlo,xhi);
			fprintf(haire,"%lf %lf\n",ylo,yhi);
			fprintf(haire,"%lf %lf\n",zlo,zhi);
			fprintf(haire," %s %s %s %s %s %s %s %s\n",item41,item42,item43,item44,item45,item46,item47,item47);
			for(i=0;i<ntot;i++){
				fprintf(haire,"%i %i %lf %lf %lf %lf\n ",index[i],type[i],xnew[i],ynew[i],znew[i],ptotnew[i]);
			}
			tt++;
		}
for(i=0;i<ntot;i++){
fscanf(hug,"%lf",&den[i]);
}
for(i=0;i<ntot;i++){
if(type[i]==2){
den[i]++;
}
else{
den[i]=den[i]+0.0;
}
}
for(i=0;i<ntot;i++){
fprintf(huw,"%lf\n",den[i]);
}
fclose(hug);
fclose(huw);

              }
             else{
		tt=0;
		while(tt<2){
			fprintf(haire,"%s %s\n",item,item11);
			fprintf(haire,"%i\n",step);
			fprintf(haire,"%s %s %s %s\n",item21,item22,item23,item24);
			fprintf(haire,"%i\n",ntot);
			fprintf(haire," %s %s %s %s %s %s\n",item31,item32,item33,item34,item35,item36);
			fprintf(haire,"%lf %lf\n",xlo,xhi);
			fprintf(haire,"%lf %lf\n",ylo,yhi);
			fprintf(haire,"%lf %lf\n",zlo,zhi);
			fprintf(haire,"%s %s %s %s %s %s %s %s\n",item41,item42,item43,item44,item45,item46,item47,item47);
			for(i=0;i<ntot;i++){
				fprintf(haire,"%i %i %lf %lf %lf %lf\n ",inx[i],typ[i],x1[i],y1[i],z1[i],ptotold[i]);
			}
			tt++;
		}

		}

		
	}
        fclose(haire);


	return 0;
}


