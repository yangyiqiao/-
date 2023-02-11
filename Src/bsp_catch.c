#include "bsp_catch.h"
//红=1，绿=2，蓝=3
//1绿蓝红
//2蓝绿红
//3蓝红绿
//4绿红蓝
//5红绿蓝
//6红蓝绿


void CatchWithMission1(void)  //抓第一个物料
{
		Position = CatchPosition; //下降到上层
		Catch_Control(0);//张开
		switch (mission_buf[0])
		{
			case '1':
				switch (Order_buf[0])
				{
					case 1:
						Move_Step(RIGHT,OneGrid);
					break;
					case 2:
						Move_Step(RIGHT,OneGrid);
					break;
					case 3:
						//不动
					break;
					case 4:
						//不动
					break;
					case 5:
						Move_Step(LEFT,OneGrid);
					break;
					case 6:
						Move_Step(LEFT,OneGrid);
					break;
				}
			break;
			case '2':
				switch (Order_buf[0])
				{
					case 1:
						Move_Step(LEFT,OneGrid);
					break;
					case 2:
						//不动
					break;
					case 3:
						Move_Step(RIGHT,OneGrid);
					break;
					case 4:
						Move_Step(LEFT,OneGrid);
					break;
					case 5:
						//不动
					break;
					case 6:
						Move_Step(RIGHT,OneGrid);
					break;
				}
			break;
			case '3':
				switch (Order_buf[0])
					{
						case 1:
							//不动
						break;
						case 2:
							Move_Step(LEFT,OneGrid);
						break;
						case 3:
							Move_Step(LEFT,OneGrid);
						break;
						case 4:
							Move_Step(RIGHT,OneGrid);
						break;
						case 5:
							Move_Step(RIGHT,OneGrid);
						break;
						case 6:
							//不动
						break;
					}
			break;
			default:
			break;
		}
		//完成移动
		HAL_Delay(200);
		Move_Step(FORWORD,2700);//前进
		Catch_Control(70);//抓取
		HAL_Delay(1000);
		Move_Step(BACKWORD,CATCHMOVE);//往后走
		Position = TOP; 	//上升
		HAL_Delay(1000);
		Rotate_Control(FIRPOS);//旋转第一个
		HAL_Delay(2000);
		Position = BOTTOM; //下降
		HAL_Delay(1000);
		Catch_Control(40);//张开（小角度待调）
		HAL_Delay(1000);
		Position = TOP; //上升
		HAL_Delay(1500);
		Rotate_Control(POS);//0度
		HAL_Delay(1000);
		//第一个抓完
}

void CatchWithMission2(void)  //抓第二个物料
{
	
		Position = CatchPosition; //下降到上层
		Catch_Control(0);//张开
		switch (mission_buf[1])  //看第二个物料颜色
		{
			case '1':	//红色
				switch (mission_buf[0])
				{
					case '2': //绿红
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 2:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 3:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 4:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 5:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 6:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
						}
					break;
					case '3': //蓝红
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 2:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 3:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 4:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 5:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 6:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
						}
						break;
					}
			break;
			case '2':		//绿色
				switch (mission_buf[0])
				{
					case '1': //红绿
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 2:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 3:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 4:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 5:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 6:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
						}
					break;
					case '3': //蓝绿
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 2:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 3:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 4:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 5:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 6:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
						}
						break;
					}
			break;
			case '3':		//蓝色
				switch (mission_buf[0])
				{
					case '1': //红蓝
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 2:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 3:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 4:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 5:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 6:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
						}
						break;
					case '2': //绿蓝
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 2:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 3:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 4:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 5:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 6:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
						}
					break;
					}
			break;
			default:
			break;
		}
		//完成移动
		HAL_Delay(200);
		Move_Step(FORWORD,CATCHMOVE);//前进
		Catch_Control(70);//抓取
		HAL_Delay(1000);
		Move_Step(BACKWORD,CATCHMOVE);//往后走
		Position = TOP; 	//上升
		HAL_Delay(1000);
		Rotate_Control(SECPOS);//旋转第二个
		HAL_Delay(2000);
		Position = BOTTOM; //下降
		HAL_Delay(1000);
		Catch_Control(40);//张开（小角度待调）
		HAL_Delay(1000);
		Position = TOP; //上升
		HAL_Delay(1000);
		Rotate_Control(POS);//0度
		HAL_Delay(1000);
		//第二个抓完
}

