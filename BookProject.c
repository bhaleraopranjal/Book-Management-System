#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
typedef struct Book
{
	char name[30];
	long long int bookId;
	char authorName[20];
	char category[10];
	double price,rating;
}Book;

void storeInfo(Book*,int);
void displayInfo(Book*,int);
void increaseMemory(Book*,int);
void noIndex(Book*,int);
void displayBook1(Book*,int); 
void hardCoaded(Book*);
void removeBook(Book*,int);
int searchByBookName(Book*,char*);
int searchByBookId(Book*,long long int);  
void searchByCategory(Book*,char*);  
void updateBook(Book*,int);
void sortByPrice(Book*);
void sortByRating(Book*);
void sortAscPrice(Book*);
void sortAscRating(Book*);
int checkRepeat(Book*,int,long long int); 
void searchByAuthorName(Book*,char*);
void displayTopBook(Book*,int);
void displayTopBookPrice(Book*,int);
void displayTopBookRating(Book*,int);

int size = 7;										//hard coaded size value given globally
int ctr = 0;										//counter(ctr) declare globally having initial value 0

void main()
{
	Book* bk = (Book*)malloc(sizeof(Book)*size);        //create array of name bk using malloc() having data base Book 
	hardCoaded(bk);											//some hard coaded details entered
	int ch;
	do   
	{
		printf("\n1.Insert book Information \n2.Display book Information \n3.Search book \n4.Remove book \n5.Update book Information \n6.Sort book \n7.Top 3 Books \n8.Exit \n\nEnter Your Choice: \n ");	
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				{
					(ctr<size)?storeInfo(bk,ctr):increaseMemory(bk,ctr);  		//calling 'storeInfo' fun to store data by user
				}
				break;
				
			case 2:
				{
					(ctr==0)?noIndex(bk,ctr):displayInfo(bk,ctr);				//calling 'displayInfo' fun to display data present in array
				}
				break;
				
			case 3:
				{
					if(ctr==0)
					{
						noIndex(bk,ctr);    										 //calling 'noindex' fun if ctr value is 0				
					}
					else
					{
						int choice;
						printf("\n1.Search by Book Id \n2.Search by Book Name \n3.Search by Author Name \n4.Search by Book Category \n\nEnter your choice:");
						scanf("%d",&choice);
						
						if(choice == 1)
						{
							long long int id;
							printf("\nEnter Id of book you want to search: ");
							scanf("%lld",&id);
							
							int i = searchByBookId(bk,id);                                            
							{
								(i >= 0)?displayBook1(bk,i):printf("\nBook not found \n");       
							}
						}
						
						if(choice == 2)
						{
							char name[20];
							printf("\nEnter name of book you want to search: "); 
							fflush(stdin);
							gets(name);
								
							int i = searchByBookName(bk,name);										//calling 'searchByName' to search player
							{
								(i >= 0)?displayBook1(bk,i):printf("\nBook not found \n");		//calling 'displayPlayer1' fun to show only searched player data
							}
						} 
						
						if(choice == 3)
						{
							char aName[20];
							printf("\nEnter name of author whose book you want to search: "); 
							fflush(stdin);
							gets(aName);
							
							searchByAuthorName(bk,aName);
						} 
						
						if(choice == 4)
						{
							char category[20];
							printf("\nEnter category of book you want to search: "); 
							fflush(stdin);
							gets(category);
							
							searchByCategory(bk,category);
						} 
						
						else if(choice > 5)
						{
							printf("\nInvalid Choice\n");  		
						}
					}					
				}
				break;

			case 4:
				{
					if(ctr==0)
					{
						noIndex(bk,ctr);    										//calling 'noindex' fun if ctr value is 0			
					}
					else
					{
						int choice;
						printf("\n1.Remove book by book id \n2.Remove book by book name \n\nEnter your choice: ");
						scanf("%d",&choice);
							
						if(choice == 1)
						{
							long long int id;
							printf("\nEnter Id of book you want to search: ");
							scanf("%lld",&id);
								
							int i = searchByBookId(bk,id);  							 
							{
								if(i >= 0)
								{
									removeBook(bk,i);							   
									printf("\nBook removed Successfully\n");
								}
								else if(i==-1)
								{
										printf("\nBook not found \n",i);	
								}
							}
						}
						
						if(choice == 2)
						{
							char name[20];
							printf("\nEnter name of book you want to search: "); 
							fflush(stdin);
							gets(name);
								
							int i = searchByBookName(bk,name);						
							{
								if(i >= 0)
								{
									removeBook(bk,i);								//calling 'removePlayer' to remove player 
									printf("\nBook removed Successfully\n");				
								}
								else if(i==-1)
								{
									printf("\nBook not found \n",i);	
								}
							}
						}
						
						else if(choice > 2)
						{
							printf("\nInvalid Choice\n");
						}
					}						
				}
				break;

				case 5:
					{
						int choice;
						printf("\n1.Update book information by Book id \n2.Update book information by book name  \nEnter your choice: ");
						scanf("%d",&choice);
								
						if(choice == 1)
						{
							long long int id;
							printf("\nEnter Id of book you want to search: ");
							scanf("%lld",&id);
								
							int i = searchByBookId(bk,id);  
								(i>=0)?updateBook(bk,i):printf("\nBook not found\n");			
						}
						if(choice == 2)
						{
							char name[20];
							printf("\nEnter name of player you want to remove: ");
							fflush(stdin);
							gets(name);
										
							int i = searchByBookName(bk,name);											
								(i>=0)?updateBook(bk,i):printf("\nBook not found\n");				
						}
						else if(choice > 2)
						{
							printf("\nInvalid Choice\n");
						}						
					}
					break;

				case 6:
					{
						int ch;
						printf("\n1.Descending Sort \n2.Ascending Sort \n\nEnter which sort you want: ");
						scanf("%d",&ch);
						
						switch(ch)
						{
							case 1:
								{
									int choice;
									printf("\n1.Sort book by price \n2.Sort book by rating   \n\nEnter your choice: ");
									scanf("%d",&choice);
									
									(choice == 1)?sortByPrice(bk):(choice == 2)?sortByRating(bk):printf("\nInvalid Choice\n");  											
								}
								break;
							case 2:
								{
									int choice;
									printf("\n1.Sort book by price \n2.Sort book by rating   \n\nEnter your choice: ");
									scanf("%d",&choice);
									
									(choice == 1)?sortAscPrice(bk):(choice == 2)?sortAscRating(bk):printf("\nInvalid Choice\n");  							
								}
								break;
							default:
								{
									printf("\nEnter valid choice\n");
								}
						}
		
					}
					break;
				
				case 7:
					{
						int choice;
						printf("\n1.Top 3 books by price \n2.Top 3 books by rating   \n\nEnter your choice: ");
						scanf("%d",&choice);
									
						(choice == 1)?displayTopBookPrice(bk,ctr):(choice == 2)?displayTopBookRating(bk,ctr):printf("\nInvalid Choice\n");										
					}
					break;						

				case 8:
					{
						printf("\nThank You\n");				
					}
					break;
				default:
					{
						printf("\nEnter Valid choice\n");		
					}
				break;
		}
	}while(ch!=8);
}

