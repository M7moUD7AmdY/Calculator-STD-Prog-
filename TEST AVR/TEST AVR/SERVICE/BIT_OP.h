/*
 * UTILS.h
 *
 * Created: 3/22/2023 7:30:48 PM
 *  Author: imahm
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define  SET_BIT(REG,BIT)        (REG|=(1<<BIT))
#define  CLR_BIT(REG,BIT)        (REG&=~(1<<BIT))
#define  TOG_BIT(REG,BIT)        (REG^=(1<<BIT))
#define  READ_BIT(REG,BIT)       ((REG>>BIT)&1)
#define  WRITE_BIT(REG,BIT,VAL)  (REG=(REG &(~(1<<BIT) | (VAL<<BIT))))




#endif /* UTILS_H_ */