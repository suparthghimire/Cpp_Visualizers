#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<vector>

using namespace std;



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
	initwindow(1080,720);
	printf("%d %d",getmaxx(),getmaxy());
}
float x = 100;
float y = 100;
void draw(){
		circle(100+x,100+y,100);
		x++;
		y++;
		delay(1);
}
