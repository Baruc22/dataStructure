#include <stdio.h>
#include <stdlib.h>

int expresionbalanciada(char *s);

int expresionbalanciada(char *s)
{
	int i=0, band=1;
	Tpila p; //pila de char
	char car;
	p=inicializapila();
	while (s[i]!="\0" && band)
	{
		if (s[i]=="("||s[i]=="{"||s[i]=="[")
		{
			push(&p,s[i]);
		}
		else if (s[i]==")"||s[i]=="}"||s[i]=="]")
		{
			if (pilavacia(p))
				return 0;
			pop(&p,&car);
		}
		if (!mismotipo(s[i],car))
			return 0;
		i++;
	}
	if (pilavacia(p))
		return 1;
	return 0;
}

int mismotipo(char car1, char car2)
{
	if ((car1=="(" && car2==")") || (car1=="[" && car2=="]") || (car1=="{" && car2=="}"))
		return 1;
	return 0;
}

//........................................//

float evaluacionexpresion (char *s) //s cadena en postfijo
{
	int i=0,dig;
	float op1,op2,res;
	char car;

	Tpila p; //float

	p=inicializapila();

	while (s[i]!='\0')
	{
		if (s[i]!='0' && s[i]<='9')
		{
			push(&p,s[i]-48)
		}
		else
		{
			pop(&p,&op2);
			pop(&p,&op1);
			res=evalua(op1,op2,s[i]);
			push(&res);

		}
		i++;
	}
	pop(&p,&res);
	//liberapila(&p);
	return res;
}

float evaluar(float a, float b, char op)
{
	swtich (op)
	{
		case '*': return a*b;
		case '+': return a+b;
		case '/': return a/b;
		case '-': return a-b;
		//case 'NULL' return pop
	}
}

void cambiapostfija(char *s, char *sp)
{
	int j=0;
	char c;
	Tpila p; //pila de char

	p=inicializapila();
	while (s[i]!='\0')
		{
			while 
			{
				if (s[i]=='(')
				{
					push(&p,s[i]);
				}
				else if (s[i]>='A' && s[i]<='Z')
					{
						sp[j++]=s[i];
					}
					else if (s[i]==')')
					{
						elementotope(p,&c);
						while(c!='(')
						{
							pop(&p,&c);
							sp[j++]=c;
							elementotope(p,&c);
						}
						pop(&p,&c)
					}
					else
					{
						elementotope(p,&c);
						while (!pilavacia(p) && esoperador(c) && prioridadmenorigual(s[i],c))
					}
				pop(&p,&c);
			}
		}
}