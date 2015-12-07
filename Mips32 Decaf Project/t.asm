.data
newLine: .asciiz "\n"
j: .word 0,0,0,0,0,0,0,0,0,0
b: .word 0
i: .word 0
.text
#class GreatestCommonDivisor{
    # int j;
    # bool b=True;
        li $t0, 1
        la $t1, b
        sw $t0, 0($t1)

    #void main(){
        # int i;
        # j[0]=10;
            li $t0, 10
        li $t4, 0
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        # j[1]=20;
            li $t0, 20
        li $t4, 1
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        # j[2]=30;
            li $t0, 30
        li $t4, 2
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        # j[3]=40;
            li $t0, 40
        li $t4, 3
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        # j[4]=50;
            li $t0, 50
        li $t4, 4
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        # j[5]=60;
            li $t0, 60
        li $t4, 5
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        # j[6]=70;
            li $t0, 70
        li $t4, 6
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        # j[7]=80;
            li $t0, 80
        li $t4, 7
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        # j[8]=90;
            li $t0, 90
        li $t4, 8
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        # j[9]=100;
            li $t0, 100
        li $t4, 9
        la $t2, j
        add $t4, $t4, $t4
        add $t4, $t4, $t4
        add $t3, $t4, $t2
            sw $t0, 0($t3)

        #while(i < 10){
            Label0:
                la $t0, i
                lw $t0, 0($t0)

                li $t1, 10
                slt $t0, $t0, $t1
                beq $t0, $zero, Label1
                #print j[i];
                    la $t3, j
                    la $t5, i
                    lw $t5, 0($t5)
                    add $t2, $t5, $t5
                    add $t2, $t2, $t2
                    add $t4, $t2, $t3
                    lw $t6, 0($t4)

                    move $a0, $t6
                    li $v0, 1
                    syscall
                    la $a0, newLine
                    li $v0, 4
                    syscall
                # i=i + 1;
                    la $t2, i
                    lw $t2, 0($t2)

                    li $t3, 1
                    add $t2, $t2, $t3
                    la $t3, i
                    sw $t2, 0($t3)
                j Label0
        #}
        Label1: 

    #}
#}
# Exit
li $v0, 10
syscall
