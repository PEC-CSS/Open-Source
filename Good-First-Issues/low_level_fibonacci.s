.data
  introText: .asciiz "Type a positive integer, please! \n"
  input: .word 123


.text
  li $v0, 4
  la $a0, introText
  syscall

  li $v0, 5
  syscall

  addi $s1, $v0, 0
  syscall

  li $s2, 0 
  li $s3, 0 
  li $s4, 1 
  loop: 
    addi $s2, $s2, 1 
    add $s5, $s3, $s4 
    addi, $s4, $s3, 0 
    addi, $s3, $s5, 0 
  bne $s2, $s1, loop

  
  li $v0, 1
  addi $a0, $s5, 0
  syscall

  
  li $v0, 10 
  syscall