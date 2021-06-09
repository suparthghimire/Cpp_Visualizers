#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>


using namespace std;


char board[3][3] = {
	{'X','X','O'},
	{'O','O','X'},
	{'X','O','X'},
};
	
char p1 = 'X';
char p2 = 'O';


void draw(void);
void setup(void);

int main(){
	setup();
	int page = 0;
	while(true){
		setvisualpage(page);
		setactivepage(1-page);
		cleardevice();
		draw();
		page = 1-page;
	}
	getch();
}


void setup(){
	initwindow(600,600);
	printf("%d %d",getmaxx(),getmaxy());
}


void drawOutline(int x, int y){
	line(x, 0, x,getmaxy());
	line(2*x, 0, 2*x,getmaxy());
	line(0,y,getmaxx(),y);
	line(0,2*y,getmaxx(),2*y);
}

	
void draw(){
	
	int w = getmaxx()/3; 
	int h = getmaxy()/3;
	
	drawOutline(w,h);
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int x = w * j + w/2;
			int y = h * i + h/2;
			char boardPos = board[i][j];
			if(boardPos == p2){
				circle(x,y,w/4);
			}else{
				int xr = w/4;
				line(x - xr, y - xr, x+xr,y+xr);
				line(x + xr, y - xr, x-xr,y+xr);
				
			}
			
		}
	}	
			
	delay(1);
}







