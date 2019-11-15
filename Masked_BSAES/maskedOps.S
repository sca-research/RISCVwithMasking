.text


.func maskedXOR
.global maskedXOR
maskedXOR:
// a0= address of 2 shares of the first 32-bit operand 
// a1= address of 2 shares of the second 32-bit operand 
// a2= address of 2 shares of the result

// operating the first share
   lw 	t0, (a0)
   lw 	t1, (a1)
   xor 	t0, t0, t1
   sw   t0, (a2)

//share-switching: clear the context
   xor  t0, t0, t0//clear t0
   xor  t1, t1, t1//clear t1
   sw   t0, 4(a2)//clear data-bus

// operating the second share
   lw 	t0, 4(a0) 
   lw 	t1, 4(a1)
   xor 	t0, t0, t1
   sw   t0, 4(a2) 

ret
.endfunc


.func maskedAND
.global maskedAND
maskedAND:
// a0= address of 2 shares of the first 32-bit operand 
// a1= address of 2 shares of the second 32-bit operand 
// a2= address of 2 shares of the result

   // loading shares
   lw 	t0, (a0)	//t0=x1
   lw 	t2, (a1)	//t2=y1
   lw 	t1, 4(a0)	//t1=x2
   lw 	t3, 4(a1)	//t3=y2

   // operating the first share
   not  t4, t3		//t4=~y2
   or	t4, t0, t4	//t4=x1|(~y2)
   //possible leakage, consider fence here
   and  t5, t0, t2      //t5=x1y1
   xor  t4, t4, t5	//t4=x1y1^(x1|(~y2))
   sw   t4, (a2)	//storing the first share

   //switching shares, consider fence here


   // operating the second share
   not  t4, t3		//t4=~y2
   or	t4, t1, t4	//t4=x2|(~y2)
   //possible leakage, consider fence here
   and  t5, t1, t2      //t5=x2y1
   xor  t4, t4, t5	//t4=x2y1^(x2|(~y2))
   sw   t4, 4(a2)	//storing the first share

ret
.endfunc
.end