void storeInfo(Book* bk,int i)
{	
	printf("\nEnter Id of Book: ");
	scanf("%lld",&bk[i].bookId);
	long long int bid = bk[i].bookId;
	int res = checkRepeat(bk,i,bid);
	if(res == 0)
	{
		printf("\nBook Id already present\n");
		storeInfo(bk,i);
	}
	else
	{
		printf("\nEnter Book Name: ");
		fflush(stdin);																//to clear buffer
		gets(bk[i].name);
			
		printf("\nEnter Author Name: ");
		fflush(stdin);																//to clear buffer
		gets(bk[i].authorName);
				
		printf("\nEnter the catrgory of book: ");
		fflush(stdin);																//to clear buffer
		gets(bk[i].category);
			
		printf("\nEnter the price of book: ");
		scanf("%lf",&bk[i].price);
		
		printf("\nEnter the rating of book: ");
		scanf("%lf",&bk[i].rating);	
				
		ctr++;		
		}	
	}

void displayInfo(Book* bk,int ctr)  
{
	printf("\nYou have entered %d Books Information\n\n",ctr);
	printf("\n+--------------------------------------------------------------------------------------------------------------------------------+");
	printf("\n|   Book Id   |            Book Name           |       Book Author     |   Book Category  |     Book Price     |   Book Rating   |");
	printf("\n+--------------------------------------------------------------------------------------------------------------------------------+");
	int j = 0;
	while(j<ctr)
	{
		printf("\n| %8lld    |   %-27s  |    %-15s    |   %-13s  |    %12f    |      %-lf   |",bk[j].bookId,bk[j].name,bk[j].authorName,bk[j].category,bk[j].price,bk[j].rating);
		j++;
	}
	printf("\n+--------------------------------------------------------------------------------------------------------------------------------+");
}

