#ifndef __bsp_stepmotor_H
#define __bsp_stepmotor_H
#include "tim.h"
#ifdef __cplusplus
 extern "C" {
#endif
     
#define S_ACCEL 1
#define T_ACCEL 0
     
/* S型加速参数 */

#define ACCELERATED_SPEED_LENGTH 600  //定义加速度的点数（其实也是3000个细分步的意思），调这个参数改变加速点
#define ACCELERATED_SPEED_LENGTH_AD 400  //定义加速度的点数（其实也是3000个细分步的意思），调这个参数改变加速点
#define FRE_MIN 0  //最低的运行频率，调这个参数调节最低运行速度
#define FRE_MAX 8000  //最高的运行频率，调这个参数调节最低运行速度
#define ADSTEP 40   //调整时匀速运行步数
#define TrackPre 3550//少巡线预判距离

#define STOP                                  0 // 加减速曲线状态：停止
#define ACCEL                                 1 // 加减速曲线状态：加速阶段
#define DECEL                                 2 // 加减速曲线状态：减速阶段
#define RUN                                   3 // 加减速曲线状态：匀速阶段

void CalculateSModelLine(float fre[], unsigned short period[], float len, float fre_max, float fre_min, float flexible);    

#endif
 
 
 
 
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
