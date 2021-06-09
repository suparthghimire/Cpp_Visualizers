#include<stdio.h>
#include<graphics.h>0

void swap(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void ballRotate(){
	circle(400,372,50);
	line(350,372,450,372);
	line(400,322,400,422);
	int i;
	
	int axs = 350,ays = 372;
	int axd = 450,ayd = 372;
	
	int bxs = 400,bys = 322;
	int bxd = 400,byd = 422;
	
	
	for(i=0;i<getmaxx()/2;i++){
		line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
		circle(400+i,372,50);
		line(axs+i,ays,axd+i,ayd);
		line(bxs+i,bys,bxd+i,byd);
		
		
		swap(&axs,&bxs);
		swap(&axd,&bxd);
		swap(&ays,&bys);
		swap(&ayd,&byd);
		
		
		
		delay(1);
		cleardevice();
	}

}

int main(){
	initwindow(1920,1080);
	ballRotate();
	getch();
}