void CatchWithMission3(void)  //抓第三个物料
{
	
		Position = CatchPosition; //下降到货架
		Catch_Control(0);//张开
		switch (mission_buf[2])  //看第三个物料颜色
		{
			case '1':	//红色
				switch (mission_buf[1])	//看第二个物料颜色
				{
					case '2': //绿红
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 2:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 3:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 4:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 5:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 6:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
						}
					break;
					case '3': //蓝红
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 2:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 3:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 4:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 5:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 6:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
						}
					break;
					}
			break;
			case '2':		//绿色
				switch (mission_buf[1])
				{
					case '1': //红绿
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 2:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 3:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 4:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 5:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 6:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
						}
						break;
					case '3': //蓝绿
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 2:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 3:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 4:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 5:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 6:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
						}
						break;
					}
			break;
			case '3':		//蓝色
				switch (mission_buf[1])
				{
					case '1': //红蓝
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 2:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 3:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 4:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 5:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 6:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
						}
					break;
					case '2': //绿蓝
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 2:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
							case 3:
								Move_Step(LEFT,TwoGrid);//左移两格
							break;
							case 4:
								Move_Step(RIGHT,TwoGrid);//右移两格
							break;
							case 5:
								Move_Step(RIGHT,OneGrid);//右移一格
							break;
							case 6:
								Move_Step(LEFT,OneGrid);//左移一格
							break;
						}
					break;
					}
			break;
			default:
			break;
		}
		//完成移动
		HAL_Delay(200);
		Move_Step(FORWORD,CATCHMOVE);//前进
		Catch_Control(70);//抓取
		HAL_Delay(1000);
		Move_Step(BACKWORD,CATCHMOVE);//往后走
		Position = TOP; 	//上升
		HAL_Delay(1000);
		Rotate_Control(THIPOS);//旋转第三个
		HAL_Delay(2000);
		Position = BOTTOM; //下降
		HAL_Delay(1000);
		Catch_Control(40);//张开（小角度待调）
		HAL_Delay(1000);
		Position = TOP; //上升
		HAL_Delay(1000);
		//第三个抓完
}

void MoveBack(void)		//回到原点
{
		switch (mission_buf[2])//看最后抓的颜色
		{
			case '1':		//红色
				switch (Order_buf[0])
				{
					case 1:
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case 2:
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case 3:
						//不动
					break;
					case 4:
						//不动
					break;
					case 5:
						Move_Step(RIGHT,OneGrid);//右移一格
					break;
					case 6:
						Move_Step(RIGHT,OneGrid);//右移一格
					break;
				}
			break;
			case '2':		//绿色
				switch (Order_buf[0])
				{
					case 1:
						Move_Step(RIGHT,OneGrid);//右移一格
					break;
					case 2:
						//不动
					break;
					case 3:
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case 4:
						Move_Step(RIGHT,OneGrid);//右移一格
					break;
					case 5:
						//不动
					break;
					case 6:
						Move_Step(LEFT,OneGrid);//左移一格
					break;
				}
			break;
			case '3':		//蓝色
				switch (Order_buf[0])
					{
						case 1:
							//不动
						break;
						case 2:
							Move_Step(RIGHT,OneGrid);//右移一格
						break;
						case 3:
							Move_Step(RIGHT,OneGrid);//右移一格
						break;
						case 4:
							Move_Step(LEFT,OneGrid);//左移一格
						break;
						case 5:
							Move_Step(LEFT,OneGrid);//左移一格
						break;
						case 6:
							//不动
						break;
					}
			break;
			default:
			break;
		}
}

void PutWithOrder1(void)			//放第一个物料
{
	Rotate_Control(FIRPOS);//旋转到第一个位置
	HAL_Delay(1500);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//旋转到原点
	HAL_Delay(2000);
	switch (mission_buf[0])//第一个抓的
		{
			case '1':		//红色
				Move_Step(RIGHT,OneGrid);//右移一格
			break;
			case '2':		//绿色
				//不动
			break;
			case '3':		//蓝色
				Move_Step(LEFT,OneGrid);//左移一格
			break;
			default:
			break;
		}
		//完成移动
	HAL_Delay(200);
	//Move_Step(FORWORD,2600);//前进
	Position = CATBOT; //下降到地面
	HAL_Delay(2000);
	Catch_Control(PUTANG);//小角度放置
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(2000);
}

