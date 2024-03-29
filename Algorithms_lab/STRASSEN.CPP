#include <iostream.h>
#include <conio.h>
#define N 4

struct m {
    int rs;
    int re;
    int cs;
    int ce;
    int a[N][N];
};

class mul{
public:
	void display(m matrix);
	m addition(m m1, m m2);
	m subraction(m m1, m m2);
	m multiply(m m1, m m2);
};


void mul:: display(m matrix)
{
    int i, j;

    for (i=matrix.rs ; i<=matrix.re ; i++) {
	for (j=matrix.cs ; j<=matrix.ce ; j++)
	    cout<<matrix.a[i][j]<<'\t';
	cout<<endl;
    }
    cout<<endl;

    return;
}

m mul:: addition(m m1, m m2)
{
    m result;
    int m1_i, m1_j;
    int m2_i, m2_j;
    int i, j;
    int n = m1.re - m1.rs;

    result.rs = result.cs = 0;
    result.re = result.ce = n;

    for (m1_i=m1.rs, m2_i=m2.rs, i=0 ; m1_i<=m1.re ; m1_i++, m2_i++, i++)
	for (m1_j=m1.cs, m2_j=m2.cs, j=0 ; m1_j<=m1.ce ; m1_j++, m2_j++, j++)
	    result.a[i][j] = m1.a[m1_i][m1_j] + m2.a[m2_i][m2_j];

    return result;
}

m mul:: subraction(m m1, m m2)
{
    m result;
    int m1_i, m1_j;
    int m2_i, m2_j;
    int i, j;
    int n = m1.re - m1.rs;

    result.rs = result.cs = 0;
    result.re = result.ce = n;

    for (m1_i=m1.rs, m2_i=m2.rs, i=0 ; m1_i<=m1.re ; m1_i++, m2_i++, i++)
	for (m1_j=m1.cs, m2_j=m2.cs, j=0 ; m1_j<=m1.ce ; m1_j++, m2_j++, j++)
	    result.a[i][j] = m1.a[m1_i][m1_j] - m2.a[m2_i][m2_j];

    return result;
}


m mul:: multiply(m m1, m m2)
{
    int n = m1.re - m1.rs + 1;

    if (n <= 2) {
	int a, b, c, d, e, f, g, h;
	m m3 = m1;

	a = m1.a[m1.rs][m1.cs];
	b = m1.a[m1.rs][m1.cs+1];
	c = m1.a[m1.rs+1][m1.cs];
	d = m1.a[m1.rs+1][m1.cs+1];
	e = m2.a[m2.rs][m2.cs];
	f = m2.a[m2.rs][m2.cs+1];
	g = m2.a[m2.rs+1][m2.cs];
	h = m2.a[m2.rs+1][m2.cs+1];

	m3.a[m3.rs][m3.cs]      = a*e + b*g;
	m3.a[m3.rs][m3.cs+1]    = a*f + b*h;
	m3.a[m3.rs+1][m3.cs]    = c*e + d*g;
	m3.a[m3.rs+1][m3.cs+1]  = c*f + d*h;

	return m3;
    }

    else{
	m A, B, C, D, E, F, G, H;
	m P1, P2, P3, P4, P5, P6, P7;
	m Q1, Q2, Q3, Q4;
	m result;
	int m1_i, m1_j;
	int i, j;

	result.rs = result.cs = 0;
	result.ce = result.re = n-1;

	A = B = C = D = m1;
	E = F = G = H = m2;

	A.rs = m1.rs;
	A.re = m1.re/2;
	A.cs = m1.cs;
	A.ce = m1.ce/2;

	B.rs = m1.rs;
	B.re = m1.re/2;
	B.cs = m1.ce/2 + 1;
	B.ce = m1.ce;

	C.rs = m1.re/2 + 1;
	C.re = m1.re;
	C.cs = m1.cs;
	C.ce = m1.ce/2;

	D.rs = m1.re/2 + 1;
	D.re = m1.re;
	D.cs = m1.ce/2 + 1;
	D.ce = m1.ce;

	E.rs = m2.rs;
	E.re = m2.re/2;
	E.cs = m2.cs;
	E.ce = m2.ce/2;

	F.rs = m2.rs;
	F.re = m2.re/2;
	F.cs = m2.ce/2 + 1;
	F.ce = m2.ce;

	G.rs = m2.re/2 + 1;
	G.re = m2.re;
	G.cs = m2.cs;
	G.ce = m2.ce/2;

	H.rs = m2.re/2 + 1;
	H.re = m2.re;
	H.cs = m2.ce/2 + 1;
	H.ce = m2.ce;

	P1 = multiply(A, subraction(F, H));
	P2 = multiply(addition(A, B), H);
	P3 = multiply(addition(C, D), E);
	P4 = multiply(D, subraction(G, E));
	P5 = multiply(addition(A, D), addition(E, H));
	P6 = multiply(subraction(B, D), addition(G, H));
	P7 = multiply(subraction(A, C), addition(E, F));

	Q1 = addition(subraction(addition(P5, P4), P2), P6);
	Q2 = addition(P1, P2);
	Q3 = addition(P3, P4);
	Q4 = subraction(subraction(addition(P1, P5), P3), P7);

	for (m1_i=Q1.rs, i=0 ; m1_i<=Q1.re ; m1_i++, i++)
	    for (m1_j=Q1.cs, j=0 ; m1_j<=Q1.ce ; m1_j++, j++)
		result.a[i][j] = Q1.a[m1_i][m1_j];

	for (m1_i=Q2.rs, i=0 ; m1_i<=Q2.re ; m1_i++, i++)
	    for (m1_j=Q2.cs, j=n/2 ; m1_j<=Q2.ce ; m1_j++, j++)
		result.a[i][j] = Q2.a[m1_i][m1_j];

	for (m1_i=Q3.rs, i=n/2 ; m1_i<=Q3.re ; m1_i++, i++)
	    for (m1_j=Q3.cs, j=0 ; m1_j<=Q3.ce ; m1_j++, j++)
		result.a[i][j] = Q3.a[m1_i][m1_j];

	for (m1_i=Q4.rs, i=n/2 ; m1_i<=Q4.re ; m1_i++, i++)
	    for (m1_j=Q4.cs, j=n/2 ; m1_j<=Q4.ce ; m1_j++, j++)
		result.a[i][j] = Q4.a[m1_i][m1_j];

	return result;
    }
}

int main(void)
{
    mul A;
    int i, j, n;
    clrscr();
    cout<<"Enter the order of NxN matrix: ";
    cin>>n;

    m m1, m2;

    cout<<"Enter the Elements of 1st matrix:"<<endl;
    for(i=0; i<n; i++){
	for(j=0; j<n; j++){
	    cin>>m1.a[i][j];
	}
    }

    cout<<"Enter the Elements of 2st matrix:"<<endl;
    for(i=0; i<n; i++){
	for(j=0; j<n; j++){
	    cin>>m2.a[i][j];
	}
    }
    m1.rs=m1.cs=m2.rs=m2.cs=0;
    m1.re=m1.ce=m2.re=m2.ce=n-1;

    cout<<"================================================="<<endl;
    cout<<"Elements of 1st matrix:"<<endl;
    A.display(m1);
    cout<<"Elements of 2st matrix:"<<endl;
    A.display(m2);

    cout<<"Elements of resultant matrix:"<<endl;
    A.display(A.multiply(m1, m2));
    getch();
    return 0;
}
