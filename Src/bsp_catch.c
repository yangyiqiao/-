#include "bsp_catch.h"
//��=1����=2����=3
//1������
//2���̺�
//3������
//4�̺���
//5������
//6������


void CatchWithMission1(void)  //ץ��һ������
{
		Position = CatchPosition; //�½����ϲ�
		Catch_Control(0);//�ſ�
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
						//����
					break;
					case 4:
						//����
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
						//����
					break;
					case 3:
						Move_Step(RIGHT,OneGrid);
					break;
					case 4:
						Move_Step(LEFT,OneGrid);
					break;
					case 5:
						//����
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
							//����
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
							//����
						break;
					}
			break;
			default:
			break;
		}
		//����ƶ�
		HAL_Delay(200);
		Move_Step(FORWORD,2700);//ǰ��
		Catch_Control(70);//ץȡ
		HAL_Delay(1000);
		Move_Step(BACKWORD,CATCHMOVE);//������
		Position = TOP; 	//����
		HAL_Delay(1000);
		Rotate_Control(FIRPOS);//��ת��һ��
		HAL_Delay(2000);
		Position = BOTTOM; //�½�
		HAL_Delay(1000);
		Catch_Control(40);//�ſ���С�Ƕȴ�����
		HAL_Delay(1000);
		Position = TOP; //����
		HAL_Delay(1500);
		Rotate_Control(POS);//0��
		HAL_Delay(1000);
		//��һ��ץ��
}

void CatchWithMission2(void)  //ץ�ڶ�������
{
	
		Position = CatchPosition; //�½����ϲ�
		Catch_Control(0);//�ſ�
		switch (mission_buf[1])  //���ڶ���������ɫ
		{
			case '1':	//��ɫ
				switch (mission_buf[0])
				{
					case '2': //�̺�
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 2:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 3:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 4:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 5:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 6:
								Move_Step(LEFT,TwoGrid);//��������
							break;
						}
					break;
					case '3': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 2:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 3:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 4:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 5:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 6:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
						}
						break;
					}
			break;
			case '2':		//��ɫ
				switch (mission_buf[0])
				{
					case '1': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 2:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 3:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 4:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 5:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 6:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
						}
					break;
					case '3': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 2:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 3:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 4:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 5:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 6:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
						}
						break;
					}
			break;
			case '3':		//��ɫ
				switch (mission_buf[0])
				{
					case '1': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 2:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 3:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 4:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 5:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 6:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
						}
						break;
					case '2': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 2:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 3:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 4:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 5:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 6:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
						}
					break;
					}
			break;
			default:
			break;
		}
		//����ƶ�
		HAL_Delay(200);
		Move_Step(FORWORD,CATCHMOVE);//ǰ��
		Catch_Control(70);//ץȡ
		HAL_Delay(1000);
		Move_Step(BACKWORD,CATCHMOVE);//������
		Position = TOP; 	//����
		HAL_Delay(1000);
		Rotate_Control(SECPOS);//��ת�ڶ���
		HAL_Delay(2000);
		Position = BOTTOM; //�½�
		HAL_Delay(1000);
		Catch_Control(40);//�ſ���С�Ƕȴ�����
		HAL_Delay(1000);
		Position = TOP; //����
		HAL_Delay(1000);
		Rotate_Control(POS);//0��
		HAL_Delay(1000);
		//�ڶ���ץ��
}

