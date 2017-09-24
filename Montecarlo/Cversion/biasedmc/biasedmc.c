#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>


void bubbllesort(double* array,int arrsiz,int* index){
	int i,j;double temp; int tmpind;
	for(i=0;i<arrsiz;i++){
		index[i]=i;
	}
	for(i=0;i<arrsiz;i++){
		for(j=0;j<(arrsiz-i-1);j++){
			if(array[j]>array[j+1]){
				temp=array[j];
				tmpind=index[j];
				array[j] = array[j + 1];
				index[j]=index[j+1];
				array[j + 1] = temp;
				index[j+1]=tmpind;
			}
		}
	}
}




int main(){
	srand((unsigned)time(NULL));
	struct fajil{
		double *x,*y,*z,*w,*ene,*deltae,*diff,*nw;
		int *ind,*typo;
	};
	 //struct fajil *parent;
	 int ctot=3424;int ptot=6;
	 struct fajil parent[ptot];
	 int i,j;
	 double oldparen=-0.6;
	 double kbt=0.06;
	 FILE* fread;
	 fread=fopen("testdata","r");
	 char ch[60];
	 int nat;
	 int ty;
	 double xlo,xhi,ylo,yhi,zlo,zhi;
	 for(i=0;i<ptot;i++){
		 parent[i].x=(double*)malloc(ctot*sizeof(double));
		 parent[i].y=(double*)malloc(ctot*sizeof(double));
		 parent[i].z=(double*)malloc(ctot*sizeof(double));
		 parent[i].w=(double*)malloc(ctot*sizeof(double));
		 parent[i].ene=(double*)malloc(ctot*sizeof(double));
		 parent[i].deltae=(double*)malloc(ctot*sizeof(double));
		 parent[i].diff=(double*)malloc(ctot*sizeof(double));
		 parent[i].ind=(int*)malloc(ctot*sizeof(int));
		 parent[i].typo=(int*)malloc(ctot*sizeof(int));
	 }
	 int t=0;
	 while(t<ptot){
		 fscanf(fread,"%i %s",&nat,ch);
		 fscanf(fread,"%i %s %s",&ty,ch,ch);
		 fscanf(fread,"%lf %lf %s %s",&xlo,&xhi,ch,ch);
		 fscanf(fread,"%lf %lf %s %s",&ylo,&yhi,ch,ch);
		 fscanf(fread,"%lf %lf %s %s",&zlo,&zhi,ch,ch);
		 fscanf(fread,"%s",ch);
		 for(i=0;i<ctot;i++){
			// fscanf(fread,"%s",ch);
			 fscanf(fread,"%i %i %lf %lf %lf %lf",&parent[t].ind[i],&parent[t].typo[i],&parent[t].x[i],&parent[t].y[i],&parent[t].z[i],&parent[t].ene[i]);
		 }
		 t++;
	 }
	 fclose(fread);

	 
	 double sumen[ptot];
	 double sum=0;
	 for(i=0;i<ptot;i++){
		 sumen[i]=0.0;
		 for(j=0;j<ctot;j++){
			 sumen[i]=sumen[i]+parent[i].ene[j];
		 }
	 }
	 double weight[ptot];
	 for(i=0;i<ptot;i++){
			 weight[i]=exp(-(sumen[i]-sumen[0])/kbt);
			// printf("%lf\n",sumen[i]);
			 sum=sum+weight[i];
	 }
         double som=0;
double sumi[ptot];
for(i=0;i<ptot;i++){
if(i==0){
sumi[i]=som+weight[i];
}
else{
sumi[i]=som+sumi[i-1]+weight[i];
}
}
		// parent[0].diff[i]=fabs(parent[0].w[i]-parent[0].w[i]/sum);
		 //parent[0].nw[i]=parent[0].w[i]/sum;
	 //}
//	 for(i=0;i<ptot;i++){
//		 weight[i]=weight[i]/sum;
		 //printf("%lf %lf\n",weight[i],sum);
//	 }

         double ra=rand()/(double) (RAND_MAX);

	 double strdiff[ptot];
	 for(i=0;i<ptot;i++){
		 strdiff[i]=sumi[i]-ra*sumi[ptot-1];
	 }
         int inde;
         for(i=0;i<ptot;i++){
               if(strdiff[i]>0.0){
                   inde=i;
                 break;
}
}
	  for(i=0;i<ptot;i++){
		  //printf("%lf %lf\n",strdiff[i],ra);
	  }

        //int *index;
	//index=(int*)malloc(ptot*sizeof(int));
//	bubbllesort(strdiff,ptot, index);

        //printf("\n\n");	
	//parent[0].x[0]=0.1;
	for(i=0;i<ptot;i++){
		//printf("%lf\n",strdiff[i]);
	}
        //printf("\n\n");
        //printf("Str %i\n",index[0]);
        FILE* newdata;
        newdata=fopen("datanew","w+");
        fprintf(newdata,"\n");
        fprintf(newdata,"%i atoms\n",nat);
        fprintf(newdata,"2 atom types\n");
        fprintf(newdata,"%lf %lf xlo xhi\n",xlo,xhi);
        fprintf(newdata,"%lf %lf ylo yhi\n",ylo,yhi);
        fprintf(newdata,"%lf %lf zlo zhi\n",zlo,zhi);
        fprintf(newdata,"\n");
        fprintf(newdata,"Atoms\n");
        fprintf(newdata,"\n");
        for(i=0;i<ctot;i++){
             fprintf(newdata,"%i %i %lf %lf %lf\n",parent[inde].ind[i],parent[inde].typo[i],parent[inde].x[i],parent[inde].y[i],parent[inde].z[i]);
}
        fclose(newdata);
        
	for(i=0;i<ctot;i++){
//	 printf("%lf %lf %lf\n",parent[index[0]].x[i],parent[index[0]].y[i],parent[index[0]].z[i]);
	}
        // printf("\n\n");
	// printf("%lf %lf %lf\n",parent[0].x[index[0]],parent[0].y[index[0]],parent[0].z[index[0]]);
        
	return 0;
}
