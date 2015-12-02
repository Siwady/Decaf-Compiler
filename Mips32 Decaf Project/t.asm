.data
newLine: .asciiz "\n"
h: .word 0
i: .word 0
x: .word 0
y: .word 0
z: .word 0
w: .word 0
.text
#class GreatestCommonDivisor{
   #-AssignStatement-
      li $t0, 366
      la $t1, h
      sw $t0, 0($t1)
   #-AssignStatement-
      li $t0, 60
      la $t1, i
      sw $t0, 0($t1)

#   void main(){
      #-AssignStatement-
         la $t0, h
         lw $t0, 0($t0)

         la $t1, x
         sw $t0, 0($t1)

      #-AssignStatement-
         la $t0, i
         lw $t0, 0($t0)

         la $t1, y
         sw $t0, 0($t1)

      #-AssignStatement-
         li $t0, 10
         la $t1, z
         sw $t0, 0($t1)

      #-AssignStatement-
         li $t0, 20
         la $t1, w
         sw $t0, 0($t1)

      #-PrintStatement-
         la $t0, z
         lw $t0, 0($t0)

         move $a0, $t0
         li $v0, 1
         syscall
         la $a0, newLine
         li $v0, 4
         syscall

      #-PrintStatement-
         la $t0, w
         lw $t0, 0($t0)

         move $a0, $t0
         li $v0, 1
         syscall
         la $a0, newLine
         li $v0, 4
         syscall

      #-PrintStatement-
         la $t0, x
         lw $t0, 0($t0)

         move $a0, $t0
         li $v0, 1
         syscall
         la $a0, newLine
         li $v0, 4
         syscall

      #-PrintStatement-
         la $t0, y
         lw $t0, 0($t0)

         move $a0, $t0
         li $v0, 1
         syscall
         la $a0, newLine
         li $v0, 4
         syscall

   #}
#}
# Exit
li $v0, 10
syscall
