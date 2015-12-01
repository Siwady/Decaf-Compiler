class GreatestCommonDivisor {
    void main() {
        printInverse(10);
        print "--------\n";
        printNormal(5);
        print getTrue(),"\n",getFalse(),"\n";
    }
    int printInverse(int a) {
        int i;
        for(i=a-1;i>=0;i=i-1)
        {
        	print i,"\n";
        }
    }
    int printNormal(int a){
        int j=0;
        while(j<a){
        	print j,"\n";
        	j=j+1;
        }
    }
    
    bool getTrue(){
    	return true;
    }
    
    bool getFalse(){
    	return false;
    }
}
