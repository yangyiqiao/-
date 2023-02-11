#ifndef __bsp_catch_H
#define __bsp_catch_H
#include "main.h"
#include "bsp_stepmotor.h"
#include "bsp_move.h"
#include "bsp_servo.h"

extern uint8_t mission_buf[7];
extern uint8_t Order_buf[1];
extern int Position;				//机械臂升降位置
extern int CatchPosition;		//抓取物料位置

#define CATCHMOVE 700 		//抓取时移动距离
#define PUTLAST 40     		//放置巡线时余量

#define POS     0					//舵机0度位置
#define FIRPOS  232				//舵机第一个物块角度
#define SECPOS	180				//舵机第二个物块角度
#define THIPOS	145				//舵机第三个物块角度

//值越小位置越高 10000为基准
#define TOP     	9200		//上升到顶点高度
#define BOTTOM  	9850		//放到车上的位置
#define CATBOT  	10900		//放到地上的位置
#define CATMA  		10300		//码垛的位置
#define CATUP  		9700		//抓取上层物料位置CATUP
#define CATDOWN		10670//10600		//抓取下层物料位置

#define PUTANG    35

#define OneGrid 	800//1000//1600		//抓取或放置物料时移动一格距离
#define TwoGrid 	2800		//抓取或放置物料时移动两格距离



void CatchWithMission1(void); //抓第一个物料
void CatchWithMission2(void); //抓第二个物料
void CatchWithMission3(void); //抓第三个物料
void MoveBack(void);					//回到原点
void PutWithOrder1(void);			//放置第一个物料
void PutWithOrder2(void);			//放置第二个物料
void PutWithOrder3(void);			//放置第三个物料
void MoveBack2(void);					//半成品区、粗加工区回到原点
void MoveBack3(void);					//粗加工区回到蓝色框
void CatchWithOrder1(void);
void CatchWithOrder2(void);
void CatchWithOrder3(void);
void PutWithOrderCU1(void);
void PutWithOrderCU2(void);
void PutWithOrderCU3(void);
void PutWithOrderCU4(void);
void PutWithOrderCU5(void);
void PutWithOrderCU6(void);
#endif