void PutWithOrder2(void)			//放第二个物料
{
	Rotate_Control(SECPOS);//旋转到第二个位置
	HAL_Delay(1000);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//旋转到原点
	switch (mission_buf[1])//第二个抓的
		{
			case '1':		//红色
				switch	(mission_buf[0])
				{
					case '2': //绿红
						Move_Step(RIGHT,OneGrid);//左移一格
					break;
					case '3': //蓝红
					Move_Step(RIGHT,TwoGrid);//左移两格
					break;
				}
			break;
			case '2':		//绿色
				switch	(mission_buf[0])
				{
					case '1': //红绿
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case '3': //蓝绿
					Move_Step(RIGHT,OneGrid);//右移一格
					break;
				}
			break;
			case '3':		//蓝色
				switch	(mission_buf[0])
				{
					case '1': //红蓝
						Move_Step(LEFT,TwoGrid);//左移两格
					break;
					case '2': //绿蓝
					Move_Step(LEFT,OneGrid);//左移一格
					break;
				}
			break;
			default:
			break;
		}
		//完成移动
	Position = CATBOT; //下降到地面
	HAL_Delay(2000);
	Catch_Control(PUTANG);//小角度放置
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(2000);
}

void PutWithOrder3(void)			//放第三个物料
{
	Rotate_Control(THIPOS);//旋转到第三个位置
	HAL_Delay(1000);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//旋转到原点
	switch (mission_buf[2])//第三个抓的
		{
			case '1':		//红色
				switch	(mission_buf[1])
				{
					case '2': //绿红
						Move_Step(RIGHT,OneGrid);//左移一格
					break;
					case '3': //蓝红
					Move_Step(RIGHT,TwoGrid);//左移两格
					break;
				}
			break;
			case '2':		//绿色
				switch	(mission_buf[1])
				{
					case '1': //红绿
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case '3': //蓝绿
					Move_Step(RIGHT,OneGrid);//右移一格
					break;
				}
			break;
			case '3':		//蓝色
				switch	(mission_buf[1])
				{
					case '1': //红蓝
						Move_Step(LEFT,TwoGrid);//左移两格
					break;
					case '2': //绿蓝
					Move_Step(LEFT,OneGrid);//左移一格
					break;
				}
			break;
			default:
			break;
		}
		//完成移动
	Position = CATBOT; //下降到地面
	HAL_Delay(2000);
	Catch_Control(0);//放置
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(2000);
}

void MoveBack2(void)					//半成品区回到原点
{
		switch (mission_buf[2])//看最后抓的颜色
		{
			case '1':		//红色
				Move_Step(LEFT,OneGrid);//左移一格
			break;
			case '2':		//绿色
				//不动
			break;
			case '3':		//蓝色
				Move_Step(RIGHT,OneGrid);//右移一格
			break;
			default:
			break;
		}
}

void MoveBack3(void)					//半成品区、粗加工区回到原点
{
		switch (mission_buf[2])//看最后抓的颜色
		{
			case '1':		//红色
				Move_Step(LEFT,TwoGrid);//左移一格
			break;
			case '2':		//绿色
				Move_Step(LEFT,OneGrid);//左移一格
			break;
			case '3':		//蓝色
				//不动
			break;
			default:
			break;
		}
}

