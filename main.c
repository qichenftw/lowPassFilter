#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double omega1, omega2, omegac, T, dt;
	int N;

	//Scan the inputs from the user.
	scanf("%lf %lf %lf", &omega1, &omega2, &omegac);

	T = 3 * 2 * M_PI / omega1;      // Total time
  N = 20 * T / (2 * M_PI / omega2);   // Total number of time steps
  dt = T / N;             // Time step

	int i;
	double Voutnew = 0, Voutcur = 0, Voutprev = 0;

	for(i = 0; i < N; i++){
		//split math into parts to make it more readable
		double partA = (1/(((1/(sqrt(2)*dt*omegac)))+(1/(dt*dt*omegac*omegac))));
		double partB = ((2/(dt*dt*omegac*omegac))-1)*Voutcur;
		double partC = ((1/(sqrt(2)*dt*omegac)) - (1/(dt*dt*omegac*omegac)))*Voutprev;
		double partD = sin(omega1*i*dt);
		double partE = 0.5 * sin(omega2*i*dt);
		Voutnew = partA * (partB + partC + partD + partE);
		printf("%lf\n", Voutnew);
		Voutprev = Voutcur;
		Voutcur = Voutnew;
	};
	return 0;
}
