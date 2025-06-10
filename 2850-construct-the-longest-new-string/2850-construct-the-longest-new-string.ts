function longestString(x: number, y: number, z: number): number {
    if(y>x)
        {
            return 2*(x+ (x+1) +z);
        }
        else if(x>y)
        {
            return 2*(y+ (y+1)+z);
        }
        return 2*(y+x+z);
    
};