void CatchWithOrder1(void)		//抓回第一个物料
{
	
	switch (mission_buf[0])//第一个抓的
		{
			case '1':		//红色
				Move_Step(RIGHT,OneGrid);//右移一格
			break;
			case '2':		//绿色
				//不动
			break;
			case '3':		//蓝色
				Move_Step(LEFT,OneGrid);//左移一格
			break;
			default:
			break;
		}
	//完成移动
	Catch_Control(0);//张开爪子
	HAL_Delay(1000);
	Position = CATBOT; //下降到地面
	HAL_Delay(2000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; 		//上升
	HAL_Delay(2000);
	Rotate_Control(FIRPOS);//旋转第一个
	HAL_Delay(2000);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(40);//张开（小角度待调）
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//0度
	HAL_Delay(1000);
}

void CatchWithOrder2(void)		//抓回第二个物料
{
	Catch_Control(0);//张开
	switch (mission_buf[1])//第二个抓的
		{
			case '1':		//红色
				switch	(mission_buf[0])
				{
					case '2': //绿红
						Move_Step(RIGHT,OneGrid);//左移一格
					break;
					case '3': //蓝红
					Move_Step(RIGHT,TwoGrid);//左移两格
					break;
				}
			break;
			case '2':		//绿色
				switch	(mission_buf[0])
				{
					case '1': //红绿
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case '3': //蓝绿
					Move_Step(RIGHT,OneGrid);//右移一格
					break;
				}
			break;
			case '3':		//蓝色
				switch	(mission_buf[0])
				{
					case '1': //红蓝
						Move_Step(LEFT,TwoGrid);//左移两格
					break;
					case '2': //绿蓝
					Move_Step(LEFT,OneGrid);//左移一格
					break;
				}
			break;
			default:
			break;
		}
		//完成移动
	Position = CATBOT; //下降到地面
	HAL_Delay(2000);
		Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; 		//上升
	HAL_Delay(2000);
	Rotate_Control(SECPOS);//旋转第二个
	HAL_Delay(2000);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(PUTANG);//张开（小角度待调）
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//0度
	HAL_Delay(1000);
}

void CatchWithOrder3(void)		//抓回第三个物料
{
		Catch_Control(0);//张开
	switch (mission_buf[2])//第三个抓的
		{
			case '1':		//红色
				switch	(mission_buf[1])
				{
					case '2': //绿红
						Move_Step(RIGHT,OneGrid);//左移一格
					break;
					case '3': //蓝红
					Move_Step(RIGHT,TwoGrid);//左移两格
					break;
				}
			break;
			case '2':		//绿色
				switch	(mission_buf[1])
				{
					case '1': //红绿
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case '3': //蓝绿
					Move_Step(RIGHT,OneGrid);//右移一格
					break;
				}
			break;
			case '3':		//蓝色
				switch	(mission_buf[1])
				{
					case '1': //红蓝
						Move_Step(LEFT,TwoGrid);//左移两格
					break;
					case '2': //绿蓝
					Move_Step(LEFT,OneGrid);//左移一格
					break;
				}
			break;
			default:
			break;
		}
		//完成移动
	Position = CATBOT; //下降到地面
	HAL_Delay(2000);
		Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; 		//上升
	HAL_Delay(1000);
	Rotate_Control(THIPOS);//旋转第三个
	HAL_Delay(2000);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(PUTANG);//张开（小角度待调）
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//0度
	HAL_Delay(1000);
}

void PutWithOrderCU1(void)			//半成品区放第一个物料
{
	Rotate_Control(FIRPOS);//旋转到第一个位置
	HAL_Delay(1500);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//旋转到原点
	switch (mission_buf[0])//第一个抓的
		{
			case '1':		//红色
				Move_Step(RIGHT,OneGrid);//右移一格
			break;
			case '2':		//绿色
				//不动
			break;
			case '3':		//蓝色
				Move_Step(LEFT,OneGrid);//左移一格
			break;
			default:
			break;
		}
		//完成移动
	Move_Step(FORWORD,750);//前进
	Position = CATBOT; //下降到地面
	HAL_Delay(2000);
	Catch_Control(PUTANG);//小角度放置
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(2000);
}

void PutWithOrderCU2(void)			//半成品区放第二个物料
{
	Rotate_Control(SECPOS);//旋转到第二个位置
	HAL_Delay(1000);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//旋转到原点
	switch (mission_buf[1])//第二个抓的
		{
			case '1':		//红色
				switch	(mission_buf[0])
				{
					case '2': //绿红
						Move_Step(RIGHT,OneGrid);//左移一格
					break;
					case '3': //蓝红
					Move_Step(RIGHT,TwoGrid);//左移两格
					break;
				}
			break;
			case '2':		//绿色
				switch	(mission_buf[0])
				{
					case '1': //红绿
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case '3': //蓝绿
					Move_Step(RIGHT,OneGrid);//右移一格
					break;
				}
			break;
			case '3':		//蓝色
				switch	(mission_buf[0])
				{
					case '1': //红蓝
						Move_Step(LEFT,TwoGrid);//左移两格
					break;
					case '2': //绿蓝
					Move_Step(LEFT,OneGrid);//左移一格
					break;
				}
			break;
			default:
			break;
		}
		//完成移动
	Position = CATBOT; //下降到地面
	HAL_Delay(2000);
	Catch_Control(PUTANG);//小角度放置
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(2000);
}

void PutWithOrderCU3(void)			//半成品区放第三个物料
{
	Rotate_Control(THIPOS);//旋转到第三个位置
	HAL_Delay(1000);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//旋转到原点
	switch (mission_buf[2])//第三个抓的
		{
			case '1':		//红色
				switch	(mission_buf[1])
				{
					case '2': //绿红
						Move_Step(RIGHT,OneGrid);//左移一格
					break;
					case '3': //蓝红
					Move_Step(RIGHT,TwoGrid);//左移两格
					break;
				}
			break;
			case '2':		//绿色
				switch	(mission_buf[1])
				{
					case '1': //红绿
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case '3': //蓝绿
					Move_Step(RIGHT,OneGrid);//右移一格
					break;
				}
			break;
			case '3':		//蓝色
				switch	(mission_buf[1])
				{
					case '1': //红蓝
						Move_Step(LEFT,TwoGrid);//左移两格
					break;
					case '2': //绿蓝
					Move_Step(LEFT,OneGrid);//左移一格
					break;
				}
			break;
			default:
			break;
		}
		//完成移动
	Position = CATBOT; //下降到地面
	HAL_Delay(2000);
	Catch_Control(0);//放置
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
}

void PutWithOrderCU4(void)			//半成品区码垛第一个物料
{
	Rotate_Control(FIRPOS);//旋转到第一个位置
	HAL_Delay(1500);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//旋转到原点
	switch (mission_buf[0])//第一个抓的
		{
			case '1':		//红色
				Move_Step(RIGHT,OneGrid);//右移一格
			break;
			case '2':		//绿色
				//不动
			break;
			case '3':		//蓝色
				Move_Step(LEFT,OneGrid);//左移一格
			break;
			default:
			break;
		}
		//完成移动
	Move_Step(FORWORD,1900);//前进
	Position = CATMA; //下降到码垛
	HAL_Delay(2000);
	Catch_Control(PUTANG);//小角度放置
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(2000);
}

void PutWithOrderCU5(void)			//半成品区放第二个物料
{
	Rotate_Control(SECPOS);//旋转到第二个位置
	HAL_Delay(1000);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//旋转到原点
	switch (mission_buf[1])//第二个抓的
		{
			case '1':		//红色
				switch	(mission_buf[0])
				{
					case '2': //绿红
						Move_Step(RIGHT,OneGrid);//左移一格
					break;
					case '3': //蓝红
					Move_Step(RIGHT,TwoGrid);//左移两格
					break;
				}
			break;
			case '2':		//绿色
				switch	(mission_buf[0])
				{
					case '1': //红绿
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case '3': //蓝绿
					Move_Step(RIGHT,OneGrid);//右移一格
					break;
				}
			break;
			case '3':		//蓝色
				switch	(mission_buf[0])
				{
					case '1': //红蓝
						Move_Step(LEFT,TwoGrid);//左移两格
					break;
					case '2': //绿蓝
					Move_Step(LEFT,OneGrid);//左移一格
					break;
				}
			break;
			default:
			break;
		}
		//完成移动
	Position = CATMA; //下降到码垛
	HAL_Delay(2000);
	Catch_Control(PUTANG);//小角度放置
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(2000);
}

void PutWithOrderCU6(void)			//半成品区放第三个物料
{
	Rotate_Control(THIPOS);//旋转到第三个位置
	HAL_Delay(1000);
	Position = BOTTOM; //下降
	HAL_Delay(1000);
	Catch_Control(70);//抓取
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
	Rotate_Control(POS);//旋转到原点
	switch (mission_buf[2])//第三个抓的
		{
			case '1':		//红色
				switch	(mission_buf[1])
				{
					case '2': //绿红
						Move_Step(RIGHT,OneGrid);//左移一格
					break;
					case '3': //蓝红
					Move_Step(RIGHT,TwoGrid);//左移两格
					break;
				}
			break;
			case '2':		//绿色
				switch	(mission_buf[1])
				{
					case '1': //红绿
						Move_Step(LEFT,OneGrid);//左移一格
					break;
					case '3': //蓝绿
					Move_Step(RIGHT,OneGrid);//右移一格
					break;
				}
			break;
			case '3':		//蓝色
				switch	(mission_buf[1])
				{
					case '1': //红蓝
						Move_Step(LEFT,TwoGrid);//左移两格
					break;
					case '2': //绿蓝
					Move_Step(LEFT,OneGrid);//左移一格
					break;
				}
			break;
			default:
			break;
		}
		//完成移动
	Position = CATMA; //下降到码垛
	HAL_Delay(1000);
	Catch_Control(0);//放置
	HAL_Delay(1000);
	Position = TOP; //上升
	HAL_Delay(1000);
}
