//Time: O(n)
//Space: O(1)
class Solution {
public:
    bool isRobotBounded(string instructions) {
        //Movement is x,y when direction is up,left,down,right
        //0: up, 1:left, 2:down, 3:right
        int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
        //Direction currently facing
        int face=0;
        int x=0;
        int y=0;
        for(int i=0;i<instructions.length();i++){
            if(instructions[i]=='L'){
                face=(face+1)%4;
                //The order in which directions are defined is such that left of it is at +1 index
            }
            if(instructions[i]=='R'){
                face=(face+3)%4;
                //The order in which directions are defined is such that left of it is at +3 index
            }
            if(instructions[i]=='G'){
                x+=dir[face][0];
                y+=dir[face][1];
            }
        }
        //If loop is complete and returned back to (0,0) or if direction is not north because then after some iterations it will complete the loop
        return ((x==0 && y==0) || face!=0);
    }
};