#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.14159265 

void menu(void);


void sinewave(){
	int angle=0;
	float y;
	int i;
	
	cleardevice();
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
			for(i=0;i<1440;i++){
				if(i<720){
					y=50*sin((angle*PI)/180);
		 			y=getmaxy()/2-y;
		 			putpixel(i-6,y,GREEN);
		 			angle++;	
//		 			delay(0);
			}
			else{
				y=50*sin((i*PI)/180);
	 			y=getmaxy()/2-y;
	 			putpixel(i-6,y,GREEN);
	 			angle++;
//	 			delay(0);
			}
		}
				
	menu();
}
		 
void cosinewave(){
	int angle=0;
	float y;
	int i;
	
	cleardevice();
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	for(i=0;i<1440;i++){
		if(i<720){
			y=50*cos((angle*PI)/180);
	 		y=getmaxy()/2-y;
	 		putpixel(i-6,y,GREEN);
	 		angle++;	
	 		delay(1);
		}
		else{
			y=50*cos((i*PI)/180);
 			y=getmaxy()/2-y;
 			putpixel(i-6,y,GREEN);
 			angle++;
 			delay(1);
		}
	}
	menu();
}
void tangentwave(){
	int angle=0;
	float y;
	int i;
	
	cleardevice();
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	for(i=0;i<1440;i++){
		if(i<720){
			y=50*tan((angle*PI)/180);
	 		y=getmaxy()/2-y;
	 		putpixel(i-6,y,GREEN);
	 		angle++;	
	 		delay(1);
		}
		else{
			y=50*tan((i*PI)/180);
 			y=getmaxy()/2-y;
 			putpixel(i-6,y,GREEN);
 			angle++;
 			delay(1);
		}
	}
	menu();

}
	
void cotecwave(){
	int angle=0;
	float y;
	int i;
	
	cleardevice();
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	for(i=0;i<1440;i++){
		if(i<720){
			y=50*1/tan((angle*PI)/180);
	 		y=getmaxy()/2-y;
	 		putpixel(i-6,y,GREEN);
	 		angle++;	
	 		delay(1);
		}
		else{
			y=50*1/tan((i*PI)/180);
 			y=getmaxy()/2-y;
 			putpixel(i-6,y,GREEN);
 			angle++;
 			delay(1);
		}
	}
	menu();
}
	
void cosecantwave(){
	int angle=0;
	float y;
	int i;
	
	cleardevice();
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
 	for(i=0;i<1440;i++){
		if(i<720){
			y=50*1/sin((angle*PI)/180);
	 		y=getmaxy()/2-y;
	 		putpixel(i-6,y,GREEN);
	 		angle++;	
	 		delay(1);
		}
		else{
			y=50*1/sin((i*PI)/180);
 			y=getmaxy()/2-y;
 			putpixel(i-6,y,GREEN);
 			angle++;
 			delay(1);
		}
	}
	menu();

}
void secantwave(){
	int angle=0;
	float y;
	int i;
	cleardevice();
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
 	for(i=0;i<1440;i++){
		if(i<720){
			y=50*1/cos((angle*PI)/180);
	 		y=getmaxy()/2-y;
	 		putpixel(i-6,y,GREEN);
	 		angle++;	
	 		delay(1);
		}
		else{
			y=50*1/cos((i*PI)/180);
 			y=getmaxy()/2-y;
 			putpixel(i-6,y,GREEN);
 			angle++;
 			delay(1);
		}
	}
	menu();

}

void menu(){
	system("cls");
	printf("1. Sine Wave\n");
	printf("2. Cosine Wave\n");
	printf("3. Tangent Wave\n");
	printf("4. Cosecant Wave:\n");
	printf("5. Secant Wave\n");
	printf("6. Cotec Wave\n");
	printf("7. Exit\n");
	printf("Enter Choice:\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Drawing Sine Wave!!!!");
			sinewave();
			getch();
			break;
		case 2:
			printf("Drawing Cosine Wave!!!!");
			cosinewave();
			getch();
			break;
		case 3:
			printf("Drawing Tangent Wave!!!!");
			tangentwave();
			getch();
			break;
		case 4:
			printf("Drawing Cosecant Wave!!!!");
			cosecantwave();
			getch();
			break;
		case 5:
			printf("Drawing Secant Wave!!!!");
			secantwave();
			getch();
			break;
		case 6:
			printf("Drawing Cotec Wave!!!!");
			cotecwave();
			getch();
			break;
		case 7:
			exit(0);
			printf("Exiting...");
			
		default:
			printf("Not Accepted! Re Enter: ");
			delay(2000);
			menu();
		
	}
}
int main(){
	initwindow(1440,1080);
	printf("%d %d",getmaxx(),getmaxy());
	
//	printf("Drawing SIne Wave!!!!");
//	sinewave();
//	printf("\nDrawing Cosine Wave!!!!");
//	cosinewave();
//	printf("\nDrawing Tangent Wave!!!!");
//	tangentwave();
//	printf("\nDrawing Cotec Wave!!!!");
//	cotecwave();
//	printf("\nDrawing Cosecant Wave!!!!");
//	cosecantwave();
//	printf("\nDrawing Secant Wave!!!!");
//	secantwave();
//	printf("\nAll Waves Drawn!!!!!");
	menu();
	getch();
}
