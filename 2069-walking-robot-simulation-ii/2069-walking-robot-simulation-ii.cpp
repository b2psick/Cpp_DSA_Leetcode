class Robot {
public:
    int x=0;
    int y=0;
    int width=0;
    int height=0;
    int a=0;
    Robot(int width, int height) {
        this->width=width;
        this->height=height;
    }
    
    void step(int num) {
        for(int i=0;i<num%(2*(width-1)+2*(height-1));i++){
            if(a==0){
                x++;
                if(x>=width){
                    x--;
                    i--;
                    a++;
                }
            }else if(a==1){
                y++;
                if(y>=height){
                    y--;
                    i--;
                    a++;
                }
            }else if(a==2){
                x--;
                if(x<0){
                    x++;
                    i--;
                    a++;
                }
            }else{
                y--;
                if(y<0){
                    y++;
                    i--;
                    a++;
                }
            }
            if(a==4) a=0;
        }
        if(num%(2*(width-1)+2*(height-1))==0){
            if(x==0&&y==0) a=3;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(a==0){
            return "East";
        }else if(a==1){
            return "North";
        }else if(a==2){
            return "West";
        }else{
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */