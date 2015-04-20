struct param
{
int num1;
int num2;
};

program sum
{
	version sum_ver
	{
		int addition(param)=3;
	}=1;
}=2;
