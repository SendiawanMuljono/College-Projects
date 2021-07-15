#include "stdio.h"
	int main()
		{
			int act,sudoku[50][50],ctr,sum;
			float t=0,res=0;
			scanf("%d",&act);
			
				for(int g=0;g<act;g++)
					{
						ctr=0;sum=0;
						/*Masukin Sudoku*/
						
						for(int y=0;y<9;y++)
							{
								for(int h=0;h<9;h++)
								{
								scanf("%d",&sudoku[y][h]);
							
								}	
							}
						
						
						/*Ngecek Sudoku kotak 1*/
						
						for(int y=0;y<3;y++)
							{
								
								for(int h=0;h<3;h++)
								{
									sum = sudoku[y][h] + sum;
								}	
								
							}
							if(sum == 45)
									{
								
									}
									else
									{
										ctr++;
									}
						
						sum=0;
						/*Ngecek Sudoku Kotak 2*/
						
						
							for(int y=0;y<3;y++)
							{
								
								for(int h=0;h<3;h++)
								{
									sum = sudoku[h][y+3] + sum;
								}	
							
							}
								if(sum == 45)
									{
								
									}
									else
									{
										ctr++;
									}
							sum=0;
							/*Ngecek Sudoku Kotak 3*/
							for(int y=0;y<3;y++)
							{
								
								for(int h=0;h<3;h++)
								{
									sum = sudoku[h][y+6] + sum;
								}	
							
							}
								if(sum == 45)
									{
								
									}
									else
									{
										ctr++;
									}
								sum=0;
							/*Ngecek Sudoku Kotak 4*/
							for(int y=0;y<3;y++)
							{
								
								for(int h=0;h<3;h++)
								{
									sum = sudoku[h+3][y] + sum;
								}	
							
							}
								if(sum == 45)
									{
								
									}
									else
									{
										ctr++;
									}
								sum=0;
							/*Ngecek Sudoku Kotak 5*/
							for(int y=0;y<3;y++)
							{
								
								for(int h=0;h<3;h++)
								{
									sum = sudoku[h+3][y+3] + sum;
								}	
							
							}
								if(sum == 45)
									{
								
									}
									else
									{
										ctr++;
									}
							sum=0;
							/*Ngecek Sudoku Kotak 6*/
							for(int y=0;y<3;y++)
							{
							
								for(int h=0;h<3;h++)
								{
									sum = sudoku[h+3][y+6] + sum;
								}	
							
							}
									if(sum == 45)
									{
								
									}
									else
									{
										ctr++;
									}
									sum=0;
							/*Ngecek Sudoku Kotak 7*/
							for(int y=0;y<3;y++)
							{
							
								for(int h=0;h<3;h++)
								{
									sum = sudoku[h+6][y] + sum;
								}	
							
							}
								if(sum == 45)
									{
								
									}
									else
									{
										ctr++;
									}
									sum=0;
							/*Ngecek Sudoku Kotak 8*/
							for(int y=0;y<3;y++)
							{
						
								for(int h=0;h<3;h++)
								{
									sum = sudoku[h+6][y+3] + sum;
								}	
							
							}
								if(sum == 45)
									{
								
									}
									else
									{
										ctr++;
									}
									sum=0;
							/*Ngecek Sudoku Kotak 9*/
							for(int y=0;y<3;y++)
							{
								
								for(int h=0;h<3;h++)
								{
									sum = sudoku[h+6][y+6] + sum;
								}	
								
							}
							if(sum == 45)
									{
								
									}
									else
									{
										ctr++;
									}
						
						
						
						if(ctr==0)
						{
							t++;
						printf("Case #%d: TRUE\n",g+1);	
						
						}
							else
						{
							
							printf("Case #%d: FALSE\n",g+1);	
							
							
						}
						
					}
					
						res=(t/act)*100;
					printf("%.2f%%\n",res);
			
		}
