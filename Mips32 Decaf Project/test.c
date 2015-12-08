class GreatestCommonDivisor {
    bool h = true;
    void main() {
		int i=6;
		int j=10;
		print 'a';
		for(i=0;i<10;i=i+1){
        	print i;
			if(i==5){
				continue;
			}
			print i;
        }
    }
	
    int gcd(int a, int b) {
        if (b == 0) { return(a); }
        else {return( gcd(b,a%b) ); 
        }
    }
    void printhola(){
        print 10;
    }
}
