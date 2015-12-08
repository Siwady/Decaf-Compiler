.data
newLine: .asciiz "\n"
h: .word 0
i: .word 0
j: .word 0
a: .word 0
b: .word 0
Ch0: .byte 'a'
.text
#class GreatestCommonDivisor{
    # bool h=True;
        li $t0, 1
        la $t1, h
        sw $t0, 0($t1)
    jal main 
    j EndClass

    #void main(){
    main:
        # int i=6;
            li $t0, 6
            la $t1, i
            sw $t0, 0($t1)
        # int j=10;
            li $t0, 10
            la $t1, j
            sw $t0, 0($t1)
        #print 'a';
lb $t0, Ch0

            move $a0, $t0
            li $v0, 11
            syscall
            la $a0, newLine
            li $v0, 4
            syscall

        #for(i < 10){
        # i=0;
            li $t0, 0
            la $t2, i
            sw $t0, 0($t2)

            Label0:
                la $t0, i
                lw $t0, 0($t0)

                li $t1, 10
                slt $t0, $t0, $t1
                beq $t0, $zero, Label1
                #print i;
                    la $t0, i
                    lw $t0, 0($t0)

                    move $a0, $t0
                    li $v0, 1
                    syscall
                    la $a0, newLine
                    li $v0, 4
                    syscall
                #if(i == 5){
                    la $t0, i
                    lw $t0, 0($t0)

                    li $t2, 5
                    beq $t0, $t2, Label2
                    li $t0, 0
                    j Label3
                    Label2:
                    li $t0, 1
                    Label3:

                    add $t2, $zero, $zero
                    beq $t0, $t2, Label4
                # i=i + 1;
                    la $t0, i
                    lw $t0, 0($t0)

                    li $t2, 1
                    add $t0, $t0, $t2
                    la $t2, i
                    sw $t0, 0($t2)

                    # continue;
                        j Label0

                    j Label5
                #}else{
                    Label4: 
                #}
                Label5: 
                #print i;
                    la $t0, i
                    lw $t0, 0($t0)

                    move $a0, $t0
                    li $v0, 1
                    syscall
                    la $a0, newLine
                    li $v0, 4
                    syscall
                # i=i + 1;
                    la $t0, i
                    lw $t0, 0($t0)

                    li $t2, 1
                    add $t0, $t0, $t2
                    la $t2, i
                    sw $t0, 0($t2)
                j Label0
        #}
        Label1: 

        jr $ra
    #}

    #int gcd(){
    gcd:
        #if(b == 0){
            la $t0, b
            lw $t0, 0($t0)

            li $t1, 0
            beq $t0, $t1, Label6
            li $t0, 0
            j Label7
            Label6:
            li $t0, 1
            Label7:

            add $t1, $zero, $zero
            beq $t0, $t1, Label8

            j Label9
        #}else{
            Label8: 
        #}
        Label9: 

        jr $ra
    #}

    #void printhola(){
    printhola:
        #print 10;
            li $t0, 10
            move $a0, $t0
            li $v0, 1
            syscall
            la $a0, newLine
            li $v0, 4
            syscall

        jr $ra
    #}
#}
EndClass:
# Exit
li $v0, 10
syscall

