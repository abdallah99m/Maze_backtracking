#include <iostream>
using namespace std;



class cnode
{
public:
	char s1[19][20]= { {'p' , ' ' , ' ' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , ' ' , ' ', ' ' , ' ' , ' ' , '#' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , '#' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , ' ' , ' ' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , ' ' , ' ' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , ' ' , ' ' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , ' ' , ' ' , ' ' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', ' ' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#'}
	, {'#' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , '#' , '#' , '#' , '#'}
	, {'#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#'}
	 };
	int plc, plr;
	
	cnode *pnext;
};
class clist
{
public:
	cnode * phead;
	cnode * ptail;
	clist()
	{
		phead = '\0';
		ptail = '\0';
	}
	~clist()
	{
		cnode *ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(cnode *pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
};
class cstack
{
public:
	cnode*phead;
	cstack()
	{
		phead = NULL;
	}
	void push(cnode*pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	}
	cnode* pop()
	{
		if (phead == NULL)
		{
			return NULL;
		}
		cnode*ptrav = phead;
		phead = phead->pnext;
		ptrav->pnext = NULL;
		return ptrav;
	}
};




void expandchild(cnode * pcur, clist& v, cstack &s)
{
	for (int k = 0; k < 4; k++)
	{
		int flag = 2;
		cnode* pchild = new cnode;
		int i, j;
		for(i=0;i<19;i++)
		{
			for (j = 0;j<20;j++)
			{
				pchild->s1[i][j] = pcur->s1[i][j];
			}
		}


		if (k == 0)
		{
			if (pchild->s1[pcur->plr - 1][pcur->plc] == '#')
			{
				flag = 1;
			}
			else
			{
				if (pcur->plr - 1 > -1)

				{
					pchild->s1[pcur->plr - 1][pcur->plc] = 'p';
					pchild->s1[pcur->plr][pcur->plc] = ' ';
					pchild->plc = pcur->plc;
					pchild->plr = pcur->plr - 1;
				}
				else { flag = 1; }
			}
		}

		if (k == 1)
		{
			if (pchild->s1[pcur->plr + 1][pcur->plc] == '#')
			{
				flag = 1;
			}
			else
			{
				if (pcur->plr + 1 < 19)
				{
					pchild->s1[pcur->plr + 1][pcur->plc] = 'p';
					pchild->s1[pcur->plr][pcur->plc] = ' ';
					pchild->plc = pcur->plc;
					pchild->plr = pcur->plr + 1;
				}
				else { flag = 1; }
			}
		}
		if (k == 2)
		{
			if (pchild->s1[pcur->plr ][pcur->plc-1] == '#')
			{
				flag = 1;
			}
			else
			{
				if (pcur->plc - 1 > -1) {
					pchild->s1[pcur->plr][pcur->plc - 1] = 'p';
					pchild->s1[pcur->plr][pcur->plc] = ' ';
					pchild->plc = pcur->plc - 1;
					pchild->plr = pcur->plr;
				}
				else { flag = 1; }
			}
		}
		if (k == 3)
		{
			if (pchild->s1[pcur->plr][pcur->plc + 1] == '#')
			{
				flag = 1;
			}
			else
			{
				pchild->s1[pcur->plr][pcur->plc + 1] = 'p';
				pchild->s1[pcur->plr][pcur->plc] = ' ';
				pchild->plc = pcur->plc + 1;
				pchild->plr = pcur->plr;
			}
		}

		cnode* pcatch = v.phead;

		while (pcatch != NULL)
		{
			if (pcatch->plc == pchild->plc&&pcatch->plr == pchild->plr)
			{
				flag = 1;
			}
			pcatch = pcatch->pnext;
		}
		if (pchild->plc == 1 && pchild->plr == 18)
		{
			cout << "the solution" << endl;
			for (i = 0; i < 19; i++)
			{
				for (j = 0; j < 20; j++)
				{
					cout << pcur->s1[i][j];
				}
				cout << endl;

			}
			cout << endl << "---------------------------------------" << endl;
			system("pause");
			flag = 1;
		}
		
		if (flag == 2)
		{

			for (i = 0; i < 19; i++)
			{
				for (j = 0; j < 20; j++)
				{
					cout << pcur->s1[i][j];
				}
				cout << endl;

			}
			
			cout << endl << "---------------------------------------" << endl;
			
			
			s.push(pchild);
		}

	}
	v.attach(pcur);
}














int main()
{
	cstack s;
	clist v;
	clist solution;
	cnode* pcur;


	pcur = new cnode;
	int i, j;
	
	pcur->plc = 0;
	pcur->plr = 0;



	
	
	pcur->pnext = NULL;
	


	s.push(pcur);
	while (s.phead != NULL)
	{
		pcur = s.pop();
		expandchild(pcur, v, s);
	}

	system("pause");

}