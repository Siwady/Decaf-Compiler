.data
h: .word 0
Str1: .asciiz "\n"
Str0: .asciiz "z="
.text

#class GreatestCommonDivisor{
    # int h=366;
        li $t0, 366
        la $t1, h
        sw $t0, 0($t1)
    jal main 
    j EndClass

    # main(){
    main:
        sw $ra, 0($sp)
        addi $sp, $sp, -8
        # int z;

        # z=gcd(x,60);
            #x

                add $a0, $zero, 
            #60
                li $t1, 60
                add $a1, $zero, $t1
            jal gcd
            add $t0, $zero, $v0
            sw $t0, 4($sp)

        #print "z=",z,"\n";
            #"z="
                la $t0, Str0
                move $a0, $t0
                li $v0, 4
                syscall
            #z
                lw $s0, 4($sp)
                move $a0, $s0
                li $v0, 1
                syscall
            #"\n"
                la $t0, Str1
                move $a0, $t0
                li $v0, 4
                syscall

    Endmain:
        addi $sp, $sp, 8
        lw $ra, 0($sp)
        jr $ra
    #}

    #int gcd(int a,int b){
    gcd:
        sw $ra, 0($sp)
        addi $sp, $sp, -12
        sw $a0, 4($sp)
        sw $a1, 8($sp)
        #if(b == 0){
            lw $s0, 8($sp)
            li $t0, 0
            beq $s0, $t0, Label0
            li $t0, 0
            j Label1
            Label0:
                li $t0, 1
            Label1:

            add $t2, $zero, $zero
            beq $t0, $t2, Label2
            #return a;
                lw $s0, 4($sp)
                add $v0, $zero, $s0
                j Endgcd

            j Label3
        #}else{
            Label2: 
            #return gcd(b,a % b);
                #b
                    lw $s1, 8($sp)
                    add $a0, $zero, $s1
                #a % b
                    lw $s1, 4($sp)
                    lw $s2, 8($sp)
                    div $s1, $s2
                    mfhi $t3
                    add $a1, $zero, $t3
                jal gcd
                add $t0, $zero, $v0
                add $v0, $zero, $t0
                j Endgcd

        #}
        Label3: 

    Endgcd:
        addi $sp, $sp, 12
        lw $ra, 0($sp)
        jr $ra
    #}

EndClass:
    li $v0, 10
    syscall
#}