void CatchWithMission3(void)  //ץ����������
{
	
		Position = CatchPosition; //�½�������
		Catch_Control(0);//�ſ�
		switch (mission_buf[2])  //��������������ɫ
		{
			case '1':	//��ɫ
				switch (mission_buf[1])	//���ڶ���������ɫ
				{
					case '2': //�̺�
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 2:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 3:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 4:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 5:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 6:
								Move_Step(LEFT,TwoGrid);//��������
							break;
						}
					break;
					case '3': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 2:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 3:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 4:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 5:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 6:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
						}
					break;
					}
			break;
			case '2':		//��ɫ
				switch (mission_buf[1])
				{
					case '1': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 2:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 3:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 4:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 5:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 6:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
						}
						break;
					case '3': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 2:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 3:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 4:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 5:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 6:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
						}
						break;
					}
			break;
			case '3':		//��ɫ
				switch (mission_buf[1])
				{
					case '1': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 2:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 3:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 4:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 5:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 6:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
						}
					break;
					case '2': //����
						switch (Order_buf[0])
						{
							case 1:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 2:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
							case 3:
								Move_Step(LEFT,TwoGrid);//��������
							break;
							case 4:
								Move_Step(RIGHT,TwoGrid);//��������
							break;
							case 5:
								Move_Step(RIGHT,OneGrid);//����һ��
							break;
							case 6:
								Move_Step(LEFT,OneGrid);//����һ��
							break;
						}
					break;
					}
			break;
			default:
			break;
		}
		//����ƶ�
		HAL_Delay(200);
		Move_Step(FORWORD,CATCHMOVE);//ǰ��
		Catch_Control(70);//ץȡ
		HAL_Delay(1000);
		Move_Step(BACKWORD,CATCHMOVE);//������
		Position = TOP; 	//����
		HAL_Delay(1000);
		Rotate_Control(THIPOS);//��ת������
		HAL_Delay(2000);
		Position = BOTTOM; //�½�
		HAL_Delay(1000);
		Catch_Control(40);//�ſ���С�Ƕȴ�����
		HAL_Delay(1000);
		Position = TOP; //����
		HAL_Delay(1000);
		//������ץ��
}

void MoveBack(void)		//�ص�ԭ��
{
		switch (mission_buf[2])//�����ץ����ɫ
		{
			case '1':		//��ɫ
				switch (Order_buf[0])
				{
					case 1:
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case 2:
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case 3:
						//����
					break;
					case 4:
						//����
					break;
					case 5:
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case 6:
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
				}
			break;
			case '2':		//��ɫ
				switch (Order_buf[0])
				{
					case 1:
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case 2:
						//����
					break;
					case 3:
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case 4:
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case 5:
						//����
					break;
					case 6:
						Move_Step(LEFT,OneGrid);//����һ��
					break;
				}
			break;
			case '3':		//��ɫ
				switch (Order_buf[0])
					{
						case 1:
							//����
						break;
						case 2:
							Move_Step(RIGHT,OneGrid);//����һ��
						break;
						case 3:
							Move_Step(RIGHT,OneGrid);//����һ��
						break;
						case 4:
							Move_Step(LEFT,OneGrid);//����һ��
						break;
						case 5:
							Move_Step(LEFT,OneGrid);//����һ��
						break;
						case 6:
							//����
						break;
					}
			break;
			default:
			break;
		}
}

void PutWithOrder1(void)			//�ŵ�һ������
{
	Rotate_Control(FIRPOS);//��ת����һ��λ��
	HAL_Delay(1500);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//��ת��ԭ��
	HAL_Delay(2000);
	switch (mission_buf[0])//��һ��ץ��
		{
			case '1':		//��ɫ
				Move_Step(RIGHT,OneGrid);//����һ��
			break;
			case '2':		//��ɫ
				//����
			break;
			case '3':		//��ɫ
				Move_Step(LEFT,OneGrid);//����һ��
			break;
			default:
			break;
		}
		//����ƶ�
	HAL_Delay(200);
	//Move_Step(FORWORD,2600);//ǰ��
	Position = CATBOT; //�½�������
	HAL_Delay(2000);
	Catch_Control(PUTANG);//С�Ƕȷ���
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(2000);
}

