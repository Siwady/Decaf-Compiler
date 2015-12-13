.data

Str0: .asciiz "--------\n"
Str1: .asciiz "\n"

.text

#class GreatestCommonDivisor{
    jal main 
    j EndClass

    # main(){
    main:
        sw $ra, 0($sp)
        addi $sp, $sp, -4
            #10
                li $t0, 10
                add $a0, $zero, $t0
                jal printInverse

        #print "--------\n";
            #"--------\n"
                la $t0, Str0
                move $a0, $t0
                li $v0, 4
                syscall

            #5
                li $t0, 5
                add $a0, $zero, $t0
                jal printNormal

        #print getTrue(),"\n",getFalse(),"\n";
            #getTrue()
                jal getTrue
                add $t0, $zero, $v0
                move $a0, $t0
                li $v0, 1
                syscall
            #"\n"
                la $t0, Str1
                move $a0, $t0
                li $v0, 4
                syscall
            #getFalse()
                jal getFalse
                add $t0, $zero, $v0
                move $a0, $t0
                li $v0, 1
                syscall
            #"\n"
                la $t0, Str1
                move $a0, $t0
                li $v0, 4
                syscall

    Endmain:
        addi $sp, $sp, 4
        lw $ra, 0($sp)
        jr $ra
    #}

    #int printInverse(int a){
    printInverse:
        sw $ra, 0($sp)
        addi $sp, $sp, -12
        sw $a0, 4($sp)
        # int i;

        #for(i = a - 1; i >= 0; i = i - 1){
            # i=a - 1;
                lw $s0, 4($sp)
                li $t0, 1
                sub $t0, $s0, $t0
                sw $t0, 8($sp)

            Label0:
                lw $s0, 8($sp)
                li $t0, 0
                slt $t0, $s0, $t0
                nor $t0, $t0, $t0
                addi $t0, $t0, 2
                beq $t0, $zero, Label1
                #print i,"\n";
                    #i
                        lw $s0, 8($sp)
                        move $a0, $s0
                        li $v0, 1
                        syscall
                    #"\n"
                        la $t0, Str1
                        move $a0, $t0
                        li $v0, 4
                        syscall

                # i=i - 1;
                    lw $s0, 8($sp)
                    li $t0, 1
                    sub $t0, $s0, $t0
                    sw $t0, 8($sp)

                j Label0
        #}
        Label1: 

    EndprintInverse:
        addi $sp, $sp, 12
        lw $ra, 0($sp)
        jr $ra
    #}

    #int printNormal(int a){
    printNormal:
        sw $ra, 0($sp)
        addi $sp, $sp, -12
        sw $a0, 4($sp)
        # int j=0;
            li $t0, 0
            sw $t0, 8($sp)

        #while(j < a){
            Label2:
                lw $s0, 8($sp)
                lw $s1, 4($sp)
                slt $t0, $s0, $s1
                beq $t0, $zero, Label3
                #print j,"\n";
                    #j
                        lw $s0, 8($sp)
                        move $a0, $s0
                        li $v0, 1
                        syscall
                    #"\n"
                        la $t0, Str1
                        move $a0, $t0
                        li $v0, 4
                        syscall
                # j=j + 1;
                    lw $s0, 8($sp)
                    li $t0, 1
                    add $t0, $s0, $t0
                    sw $t0, 8($sp)

                j Label2
        #}
        Label3: 

    EndprintNormal:
        addi $sp, $sp, 12
        lw $ra, 0($sp)
        jr $ra
    #}

    #bool getTrue(){
    getTrue:
        sw $ra, 0($sp)
        addi $sp, $sp, -4
        #return True;
            li $t0, 1
            add $v0, $zero, $t0
            j EndgetTrue

    EndgetTrue:
        addi $sp, $sp, 4
        lw $ra, 0($sp)
        jr $ra
    #}

    #bool getFalse(){
    getFalse:
        sw $ra, 0($sp)
        addi $sp, $sp, -4
        #return False;
            li $t1, 0
            add $v0, $zero, $t1
            j EndgetFalse

    EndgetFalse:
        addi $sp, $sp, 4
        lw $ra, 0($sp)
        jr $ra
    #}

EndClass:
    li $v0, 10
    syscall
#}

