#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<vector>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989

using namespace std;



void draw(void);
void setup(void);

float angle = 0;
vector<float> wave;

struct Data_dft{
	float re;
	float im;
	float freq;
	float amp;
	float phase;
};


vector <Data_dft> dft(vector<float> x){
	vector <Data_dft> X;
	
	struct Data_dft dft_data;
	
	int N = x.size();
	float re = 0;
	float im = 0;
	float freq = 0;
	float amp = 0;
	float phase = 0;
	for(int k=0;k<N;k++){
		for(int n=0;n<N;n++){
			float theta = (2*PI * k * n) / N;
			re += x[n] * cos(theta);
			im -= x[n] * sin(theta);
		}
		re = re/N;
		im = im/N;
		freq = k;
		amp = sqrt(re*re+im*im);
		phase = atan2(im,re);
		
		dft_data.re = re;
		dft_data.im = im;
		dft_data.freq = freq;
		dft_data.amp = amp;
		dft_data.phase = phase;
		
		X.push_back(dft_data);
	}
	return X;
}



vector <Data_dft> data_dft;

int main(){
	setup();
	
	vector <float> y;
	
	for(int i=0;i<100;i++){
		y.push_back(i);
	}

	data_dft = dft(y);
				
				
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

void draw(){
		float x = 120,y=getmaxy()/2;
		for(int i=0;i<data_dft.size();i++){
			float prevX = x;
			float prevY = y;
			
			
			float freq = data_dft[i].freq;
			float radius = data_dft[i].amp;
			float phase = data_dft[i].phase;
			
			x+= radius*cos(freq*angle + phase + PI/2);
			y+= radius*sin(freq*angle + phase + PI/2);
			
			setcolor(8);
			circle(prevX,prevY,radius);
			
			setcolor(15);
			line(prevX,prevY,x,y);
		}	
		wave.insert(wave.begin(),y);
		line(x,y,250,wave[0]);
		
//		beginshape();
		for(int i=0;i<wave.size();i++){			
			setcolor(WHITE);
        	setfillstyle(SOLID_FILL, WHITE);			
			circle(i+250,wave[i],1);
//	        floodfill(i+250,wave[i], WHITE);
		}
//		endshape();
		
		if(wave.size()>500){
			wave.pop_back();
		}
		delay(1);
		float dt = 2*PI/data_dft.size();
		angle+=dt;
}




//void draw(){
//		float x = 120,y=getmaxy()/2;
//		for(int i=0;i<6;i++){
//			float prevX = x;
//			float prevY = y;
//			int n = i*2+1;
//			float radius = 50 * (4 / (n * PI));;
//			x+= radius*cos(n*angle);
//			y+= radius*sin(n*angle);
//			setcolor(8);
//			circle(prevX,prevY,radius);
//			setcolor(15);
//			line(prevX,prevY,x,y);
//		}	
//		wave.insert(wave.begin(),y);
//		line(x,y,250,wave[0]);
//		for(int i=0;i<wave.size();i++){
//			putpixel(i+250,wave[i],15);
//		}
//		
//		if(wave.size()>500){
//			wave.pop_back();
//		}
//		delay(1);
//		angle+=0.03;
//}