void PutWithOrder2(void)			//�ŵڶ�������
{
	Rotate_Control(SECPOS);//��ת���ڶ���λ��
	HAL_Delay(1000);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//��ת��ԭ��
	switch (mission_buf[1])//�ڶ���ץ��
		{
			case '1':		//��ɫ
				switch	(mission_buf[0])
				{
					case '2': //�̺�
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,TwoGrid);//��������
					break;
				}
			break;
			case '2':		//��ɫ
				switch	(mission_buf[0])
				{
					case '1': //����
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,OneGrid);//����һ��
					break;
				}
			break;
			case '3':		//��ɫ
				switch	(mission_buf[0])
				{
					case '1': //����
						Move_Step(LEFT,TwoGrid);//��������
					break;
					case '2': //����
					Move_Step(LEFT,OneGrid);//����һ��
					break;
				}
			break;
			default:
			break;
		}
		//����ƶ�
	Position = CATBOT; //�½�������
	HAL_Delay(2000);
	Catch_Control(PUTANG);//С�Ƕȷ���
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(2000);
}

void PutWithOrder3(void)			//�ŵ���������
{
	Rotate_Control(THIPOS);//��ת��������λ��
	HAL_Delay(1000);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//��ת��ԭ��
	switch (mission_buf[2])//������ץ��
		{
			case '1':		//��ɫ
				switch	(mission_buf[1])
				{
					case '2': //�̺�
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,TwoGrid);//��������
					break;
				}
			break;
			case '2':		//��ɫ
				switch	(mission_buf[1])
				{
					case '1': //����
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,OneGrid);//����һ��
					break;
				}
			break;
			case '3':		//��ɫ
				switch	(mission_buf[1])
				{
					case '1': //����
						Move_Step(LEFT,TwoGrid);//��������
					break;
					case '2': //����
					Move_Step(LEFT,OneGrid);//����һ��
					break;
				}
			break;
			default:
			break;
		}
		//����ƶ�
	Position = CATBOT; //�½�������
	HAL_Delay(2000);
	Catch_Control(0);//����
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(2000);
}

void MoveBack2(void)					//���Ʒ���ص�ԭ��
{
		switch (mission_buf[2])//�����ץ����ɫ
		{
			case '1':		//��ɫ
				Move_Step(LEFT,OneGrid);//����һ��
			break;
			case '2':		//��ɫ
				//����
			break;
			case '3':		//��ɫ
				Move_Step(RIGHT,OneGrid);//����һ��
			break;
			default:
			break;
		}
}

void MoveBack3(void)					//���Ʒ�����ּӹ����ص�ԭ��
{
		switch (mission_buf[2])//�����ץ����ɫ
		{
			case '1':		//��ɫ
				Move_Step(LEFT,TwoGrid);//����һ��
			break;
			case '2':		//��ɫ
				Move_Step(LEFT,OneGrid);//����һ��
			break;
			case '3':		//��ɫ
				//����
			break;
			default:
			break;
		}
}

void CatchWithOrder1(void)		//ץ�ص�һ������
{
	
	switch (mission_buf[0])//��һ��ץ��
		{
			case '1':		//��ɫ
				Move_Step(RIGHT,OneGrid);//����һ��
			break;
			case '2':		//��ɫ
				//����
			break;
			case '3':		//��ɫ
				Move_Step(LEFT,OneGrid);//����һ��
			break;
			default:
			break;
		}
	//����ƶ�
	Catch_Control(0);//�ſ�צ��
	HAL_Delay(1000);
	Position = CATBOT; //�½�������
	HAL_Delay(2000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; 		//����
	HAL_Delay(2000);
	Rotate_Control(FIRPOS);//��ת��һ��
	HAL_Delay(2000);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(40);//�ſ���С�Ƕȴ�����
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//0��
	HAL_Delay(1000);
}

void CatchWithOrder2(void)		//ץ�صڶ�������
{
	Catch_Control(0);//�ſ�
	switch (mission_buf[1])//�ڶ���ץ��
		{
			case '1':		//��ɫ
				switch	(mission_buf[0])
				{
					case '2': //�̺�
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,TwoGrid);//��������
					break;
				}
			break;
			case '2':		//��ɫ
				switch	(mission_buf[0])
				{
					case '1': //����
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,OneGrid);//����һ��
					break;
				}
			break;
			case '3':		//��ɫ
				switch	(mission_buf[0])
				{
					case '1': //����
						Move_Step(LEFT,TwoGrid);//��������
					break;
					case '2': //����
					Move_Step(LEFT,OneGrid);//����һ��
					break;
				}
			break;
			default:
			break;
		}
		//����ƶ�
	Position = CATBOT; //�½�������
	HAL_Delay(2000);
		Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; 		//����
	HAL_Delay(2000);
	Rotate_Control(SECPOS);//��ת�ڶ���
	HAL_Delay(2000);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(PUTANG);//�ſ���С�Ƕȴ�����
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//0��
	HAL_Delay(1000);
}

