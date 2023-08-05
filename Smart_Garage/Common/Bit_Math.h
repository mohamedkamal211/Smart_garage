#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_
/*Function like macro bitmath (Set/Clear/Tog/Read)*/
#define Set_Bit(Reg,Bit_no)     Reg|=(1<<Bit_no)
#define Clear_Bit(Reg,Bit_no)   Reg&=~(1<<Bit_no)
#define Tog_Bit(Reg,Bit_no)     Reg^=(1<<Bit_no)
#define Get_Bit(Reg,Bit_no)     ((Reg>>Bit_no)&0x01)


					

// 01100110
// 00000100
//-------------
//		->       
//reg&(1<<bit_no) read Zero 


#endif 