void increaseMemory(Book* bk,int ctr)
{
	printf("\nYou can not enter player information\n");
	char choice;
	printf("\nDo you want to increase memory to insert details(y/n): ");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice == 'y' || choice == 'Y')
	{
		int n;
		printf("\nHow much memory you want to increase: ");
		scanf("%d",&n);
		size = size + n;
		bk = (Book*)realloc(bk,(size)*sizeof(Book));                    //calling 'realloc' fun to increase the size of array
		storeInfo(bk,ctr);													//calling 'storeinfo' fun to store info
	}
	else if(choice == 'n' || choice == 'N')
	{
		printf("\nok...You can not insert more players\n");
	}
	else
	{
		printf("\nEnter valid choice\n");
	}
}

void noIndex(Book* bk,int ctr)									
{
	printf("\nThere is no any information to show");
	char choice;
	printf("\nDo yo want to insert Information(y/n): ");
	fflush(stdin);
	scanf("%c",&choice);
				
	(choice == 'y' || choice == 'Y')?storeInfo(bk,ctr):(choice == 'n' || choice == 'N')?printf("\nok...If you want to insert information choose choice 1\n"):printf("\nEnter valid choice\n");
}

int searchByBookId(Book* bk,long long int id)                                    
{		
	for(int i=0; i<ctr; i++)
	{
		if(bk[i].bookId == id )
		{
			return i;
		}
	}
	return -1;	
}

int searchByBookName(Book* bk,char* name)                                    
{
	for(int i=0; i<ctr; i++)
	{
		if(strcasecmp(bk[i].name,name)==0)
		{
			return i;
		}
	}
	return -1;		
}

void searchByAuthorName(Book* bk,char* aName)                                    
{
	int f = 0; 
	for(int i=0; i<ctr; i++)
	{
		if(strcasecmp(bk[i].authorName,aName)==0)
		{
			displayBook1(bk,i);
			f++;
		}
	}
	if(f == 0)	
	{
		printf("\nThere is no any book of author %s \n",aName);	
	}	
}

void searchByCategory(Book* bk,char* category)                                   
{
	int f = 0; 
	for(int i=0; i<ctr; i++)
	{
		if(strcasecmp(bk[i].category,category)==0)
		{
			displayBook1(bk,i);
			f++;
		}
	}
	if(f == 0)	
	{
		printf("\nThere is no any book of category %s \n",category);	
	}	
}

void displayBook1(Book* bk,int j)   
{
	printf("\n+--------------------------------------------------------------------------------------------------------------------------------+");
	printf("\n|   Book Id   |            Book Name           |       Book Author     |   Book Category  |     Book Price     |   Book Rating   |");
	printf("\n+--------------------------------------------------------------------------------------------------------------------------------+");
	printf("\n| %8lld    |   %-27s  |    %-15s    |   %-13s  |    %12f    |      %-lf   |",bk[j].bookId,bk[j].name,bk[j].authorName,bk[j].category,bk[j].price,bk[j].rating);
	printf("\n+--------------------------------------------------------------------------------------------------------------------------------+");	
	printf("\n");	
}

void hardCoaded(Book* bk)
{
	Book b;
	
	b.bookId = 25623;
	strcpy(b.name,"And Then There Were None");
	strcpy(b.authorName,"Agatha Christie");
	strcpy(b.category,"Mystery");
	b.price = 1204;
	b.rating = 4.3;

	bk[ctr++] = b;
	
	b.bookId = 789123;
	strcpy(b.name,"A Tale of Two Cities");
	strcpy(b.authorName,"Charles Dickens");
	strcpy(b.category,"Historical");
	b.price = 1650.25;
	b.rating = 4.1;

	bk[ctr++] = b;
	
	b.bookId = 45623;
	strcpy(b.name,"Watership Down");
	strcpy(b.authorName,"Richard Adams");
	strcpy(b.category,"Fantasy");
	b.price = 365;
	b.rating = 3.6;

	bk[ctr++] = b;
	
}

void removeBook(Book* bk,int i)
{
	for(int j=i; j<ctr-1; j++)  
	{
		bk[j] = bk[j+1];
	}
	ctr--;												//counter value decrased because one/searched index removed	
}