void CatchWithOrder3(void)		//ץ�ص���������
{
		Catch_Control(0);//�ſ�
	switch (mission_buf[2])//������ץ��
		{
			case '1':		//��ɫ
				switch	(mission_buf[1])
				{
					case '2': //�̺�
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,TwoGrid);//��������
					break;
				}
			break;
			case '2':		//��ɫ
				switch	(mission_buf[1])
				{
					case '1': //����
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,OneGrid);//����һ��
					break;
				}
			break;
			case '3':		//��ɫ
				switch	(mission_buf[1])
				{
					case '1': //����
						Move_Step(LEFT,TwoGrid);//��������
					break;
					case '2': //����
					Move_Step(LEFT,OneGrid);//����һ��
					break;
				}
			break;
			default:
			break;
		}
		//����ƶ�
	Position = CATBOT; //�½�������
	HAL_Delay(2000);
		Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; 		//����
	HAL_Delay(1000);
	Rotate_Control(THIPOS);//��ת������
	HAL_Delay(2000);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(PUTANG);//�ſ���С�Ƕȴ�����
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//0��
	HAL_Delay(1000);
}

void PutWithOrderCU1(void)			//���Ʒ���ŵ�һ������
{
	Rotate_Control(FIRPOS);//��ת����һ��λ��
	HAL_Delay(1500);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//��ת��ԭ��
	switch (mission_buf[0])//��һ��ץ��
		{
			case '1':		//��ɫ
				Move_Step(RIGHT,OneGrid);//����һ��
			break;
			case '2':		//��ɫ
				//����
			break;
			case '3':		//��ɫ
				Move_Step(LEFT,OneGrid);//����һ��
			break;
			default:
			break;
		}
		//����ƶ�
	Move_Step(FORWORD,750);//ǰ��
	Position = CATBOT; //�½�������
	HAL_Delay(2000);
	Catch_Control(PUTANG);//С�Ƕȷ���
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(2000);
}

void PutWithOrderCU2(void)			//���Ʒ���ŵڶ�������
{
	Rotate_Control(SECPOS);//��ת���ڶ���λ��
	HAL_Delay(1000);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//��ת��ԭ��
	switch (mission_buf[1])//�ڶ���ץ��
		{
			case '1':		//��ɫ
				switch	(mission_buf[0])
				{
					case '2': //�̺�
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,TwoGrid);//��������
					break;
				}
			break;
			case '2':		//��ɫ
				switch	(mission_buf[0])
				{
					case '1': //����
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,OneGrid);//����һ��
					break;
				}
			break;
			case '3':		//��ɫ
				switch	(mission_buf[0])
				{
					case '1': //����
						Move_Step(LEFT,TwoGrid);//��������
					break;
					case '2': //����
					Move_Step(LEFT,OneGrid);//����һ��
					break;
				}
			break;
			default:
			break;
		}
		//����ƶ�
	Position = CATBOT; //�½�������
	HAL_Delay(2000);
	Catch_Control(PUTANG);//С�Ƕȷ���
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(2000);
}

