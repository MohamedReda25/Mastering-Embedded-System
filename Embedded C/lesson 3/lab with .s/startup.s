/* learn_in_depth 
by Mohamed Reda */



.section .vectors

.word 0x20001000  	/*stack top address*/
.word _reset 		/*1 resrt*/
.word vector_handler	/*2 NMI*/
.word vector_handler	/*3 Hard Fault*/
.word vector_handler	/*4 Mem Manage*/
.word vector_handler	/*5 Bus Fault*/
.word vector_handler	/*6 Usage Fault*/
.word vector_handler	/*7 Reserved*/
.word vector_handler	/*8 Reserved*/
.word vector_handler	/*9 Reserved*/
.word vector_handler	/*10 Reserved*/
.word vector_handler	/*11 SV Call*/
.word vector_handler	/*12 Debug mointor*/
.word vector_handler	/*13 Reserved*/
.word vector_handler	/*14 PendSV*/
.word vector_handler	/*15 Systick*/
.word vector_handler	/*16 IRQ0*/
.word vector_handler	/*17 IRQ1*/
.word vector_handler	/*18 IRQ2*/	
.word vector_handler	/*19 ...*/
						


.section .text
_reset:
	bl main
	b .
	.thumb_func
vector_handler:
	b _reset