#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<vector>
#include<stack>
#include<algorithm>
#include <stdexcept>    


#define n 40
#define SI 40
#define HEAD_COLOR 10
#define WALL_COLOR 7


using namespace std;



void draw(void);
void setup(void);
class Cell;

vector<Cell> cellPool;

class Cell{
	int i,j;
	
	int w = 15;
	int translate = 100;
	
	bool walls[4] = {true,true,true,true};
	
	bool visited = false;
	
	pair<int,int> calcCenter(int i,int j){
		int x = ((i * w) + (i * w + w))/2;
		int y = ((j * w) + (j * w + w))/2;	
		return make_pair(x,y);
	}
	
	int random(int low,int big){
		return rand()%((big-low)+1)+low;
	}
	
	public: 
	void fillcircle(int x,int y, int color){
		setcolor(color);
		setfillstyle(SOLID_FILL,color);
		circle(x,y,5);
		floodfill(x,y,color);
	}
	
	pair<int,int> cellCenter;

	Cell(){}
	Cell(int i,int j){
		this->i = i;
		this->j = j;
		cellCenter = calcCenter(i,j);
	}
	void drawCell(){
		
		int x = i*w;
		int y = j*w;
		
		setcolor(WALL_COLOR);
		if(walls[0]) line(x, y, x + w, y);
		if(walls[1]) line(x + w, y, x + w, y + w);
		if(walls[2]) line(x + w, y + w, x, y + w);
		if(walls[3]) line(x, y + w, x, y);
		

	}
	void setWallTop(bool top){
		walls[0] = top;
	}
	
	void setWallRight(bool right){
		walls[1] = right;
	}
	void setWallBottom(bool bottom){
		walls[2] = bottom;
	}
	void setWallLeft(bool left){
		walls[3] = left;
	}
	
	bool checkVisited(){
		return visited;
	}
	
	int index(int i,int j){
		if(i<0 || j < 0 || i > n - 1 || j > n - 1) return -1;
		else return i * n + j;
	}
	
	Cell findNeighbour(){
		vector<Cell> neighbours;
		
		int topIndex = index(i - 1, j);
		if(topIndex!=-1){
			try{
				if(!cellPool[topIndex].visited){
					neighbours.push_back(cellPool[topIndex]);	
				}
			}catch (const out_of_range& oor) {}
		}
		
		int rightIndex = index(i, j + 1);
		if(rightIndex!=-1){
			try{	
				if(!cellPool[rightIndex].visited){
					neighbours.push_back(cellPool[rightIndex]);			
				}
			}catch(const out_of_range& oor){}
		}
		
		int bottomIndex = index(i + 1, j);
		if(bottomIndex != -1){
			try{
				if(!cellPool[bottomIndex].visited){
					neighbours.push_back(cellPool[bottomIndex]);		
				}
			}catch(const out_of_range& oor){}
		}
		
		int leftIndex = index(i, j - 1);
		if(leftIndex != -1){
			try{
				if(!cellPool[leftIndex].visited){
					neighbours.push_back(cellPool[leftIndex]);			
				}
			
			}catch(const out_of_range& oor){}
		}			
		
		if(neighbours.size()>0){
			int selectedNeighbour = random(0,neighbours.size()-1);
			return neighbours[selectedNeighbour];	
		}else{
			throw -1;
		}
		
	}
	
	bool operator == (Cell c){
		return c.i == i && c.j == j;
	}	
	
	void markVisited(){
		visited = true;
	}
	
};


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


stack<Cell> exploringList;


int visitedCount = 0;

void setup(){
	initwindow(1080,720);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			Cell c = Cell(i,j);
			cellPool.push_back(c);	
		}
	}
	exploringList.push(cellPool[SI]);
	cellPool[SI].markVisited();
	visitedCount = 1;
}

int cellIndex(Cell cell){
	for(int i=0;i<cellPool.size();i++){
		if(cellPool[i] == cell){
			return i;
		}
	}
	return -1;
}

void removeWalls(int prev,int current){
	if(prev + n == current ){
		// remove right wall of previous cell
		cellPool[prev].setWallRight(false);
		//remove left wall of current cell 			
		cellPool[current].setWallLeft(false);
	}
	else if(prev - n == current){
		//remove left wall of previous cell
		cellPool[prev].setWallLeft(false);
		//remove right wall of current cell			
		cellPool[current].setWallRight(false);
	}
	else if(prev + 1 == current){
		//remove  bottom wall of previous cell
		cellPool[prev].setWallBottom(false);
		//remove top wall of current cell
		cellPool[current].setWallTop(false);
	}
	else if(prev - 1 == current){
		// remove top wall of previous cell
		cellPool[prev].setWallTop(false);
		//remove bottom wall of currentCell			
		cellPool[current].setWallBottom(false);
	}
}


int _count = SI;
void generateMaze(){
	bool status = false;
	try{
		Cell nextNeighbour = cellPool[_count].findNeighbour();
		int neighbourIndex = cellIndex(nextNeighbour);
		
		if(neighbourIndex != -1){
			int prevCount = _count;
			
			cellPool[neighbourIndex].markVisited();
			
			_count = neighbourIndex;
						
			exploringList.push(cellPool[_count]);
			
			removeWalls(prevCount,_count);	
			
			visitedCount++;
		}
	}catch(int err){
		if(!exploringList.empty()){
			Cell currentCell = exploringList.top();
			exploringList.pop();
			int currentCellIndex = cellIndex(currentCell);
			_count = currentCellIndex;
			status = true;
		}
	}
}
void draw(){
		for(int i=0;i<cellPool.size();i++){
			cellPool[i].drawCell();
		}
		if(visitedCount<n*n) {
			generateMaze();
			exploringList.top().fillcircle(exploringList.top().cellCenter.first,exploringList.top().cellCenter.second,HEAD_COLOR);
		}			
		delay(5);
}
