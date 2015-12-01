class GreatestCommonDivisor {
    int h = 366;
    int i = 60;
    void main() {
        int x, y, z,w;
        x = h;
        y = i;
        z = gcd(x, y);
        w= gcd(12, 20);
        print "z=",z,"\nw=",w,"\n";
        
    }
    
    // Función que calcula el máximo común divisor
    int gcd(int a, int b) {
        if (b == 0) { return(a); }
        else {return( gcd(b,a%b) ); 
        }
    }
    void printhola(){
        print "hola.\n";
    }
}