void updateBook(Book* bk,int i)
{
	int ch;
	printf("\n1.Update Price \n2.Update Rating \n\nEnter what you want to update: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			{
				printf("\nEnter updated price: ");
				scanf("%lf",&bk[i].price );
				
				printf("\nPrice updated successfully\n");
				displayBook1(bk,i);	
			}
		break;
		
		case 2:
			{
				
				printf("\nEnter updated rating: ");
				scanf("%lf",&bk[i].rating);
					
				printf("\nRating updated successfully\n");
				displayBook1(bk,i);		
			}
		break;
		
		default:
			{
				printf("\nEnter Valid choice\n");
			}
		break;
	}
}

void sortByPrice(Book* bk)								//fun to descending sort books by price
{
	Book bkk[size];									//create new array to keep original array as it is
	for(int i=0; i<ctr; i++)
	{
		bkk[i] = bk[i];									//assign original array value to duplicate array
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(bkk[i].price  < bkk[j].price)					//sort duplicated array
			{
				Book temp = bkk[i];
				bkk[i] = bkk[j];
				bkk[j] = temp;
			}
		}
	}
	displayInfo(bkk,ctr);										//display duplicated array
}

void sortByRating(Book* bk)
{
	Book bkk[size];
	for(int i=0; i<ctr; i++)
	{
		bkk[i] = bk[i];
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(bkk[i].rating  < bkk[j].rating)
			{
				Book temp = bkk[i];
				bkk[i] = bkk[j];
				bkk[j] = temp;
			}
		}
	}
	displayInfo(bkk,ctr);
}

void sortAscPrice(Book* bk)
{
	Book bkk[size];									//create new array to keep original array as it is
	for(int i=0; i<ctr; i++)
	{
		bkk[i] = bk[i];									//assign original array value to duplicate array
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(bkk[i].price  > bkk[j].price)					//sort duplicated array
			{
				Book temp = bkk[i];
				bkk[i] = bkk[j];
				bkk[j] = temp;
			}
		}
	}
	displayInfo(bkk,ctr);										//display duplicated array	
}

void sortAscRating(Book* bk)
{
	Book bkk[size];
	for(int i=0; i<ctr; i++)
	{
		bkk[i] = bk[i];
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(bkk[i].rating  > bkk[j].rating)
			{
				Book temp = bkk[i];
				bkk[i] = bkk[j];
				bkk[j] = temp;
			}
		}
	}
	displayInfo(bkk,ctr);
}

int checkRepeat(Book* bk,int i,long long int id)
{
	for(int j=0; j<i-1; j++)
	{
		if(id == bk[j].bookId)
		{
			return 0;
		}
	}			
	return 1;	
}

void displayTopBook(Book* bk,int ctr)
{
	printf("\n+--------------------------------------------------------------------------------------------------------------------------------+");
	printf("\n|   Book Id   |            Book Name           |       Book Author     |   Book Category  |     Book Price     |   Book Rating   |");
	printf("\n+--------------------------------------------------------------------------------------------------------------------------------+");


	printf("\nTop 3 books are as follows: \n");
	int j=0;
	while(j<3)
	{
		printf("\n| %8lld    |   %-27s  |    %-15s    |   %-13s  |    %12f    |      %-lf   |",bk[j].bookId,bk[j].name,bk[j].authorName,bk[j].category,bk[j].price,bk[j].rating);
		j++;
	}
	printf("\n+--------------------------------------------------------------------------------------------------------------------------------+");	
	printf("\n");	
}

void displayTopBookPrice(Book* bk,int ctr)
{
	Book bkk[size];									//create new array to keep original array as it is
	for(int i=0; i<ctr; i++)
	{
		bkk[i] = bk[i];									//assign original array value to duplicate array
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(bkk[i].price  < bkk[j].price)					//sort duplicated array
			{
				Book temp = bkk[i];
				bkk[i] = bkk[j];
				bkk[j] = temp;
			}
		}
	}
	displayTopBook(bkk,ctr);	
}

void displayTopBookRating(Book* bk,int ctr)
{
	Book bkk[size];
	for(int i=0; i<ctr; i++)
	{
		bkk[i] = bk[i];
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(bkk[i].rating  < bkk[j].rating)
			{
				Book temp = bkk[i];
				bkk[i] = bkk[j];
				bkk[j] = temp;
			}
		}
	}
	displayTopBook(bkk,ctr);
}
