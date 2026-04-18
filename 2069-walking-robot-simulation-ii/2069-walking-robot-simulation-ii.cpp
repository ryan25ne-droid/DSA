class Robot {
private:
int x, y;        // position
string dir;      // direction
int width, height;  //dimensions of board
int stepsTaken;
public:
    Robot(int width, int height) {
        this->width=width-1;
        this->height=height-1;
        x=0;
        y=0;
        dir="East";
        stepsTaken=0;        
    }
    
    // void step(int num) {
    //     if(num<width){
    //         x=num;
    //         dir="East";
    //     }
    //     else if(num-width<height){
    //         x=width;
    //         y=num-width;
    //         dir="North";
    //     }
    //     else if(num-(width+height)<width){
    //         num-=(width+height);
    //         x=width-num;
    //         y=height;
    //         dir="West";
    //     }
    //     else if(num-(2*width+height)<height){
    //         num-=(2*width+height);
    //         x=0;
    //         y=height-num;
    //         dir="South";
    //     }
    //     else{
    //         num-=(2*width+2*height);
    //         step(num);
    //     }
    // }
        void step(int num) {
            int perimeter=2*width+2*height;
            stepsTaken=(stepsTaken+num)%perimeter; //updating the state of the robot to give it memory.
            int s=stepsTaken;  //used 
            if(s==0 &&num>0){
                x=0;
                y=0;
                dir="South";
            }
            else if(s<=width){
                x=s;
                y=0;
                dir="East";
            }
            else if(s-width<=height){
                x=width;
                y=s-width;
                dir="North";
            }
            else if(s-(width+height)<=width){
                s-=(width+height);
                x=width-s;
                y=height;
                dir="West";
            }
            else if(s-(2*width+height)<=height){
                s-=(2*width+height);
                x=0;
                y=height-s;
                dir="South";
            }
        //Since we have taken modulo from 2*width+2*height, we know that s would be less than the perimeter for sure.
    }
    
    vector<int> getPos() {
        return{x,y};       
    }
    
    string getDir() {
        return dir;        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */