/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		     : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

# include <iostream.h>
# include <conio.h>
# include <stdlib.h>

struct node
{
	int data;
	node * next;
};


void reverse(node *first)
{
	node *current = first, *current1;
	int count = 0, z = 0, k = 1, check, temp;
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	count++;
	check = count / 2;
	if (count % 2 != 0)
	{


		current = first;

		z = 0;
		while (z != count / 2 + 1)
		{
			current = current->next;
			z++;
		}
		z = 0;
		for (int i = count / 2 + 1; i > 1; i--)
		{
			current1 = first;
			while (check != 1)
			{
				current1 = current1->next;
				check--;
			}

			temp = current1->data;
			current1->data = current->data;
			current->data = temp;
			current = current->next;
			check = count / 2 - k;
			k++;
		}

	}


	else if (count % 2 == 0)
	{

		current = first;

		z = 0;
		while (z != count / 2)
		{
			current = current->next;
			z++;
		}
		z = 0;
		for (int i = count / 2 + 1; i > 1; i--)
		{
			current1 = first;
			while (check != 1)
			{
				current1 = current1->next;
				check--;
			}

			temp = current1->data;
			current1->data = current->data;
			current->data = temp;
			current = current->next;
			check = count / 2 - k;
			k++;
		}

	}






}


node sort(node *first)
{

	node *current = first, *current1 = first;
	int count = 0, size = 0, temp = 0, z = 0;

	while (current->next != NULL)
	{
		size++;
		current = current->next;
	}
	size++;
	size *= size;

	current = first;
	current = current->next;


	do
	{
		if (current1->next == NULL)
		{
			current = first;
			current1 = first;
			current = current->next;
		}
		if (current1->data > current->data)
		{
			z++;
		}

		else if (current1->data < current->data)
		{
			temp = current1->data;
			current1->data = current->data;
			current->data = temp;
			z++;
		}

		current = current->next;
		current1 = current1->next;

	} while (z != size);

	return *first;
}



void search(int num, node *first)
{
	node *current = first, *current1 = first;
	int count = 0, ncount = 0;
	while (current->next != NULL)
	{
		ncount++;
		if (current->data == num)
		{
			cout << "\n The Number Is=" << current->data;
			cout << "\n At Node=" << ncount;
			count++;
		}

		current = current->next;
	}
	if (current->data == num)
	{
		ncount++;
		cout << "\n The Number Is=" << current->data;
		cout << "\n At Node=" << ncount;
		count++;
	}
	else if (count == 0)
	{
		cout << "\n Number Not Found.";
	}
}

void del(int num, node *first)
{
	node * current = first;
	node * current1 = first;
	int count = 0;
	while (current->data != num)
	{
		current = current->next;
		if (count >= 1)
			current1 = current1->next;
		count++;
	}
	if (count == 0)
	{
		//current1=current1->next;
		first->next = current->next;
		delete current;
	}
	else
	{
		current1->next = current->next;
		delete current;
		current = current->next;

	}

}

void delsec(node *first)
{
	node * current = first, *current1 = first;
	int count = 0, i = 0;
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	count++;
	current = first;
	for (i = 0; i < count; i++)
	{
		current = current1;
		if (i % 2 != 0)
		{
			current = current->next;
			current1->next = current->next;
			delete current;
		}

		if (i >= 1 && i % 2 == 0)
		{
			current1 = current1->next;
		}

	}


}




void insert(int num, node *first, node *last, node *newnode)
{
	node * current = first;
	node * current1 = first;
	int count = 0;


	if (last->data < num)
	{
		newnode = new node;
		newnode->data = num;
		last->next = newnode;
		newnode->next = NULL;
		last = newnode;
	}


	else if (current->data < num)
	{
		while (current->data < num)
		{
			current = current->next;
			if (count >= 1)
				current1 = current1->next;
			count++;
		}
		newnode = new node;
		newnode->data = num;
		current1->next = newnode;
		newnode->next = current;
	}

	else if (current->data > num || current->data == num)
	{
		newnode = new node;
		newnode->data = num;
		newnode->next = first;
		first = newnode;
	}
}

void inser(int num, int no, node *first)
{
	node * current = first, *current1 = first;
	node *newnode;
	int count = 0;
	while (current->data != num)
	{
		current = current->next;
		if (count >= 1)
			current1 = current1->next;
		count++;
	}
	current = current->next;
	current1 = current1->next;
	newnode = new node;
	newnode->data = no;
	current1->next = newnode;
	newnode->next = current;

}

void su(node *first)
{
	node *current = first;
	int sum = 0;
	while (current->next != NULL)
	{
		sum += current->data;
		current = current->next;
	}
	sum += current->data;
	cout << "\n The Sum Of All The Nodes Is=" << sum;
}


void display(node* first)
{
	node *current;
	current = first;
	cout << "\n";
	cout << "\n";
	for (int h = 0; h < 79; h++)
	{
		cputs("\xDC");
	}
	while (current->next != NULL)
	{
		cputs(" \xDB ");
		cout << current->data;
		current = current->next;

	}
	cputs(" \xDB ");
	cout << current->data << "\n";

	for (int h = 0; h < 79; h++)
	{
		cputs("\xDF");
	}

}


void concat(node * first, node * first3)
{
	node *current = first3;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = first;
	cout << "\n To See The two Lists Concatenated, Get The Display of List2.";

}


void freenode(node *first)
{
	node *current = first, *current1 = first;
	current1 = current1->next;

	while (current1->next != NULL)
	{
		first = current1;
		delete current;
		current = current1;
		current1 = current1->next;
	}
	first = current1;
	delete current;
	current = current1;
	current1 = current1->next;

}


void order(node * first, node *first3)
{
	node * current = first, *newnode4, *first4 = NULL;
	node * current1 = first3;



	while (current->next != NULL)
	{
		newnode4 = new node;
		newnode4->data = current->data;
		newnode4->next = first4;
		first4 = newnode4;
		current = current->next;
	}

	newnode4 = new node;
	newnode4->data = current->data;
	newnode4->next = first4;
	first4 = newnode4;


	while (current1->next != NULL)
	{
		newnode4 = new node;
		newnode4->data = current1->data;
		newnode4->next = first4;
		first4 = newnode4;
		current1 = current1->next;
	}
	newnode4 = new node;
	newnode4->data = current1->data;
	newnode4->next = first4;
	first4 = newnode4;

	sort(first4);

	display(first4);

}

void unionn(node *first, node *first3)
{
	node *current = first, *current1 = first3;
	node *currentu, *firstu = NULL, *newnodeu, *current2;
	int count = 0;
	while (current->next != NULL)
	{
		newnodeu = new node;
		newnodeu->data = current->data;
		newnodeu->next = firstu;
		firstu = newnodeu;
		current = current->next;
	}
	newnodeu = new node;
	newnodeu->data = current->data;
	newnodeu->next = firstu;
	firstu = newnodeu;
	while (current1->next != NULL)
	{
		newnodeu = new node;
		newnodeu->data = current1->data;
		newnodeu->next = firstu;
		firstu = newnodeu;
		current1 = current1->next;
	}
	newnodeu = new node;
	newnodeu->data = current1->data;
	newnodeu->next = firstu;
	firstu = newnodeu;

	*firstu = sort(firstu);

	current = firstu;
	current1 = firstu;
	current1 = current1->next;
	current2 = firstu;
	while (current1->next != NULL)
	{
		if (current->data == current1->data)
		{
			current2->next = current1;
			delete current;
			current = current1;
			current1 = current1->next;
		}
		else
		{
			if (count >= 1)
				current2 = current2->next;
			count++;
			current1 = current1->next;
			current = current->next;
		}

	}
	if (current->data == current1->data)
	{
		current2->next = current1;
		delete current;
		current = current1;
		current1 = current1->next;
	}
	else
	{
		if (count >= 1)
			current2 = current2->next;
		count++;
		current1 = current1->next;
		current = current->next;
	}
	display(firstu);
}





void intersection(node *first, node *first3)
{
	node *current = first, *current1 = first3;
	node *newnodei, *firsti = NULL;
	while (current->next != NULL)
	{
		current1 = first3;
		while (current1->next != NULL)
		{
			if (current->data == current1->data)
			{
				newnodei = new node;
				newnodei->data = current->data;
				newnodei->next = firsti;
				firsti = newnodei;
			}
			current1 = current1->next;
		}
		if (current1->next == NULL)
		{
			if (current1->data == current->data)
			{
				newnodei = new node;
				newnodei->data = current->data;
				newnodei->next = firsti;
				firsti = newnodei;
			}
		}
		current = current->next;
	}
	current1 = first3;
	while (current1->next != NULL)
	{
		if (current->data == current1->data)
		{
			newnodei = new node;
			newnodei->data = current->data;
			newnodei->next = firsti;
			firsti = newnodei;
		}
		current1 = current1->next;
	}
	if (current->data == current1->data)
	{
		newnodei = new node;
		newnodei->data = current->data;
		newnodei->next = firsti;
		firsti = newnodei;
	}
	display(firsti);


}


void elements(node *first, node *first3)
{
	node *current = first, *current1 = first3;
	int count = 0;
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	count++;
	cout << "\n The Number Of Elements In List1=" << count;
	count = 0;
	while (current1->next != NULL)
	{
		current1 = current1->next;
		count++;
	}
	count++;
	cout << "\n The Number Of Elements In List2=" << count;

	getch();
}


void forward(node *first, int p, int n)
{
	node *current = first, *current1 = first, *newnode;
	int count = 0, z = 0, k = 0, temp = 0, l = 0, e = 0;

	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	count++;
	l = count;
	count = 0;
	e = p;
	current = first;
	current1 = first;


	while (e - 1 != 0)
	{

		current1 = current1->next;
		e--;

	}

	temp = current1->data;
	current = first;
	current1 = first;
	current = current->next;
	k = p + n;
	while (k - 1 != 0)
	{
		current = current->next;

		current1 = current1->next;

		k--;
	}
	newnode = new node;
	newnode->data = temp;
	newnode->next = current;
	current1->next = newnode;


	current = first;
	current1 = first;
	current = current->next;
	while (current->data != temp)
	{
		current = current->next;
		current1 = current1->next;

	}
	current1->next = current->next;
	delete current;
	display(first);
	getch();
}


void copyy(node *first)
{
	node *current = first;
	node *newnodec, *firstc = NULL;
	while (current->next != NULL)
	{
		newnodec = new node;
		newnodec->data = current->data;
		newnodec->next = firstc;
		firstc = newnodec;
		current = current->next;
	}
	newnodec = new node;
	newnodec->data = current->data;
	newnodec->next = firstc;
	firstc = newnodec;
	display(firstc);
}



void main()
{
	clrscr();
	node *first = NULL, *newnode, *current, *last, *A;
	node *first3 = NULL, *newnode3, *current3, *last3;
	int choice, num, count = 0, count3 = 0, no, p, n;

	do
	{
		clrscr();
		textcolor(2);
		textbackground(9);

		cout << "\n\n\t\t\t\t";
		cputs("LINK LIST PROBLEMS");
		textbackground(16);

		cout << "\n\n Press 1 To Append An Element To The End Of List.\n Press 2 To Displaying The Data.\n Press 3 To Concatenate Two Lists.\n Press 4 To Free All Nodes In a list."
			<< "\n Press 5 To Reverse The List.\n Press 6 To Delete Any Node.\n Press 7 To Combine To Ordered Lists into Single Ordered List."
			<< "\n Press 8 To Get The Union Of the two Lists.\n Press 9 To get The Intersetion of the two Lists.\n Press 10 To Insert an Element After A given Element."
			<< "\n Press 11 To Delete Every Second Element From The List \n Press 12 To Place Elements Of the List In increasing Order.\n Press 13 To Get The Sum Of the Integers In a list."
			<< "\n Press 14 To Get The Number Of Elements In a List.\n Press 15 To Move Node P forward N Positions In a list.\n Press 16 To Make A Second Copy Of the List.\n Any other Number To quit.";
		cout << "\n Enter Your Choice=";
		cin >> choice;
		textcolor(15);
		if (choice == 1)
		{
			do{
				clrscr();

				cout << "\n Press 1 Append Element To List1.\n Press 2 To Append Element To List2";
				cout << "\n Enter Your Choice=";
				cin >> choice;
				if (choice == 1)
				{
					newnode = new node;
					cout << "\n Enter The Data=";
					cin >> newnode->data;
					newnode->next = first;
					first = newnode;
					if (count == 0)
						last = newnode;
					count++;
				}
				else if (choice == 2)
				{
					newnode3 = new node;
					cout << "\n Enter The Data=";
					cin >> newnode3->data;
					newnode3->next = first3;
					first3 = newnode3;
					if (count3 == 0)
						last3 = newnode3;
					count3++;
				}
			} while (choice != 0);
		}


		else if (choice == 2)
		{
			do{
				clrscr();
				cout << "\n Press 1 Display List 1.\n Press 2 To Display List 2.";
				cout << "\n Enter Your Choice=";
				cin >> choice;
				if (choice == 1)
				{
					display(first);
					getch();
				}
				else if (choice == 2)
				{
					display(first3);
					getch();
				}
			} while (choice != 0);
		}


		/*	else if( choice==3)
		  { cout<<"\n Enter The Number You Want To Insert=";
		  cin>>num;
		  insert(num,first,last,newnode);
		  }*/

		else if (choice == 3)
		{

			concat(first, first3);
			getch();
		}

		/*	else if( choice==4)
		  {
		  sort(first);
		  getch();
		  }*/

		else if (choice == 4)
		{
			do{
				clrscr();
				cout << "\n Press 1 To free All Nodes Of List 1.\n Press 2 To Free All Nodes Of list 2.";
				cout << "\n Enter Your Choice==";
				cin >> choice;
				if (choice == 1)
				{
					freenode(first);
					getch();
				}
				else if (choice == 2)
				{
					freenode(first3);
					getch();
				}
			} while (choice != 0);
		}


		/*	else if(choice==5)
		  { cout<<"\n Enter Number To Search=";
		  cin>>num;
		  search(num,first);
		  getch();
		  } */

		else if (choice == 5)
		{
			do{
				clrscr();
				cout << "\n Press 1 To Reverse List 1.\n Press 2 To Reverse List 2";
				cout << "\n Enter Your choice=";
				cin >> choice;
				if (choice == 1)
				{
					reverse(first);
					getch();
				}
				else if (choice == 2)
				{
					reverse(first3);
					getch();
				}
			} while (choice != 0);
		}

		else if (choice == 6)
		{
			do{
				clrscr();
				cout << "\n Press 1 To Delete from List 1.\n Press 2 To Delete From List 2.";
				cout << "\n Enter Your Choice=";
				cin >> choice;
				if (choice == 1)
				{
					cout << "\n Enter The Number You Want To delete=";
					cin >> num;
					del(num, first);

					getch();
				}
				else if (choice == 2)
				{
					cout << "\n Enter The Number You Want To delete=";
					cin >> num;
					del(num, first3);
					getch();

				}
			} while (choice != 0);
		}





		else if (choice == 7)
		{
			order(first, first3);
			getch();
		}

		else if (choice == 8)
		{
			unionn(first, first3);

			getch();
		}

		else if (choice == 9)
		{
			intersection(first, first3);
			getch();
		}

		else if (choice == 10)
		{
			do
			{
				clrscr();
				cout << "\n Press 1 To Insert In List 1.\n Press 2 To Insert In List 2.";
				cout << "\n Enter Your Choice=";
				cin >> choice;
				if (choice == 1)
				{
					cout << "\n Enter The Number To Insert=";
					cin >> no;
					cout << "\n Enter The Number After Which To Insert=";
					cin >> num;
					inser(num, no, first);
					getch();
				}
				else if (choice == 2)
				{
					cout << "\n Enter The Number To Insert=";
					cin >> no;
					cout << "\n Enter The Number After Which To Insert=";
					cin >> num;
					inser(num, no, first3);
					getch();
				}
			} while (choice != 0);

		}

		else if (choice == 11)
		{
			do
			{
				clrscr();
				cout << "\n Press 1 To delete In List 1.\n Press 2 To Delete In List 2.";
				cout << "\n Enter Your Choice=";
				cin >> choice;
				if (choice == 1)
				{
					cout << "\n Deleting Every Second Node.";
					delsec(first);
					getch();
				}
				else if (choice == 2)
				{
					cout << "\n Deleting Every Second Node.";
					delsec(first3);
					getch();
				}
			} while (choice != 0);

		}

		else if (choice == 12)
		{
			do{
				clrscr();
				cout << "\n Press 1 To Sort  List 1.\n Press 2 To Sort List 2.";
				cout << "\n Enter Your Choice=";
				cin >> choice;
				if (choice == 1)
				{
					sort(first);
					getch();
				}
				else if (choice == 2)
				{
					sort(first3);
					getch();
				}
			} while (choice != 0);
		}


		else if (choice == 13)
		{
			do{
				clrscr();
				cout << "\n Press 1 To Sum List 1.\n Press 2 To Sum List 2.";
				cout << "\n Enter Your Choice=";
				cin >> choice;
				if (choice == 1)
				{
					su(first);
					getch();
				}
				else if (choice == 2)
				{
					su(first3);
					getch();
				}
			} while (choice != 0);
		}


		else if (choice == 14)
		{
			elements(first, first3);
		}

		else if (choice == 15)
		{
			cout << "\n Enter The Node To Move forward=";
			cin >> p;
			cout << "\n Enter How Much to Move Forward=";
			cin >> n;
			forward(first, p, n);

		}


		else if (choice == 16)
		{
			do
			{
				cout << "\n Press 1 To make Copy Of List1.\n Press 2 To Make Copy Of List 2.";
				cout << "\n Enter Your Choice=";
				cin >> choice;
				if (choice == 1)
				{
					copyy(first);
					getch();
				}
				else if (choice == 2)
				{
					copyy(first3);
					getch();
				}
			} while (choice != 0);

		}

		else
		{
			exit(0);
		}
	} while (1);
}