void PutWithOrderCU3(void)			//���Ʒ���ŵ���������
{
	Rotate_Control(THIPOS);//��ת��������λ��
	HAL_Delay(1000);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//��ת��ԭ��
	switch (mission_buf[2])//������ץ��
		{
			case '1':		//��ɫ
				switch	(mission_buf[1])
				{
					case '2': //�̺�
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,TwoGrid);//��������
					break;
				}
			break;
			case '2':		//��ɫ
				switch	(mission_buf[1])
				{
					case '1': //����
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,OneGrid);//����һ��
					break;
				}
			break;
			case '3':		//��ɫ
				switch	(mission_buf[1])
				{
					case '1': //����
						Move_Step(LEFT,TwoGrid);//��������
					break;
					case '2': //����
					Move_Step(LEFT,OneGrid);//����һ��
					break;
				}
			break;
			default:
			break;
		}
		//����ƶ�
	Position = CATBOT; //�½�������
	HAL_Delay(2000);
	Catch_Control(0);//����
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
}

void PutWithOrderCU4(void)			//���Ʒ������һ������
{
	Rotate_Control(FIRPOS);//��ת����һ��λ��
	HAL_Delay(1500);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//��ת��ԭ��
	switch (mission_buf[0])//��һ��ץ��
		{
			case '1':		//��ɫ
				Move_Step(RIGHT,OneGrid);//����һ��
			break;
			case '2':		//��ɫ
				//����
			break;
			case '3':		//��ɫ
				Move_Step(LEFT,OneGrid);//����һ��
			break;
			default:
			break;
		}
		//����ƶ�
	Move_Step(FORWORD,1900);//ǰ��
	Position = CATMA; //�½������
	HAL_Delay(2000);
	Catch_Control(PUTANG);//С�Ƕȷ���
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(2000);
}

void PutWithOrderCU5(void)			//���Ʒ���ŵڶ�������
{
	Rotate_Control(SECPOS);//��ת���ڶ���λ��
	HAL_Delay(1000);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//��ת��ԭ��
	switch (mission_buf[1])//�ڶ���ץ��
		{
			case '1':		//��ɫ
				switch	(mission_buf[0])
				{
					case '2': //�̺�
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,TwoGrid);//��������
					break;
				}
			break;
			case '2':		//��ɫ
				switch	(mission_buf[0])
				{
					case '1': //����
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,OneGrid);//����һ��
					break;
				}
			break;
			case '3':		//��ɫ
				switch	(mission_buf[0])
				{
					case '1': //����
						Move_Step(LEFT,TwoGrid);//��������
					break;
					case '2': //����
					Move_Step(LEFT,OneGrid);//����һ��
					break;
				}
			break;
			default:
			break;
		}
		//����ƶ�
	Position = CATMA; //�½������
	HAL_Delay(2000);
	Catch_Control(PUTANG);//С�Ƕȷ���
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(2000);
}

void PutWithOrderCU6(void)			//���Ʒ���ŵ���������
{
	Rotate_Control(THIPOS);//��ת��������λ��
	HAL_Delay(1000);
	Position = BOTTOM; //�½�
	HAL_Delay(1000);
	Catch_Control(70);//ץȡ
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
	Rotate_Control(POS);//��ת��ԭ��
	switch (mission_buf[2])//������ץ��
		{
			case '1':		//��ɫ
				switch	(mission_buf[1])
				{
					case '2': //�̺�
						Move_Step(RIGHT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,TwoGrid);//��������
					break;
				}
			break;
			case '2':		//��ɫ
				switch	(mission_buf[1])
				{
					case '1': //����
						Move_Step(LEFT,OneGrid);//����һ��
					break;
					case '3': //����
					Move_Step(RIGHT,OneGrid);//����һ��
					break;
				}
			break;
			case '3':		//��ɫ
				switch	(mission_buf[1])
				{
					case '1': //����
						Move_Step(LEFT,TwoGrid);//��������
					break;
					case '2': //����
					Move_Step(LEFT,OneGrid);//����һ��
					break;
				}
			break;
			default:
			break;
		}
		//����ƶ�
	Position = CATMA; //�½������
	HAL_Delay(1000);
	Catch_Control(0);//����
	HAL_Delay(1000);
	Position = TOP; //����
	HAL_Delay(1000);
}
