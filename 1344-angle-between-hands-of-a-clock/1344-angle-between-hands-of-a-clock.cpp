class Solution {
public:
    double angleClock(int hour1, int minutes1) {
        double angle1;
        float hour = hour1;
        float minutes = minutes1;
        angle1=(hour*30)+(minutes/2);
        double angle2=(minutes*6);
        if(angle1>360) angle1=angle1-360;
        if(angle1-angle2==360) return 0;
        float p;
        if(angle1-angle2>angle2-angle1){
            p=angle1-angle2;
        }else{
            p=angle2-angle1;
        }
        if(p>180){
            return 180-(p-180);
        }
        return p;
    }
};