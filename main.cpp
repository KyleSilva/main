#include <iostream>
#include <fstream>
#include "string.h"
#include "function.h"
#include "extern.h"
using namespace std;

int main()
{
	int iters=0;
	read_mesh("naca0012.grd");
	initial();
    ofstream residual;
	residual.open("residual.plt");
	residual<<"res"<<endl<<"variables=iter,res"<<endl
		<<"Zone T=iter, I=5000, F=Point, C=Red"<<endl;
	for (int i=0;i<nedge;i++)
	{
		printf("k=%d\n",k[i]);
		getchar();
	}
	getchar();
	wi_cal();
	qk_cal();
	art_dis_cal();
	//getchar();
	for(int i=0;i<ncell;i++)
	{
		//printf("Q=%lf\n",Q[0][i]);
		res0=res0+abs(-Q[0][i]+D[0][i]);
		
	}
	printf("res0=%lf\n",res0);
	//getchar();
	do
	{
		Runge_Kutta();
		cout<<iters++<<'\t'<<'\t'<<"res="<<res<<endl;
		residual<<iters<<'\t'<<res<<endl;
	}while((iters<20000)&(res>0.1));
	residual.close();

	write_plt("mach0.8.plt");
	cp_out("Cp_mach0.8.plt");
	cout<<"cl="<<cl<<endl;
	cout<<"cd="<<cd<<endl;
	ofstream cl_cd_out;
	cl_cd_out.open("cl_cd.dat");


	free_memery(iedge,4);
	free_memery(icell,3);
	free_memery(W,4);
	free_memery(Q,4);
	free_memery(W0,4);
	free_memery(Rm,4);
	free_memery(xy,2);
	free_memery(vol);
	free_memery(k);
	free_memery(p);
	free_memery(P);
	free_memery(dt);
	free_memery(dx);
	free_memery(dy);
	free_memery(Mach);
	free_memery(D,4);
	free_memery(dw,4);
	free_memery(d2,4);
	free_memery(d4,4);
	cin.get();

	return 0;
}

//for test only
//for lan test

